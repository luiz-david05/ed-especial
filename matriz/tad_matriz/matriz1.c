#include <stdlib.h> // malloc, free, exit
#include <stdio.h> // printf
#include "matriz.h"

// matrizes dinamicas representadas por vetores simples

struct matriz {
    int lin;
    int col;
    float* v;
};

Matriz* cria_matriz(int m, int n) {
    Matriz* novaMatriz = (Matriz*) malloc(sizeof(Matriz));
    if (novaMatriz == NULL) {
        printf("Memoria insuficiente!\n");
        exit(1);
    }
    novaMatriz->lin = m;
    novaMatriz->col = n;
    novaMatriz->v = (float*) malloc(m * n * sizeof(float));
    return novaMatriz;
}

void libera_matriz(Matriz* matriz) {
    free(matriz->v);
    free(matriz);
}

float acessa_matriz(Matriz* matriz, int i, int j) {
    int k;

    if (i < 0 || i > matriz->lin || j < 0 || j>matriz->col) {
        printf("Acesso invalido!\n");
        exit(1);
    }
    k = i*matriz->col + j;
    return matriz->v[k];
}

void atribui_matriz (Matriz* matriz, int i, int j, float v) {
    if (i < 0 || i >= matriz->lin || j < 0 || j>= matriz->col) {
        printf("Atribuicao invalida!\n");
        exit(1);
    }
    int k = i * matriz->col + j;
    matriz->v[k] = v;
}

int qtd_linhas(Matriz* matriz) {
    return matriz->lin;
}

int qtd_colunas(Matriz* matriz) {
    return matriz->col;
}

int eh_quadrada_simetrica(Matriz* matriz) {
    int n = matriz->lin;
    
    // Verifica se a matriz é quadrada
    if (n != matriz->col) {
        return 0;
    }

    // Verifica se a matriz é simétrica
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (acessa_matriz(matriz, i, j) != acessa_matriz(matriz, j, i)) {
                return 0;
            }
        }
    }
    return 1;
}

Matriz* cria_transposta(Matriz* matriz) {
    int m = matriz->lin;
    int n = matriz->col;

    Matriz* matrizTransposta = cria_matriz(n, m);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            float valor = acessa_matriz(matriz, i, j);
            atribui_matriz(matrizTransposta, j, i, valor);
        }
    }

    return matrizTransposta;
}

void imprime_matriz(Matriz* matriz) {
    for (int i = 0; i < qtd_linhas(matriz); i++) {
        for (int j = 0; j < qtd_colunas(matriz); j++) {
            printf("%.1f ", acessa_matriz(matriz, i, j));
        }
        printf("\n");
    }
}