#include <stdio.h>

/* Leia um número inteiro (3 dígitos), calcule e 
escreva a soma do número com seu inverso.
(Ex.: número = 532 ; inverso = 235 ; soma = 532 + 235 = 767).*/

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
    int soma = n + inverso;

    printf("Soma: %d + %d = %d\n", n, inverso, soma);

    return 0;
}