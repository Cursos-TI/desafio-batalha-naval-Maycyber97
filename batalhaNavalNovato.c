#include <stdio.h>

int main() {
    // Tamanho do tabuleiro
    int tabuleiro[10][10];

    // Inicializando o tabuleiro com 0 (água)
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // Navio horizontal (tamanho 3)
    int linhaNavioH = 2; // Linha inicial
    int colunaNavioH = 4; // Coluna inicial

    // Verifica se cabe no tabuleiro
    if (colunaNavioH + 2 < 10) {
        tabuleiro[linhaNavioH][colunaNavioH] = 3;
        tabuleiro[linhaNavioH][colunaNavioH + 1] = 3;
        tabuleiro[linhaNavioH][colunaNavioH + 2] = 3;
    } else {
        printf("Navio horizontal fora do limite!\n");
    }

    // Navio vertical (tamanho 3)
    int linhaNavioV = 5; // Linha inicial
    int colunaNavioV = 1; // Coluna inicial

    // Verifica se cabe no tabuleiro e se não sobrepõe o outro navio
    if (linhaNavioV + 2 < 10 &&
        tabuleiro[linhaNavioV][colunaNavioV] == 0 &&
        tabuleiro[linhaNavioV + 1][colunaNavioV] == 0 &&
        tabuleiro[linhaNavioV + 2][colunaNavioV] == 0) {

        tabuleiro[linhaNavioV][colunaNavioV] = 3;
        tabuleiro[linhaNavioV + 1][colunaNavioV] = 3;
        tabuleiro[linhaNavioV + 2][colunaNavioV] = 3;
    } else {
        printf("Navio vertical fora do limite ou sobreposição!\n");
    }

    // Exibindo o tabuleiro
    printf("\nTabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");

    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}