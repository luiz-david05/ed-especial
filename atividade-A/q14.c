#include <stdio.h>

/* Leia 3 notas de um aluno e o peso de cada nota, calcule e escreva a média ponderada. */

int main() {
    float n1, n2, n3;
    int p1, p2, p3;
    printf("Digite as notas: ");
    scanf("%f %f %f", &n1, &n2, &n3);
    printf("Digite os respectivos pesos das notas: ");
    scanf("%d %d %d", &p1, &p2, &p3);

    float media_p = (n1 * p1 + n2 * p2 + n3 * p3) / (p1 + p2 + p3);
    printf("media ponderada = %.1f", media_p);

    return 0;
}