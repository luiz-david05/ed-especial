#include <stdio.h>

/* Leia o valor da base e altura de um triângulo, calcule e escreva sua área. (área=(base * altura)/2) */

int main() {
    float base, altura;
    printf("Digite a base e altura do triangulo: ");
    scanf("%f %f", &base, &altura);

    float area = (base * altura) / 2;
    printf("Area do triangulo = %.1f\n", area);

    return 0;
}