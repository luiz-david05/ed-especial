#include <stdio.h>

int main() {
    // notas é um vetor
    double notas, media;
    int i, n;

    printf("Digite a quantidade de notas: ");
    scanf("%d", &n);

    printf("Digite as notas\n");
    for (i = 0; i < n; i++) {
        printf("->: ");
        scanf("%lf", &notas);
        media += notas;
    }

    media /= n;

    printf("Media = %.1lf\n", media);

    return 0;
}