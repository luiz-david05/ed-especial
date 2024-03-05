#include <stdio.h>

/* Uma loja vende seus produtos no sistema entrada mais duas prestações, sendo a entrada maior ou igual a
cada uma das duas prestações; estas devem ser iguais, inteiras e as maiores possíveis. Por exemplo, se o
valor da mercadoria for R$ 270,00, a entrada e as duas prestações são iguais a R$ 90,00; se o valor da
mercadoria for R$ 302,00, a entrada é de R$ 102,00 e as duas prestações são iguais a R$ 100,00.
Escreva um algoritmo que receba o valor da mercadoria e forneça o valor da entrada e das duas
prestações, de acordo com as regras acima.*/

int main() {
    int valor_mercadoria;
    printf("Digite o valor da mercadoria: ");
    scanf("%d", &valor_mercadoria);

    int resto = valor_mercadoria % 3;
    float entrada = valor_mercadoria / 3 + resto;
    float prestacao = valor_mercadoria / 3;

    printf("Resultado: Entrada = %.2f, Prestacao = %.2f\n", entrada, prestacao);

    return 0;
} 