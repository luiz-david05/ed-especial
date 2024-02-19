#include <stdio.h>

/* Leia a idade de uma pessoa expressa em anos, meses e dias 
e escreva-a expressa apenas em dias. */

int main() {
    int idade_anos, idade_meses, idade_dias;
    printf("Digite a idade em anos, meses e dias: ");
    scanf("%d %d %d", &idade_anos, &idade_meses, &idade_dias);

    int idade_total_dias = idade_anos * 365 + idade_meses * 30 + idade_dias;

    printf("Idade em dias (valor aproximado): %d\n", idade_total_dias);

    return 0;
}