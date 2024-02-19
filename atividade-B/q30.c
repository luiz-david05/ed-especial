#include <stdio.h>

/* Leia um número inteiro de minutos, calcule e escreva quantos dias, 
quantas horas e quantos minutos ele corresponde. */

int main() {
    int min;
    printf("Digite o numero de minutos: ");
    scanf("%d", &min);

    int resto = min;
    int dias = resto / (24 * 60);
    resto %= 24 * 60;
    int hr = resto / 60;
    int resto_min = resto %= 60;
    printf("Resultado: %d dias, %d horas e %d minutos\n", dias, hr, resto_min);

    return 0;
}