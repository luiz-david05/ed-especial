#include <stdio.h>

/* Leia a idade de uma pessoa expressa em dias e escreva-a expressa em anos, meses e dias. */

int main() {
    int idade_dias;
    printf("Digite a idade em dias: ");
    scanf("%d", &idade_dias);

    int resto = idade_dias;
    int idade_anos = resto / 365;
    resto %= 365;
    int idade_meses = resto / 30;
    int idade_resto_dias = resto %= 30;

    printf("Idade em anos, meses e dias (valor aproximado): %d anos, %d meses e %d dias", idade_anos, idade_meses, idade_resto_dias);

    return 0;
}