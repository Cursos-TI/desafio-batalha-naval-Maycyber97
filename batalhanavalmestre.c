#include <stdio.h>
#include <stdlib.h>

int main() {
    // -------------------------------
    // 1. Criação do Tabuleiro 10x10
    // -------------------------------
    int tabuleiro[10][10];

    // Inicializa com água (0)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // -------------------------------------
    // 2. Posiciona Navios de forma fixa (3)
    // -------------------------------------
    // Navio horizontal
    tabuleiro[1][2] = 3;
    tabuleiro[1][3] = 3;
    tabuleiro[1][4] = 3;

    // Navio vertical
    tabuleiro[5][7] = 3;
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;

    // Diagonal ↘
    tabuleiro[0][0] = 3;
    tabuleiro[1][1] = 3;
    tabuleiro[2][2] = 3;

    // Diagonal ↙
    tabuleiro[3][6] = 3;
    tabuleiro[4][5] = 3;
    tabuleiro[5][4] = 3;

    // ---------------------------------------------
    // 3. Matrizes de Habilidades (5x5 com centro)
    // ---------------------------------------------
    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    // Inicializa todas com 0
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cone[i][j] = 0;
            cruz[i][j] = 0;
            octaedro[i][j] = 0;
        }
    }

    // --------------------
    // 3.1 Habilidade: Cone
    // --------------------
    // Forma de pirâmide invertida com base embaixo
    for (int i = 0; i < 5; i++) { // linhas
        for (int j = 0; j < 5; j++) { // colunas
            if (j >= 2 - i && j <= 2 + i) {
                cone[i][j] = 1;
            }
        }
    }

    // --------------------
    // 3.2 Habilidade: Cruz
    // --------------------
    for (int i = 0; i < 5; i++) {
        cruz[2][i] = 1; // linha central
        cruz[i][2] = 1; // coluna central
    }

    // ------------------------
    // 3.3 Habilidade: Octaedro
    // ------------------------
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) {
                octaedro[i][j] = 1;
            }
        }
    }

    // ----------------------------------------------------------
    // 4. Sobrepor Habilidades no Tabuleiro (valor 5 nas áreas)
    // ----------------------------------------------------------
    // Ponto de origem no tabuleiro
    int origemConeLinha = 2, origemConeColuna = 2;
    int origemCruzLinha = 6, origemCruzColuna = 6;
    int origemOctaLinha = 5, origemOctaColuna = 2;

    // Função genérica de sobreposição (feita com loops aqui mesmo)
    for (int i = 0; i < 5; i++) { // linha da matriz de habilidade
        for (int j = 0; j < 5; j++) { // coluna da matriz de habilidade

            // Cone
            if (cone[i][j] == 1) {
                int linha = origemConeLinha + (i - 2);
                int coluna = origemConeColuna + (j - 2);
                if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10 &&
                    tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = 5;
                }
            }

            // Cruz
            if (cruz[i][j] == 1) {
                int linha = origemCruzLinha + (i - 2);
                int coluna = origemCruzColuna + (j - 2);
                if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10 &&
                    tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = 5;
                }
            }

            // Octaedro
            if (octaedro[i][j] == 1) {
                int linha = origemOctaLinha + (i - 2);
                int coluna = origemOctaColuna + (j - 2);
                if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10 &&
                    tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }

    // --------------------------
    // 5. Imprimir o Tabuleiro Final
    // --------------------------
    printf("\nTabuleiro com habilidades (0 = água, 3 = navio, 5 = habilidade):\n\n");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}