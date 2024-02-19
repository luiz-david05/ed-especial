#include <stdio.h>
#include <math.h>

/* Leia um número inteiro (4 dígitos binários), calcule e escreva o 
equivalente na base decimal.*/

int main() {
    int n_binario;
    printf("Digite o numero binario(4 digitos): ");
    scanf("%d", &n_binario);

    int resto = n_binario;
    int d1 = resto / 1000;
    resto %= 1000;
    int d2 = resto / 100;
    resto %= 100;
    int d3 = resto / 10;
    int d4 = resto %= 10;

    int decimal = d1 * 8 + d2 * 4 + d3 * 2 + d4 * 1;

    printf("Decimal = %d\n", decimal);

    return 0;
}