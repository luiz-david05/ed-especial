#include <stdlib.h> // malloc, free, exit
#include <stdio.h> // printf
#include "matriz.h"

// matrizes dinamicas representadas por vetores de ponteiros

struct matriz {
    int lin;
    int col;
    float **v;
};

Matriz* cria_matriz(int m, int n) {
    int i;
    Matriz* novaMatriz = (Matriz*) malloc(sizeof(Matriz));
    if (novaMatriz == NULL) {
        printf("Memoria insuficiente!\n");
        exit(1);
    }
    novaMatriz->lin = m;
    novaMatriz->col = n;
    novaMatriz->v = (float**) malloc(m * sizeof(float*));

    if (novaMatriz->v == NULL) {
        printf("Memoria insuficiente!\n");
        free(novaMatriz);
        exit(1);
    }

    for (i = 0; i < m; i++) {
        novaMatriz->v[i] = (float*) malloc(n * sizeof(float));
    }

    return novaMatriz;
}

void libera_matriz(Matriz* matriz) {
    int i;
    for (i = 0; i < matriz->lin; i++) {
        free(matriz->v[i]);
    }
    free(matriz->v);
    free(matriz);
}

float acessa_matriz(Matriz* matriz, int i, int j) {
    if (i < 0 || i >= matriz->lin || j < 0 || j >= matriz->col) {
        printf("Acesso invalido\n");
        exit(1);
    }
    return matriz->v[i][j];
}

void atribui_matriz(Matriz* matriz, int i, int j, float v) {
    if (i < 0 || i >= matriz->lin || j < 0 || j >= matriz->col) {
        printf("Atribuicao invalida\n");
        exit(1);
    }
    matriz->v[i][j] = v;
}

int qtd_linhas(Matriz* matriz) {
    return matriz->lin;
}

int qtd_colunas(Matriz* matriz) {
    return matriz->col;
}