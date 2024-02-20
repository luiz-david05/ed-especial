#include <stdio.h>

/* Leia 2 (duas) frações (numerador e denominador), calcule e escreva a soma destas frações,
escrevendo o resultado em forma de fração.*/

int main() {
    printf("Soma de fracoes com denominadores iguais\n");
    int num1, den1, num2, den2;
    printf("Digite o numerador e denominador da primeira fracao: ");
    scanf("%d %d", &num1, &den1);

    printf("Digite o numerador e denominador da segunda fracao: ");
    scanf("%d %d", &num2, &den2);

    int soma = num1 + num2;

    printf("Resultado da soma das fracoes(sujeito a erros): %d/%d\n", soma, den1);

    return 0;
}