#include <stdio.h>

/* Leia 2 números inteiros, calcule e escreva o quociente e o resto da divisão do 1° pelo 2°. */

int main() {
    int n1, n2;
    printf("Digite os dois(2) numeros: ");
    scanf("%d %d", &n1, &n2);

    int quociente = n1 / n2;
    int resto = n1 % n2;

    printf("Quociente: %d\n", quociente);
    printf("Resto: %d\n", resto);

    return 0;
}