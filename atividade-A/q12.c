#include <stdio.h>

/* Leia o salário de um trabalhador e escreva seu novo salário com um aumento de 25%. */

int main() {
    float salario;
    printf("Digite o salario: ");
    scanf("%f", &salario);

    float aumento = salario * 0.25;
    printf("Salario + aumento(%.2f) = %.2f\n", aumento, salario + aumento);

    return 0;
}