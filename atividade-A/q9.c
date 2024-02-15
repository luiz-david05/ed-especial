#include <stdio.h>

/* Leia 2 números (A, B) e escreva-os em ordem inversa (B, A). */

int main() {
    int n1, n2;
    printf("Digite os dois(2) numeros: ");
    scanf("%d %d", &n1, &n2);

    printf("Numeros na ordem inversa: (%d, %d)\n", n2, n1);

    return 0;
}