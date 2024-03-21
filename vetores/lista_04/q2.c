#include <stdio.h>
#include <stdlib.h>
#include "vetores_utils.h"
#include <stdbool.h>

bool elemento_existe(int *v, int len, int elemento) {
    for (int i = 0; i < len; i++) {
        if (v[i] == elemento) {
            return true;
        } 
    }
    
    return false;
}

void eliminar_elementos_repetidos(int *v, int *len) {
    int v_temp[*len];
    int len_temp = 0;

    for (int i = 0; i < *len; i++) {
        if (!elemento_existe(v_temp, len_temp, v[i])) {
            v_temp[len_temp] = v[i];
            len_temp++;
        }
    }

    for (int i = 0; i < len_temp; i++) {
        v[i] = v_temp[i];
    }

    *len = len_temp;
}

void preencher_vetor_elementos_repetidos(int *v1, int len1, int *v2, int len2, int *v3) {
    int k = 0;
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (v1[i] ==  v2[j]) {
                v3[k] = v1[i];
                k++;
            }
        }
    }

    printf("Vetor preenchido!\n");
}

int main() {
    int r[5] = {1, 2, 3, 4, 5};
    int s[10] = {1, 1, 6, 4, 7, 4, 2, 8, 9, 10};
    int tamanho_x = sizeof(r) / sizeof(r[0]);
    int x[tamanho_x];
    
    printf("Elementos do vetor r: ");
    exibir_elementos_vetor(5, r);

    printf("Elementos do vetor s: ");
    exibir_elementos_vetor(10, s);

    // // calculo tamanho dos vetores
    // int len1 = sizeof(r)/sizeof(r[0]);
    // int len2 = sizeof(s)/sizeof(s[0]);
    // int len3 = sizeof(x)/sizeof(x[0]);

    preencher_vetor_elementos_repetidos(r, 5, s, 10, x);
    eliminar_elementos_repetidos(x, &tamanho_x);
    
    printf("Elementos do vetor x: ");
    exibir_elementos_vetor(tamanho_x, x);

    return 0;
}