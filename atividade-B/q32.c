#include <stdio.h>

/* Leia um número inteiro (3 dígitos), calcule e
escreva a diferença entre o número e seu inverso. */

int main() {
    int n;
    printf("Digite o numero: ");
    scanf("%d", &n);

    int resto = n;
    int c = resto / 100;
    resto %= 100;
    int d = resto / 10;
    int u = resto %= 10;

    int inverso = u * 100 + d * 10 + c * 1;
    int diff = n - inverso;

    printf("Diff = %d - %d = %d\n", n, inverso, diff);

    return 0;
}