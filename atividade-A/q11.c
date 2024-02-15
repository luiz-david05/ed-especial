#include <stdio.h>

/* Leia um número inteiro (3 dígitos) e escreva o inverso do número. (Ex.: número = 532 ; inverso = 235) */

int main() {
    int n;
    printf("Digite o numero: ");
    scanf("%d", &n);

    int c, d, u, resto = n;
    c = resto / 100;
    resto %= 100;
    d = resto / 10;
    u = resto % 10;

    printf("Numero (%d) e numero inverso: (%d%d%d)\n", n, u, d, c);

    return 0;
}