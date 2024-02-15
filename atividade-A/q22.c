#include <stdio.h>

/* Leia um valor em km, calcule e escreva o equivalente em m. */

int main() {
    float km;
    printf("Distancia km: ");
    scanf("%f", &km);

    float m = km * 1000;
    printf("Distancia metros = %.1f\n", m);

    return 0;
}