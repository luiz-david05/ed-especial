#include <stdio.h>

/* Leia um número inteiro (4 dígitos), calcule e escreva a soma dos elementos que o compõem. 
Ex.: número = 9534 ; soma = 9+5+3+4 = 21. */

int main() {
    int n;
    printf("Digite o numero: ");
    scanf("%d", &n);

    int resto = n;
    int m = resto / 1000;
    resto %= 1000;
    int c = resto / 100;
    resto %= 100;
    int d = resto / 10;
    int u = resto %= 10;

    int soma = m + c + d + u;

    printf("Soma dos elementos: %d + %d + %d + %d = %d\n", m, c, d, u, soma);

    return 0;
}