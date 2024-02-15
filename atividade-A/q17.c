#include <stdio.h>

/* Leia o valor da base e altura de um retângulo, calcule e escreva sua área. (área = base * altura) */

int main() {
    float base, altura;
    printf("Digite o valor da base e altura do retangulo: ");
    scanf("%f %f", &base, &altura);

    float area = base * altura;
    printf("Area do retangulo = %.1f", area);

    return 0;
}