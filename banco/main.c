#include "banco.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void liberaMemoria(Conta *contas, int qtdContas) {
    int i;
    for (i = 0; i < qtdContas; i++) {
        free(contas[i].titular);
        free(contas[i].transacoes);
    }
}

void salvaDados(Banco *banco, int qtdContas) {
    salvaContasArquivo(banco->contas, qtdContas);
}

void criaNovoArquivoContas() {
    FILE *arquivo = fopen("contas.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o novo arquivo de contas.\n");
        exit(EXIT_FAILURE);
    }
    printf("Novo arquivo de contas criado.\n");
    fclose(arquivo);
}

void listaContas(Conta *contas, int qtdContas) {
    int i;
    for (i = 0; i < qtdContas; i++) {
        printf("Conta [%d]\n", i+1);
        printf("Conta: %d; Nome: %s; CPF: %s; Saldo: %.2f\n", contas[i].numero, contas[i].titular->nome, contas[i].titular->cpf, contas[i].saldo);
    }
}

void verificaArquivoContas() {
    FILE *arquivo = fopen("contas.txt", "r");
    if (arquivo == NULL) {
        printf("O arquivo de contas não existe.\n");
        char resposta;
        printf("Deseja criar um novo arquivo de contas? (s/n): ");
        scanf(" %c", &resposta);
        if (resposta == 's' || resposta == 'S') {
            criaNovoArquivoContas();
        } else {
            exit(EXIT_SUCCESS);
        }
    }
    fclose(arquivo);
}

int main()
{
    srand(time(NULL));

    Banco *agiotagens = criaBanco();
    int qtdContas = 0;

    verificaArquivoContas();
    carregaContasArquivo(agiotagens, &qtdContas);

    printf("\nQuantidade de contas no banco: %d\n", qtdContas);
    listaContas(agiotagens->contas, qtdContas);
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
            deposita(agiotagens->contas, qtdContas, numeroConta, valor);
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
            saca(agiotagens->contas, qtdContas, numeroConta, valor);
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
            realizaPix(agiotagens->contas, qtdContas);
        } else if (opcao == 6) {
            printf("\nAltera dados do titular\n");
            int numeroConta;
            printf("Informe o numero da conta: ");
            scanf("%d", &numeroConta);

            alteraDados(agiotagens->contas, qtdContas, numeroConta);
        } // else if (opcao == 7) {
        //     printf("\nGerar extrato bancario\n");
        //     int numeroConta;
        //     printf("Informe o numero da conta: ");
        //     scanf("%d", &numeroConta);

        //     geraExtrato(agiotagens->contas, qtdTransacoes, numeroConta, qtdContas);
        // }

        printf("\nTecle 1 para continuar: ");
        scanf("%d", &pause);
        exibeMenu();
        scanf("%d", &opcao);
        // atexit((void(*)(void))salvaDados);
    }

    salvaDados(agiotagens, qtdContas);
    printf("\nOPERACAO ENCERRADA.\n");

    free(agiotagens);
    return 0;
}