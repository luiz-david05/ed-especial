#include <stdio.h>

/* Leia uma velocidade em m/s, calcule e escreva esta velocidade em km/h. (Vkm/h = Vm/s * 3.6) */

int main() {
    float n;
    printf("Velocidade em m/s: ");
    scanf("%f", &n);

    printf("Velocidade em km/h: %.2f\n", n * 3.6);
    
    return 0;
}