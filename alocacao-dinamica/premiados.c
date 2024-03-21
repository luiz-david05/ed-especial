#include <stdio.h>
#include <stdlib.h>
#include "premiados_utils.h"

int *premiados(int n, int *inscr, float *t1, int p1, float *t2, int p2, int *tam)
{
    int i = 0, cont = 0, *maiores_medias;
    float *media, maior_media = 0;

    media = (float *)malloc(n * sizeof(float));

    for (i = 0; i < n; i++)
    {
        media[i] = calcular_media_ponderada(t1[i], p1, t2[i], p2);
    }

    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("Media do candidato '%d' = %.1f\n", inscr[i], media[i]);
        if (media[i] > maior_media)
        {
            maior_media = media[i];
        }
    }
    printf("\nMaior media encontrada = %.1f\n", maior_media);

    for (i = 0; i < n; i++)
    {
        if (maior_media == media[i])
        {
            cont++;
        }
    }

    *tam = cont;
    // participantes com as maiores medias
    maiores_medias = (int *)malloc(cont * sizeof(int));

    int j = 0;
    for (i = 0; i < n; i++)
    {
        if (maior_media == media[i])
        {
            maiores_medias[j] = inscr[i];
            j++;
        }
    }

    return maiores_medias;
}

void pegar_numero_inscricao(int *inscr, int qtd)
{
    printf("\nInsira o numero da inscricao de cada candidato\n");
    for (int i = 0; i < qtd; i++)
    {
        printf("%d ->: ", i + 1);
        scanf("%d", &inscr[i]);
    }
}

int main(void)
{
    int i, n, *inscr, p1, p2, tam, *maiores_medias;
    float *t1, *t2;
    printf("Informe a quantidade de participantes do concurso: ");
    scanf("%d", &n);

    inscr = (int *)malloc(n * sizeof(int));
    t1 = (float *)malloc(n * sizeof(float));
    t2 = (float *)malloc(n * sizeof(float));

    pegar_numero_inscricao(inscr, n);

    printf("\nInsira a nota do primeiro teste de cada candidato\n");

    for (i = 0; i < n; i++)
    {
        printf("candidato %d ->: ", inscr[i]);
        scanf("%f", &t1[i]);
    }

    printf("\nInforme o peso da nota do primeiro teste: ");
    scanf("%d", &p1);

    printf("\nInsira a nota do segundo teste de cada candidato\n");
    for (i = 0; i < n; i++)
    {
        printf("candidato %d ->: ", i + 1);
        scanf("%f", &t2[i]);
    }

    printf("\nInforme o peso da nota do segundo teste: ");
    scanf("%d", &p2);

    maiores_medias = premiados(n, inscr, t1, p1, t2, p2, &tam);
    printf("\nQuantidade de alunos com a maior media = %d\n", tam);

    // CASO DÊ EMPATE
    if (tam > 1)
    {
        printf("\nNumero de inscricao dos participantes com as maiores medias: ");
        for (i = 0; i < tam; i++)
        {
            printf("'%d'\n", maiores_medias[i]);
        }
    } else {
        printf("Numero de inscricao do participante com a maior media: '%d'", maiores_medias[0]);
    }

    return 0;
}