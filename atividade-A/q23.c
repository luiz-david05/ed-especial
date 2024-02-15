#include <stdio.h>

/* Leia um valor em kg (quilograma), calcule e escreva o equivalente em g (grama). */

int main() {
    float kg;
    printf("Peso em kg: ");
    scanf("%f", &kg);

    float g = kg * 1000;
    printf("Peso em gramas = %.1f", g);

    return 0;
}