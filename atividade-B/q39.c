#include <stdio.h>
#include <math.h>

/* Leia três números inteiros e positivos (A, B, C) e calcule
a seguinte expressão: D = R + S / 2, onde: R = (A + B)**2, S = (B + C)**2*/

int main() {
    int a,b,c;
    printf("Digite o valor das variaveis a, b e c: ");
    scanf("%d %d %d", &a, &b, &c);

    int r = pow(a + b, 2);
    int s = pow(b + c, 2);
    int d = (r + s) / 2;

    printf("Resultado da expressao: R = %d, S = %d, e D = %d\n",r, s, d);

    return 0;
}