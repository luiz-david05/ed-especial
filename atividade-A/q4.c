#include <stdio.h>

/* Leia o valor do dólar e um valor em dólar, calcule e escreva o equivalente em real (R$). */

int main() {
    float valor_dolar;
    printf("Valor em dolar: ");
    scanf("%f", &valor_dolar);
    
    float cotacao;
    printf("Valor da cotacao: ");
    scanf("%f", &cotacao);

    printf("Valor: R$%.2f", valor_dolar * cotacao);

    return 0;
}