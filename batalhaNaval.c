#include <stdio.h>

#define SIZE 10 

void inicializarTabuleiro(int tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void exibirTabuleiro(int tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void posicionarNavios(int tabuleiro[SIZE][SIZE]) {
    // Navio horizontal
    for (int j = 2; j < 5; j++) {
        tabuleiro[1][j] = 3;
    }
    // Navio vertical
    for (int i = 3; i < 6; i++) {
        tabuleiro[i][4] = 3;
    }
    // Navio diagonal (")")
    for (int i = 6, j = 6; i < 9; i++, j++) {
        tabuleiro[i][j] = 3;
    }
    // Navio diagonal (/)
    for (int i = 2, j = 8; i < 5; i++, j--) {
        tabuleiro[i][j] = 3;
    }
}

void aplicarHabilidadeCruz(int tabuleiro[SIZE][SIZE], int x, int y) {
    for (int i = 0; i < SIZE; i++) {
        tabuleiro[i][y] = 1;
        tabuleiro[x][i] = 1;
    }
}

void aplicarHabilidadeCone(int tabuleiro[SIZE][SIZE], int x, int y) {
    for (int i = x; i < SIZE && (i - x) < 3; i++) {
        for (int j = y - (i - x); j <= y + (i - x) && j < SIZE; j++) {
            if (j >= 0)
                tabuleiro[i][j] = 1;
        }
    }
}

void aplicarHabilidadeOctaedro(int tabuleiro[SIZE][SIZE], int x, int y) {
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (x + i >= 0 && x + i < SIZE && y + j >= 0 && y + j < SIZE && abs(i) + abs(j) <= 2) {
                tabuleiro[x + i][y + j] = 1;
            }
        }
    }
}

int main() {
    int tabuleiro[SIZE][SIZE];
    inicializarTabuleiro(tabuleiro);
    
    // Nível Novato - Posicionamento dos Navios..
    posicionarNavios(tabuleiro);
    printf("Tabuleiro com navios:\n");
    exibirTabuleiro(tabuleiro);
    
    // Nível Mestre - Aplicação de habilidades.
    printf("\nHabilidade Cruz aplicada no centro:\n");
    aplicarHabilidadeCruz(tabuleiro, SIZE/2, SIZE/2);
    exibirTabuleiro(tabuleiro);
    
    printf("\nHabilidade Cone aplicada no topo:\n");
    aplicarHabilidadeCone(tabuleiro, 0, SIZE/2);
    exibirTabuleiro(tabuleiro);
    
    printf("\nHabilidade Octaedro aplicada no meio:\n");
    aplicarHabilidadeOctaedro(tabuleiro, SIZE/2, SIZE/2);
    exibirTabuleiro(tabuleiro);
    
    return 0;
}