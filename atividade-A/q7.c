#include <stdio.h>

/* Leia 3 números, calcule e escreva a soma dos 2 primeiros e a diferença entre os 2 últimos. */

int main() {
    int n1, n2, n3;
    printf("digite os 3 numeros: ");
    scanf("%d %d %d", &n1, &n2, &n3);

    int soma = n1 + n2;
    int diff = n2 - n3;

    printf("soma dos dois(%d + %d) primeiros: %d\n", n1, n2, soma);
    printf("Diferenca entre os dois(%d - %d) ultimos: %d\n", n2, n3, diff);

    return 0;
}