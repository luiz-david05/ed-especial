#include <stdio.h>

/* Leia um valor em minutos, calcule e escreva o equivalente em horas e minutos. */

int main() {
    int min;
    printf("Digite o tempo em minutos: ");
    scanf("%d", &min);

    int hr = min / 60;
    int min_resto = min % 60;

    printf("Tempo em horas e minutos: %dhr:%dmin\n", hr, min_resto);

    return 0;
}