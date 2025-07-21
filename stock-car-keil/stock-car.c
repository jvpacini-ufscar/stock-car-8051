// glcd-8051-image.c
// Jogo Stock Car - Versão Otimizada para Keil
#include <reg51.h>
#include <intrins.h>

// --- Definições ---
#define SCREEN_W 128
#define SCREEN_H 64
#define PLAYER_Y 56
#define CAR_SIZE 8
#define TRACK_WIDTH 40
#define BORDER_WIDTH 4
#define MAX_ENEMIES 3
#define MAX_CURVE_OFFSET 15

// Estados do jogo
#define GAME_PLAYING 0
#define GAME_OVER 1

#define CHAR_WIDTH 4
#define CHAR_HEIGHT 6

#define Data_Port P1
sbit RS = P2^0;
sbit RW = P2^1;
sbit E = P2^2;
sbit CS1 = P2^3;
sbit CS2 = P2^4;
sbit RST = P2^5;

sbit BUTTON_LEFT = P3^0;
sbit BUTTON_RIGHT = P3^2;
sbit BUTTON_START = P3^3;

// --- Sprites otimizados ---
code unsigned char car_sprite[CAR_SIZE] = {
    0x18,0x3C,0x7E,0xFF,0xFF,0x7E,0x3C,0x18
};

code unsigned char enemy_sprite[CAR_SIZE] = {
    0x81,0xC3,0xE7,0xFF,0xFF,0xE7,0xC3,0x81
};

code unsigned char border_sprite[BORDER_WIDTH] = {
    0xFF,0xFF,0xFF,0xFF
};

code unsigned char crash_sprite[CAR_SIZE] = {
    0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA,0x55
};

// --- Fonte compacta para números (4x6 pixels) ---
code unsigned char digits[10][CHAR_WIDTH] = {
    {0x3E,0x41,0x41,0x3E}, // 0
    {0x42,0x7F,0x40,0x00}, // 1
    {0x62,0x51,0x49,0x46}, // 2
    {0x22,0x49,0x49,0x36}, // 3
    {0x18,0x14,0x7F,0x10}, // 4
    {0x27,0x45,0x45,0x39}, // 5
    {0x3E,0x49,0x49,0x30}, // 6
    {0x01,0x71,0x0D,0x03}, // 7
    {0x36,0x49,0x49,0x36}, // 8
    {0x06,0x49,0x49,0x3E}  // 9
};

// Apenas as letras necessárias
code unsigned char letters[9][CHAR_WIDTH] = {
    {0x7E,0x09,0x09,0x7E}, // A
    {0x3E,0x41,0x41,0x22}, // C  
    {0x7F,0x49,0x49,0x41}, // E
    {0x3E,0x41,0x49,0x7A}, // G
    {0x7F,0x40,0x40,0x40}, // L (usado para construir outras)
    {0x3E,0x41,0x41,0x3E}, // O
    {0x7F,0x09,0x19,0x46}, // R
    {0x26,0x49,0x49,0x32}, // S
    {0x1F,0x20,0x40,0x3F}  // V
};

// Índices das letras
#define L_A 0
#define L_C 1
#define L_E 2
#define L_G 3
#define L_L 4
#define L_O 5
#define L_R 6
#define L_S 7
#define L_V 8

// --- Variáveis do jogo ---
unsigned char player_x;
signed char track_offset;
unsigned char scroll_offset;
signed char curve_direction;
unsigned char curve_timer;
unsigned char random_seed;
unsigned char game_state;
unsigned int score;
unsigned char score_timer;

// Inimigos
unsigned char enemy_x[MAX_ENEMIES];
unsigned char enemy_y[MAX_ENEMIES];
unsigned char enemy_active[MAX_ENEMIES];

// --- Protótipos ---
void delay(unsigned int k);
unsigned char get_random(void);
void GLCD_Init(void);
void GLCD_Clear(void);
void GLCD_DrawSprite(unsigned char x, unsigned char y, unsigned char size, const unsigned char *sprite);
void GLCD_DrawChar(unsigned char x, unsigned char y, const unsigned char *chr);
void GLCD_DrawDigit(unsigned char x, unsigned char y, unsigned char digit);
void GLCD_DrawNumber(unsigned char x, unsigned char y, unsigned int num);
unsigned char get_track_left(void);
unsigned char get_track_right(void);
unsigned char check_collision(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2);
unsigned char check_any_button(void);
void Game_Init(void);
void Game_Update(void);
void Game_Draw(void);
void Game_ShowGameOver(void);

// --- Implementações ---
void delay(unsigned int k) {
    unsigned int i,j;
    for(i=0;i<k;i++)
        for(j=0;j<120;j++);
}

unsigned char get_random() {
    random_seed ^= (random_seed << 3);
    random_seed ^= (random_seed >> 5);
    random_seed ^= (random_seed << 4);
    return random_seed;
}

void GLCD_SelectChip(unsigned char chip) {
    CS1 = CS2 = 0;
    if(chip == 1) CS1 = 1;
    else CS2 = 1;
    _nop_();
}

void GLCD_Command(char cmd) {
    Data_Port = cmd;
    RS = 0; RW = 0; E = 1; _nop_();
    E = 0; _nop_();
}

void GLCD_Data(char d) {
    Data_Port = d;
    RS = 1; RW = 0; E = 1; _nop_();
    E = 0; _nop_();
}

void GLCD_Init() {
    CS1 = CS2 = 1; RST = 1; delay(20);
    
    GLCD_SelectChip(0);
    GLCD_Command(0x3F);
    
    GLCD_SelectChip(1);
    GLCD_Command(0x3F);
}

void GLCD_Clear() {
    unsigned char page, col;
    
    for(page=0; page<8; page++){
        GLCD_SelectChip(0);
        GLCD_Command(0xB8 + page);
        GLCD_Command(0x40);
        for(col=0; col<64; col++) GLCD_Data(0x00);
        
        GLCD_SelectChip(1);
        GLCD_Command(0xB8 + page);
        GLCD_Command(0x40);
        for(col=0; col<64; col++) GLCD_Data(0x00);
    }
}

void GLCD_DrawSprite(unsigned char x, unsigned char y, unsigned char size, const unsigned char *sprite) {
    unsigned char page, offset, col, gx, chip, cx, byte;
    
    page = y/8;
    offset = y%8;
    
    for(col=0; col<size; col++){
        gx = x + col;
        if(gx >= SCREEN_W) break;
        
        chip = (gx < 64 ? 0 : 1);
        cx = (gx < 64 ? gx : gx-64);
        byte = sprite[col];
        
        GLCD_SelectChip(chip);
        GLCD_Command(0xB8 + page);
        GLCD_Command(0x40 + cx);
        GLCD_Data(byte << offset);
        
        if(offset && page < 7){
            GLCD_SelectChip(chip);
            GLCD_Command(0xB8 + page + 1);
            GLCD_Command(0x40 + cx);
            GLCD_Data(byte >> (8 - offset));
        }
    }
}

void GLCD_DrawChar(unsigned char x, unsigned char y, const unsigned char *chr) {
    GLCD_DrawSprite(x, y, CHAR_WIDTH, chr);
}

void GLCD_DrawDigit(unsigned char x, unsigned char y, unsigned char digit) {
    if(digit <= 9) {
        GLCD_DrawChar(x, y, digits[digit]);
    }
}

void GLCD_DrawNumber(unsigned char x, unsigned char y, unsigned int num) {
    unsigned char pos;
    
    pos = x;
    if(num >= 100) {
        GLCD_DrawDigit(pos, y, num/100);
        pos += 5;
        num %= 100;
        GLCD_DrawDigit(pos, y, num/10);
        pos += 5;
        GLCD_DrawDigit(pos, y, num%10);
    }
    else if(num >= 10) {
        GLCD_DrawDigit(pos, y, num/10);
        pos += 5;
        GLCD_DrawDigit(pos, y, num%10);
    }
    else {
        GLCD_DrawDigit(pos, y, num);
    }
}

unsigned char get_track_left(void) {
    signed int left = (SCREEN_W / 2) - (TRACK_WIDTH / 2) + track_offset;
    if(left < BORDER_WIDTH) left = BORDER_WIDTH;
    if(left > SCREEN_W - TRACK_WIDTH - BORDER_WIDTH) 
        left = SCREEN_W - TRACK_WIDTH - BORDER_WIDTH;
    return (unsigned char)left;
}

unsigned char get_track_right(void) {
    return get_track_left() + TRACK_WIDTH;
}

unsigned char check_collision(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2) {
    return (x1 < x2 + CAR_SIZE && x1 + CAR_SIZE > x2 && 
            y1 < y2 + CAR_SIZE && y1 + CAR_SIZE > y2);
}

unsigned char check_any_button(void) {
    return (!BUTTON_LEFT || !BUTTON_RIGHT || !BUTTON_START);
}

void Game_Init(void) {
    unsigned char i;
    
    game_state = GAME_PLAYING;
    track_offset = 0;
    player_x = (SCREEN_W / 2) - (CAR_SIZE / 2);
    scroll_offset = 0;
    curve_direction = 0;
    curve_timer = 0;
    random_seed += 0x1F;
    score = 0;
    score_timer = 0;
    
    for(i = 0; i < MAX_ENEMIES; i++){
        enemy_active[i] = 0;
    }
}

void Game_Update(void) {
    unsigned char i, track_left, track_right;
    signed int new_offset, left_pos, right_pos;
    
    if(game_state != GAME_PLAYING) return;
    
    // Score
    if(++score_timer >= 10) {
        score_timer = 0;
        if(score < 999) score++;
    }
    
    // Track curves
    if(++curve_timer > 40) {
        curve_timer = 0;
        curve_direction = (get_random() % 3) - 1;
    }
    
    if(curve_direction != 0) {
        new_offset = track_offset + curve_direction;
        if(new_offset >= -MAX_CURVE_OFFSET && new_offset <= MAX_CURVE_OFFSET) {
            left_pos = (SCREEN_W / 2) - (TRACK_WIDTH / 2) + new_offset;
            right_pos = left_pos + TRACK_WIDTH;
            if(left_pos >= BORDER_WIDTH && right_pos <= SCREEN_W - BORDER_WIDTH) {
                track_offset = new_offset;
            }
        }
    }
    
    scroll_offset++;
    if(scroll_offset >= 8) scroll_offset = 0;
    
    // Player
    track_left = get_track_left();
    track_right = get_track_right();
    
    if(!BUTTON_LEFT && player_x > track_left)
        player_x -= 2;
    if(!BUTTON_RIGHT && player_x < track_right - CAR_SIZE)
        player_x += 2;
    
    if(player_x < track_left) player_x = track_left;
    if(player_x > track_right - CAR_SIZE) player_x = track_right - CAR_SIZE;
    
    // Enemies
    for(i = 0; i < MAX_ENEMIES; i++){
        if(enemy_active[i]){
            enemy_y[i] += 3;
            if(enemy_y[i] >= SCREEN_H) {
                enemy_active[i] = 0;
            }
            else if(check_collision(player_x, PLAYER_Y, enemy_x[i], enemy_y[i])){
                game_state = GAME_OVER;
                return;
            }
        } else {
            if((get_random() % 180) < 2){
                enemy_active[i] = 1;
                enemy_y[i] = 0;
                enemy_x[i] = track_left + (get_random() % (track_right - track_left - CAR_SIZE));
            }
        }
    }
}

void Game_Draw(void) {
    unsigned char i, y, track_left, track_right;
    
    if(game_state != GAME_PLAYING) return;
    
    track_left = get_track_left();
    track_right = get_track_right();
    
    GLCD_Clear();
    
    // Score
    GLCD_DrawChar(2, 2, letters[L_S]);
    GLCD_DrawNumber(8, 2, score);
    
    // Track borders
    for(i = 0; i < SCREEN_H; i += 8) {
        y = i - scroll_offset;
        if(y < SCREEN_H) {
            if(track_left >= BORDER_WIDTH) {
                GLCD_DrawSprite(track_left - BORDER_WIDTH, y, BORDER_WIDTH, border_sprite);
            }
            if(track_right <= SCREEN_W - BORDER_WIDTH) {
                GLCD_DrawSprite(track_right, y, BORDER_WIDTH, border_sprite);
            }
        }
    }
    
    // Player
    GLCD_DrawSprite(player_x, PLAYER_Y, CAR_SIZE, car_sprite);
    
    // Enemies
    for(i = 0; i < MAX_ENEMIES; i++){
        if(enemy_active[i]){
            GLCD_DrawSprite(enemy_x[i], enemy_y[i], CAR_SIZE, enemy_sprite);
        }
    }
}

void Game_ShowGameOver(void) {
    unsigned char x;
    
    GLCD_Clear();
    
    // "GAME OVER" centralizado
    x = 35;
    GLCD_DrawChar(x, 20, letters[L_G]);      // G
    GLCD_DrawChar(x+5, 20, letters[L_A]);    // A
    GLCD_DrawChar(x+10, 20, letters[L_L]);   // M (usando L como base)
    GLCD_DrawChar(x+15, 20, letters[L_E]);   // E
    GLCD_DrawChar(x+25, 20, letters[L_O]);   // O
    GLCD_DrawChar(x+30, 20, letters[L_V]);   // V
    GLCD_DrawChar(x+35, 20, letters[L_E]);   // E
    GLCD_DrawChar(x+40, 20, letters[L_R]);   // R
    
    // "SCORE XXX"
    x = 40;
    GLCD_DrawChar(x, 35, letters[L_S]);      // S
    GLCD_DrawChar(x+5, 35, letters[L_C]);    // C
    GLCD_DrawChar(x+10, 35, letters[L_O]);   // O
    GLCD_DrawChar(x+15, 35, letters[L_R]);   // R
    GLCD_DrawChar(x+20, 35, letters[L_E]);   // E
    GLCD_DrawNumber(x+30, 35, score);
}

void main() {
    GLCD_Init();
    Game_Init();
    
    while(1) {
        if(game_state == GAME_PLAYING) {
            Game_Update();
            Game_Draw();
            delay(!BUTTON_START ? 25 : 50);
        }
        else {
            Game_ShowGameOver();
            if(check_any_button()) {
                while(check_any_button()) delay(10);
                Game_Init();
            }
            delay(100);
        }
    }
}
