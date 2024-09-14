#include <stdio.h>
#include "ms.h"

int main() {
    MatrizSimetrica* ms = ms_cria(2);

    ms_atribui(ms, 0, 0, 1.0);
    ms_atribui(ms, 0, 1, 2.0);
    ms_atribui(ms, 0, 2, 3.0);
    ms_atribui(ms, 1, 1, 4.0);
    ms_atribui(ms, 1, 2, 5.0);
    ms_atribui(ms, 2, 2, 6.0);

    printf("Matriz Simétrica:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.1f ", ms_acessa(ms, i, j));
        }
        printf("\n");
    }

    // Liberar a memória alocada
    ms_libera(ms);

    return 0;
}