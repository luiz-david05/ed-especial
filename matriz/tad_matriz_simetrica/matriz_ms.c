#include <stdlib.h> // malloc, free, exit
#include <stdio.h> // printf
#include "ms.h"

typedef struct matriz_simetrica {
    int n;
    float *v;
} MatrizSimetrica;

MatrizSimetrica* ms_cria(int n) {
    MatrizSimetrica* msNova = (MatrizSimetrica*) malloc(sizeof(MatrizSimetrica));
    if (msNova == NULL) {
        printf("Memoria insuficiente!\n");
        exit(1);
    }
    msNova->n = n;
    msNova->v = (float*) malloc(n * (n + 1) / 2 * sizeof(float));
    if (msNova->v == NULL) {
        printf("Memoria insuficiente!\n");
        free(msNova);
        exit(1);
    }
    return msNova;
}

void ms_libera(MatrizSimetrica* ms) {
    if (ms != NULL) {
        free(ms->v);
        free(ms);
    }
}

float ms_acessa(MatrizSimetrica* m, int i, int j) {
    if (i < 0 || i >= m->n || j < 0 || j >= m->n) {
        printf("Índice inválido!\n");
        exit(1);
    }
    if (i < j) {
        // Garantir acesso a parte superior da matriz
        int temp = i;
        i = j;
        j = temp;
    }
    int indice = i * (i + 1) / 2 + j;
    return m->v[indice];
}

void ms_atribui(MatrizSimetrica* ms, int i, int j, float v) {
    if (i < 0 || i >= ms->n || j < 0 || j >= ms->n) {
        printf("Índice inválido!\n");
        exit(1);
    }
    if (i < j) {
        // Garantir que sempre atribua à parte superior da matriz
        int temp = i;
        i = j;
        j = temp;
    }
    int indice = i * (i + 1) / 2 + j;
    ms->v[indice] = v;
}
