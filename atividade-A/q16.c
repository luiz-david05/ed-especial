#include <stdio.h>

/* Leia o valor do lado de um quadrado, calcule e escreva sua área. (área = lado2) */

int main() {
    float lado;
    printf("Valor do lado do quadrado: ");
    scanf("%f", &lado);

    float area = lado * lado;
    printf("Area do quadrado: %.1f", area);

    return 0;
}