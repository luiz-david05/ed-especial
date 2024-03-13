#include <stdio.h>

double calcularMedia(int n, int* v)
{
    int i;
    double soma = 0;

    for (i = 0; i < n; i++) {
        soma += v[i];
    }

    return soma / n;
}

double calcularVariancia(int n, int* v, double m) {
    int i;
    double soma = 0;

    for (i = 0; i < n; i++) {
        soma += (v[i] - m) * (v[i] - m);
    }

    return soma / n;
}

int main()
{
    int v[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    double media, variancia;
    // int i;

    /* leitura dos valores
    for (i = 0; i < 8; i++) {
        scanf("%lf", &v[i]);
    }
    */

    /* calculo da média
     for (i = 0; i < 8; i++) {
         media += v[i];
     }
     media /= 8;
    */

    /* calculo da variância
    for (i = 0; i < 8; i++) {
        variancia = variancia + (v[i] - media) * (v[i] - media);
    }
    variancia /= 8;
    */
    media = calcularMedia(8, v);
    variancia = calcularVariancia(8, v, media);

    printf("Media = %.1lf, Variancia = %.1lf\n", media, variancia);

    return 0;
}