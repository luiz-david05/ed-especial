#include <stdio.h>

int main() {
    float km;
    printf("Velocidade em km/h: ");
    scanf("%f", &km);

    printf("Em m/s: %.2f\n", km / 3.6);

    return 0;
}