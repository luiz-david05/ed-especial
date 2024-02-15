#include <stdio.h>

/* Leia 2 números, calcule e escreva a divisão da soma pela subtração dos números lidos. */

int main() {
    int n1, n2;

    printf("Digite os 2(dois) numeros: ");
    scanf("%d %d", &n1, &n2);

    int soma = n1 + n2;
    int diff = n1 - n2;

    int div = soma / diff;

    printf("Divisao da soma(%d) pela subtracao(%d) = %d\n", soma, diff, div);

    return 0;
}