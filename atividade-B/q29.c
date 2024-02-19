#include <stdio.h>

/* Leia um número inteiro de meses, calcule e 
escreva quantos anos e quantos meses ele corresponde.*/

int main() {
    int meses;
    printf("Digite o numero de meses: ");
    scanf("%d", &meses);

    int anos = meses / 12;
    int resto_meses = meses % 12;
    printf("Resultado: %d anos e %d meses\n", anos, resto_meses);

    return 0;
}