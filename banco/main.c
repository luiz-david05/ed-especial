#include "banco.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    srand(time(NULL));

    Banco *vascoBank = criaBanco();
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
            adicionaContaAoBanco(vascoBank, novaConta, &qtdContas);
            printf("\nBem-vindo ao Vasco Bank\n");
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
            deposita(vascoBank->contas, qtdContas, numeroConta, &qtdTransacoes, valor);
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
            saca(vascoBank->contas, qtdContas, numeroConta, &qtdTransacoes, valor);
        }
        else if (opcao == 4)
        {
            printf("\nConsultar Saldo\n");
            int numeroConta;
            printf("\nNumero da conta: ");
            scanf("%d", &numeroConta);
            consultaSaldo(vascoBank->contas, qtdContas, numeroConta);
        }
        else if (opcao == 5)
        {
            printf("\nRealizar Transferencia Pix\n");
            realizaPix(vascoBank->contas, qtdContas, &qtdTransacoes);
        } else if (opcao == 6) {
            printf("\nAltera dados do titular\n");
            int numeroConta;
            printf("Informe o numero da conta: ");
            scanf("%d", &numeroConta);

            alteraDados(vascoBank->contas, qtdContas, numeroConta);
        } else if (opcao == 7) {
            printf("\nGerar extrato bancario\n");
            int numeroConta;
            printf("Informe o numero da conta: ");
            scanf("%d", &numeroConta);

            geraExtrato(vascoBank->contas, qtdTransacoes, numeroConta, qtdContas);
        }

        printf("\nTecle 1 para continuar: ");
        scanf("%d", &pause);
        exibeMenu();
        scanf("%d", &opcao);
    }

    printf("\nOPERACAO ENCERRADA.\n");

    free(vascoBank);
    return 0;
}