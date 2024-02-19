#include <stdio.h>

/* Leia 3 números, calcule e escreva a média dos números. */

int main() {
    float n1, n2, n3;
    printf("Digite os tres(3) numeros: ");
    scanf("%f %f %f", &n1, &n2, &n3);

    float media =  (n1 + n2 + n3) / 3;

    printf("Media = %.1f\n", media);

    return 0; 
}