#include <stdio.h>

/* Leia um valor em real (R$), calcule e escreva 70% deste valor. */

int main() {
    float valor;
    printf("Digite o valor: ");
    scanf("%f", &valor);

    float percentual = valor * 0.7;
    printf("setenta(70) porcento = %.2f\n", percentual);

    return 0;
}