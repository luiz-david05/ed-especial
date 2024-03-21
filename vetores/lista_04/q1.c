#include <stdio.h>
#include "vetores_utils.h"

/* 1. Escreva um programa em C para ler um vetor X de n elementos inteiros.
Crie uma função que copie os elementos do vetor X para um vetor Y fazendo com que o 
1o. elemento de X seja copiado para o n-ésimo elemento de Y, o 2o. de X para o n-ésimo-1. de Y e 
assim sucessivamente. Imprima o vetor Y na main.*/

int main() {
    int n;
    printf("Tamanho do vetor: ");
    scanf("%d", &n);

    int x[n];
    preencher_vetor(n, x);
    int y[n];
    preencher_inverso(n, x, y);

    printf("Vetor x: ");
    exibir_elementos_vetor(n, x);

    printf("Vetor y: ");
    exibir_elementos_vetor(n, y);

    return 0;
}