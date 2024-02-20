#include <stdio.h>

/* Calcule a quantidade de dinheiro gasta por um fumante. Dados de entrada: o número de 
anos que ele fuma, o no de cigarros fumados por dia e o preço de uma carteira (1 carteira tem 20 cigarros). */

int main() {
    int anos_fumando, n_cigarros_dia, preco_carteira;
    printf("Digite a quantidade de anos fumando: ");
    scanf("%d", &anos_fumando);
    printf("Digite a quantidade cigarros fumados por dia: ");
    scanf("%d", &n_cigarros_dia);
    printf("Digite o preco da carteira de cigarros: ");
    scanf("%d", &preco_carteira);

    int anos_dias = anos_fumando * 365;
    int qtd_cigarros_per_dia = anos_dias * n_cigarros_dia;
    int qtd_carteiras = qtd_cigarros_per_dia / 20;
    float gasto = qtd_carteiras * preco_carteira;

    printf("\nValor gasto(aproximado): %.2f\n", gasto);

    return 0;
}