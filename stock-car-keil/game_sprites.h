#ifndef GAME_SPRITES_H
#define GAME_SPRITES_H

// Sprite Dimensions
#define PLAYER_CAR_WIDTH    8
#define PLAYER_CAR_HEIGHT   8

#define ENEMY_CAR_WIDTH     8
#define ENEMY_CAR_HEIGHT    8

#define ASTERISK_WIDTH      8
#define ASTERISK_HEIGHT     8

// New dimensions for the road line sprite
#define ROAD_LINE_WIDTH     4   // Width of the road line
#define ROAD_LINE_HEIGHT    8   // Height of the road line

// Declaration of bitmaps (the 'code' keyword indicates storage in program memory/ROM)
// These are "extern", meaning their actual data is defined in another .c file (in this case, glcd-8051-image.c)
extern code unsigned char solid_8x8[];
extern code unsigned char asterisk_8x8[];
extern code unsigned char road_line_4x8[]; // Declaration of the new road line sprite

// Add other sprite declarations you create here (e.g., road sprites, other cars)

#endif // GAME_SPRITES_H