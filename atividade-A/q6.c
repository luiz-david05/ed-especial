#include <stdio.h>

/* Leia uma velocidade em km/h, calcule e escreva esta velocidade em m/s. (Vm/s = Vkm/h / 3.6) */

int main() {
    float km;
    printf("Velocidade em km/h: ");
    scanf("%f", &km);

    printf("Em m/s: %.2f\n", km / 3.6);

    return 0;
}