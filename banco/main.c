#include "banco.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void liberaMemoria(Banco *banco, int qtdContas)
{
    int i;
    for (i = 0; i < qtdContas; i++)
    {
        free(banco->contas[i].titular);
    }

    free(banco->contas);
    free(banco);
}

int main()
{
    srand(time(NULL));

    Banco *agiotagens = criaBanco();
    int qtdContas = 0;
    int qtdTransacoes = 0;

    exibeMenu();
    int opcao;
    scanf("%d", &opcao);
    int pause;

    while (opcao > 0)
    {
        if (opcao == 1)
        {
            printf("\nAbrir Conta\n");
            Conta *novaConta = criaConta();
            adicionaContaAoBanco(agiotagens, novaConta, &qtdContas);
            printf("\nBem-vindo ao AGIOTAGENS & CIA\n");
        }
        else if (opcao == 2)
        {
            printf("\nDepositar\n");
            float valor;
            printf("\nValor do deposito: ");
            scanf("%f", &valor);
            int numeroConta;
            printf("\nNumero da conta: ");
            scanf("%d", &numeroConta);
            deposita(agiotagens->contas, qtdContas, numeroConta, valor, &qtdTransacoes);
        }
        else if (opcao == 3)
        {
            printf("\nSacar\n");
            float valor;
            printf("\nValor do saque: ");
            scanf("%f", &valor);
            int numeroConta;
            printf("\nNumero da conta: ");
            scanf("%d", &numeroConta);
            saca(agiotagens->contas, qtdContas, numeroConta, valor, &qtdTransacoes);
        }
        else if (opcao == 4)
        {
            printf("\nConsultar Saldo\n");
            int numeroConta;
            printf("\nNumero da conta: ");
            scanf("%d", &numeroConta);
            consultaSaldo(agiotagens->contas, qtdContas, numeroConta);
        }
        else if (opcao == 5)
        {
            printf("\nRealizar Transferencia Pix\n");

            char chaveOrigem[15];
            char chaveDestino[15];

            getchar();
            printf("Informe a chave de origem: ");
            fgets(chaveOrigem, sizeof(chaveOrigem), stdin);
            chaveOrigem[strcspn(chaveOrigem, "\n")] = '\0';

            printf("Informe a chave de destino: ");
            fgets(chaveDestino, sizeof(chaveDestino), stdin);
            chaveDestino[strcspn(chaveDestino, "\n")] = '\0';

            realizaPix(agiotagens->contas, qtdContas, &qtdTransacoes, chaveOrigem, chaveDestino);
        }
        else if (opcao == 6)
        {
            printf("\nAltera dados do titular\n");
            int numeroConta;
            printf("Informe o numero da conta: ");
            scanf("%d", &numeroConta);

            alteraDados(agiotagens->contas, qtdContas, numeroConta);
        }
        else if (opcao == 7)
        {
            printf("\nGerar extrato bancario\n");
            int numeroConta;
            printf("Informe o numero da conta: ");
            scanf("%d", &numeroConta);

            geraExtrato(agiotagens->contas, numeroConta, qtdContas, qtdTransacoes);
        }

        printf("\nTecle 1 para continuar: ");
        scanf("%d", &pause);
        exibeMenu();
        scanf("%d", &opcao);
    }

    liberaMemoria(agiotagens, qtdContas);
    printf("\nOPERACAO ENCERRADA.\n");

    return 0;
}