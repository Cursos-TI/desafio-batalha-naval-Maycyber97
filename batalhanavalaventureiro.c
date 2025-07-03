#include <stdio.h>

int main() {
    // Tamanho do tabuleiro
    int tabuleiro[10][10];

    // Inicializa o tabuleiro com 0 (água)
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // ---------------------
    // NAVIO 1: Horizontal
    // ---------------------
    int linhaH = 1;
    int colunaH = 2;

    // Verifica limites
    if (colunaH + 2 < 10 &&
        tabuleiro[linhaH][colunaH] == 0 &&
        tabuleiro[linhaH][colunaH + 1] == 0 &&
        tabuleiro[linhaH][colunaH + 2] == 0) {

        tabuleiro[linhaH][colunaH] = 3;
        tabuleiro[linhaH][colunaH + 1] = 3;
        tabuleiro[linhaH][colunaH + 2] = 3;
    } else {
        printf("Navio horizontal não pôde ser posicionado.\n");
    }

    // ---------------------
    // NAVIO 2: Vertical
    // ---------------------
    int linhaV = 5;
    int colunaV = 7;

    if (linhaV + 2 < 10 &&
        tabuleiro[linhaV][colunaV] == 0 &&
        tabuleiro[linhaV + 1][colunaV] == 0 &&
        tabuleiro[linhaV + 2][colunaV] == 0) {

        tabuleiro[linhaV][colunaV] = 3;
        tabuleiro[linhaV + 1][colunaV] = 3;
        tabuleiro[linhaV + 2][colunaV] = 3;
    } else {
        printf("Navio vertical não pôde ser posicionado.\n");
    }

    // ---------------------
    // NAVIO 3: Diagonal Principal (↘)
    // ---------------------
    int linhaD1 = 0;
    int colunaD1 = 0;

    if (linhaD1 + 2 < 10 && colunaD1 + 2 < 10 &&
        tabuleiro[linhaD1][colunaD1] == 0 &&
        tabuleiro[linhaD1 + 1][colunaD1 + 1] == 0 &&
        tabuleiro[linhaD1 + 2][colunaD1 + 2] == 0) {

        tabuleiro[linhaD1][colunaD1] = 3;
        tabuleiro[linhaD1 + 1][colunaD1 + 1] = 3;
        tabuleiro[linhaD1 + 2][colunaD1 + 2] = 3;
    } else {
        printf("Navio diagonal principal não pôde ser posicionado.\n");
    }

    // ---------------------
    // NAVIO 4: Diagonal Secundária (↙)
    // ---------------------
    int linhaD2 = 3;
    int colunaD2 = 6;

    if (linhaD2 + 2 < 10 && colunaD2 - 2 >= 0 &&
        tabuleiro[linhaD2][colunaD2] == 0 &&
        tabuleiro[linhaD2 + 1][colunaD2 - 1] == 0 &&
        tabuleiro[linhaD2 + 2][colunaD2 - 2] == 0) {

        tabuleiro[linhaD2][colunaD2] = 3;
        tabuleiro[linhaD2 + 1][colunaD2 - 1] = 3;
        tabuleiro[linhaD2 + 2][colunaD2 - 2] = 3;
    } else {
        printf("Navio diagonal secundária não pôde ser posicionado.\n");
    }

    // ---------------------
    // Impressão do Tabuleiro
    // ---------------------
    printf("\nTabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");

    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}