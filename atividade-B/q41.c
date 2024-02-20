#include <stdio.h>

/* O custo ao consumidor de um carro novo é a soma do custo de fábrica com a percentagem do
distribuidor e dos impostos (aplicados ao custo de fábrica). Supondo que a percentagem do distribuidor
seja de 28% e os impostos de 45%, escreva um algoritmo que leia o custo de fábrica de um carro e
escreva o custo ao consumidor.*/

int main() {
    // não faz sentido pedir o custo de fabricacao, achei melhor pedir o custo final do veiculo
    float custo_carro;
    printf("Digite o preco do carro: ");
    scanf("%f", &custo_carro);

    float perc_distribuidor = custo_carro * 0.28;
    float imposto_bostil = custo_carro * 0.45;
    float custo_fabricao = (custo_carro - perc_distribuidor) - imposto_bostil;

    printf("Percentual do distribuidor: %.2f\n", perc_distribuidor);
    printf("Impostos governo: %.2f\n", imposto_bostil);
    printf("Custo de fabricacao: %.2f\n", custo_fabricao);

    return 0;
}