#pragma once
#define VETORES_UTILS
#include <stdio.h>

void preencher_vetor(int n, int *v) {
    int i = 0;

    printf("Digite os elementos do vetor de tamanho %d\n", n);
    for (; i < n; i++) {
        printf("%d ->: ", i + 1);
        scanf("%d", &v[i]);
    }

    printf("Vetor preenchido!\n");
}

void exibir_elementos_vetor(int n, int *v) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    printf("\n");
}

void preencher_inverso(int n, int *v1, int *v2) {
    for (int i = 0; i < n; i++) {
        v2[n - i - 1] = v1[i]; 
    }

    printf("Vetor preenchido!\n");
}