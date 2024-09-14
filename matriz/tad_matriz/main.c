#include <stdio.h>
#include "matriz.h"

int main() {
    Matriz* m = cria_matriz(3, 4);

    for (int i = 0; i < qtd_linhas(m); i++) {
        for (int j = 0; j < qtd_colunas(m); j++) {
            atribui_matriz(m, i, j, (float)(i * qtd_colunas(m) + j));
        }
    }

    printf("Matriz de 3 linhas e 4 colunas\n");
    for (int i = 0; i < qtd_linhas(m); i++) {
        for (int j = 0; j < qtd_colunas(m); j++) {
            printf("%.2f ", acessa_matriz(m, i, j));
        }
        printf("\n");
    }

    libera_matriz(m);

    return 0;
}