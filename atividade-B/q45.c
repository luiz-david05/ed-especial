#include <stdio.h>

/* Um algoritmo para gerenciar os saques de um caixa eletrônico deve possuir algum mecanismo para
decidir o numero de notas de cada valor que deve ser disponibilizado para o cliente que realizou o
saque. Um possível critério seria o da "distribuição ótima" no sentido de que as notas de menor valor
disponíveis fossem distribuídas em número mínimo possível. Por exemplo, se a maquina só dispõe de
notas de R$ 50, de R$ 10, de R$ 5 e de R$ 1, para uma quantia solicitada de R$ 87, o algoritmo deveria
indicar uma nota de R$ 50, três notas de R$ 10, uma nota de R$ 5 e duas notas de R$ 1. Escreva um
algoritmo que receba o valor da quantia solicitada e retorne a distribuição das notas de acordo com o
critério da distribuição ótima. */

int main() {
    int valor_saque;
    printf("Digite o valor do saque: ");
    scanf("%d", &valor_saque);

    int resto = valor_saque;
    int nota_100 = resto / 100;
    resto %= 100;
    int nota_50 = resto / 50;
    resto %= 50;
    int nota_10 = resto / 10;
    resto %= 10;
    int nota_5 = resto / 5;
    int nota_1 = resto %= 5;

    printf("%d Notas de 100\n", nota_100);
    printf("%d Notas de 50\n", nota_50);
    printf("%d Notas de 10\n", nota_10);
    printf("%d Notas de 5\n", nota_5);
    printf("%d Notas de 1\n", nota_1);

    return 0;
}