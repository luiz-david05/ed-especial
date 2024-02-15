#include <stdio.h>
/* Leia o valor do raio de uma circunferência, calcule e escreva seu comprimento.(c = 2 * p * r) */

int main() {
    double pi = 3.14;
    float raio;
    printf("Digite o valor do raio: ");
    scanf("%f", &raio);

    float circunferencia = 2 * pi * raio;
    printf("Valor da circunferencia = %.2f", circunferencia);

    return 0;
}