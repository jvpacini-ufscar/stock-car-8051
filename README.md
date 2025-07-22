🏎️ Stock Car Game for 8051 Microcontroller
Um jogo clássico de corrida implementado em C para microcontrolador AT89C52 com display GLCD 128x64

📋 Sobre o Projeto
Este projeto implementa um jogo completo de Stock Car em linguagem C para o microcontrolador AT89C52 (família 8051), utilizando um display LCD gráfico de 128x64 pixels com controlador KS0108. O jogo demonstra conceitos avançados de programação em sistemas embarcados, incluindo:

🎮 Interface gráfica responsiva
🚗 Sistema de sprites bitmap otimizado
💥 Detecção de colisão em tempo real
🏆 Sistema de pontuação dinâmico
🛣️ Geração procedural de pistas
✨ Características
Controles intuitivos: 3 botões (esquerda, direita, turbo)
Pista dinâmica: Curvas geradas algoritmicamente
Inimigos inteligentes: Spawn aleatório com padrões variados
Sistema de score: Pontuação baseada em tempo de sobrevivência
Tela de Game Over: Interface profissional com reinício
Otimização extrema: Código otimizado para 2KB de memória
🛠️ Materiais Necessários
Hardware
Microcontrolador AT89C52 ou compatível 8051
Display GLCD 128x64 com controlador KS0108/KS0107
3 botões push-button
Cristal oscilador 11.0592 MHz
Resistores de pull-up (10kΩ)
Potenciômetro para contraste (10kΩ)
Capacitores de desacoplamento
Software
Keil uVision C51 - IDE e compilador
Proteus ISIS - Simulação de circuito
Git para controle de versão
🚀 Como Usar
1. Clone o Repositório
git clone https://github.com/seu-usuario/stock-car-8051.git
cd stock-car-8051
2. Abrir no Keil uVision
Abra o Keil uVision
Carregue o projeto: simulation/keil/stock-car.uvproj
Compile o projeto (F7)
Gere o arquivo HEX
3. Simular no Proteus
Abra o Proteus ISIS
Carregue o projeto: simulation/proteus/stock-car.pdsprj
Carregue o arquivo HEX gerado
Execute a simulação
4. Programar o Microcontrolador
Use um programador compatível com 8051
Grave o arquivo .hex gerado pelo Keil
🎮 Como Jogar
Iniciar: Pressione qualquer botão na tela inicial
Controles:
Botão Esquerdo: Move o carro para a esquerda
Botão Direito: Move o carro para a direita
Botão Start: Ativa modo turbo (velocidade reduzida)
Objetivo: Evite colidir com outros carros
Pontuação: Ganha pontos automaticamente enquanto sobrevive

Game Over: Pressione qualquer botão para reiniciar
🏗️ Arquitetura do Código
main.c

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
📊 Especificações Técnicas
Componente		Especificação
Microcontrolador	AT89C52 (8051 compatible)
Clock			11.0592 MHz
Memória RAM		256 bytes internos
Memória Flash		8KB (2KB usados)
Display			GLCD 128x64 KS0108
Resolução de jogo	128x64 pixels
Sprites			8x8 pixels bitmap
Fonte			4x6 pixels custom

🔧 Compilação e Otimizações
O projeto foi otimizado para a versão de avaliação do Keil (limite de 2KB):

Sprites compactos: Redução de 5x7 para 4x6 pixels
Fonte mínima: Apenas caracteres necessários
Funções combinadas: Redução de overhead
Tipos otimizados: Uso inteligente de unsigned char
Comandos de Compilação
bash
Copy

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

💡 Ideias para Contribuições
[ ] Sistema de diferentes níveis de dificuldade
[ ] Efeitos sonoros com buzzer
[ ] High score persistente em EEPROM
[ ] Física de movimento melhorada
[ ] Power-ups e bônus especiais
[ ] Multiplayer local
[ ] Documentação em inglês
📝 Documentação
📄 Relatório Técnico Completo
🔧 Esquema do Circuito
📋 Lista de Componentes
🎯 Guia de Troubleshooting

Gameplay
<img width="1076" height="767" alt="Captura de tela 2025-07-21 193820" src="https://github.com/user-attachments/assets/302ad2c1-ca0b-4506-b9fc-8468a91aea5d" />


🏆 Reconhecimentos
Inspirado nos jogos clássicos de arcade dos anos 80
Desenvolvido como projeto acadêmico de Sistemas Embarcados
Agradecimentos à comunidade 8051 e retro-computing
Agradecimento especial ao Professor Doutor Emerson Carlos Pedrino

📄 Licença
Este projeto está licenciado sob a Licença MIT - veja o arquivo LICENSE para detalhes.

👤 Autores
Professor Doutor Emerson Carlos Pedrino
Estudante de Engenharia de Computação, UFSCar - João Victor Pacini
Estudante de Engenharia de Computação, UFSCar - Samuel Said

🌟 Mostre seu Apoio
Se este projeto te ajudou, deixe uma ⭐ no repositório!

Feito com ❤️ e muito café ☕

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
