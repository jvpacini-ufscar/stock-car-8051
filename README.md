🏎️ Stock Car Game for 8051 Microcontroller <br>
Um jogo clássico de corrida implementado em C para microcontrolador AT89C52 com display GLCD 128x64

📋 Sobre o Projeto <br>
Este projeto implementa um jogo completo de Stock Car em linguagem C para o microcontrolador AT89C52 (família 8051), utilizando um display LCD gráfico de 128x64 pixels com controlador KS0108. O jogo demonstra conceitos avançados de programação em sistemas embarcados, incluindo:

🎮 Interface gráfica responsiva <br>
🚗 Sistema de sprites bitmap otimizado <br>
💥 Detecção de colisão em tempo real <br>
🏆 Sistema de pontuação dinâmico <br>
🛣️ Geração procedural de pistas <br>
✨ Características <br>
Controles intuitivos: 2 botões (esquerda, direita) <br>
Pista dinâmica: Curvas geradas algoritmicamente <br>
Inimigos inteligentes: Spawn aleatório com padrões variados <br>
Sistema de score: Pontuação baseada em tempo de sobrevivência <br>
Tela de Game Over: Interface profissional com reinício <br>
Otimização extrema: Código otimizado para 2KB de memória <br>
🛠️ Materiais Necessários <br>
Hardware <br>
Microcontrolador AT89C52 ou compatível 8051 <br>
Display GLCD 128x64 com controlador KS0108/KS0107 <br>
2 botões push-button <br>
Cristal oscilador 11.0592 MHz <br>
Resistores de pull-up (10kΩ) <br>
Potenciômetro para contraste (10kΩ) <br>
Capacitores de desacoplamento <br>
Software <br>
Keil uVision C51 - IDE e compilador <br>
Proteus ISIS - Simulação de circuito <br>
Git para controle de versão <br>
🚀 Como Usar <br>
1. Clone o Repositório <br>
git clone https://github.com/seu-usuario/stock-car-8051.git 
cd stock-car-8051
2. Abrir no Keil uVision <br>
Abra o Keil uVision
Carregue o projeto: simulation/keil/stock-car.uvproj
Compile o projeto (F7)
Gere o arquivo HEX
3. Simular no Proteus <br>
Abra o Proteus ISIS
Carregue o projeto: simulation/proteus/stock-car.pdsprj
Carregue o arquivo HEX gerado
Execute a simulação
4. Programar o Microcontrolador <br>
Use um programador compatível com 8051
Grave o arquivo .hex gerado pelo Keil
🎮 Como Jogar <br>
Iniciar: Pressione qualquer botão na tela inicial <br>
Controles:  <br>
Botão Esquerdo: Move o carro para a esquerda <br>
Botão Direito: Move o carro para a direita <br>
Botão Start: Ativa modo turbo (velocidade reduzida) <br>
Objetivo: Evite colidir com outros carros <br>
Pontuação: Ganha pontos automaticamente enquanto sobrevive <br>

Game Over: Pressione qualquer botão para reiniciar <br>
🏗️ Arquitetura do Código <br>
main.c <br>
├── Sistema de Estados (PLAYING/GAME_OVER) <br>
├── Interface GLCD <br>
│ ├── Inicialização dual-chip <br>
│ ├── Renderização de sprites <br>
│ └── Sistema de fontes bitmap <br>
├── Lógica do Jogo <br>
│ ├── Controle do jogador <br> 
│ ├── Gerenciamento de inimigos <br>
│ ├── Detecção de colisão (AABB) <br>
│ └── Sistema de pontuação <br>
└── Otimizações <br>
├── Gerador pseudo-aleatório (LFSR) <br>
├── Sprites compactos <br>
└── Gerenciamento eficiente de memória <br>

📊 Especificações Técnicas <br>
Componente		Especificação <br>
Microcontrolador	AT89C52 (8051 compatible) <br>
Clock			11.0592 MHz <br>
Memória RAM		256 bytes internos <br>
Memória Flash		8KB (2KB usados) <br>
Display			GLCD 128x64 KS0108 <br>
Resolução de jogo	128x64 pixels <br>
Sprites			8x8 pixels bitmap <br>
Fonte			4x6 pixels custom <br>

🔧 Compilação e Otimizações <br>
O projeto foi otimizado para a versão de avaliação do Keil (limite de 2KB): <br>

Sprites compactos: Redução de 5x7 para 4x6 pixels <br>
Fonte mínima: Apenas caracteres necessários <br>
Funções combinadas: Redução de overhead <br>
Tipos otimizados: Uso inteligente de unsigned char <br>
Comandos de Compilação <br>
bash <br>
Copy <br>

# No Keil uVision 
Build Target: F7
Rebuild All: Ctrl+F7
📈 Resultados de Performance
Tamanho do código: ~1.8KB (90% do limite)
Uso de RAM: ~45 bytes
FPS médio: 18-22 FPS
Tempo de resposta: <50ms
Spawn de inimigos: Aleatório balanceado
🤝 Contribuindo
Contribuições são bem-vindas! Para contribuir:

Faça um Fork do projeto
Crie uma branch para sua feature (git checkout -b feature/AmazingFeature)
Commit suas mudanças (git commit -m 'Add some AmazingFeature')
Push para a branch (git push origin feature/AmazingFeature)

Abra um Pull Request

💡 Ideias para Contribuições <br>
[ ] Sistema de diferentes níveis de dificuldade <br>
[ ] Efeitos sonoros com buzzer <br>
[ ] High score persistente em EEPROM <br>
[ ] Física de movimento melhorada <br>
[ ] Power-ups e bônus especiais <br>
[ ] Multiplayer local <br>
[ ] Documentação em inglês <br>
📝 Documentação <br>
📄 Relatório Técnico Completo <br>
🔧 Esquema do Circuito <br>
📋 Lista de Componentes <br>
🎯 Guia de Troubleshooting <br>

Gameplay
<img width="1076" height="767" alt="Captura de tela 2025-07-21 193820" src="https://github.com/user-attachments/assets/302ad2c1-ca0b-4506-b9fc-8468a91aea5d" />


🏆 Reconhecimentos <br>
Inspirado nos jogos clássicos de arcade dos anos 80 <br>
Desenvolvido como projeto acadêmico de Sistemas Embarcados <br>
Agradecimentos à comunidade 8051 e retro-computing <br>
Agradecimento especial ao Professor Doutor Emerson Carlos Pedrino <br>

📄 Licença <br>
Este projeto está licenciado sob a Licença MIT - veja o arquivo LICENSE para detalhes. <br>

👤 Autores <br>
Professor Doutor Emerson Carlos Pedrino <br>
Estudante de Engenharia de Computação, UFSCar - João Victor Pacini <br>
Estudante de Engenharia de Computação, UFSCar - Samuel Said <br>

🌟 Mostre seu Apoio <br>
Se este projeto te ajudou, deixe uma ⭐ no repositório! <br>

Feito com ❤️ e muito café ☕ <br>

4. LICENSE (MIT)
MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy

of this software and associated documentation files (the "Software"), to deal

in the Software without restriction, including without limitation the rights

to use, copy, modify, merge, publish, distribute, sublicense, and/or sell

copies of the Software, and to permit persons to whom the Software is

furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all

copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR

IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,

FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE

AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER

LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,

OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE

SOFTWARE.

5. hardware/components-list.md
Lista de Componentes
Componentes Principais
Componente	Modelo/Especificação	Quantidade	Observações
Microcontrolador	AT89C52 ou AT89S52	1	8051 compatible
Display GLCD	128x64 KS0108/KS0107	1	Backlight opcional
Cristal Oscilador	11.0592 MHz	1	Para baud rate padrão
Capacitor Cerâmico	22pF	2	Para oscilador
Capacitor Eletrolítico	10µF/16V	2	Desacoplamento
Resistor	10kΩ	6	Pull-up e divisor
Resistor	330Ω	1	LED indicador
Potenciômetro	10kΩ	1	Contraste do display
Push Button	6x6mm	3	Controles do jogo
LED	5mm Vermelho	1	Indicador de power
Protoboard	830 pontos	1	Para montagem
 Download
 Copy

Conexões dos Pinos
Microcontrolador AT89C52
P1.0-P1.7: Data bus para GLCD
P2.0: RS (Register Select)
P2.1: R/W (Read/Write)
P2.2: E (Enable)
P2.3: CS1 (Chip Select 1)
P2.4: CS2 (Chip Select 2)
P2.5: RST (Reset do GLCD)
P3.0: Botão Esquerda
P3.2: Botão Direita
P3.3: Botão Start
Display GLCD 128x64
Pinos 1-8: Data bus (DB0-DB7)
Pino 4: RS (Register Select)
Pino 5: R/W (Read/Write)
Pino 6: E (Enable)
Pino 15: CS1 (Chip Select 1)
Pino 16: CS2 (Chip Select 2)
Pino 17: RST (Reset)
Pino 3: V0 (Contraste - conectar ao potenciômetro)
Fonte de Alimentação
Tensão: 5V DC
Corrente: Mínimo 300mA
Regulador: 7805 (se usando fonte >5V)
