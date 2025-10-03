#include <stdio.h>

#define NAVIO   3
#define AGUA    0
#define EFEITO  5
#define N 10
#define NAVIO_TAM 3

// Imprime o tabuleiro 
void imprimir_tabuleiro(int t[N][N], const char cab[10]) {
    printf("     ");
    for (int i = 0; i < N; i++) {
        printf("%2c ", cab[i]);
    }
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("%2d | ", i + 1);
        for (int j = 0; j < N; j++) {
            printf("%2d ", t[i][j]);
        }
        printf("\n");
    }
}


int forma_cabe(int lin, int col) {
    return lin >= 0 && col >= 0 && lin + 3 <= N && col + 5 <= N;
}


int aplicar_forma(int t[N][N], int lin, int col, const int forma[3][5]) {
    if (!forma_cabe(lin, col)) {
        printf("Erro: forma 3x5 nao cabe em (%d,%d).\n", lin, col);
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (forma[i][j] != AGUA) {
                t[lin + i][col + j] = forma[i][j];
            }
        }
    }
    return 1;
}


int navio_horizontal_ok(int t[N][N], int lin, int col) {
    if (lin < 0 || col < 0 || col + NAVIO_TAM > N) return 0;
    for (int j = 0; j < NAVIO_TAM; j++) {
        if (t[lin][col + j] != AGUA) return 0;
    }
    return 1;
}

int navio_vertical_ok(int t[N][N], int lin, int col) {
    if (lin < 0 || col < 0 || lin + NAVIO_TAM > N) return 0;
    for (int i = 0; i < NAVIO_TAM; i++) {
        if (t[lin + i][col] != AGUA) return 0;
    }
    return 1;
}

int navio_diagonal_ok(int t[N][N], int lin, int col) {
    if (lin < 0 || col < 0 || lin + NAVIO_TAM > N || col + NAVIO_TAM > N) return 0;
    for (int i = 0; i < NAVIO_TAM; i++) {
        if (t[lin + i][col + i] != AGUA) return 0;
    }
    return 1;
}


int colocar_navio_horizontal(int t[N][N], int lin, int col) {
    if (!navio_horizontal_ok(t, lin, col)) {
        printf("Erro: navio horizontal em (%d,%d) nao cabe ou sobrepoe.\n", lin, col);
        return 0;
    }
    for (int j = 0; j < NAVIO_TAM; j++) t[lin][col + j] = NAVIO;
    return 1;
}

int colocar_navio_vertical(int t[N][N], int lin, int col) {
    if (!navio_vertical_ok(t, lin, col)) {
        printf("Erro: navio vertical em (%d,%d) nao cabe ou sobrepoe.\n", lin, col);
        return 0;
    }
    for (int i = 0; i < NAVIO_TAM; i++) t[lin + i][col] = NAVIO;
    return 1;
}

int colocar_navio_diagonal(int t[N][N], int lin, int col) {
    if (!navio_diagonal_ok(t, lin, col)) {
        printf("Erro: navio diagonal em (%d,%d) nao cabe ou sobrepoe.\n", lin, col);
        return 0;
    }
    for (int i = 0; i < NAVIO_TAM; i++) t[lin + i][col + i] = NAVIO;
    return 1;
}

int main(void) {
    int tabuleiro[N][N] = { AGUA }; /* zera tudo */
    char cabecalho[10] = { 'A','B','C','D','E','F','G','H','I','J' };

    /* Habilidades (3x5) */
    const int cone[3][5] = {
        {AGUA, AGUA, EFEITO, AGUA, AGUA},
        {AGUA, EFEITO, EFEITO, EFEITO, AGUA},
        {EFEITO, EFEITO, EFEITO, EFEITO, EFEITO}
    };

    const int cruz[3][5] = {
        {AGUA, AGUA, EFEITO, AGUA, AGUA},
        {EFEITO, EFEITO, EFEITO, EFEITO, EFEITO},
        {AGUA, AGUA, EFEITO, AGUA, AGUA}
    };

    const int octaedro[3][5] = {
        {AGUA, AGUA, EFEITO, AGUA, AGUA},
        {AGUA, EFEITO, EFEITO, EFEITO, AGUA},
        {AGUA, AGUA, EFEITO, AGUA, AGUA}
    };

    /* Posicionamentos */
    aplicar_forma(tabuleiro, 4, 3, cone);
    aplicar_forma(tabuleiro, 1, 2, cruz);
    aplicar_forma(tabuleiro, 7, 2, octaedro);

    colocar_navio_horizontal(tabuleiro, 1, 1);
    colocar_navio_vertical(tabuleiro, 5, 2);
    colocar_navio_diagonal(tabuleiro, 1, 7);

    imprimir_tabuleiro(tabuleiro, cabecalho);
    return 0;
}
