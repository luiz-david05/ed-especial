#include <stdio.h>
#include <stdlib.h>

double calcularMedia(int n, int *v)
{
    int i;
    double soma = 0;

    for (i = 0; i < n; i++) {
        soma += v[i];
    }

    return soma / n;
}

double calcularVariancia(int n, int *v, double m) {
    int i;
    double soma = 0;

    for (i = 0; i < n; i++) {
        soma += (v[i] - m) * (v[i] - m);
    }

    return soma / n;
}

int main()
{
    int *v, i, n;
    double media, variancia;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    v = (int *) malloc(n * sizeof(int));

    if (v == NULL) {
        printf("Memoria insuficiente.\n");

        return 1;
    }

    printf("Digite os elementos do vetor de tamanho %d\n", n);
    for (i = 0; i < n; i++) {
        printf("->: ");
        scanf("%d", &v[i]);
    }

    media = calcularMedia(n, v);
    variancia = calcularVariancia(n, v, media);

    printf("Media = %.1lf, Variancia = %.1lf\n", media, variancia);
    free(v);

    return 0;
}