#include <stdio.h>
#include "matriz.h"

int main() {
    Matriz* m = cria_matriz(3, 3);

    atribui_matriz(m, 2, 0, 1.0);
    atribui_matriz(m, 0, 1, 2.0);
    atribui_matriz(m, 0, 2, 3.0);

    printf("Matriz Original:\n");
    imprime_matriz(m);

    Matriz* mt = cria_transposta(m);
    printf("\nMatriz Transposta:\n");
    for (int i = 0; i < qtd_linhas(mt); i++) {
        for (int j = 0; j < qtd_colunas(mt); j++) {
            printf("%.1f ", acessa_matriz(mt, i, j));
        }
        printf("\n");
    }

    libera_matriz(m);
    libera_matriz(mt);

    return 0;
}