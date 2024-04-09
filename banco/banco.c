#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "banco.h"

Titular *criaTitular()
{
    Titular *titular = (Titular *)malloc(sizeof(Titular));

    if (titular == NULL)
    {
        printf("Falha ao alocar memoria para criar um titular\n");
        exit(EXIT_FAILURE);
    }

    getchar();
    printf("Nome do titular: ");
    fgets(titular->nome, sizeof(titular->nome), stdin);
    titular->nome[strcspn(titular->nome, "\n")] = '\0';

    printf("CPF: ");
    fgets(titular->cpf, sizeof(titular->cpf), stdin);
    titular->cpf[strcspn(titular->cpf, "\n")] = '\0';

    return titular;
}

Data criaDataAtual()
{
    time_t agora;
    struct tm *info_tempo;
    time(&agora);
    info_tempo = localtime(&agora);

    Data dataAtual;
    dataAtual.dia = info_tempo->tm_mday;
    dataAtual.mes = info_tempo->tm_mon + 1;
    dataAtual.ano = info_tempo->tm_year + 1900;

    return dataAtual;
}

Transacao *criaTransacao()
{
    Transacao *novaTransacao = (Transacao *)malloc(sizeof(Transacao));

    if (novaTransacao == NULL)
    {
        printf("Falha ao alocar memoria para criar transacao\n");
        exit(EXIT_FAILURE);
    }

    return novaTransacao;
}

void adicionaTransacao(Conta *conta, Transacao *novaTransacao, int *qtdTransacoes)
{
    conta->transacoes = (Transacao *)realloc(conta->transacoes, (*qtdTransacoes + 1) * sizeof(Transacao));

    if (conta->transacoes == NULL)
    {
        printf("\nFalha ao alocar memoria para adicionar transacao\n");
        exit(EXIT_FAILURE);
    }

    conta->transacoes[*qtdTransacoes] = *novaTransacao;
    (*qtdTransacoes)++;
}

Conta *criaConta()
{
    Conta *novaConta;
    novaConta = (Conta *)malloc(sizeof(Conta));

    if (novaConta == NULL)
    {
        printf("Falha ao alocar memoria para criar uma conta\n");
        exit(EXIT_FAILURE);
    }

    novaConta->titular = criaTitular();

    printf("\nO numero da conta foi gerado automaticamente e de forma pseudoaleatoria.\nSaldo da conta inicializado em 0.\n");
    novaConta->numero = rand() % 10000;
    novaConta->saldo = 0.0;
    novaConta->transacoes = NULL;

    printf("\nConta '%d' criada com sucesso!\n", novaConta->numero);

    return novaConta;
}

Banco *criaBanco()
{
    Banco *novoBanco;
    novoBanco = (Banco *)malloc(sizeof(Banco));

    if (novoBanco == NULL)
    {
        printf("Falha ao alocar memoria para criar banco\n");
        exit(EXIT_FAILURE);
    }

    strcpy(novoBanco->nome, "AGIOTAGENS & CIA");
    strcpy(novoBanco->endereco.logradouro, "Avenida Roberto Dinamite");
    novoBanco->endereco.numero = 10;
    strcpy(novoBanco->endereco.cep, "20921-060");
    strcpy(novoBanco->endereco.uf, "RJ");
    novoBanco->contas = NULL;

    return novoBanco;
}

int consultaContaPorIndice(Conta *contas, int numeroConta, int qtdContas)
{
    int i;
    for (i = 0; i < qtdContas; i++)
    {
        if (contas[i].numero == numeroConta)
        {
            return i;
        }
    }
    return -1;
}

void adicionaContaAoBanco(Banco *banco, Conta *novaConta, int *qtdContas)
{
    int indice = consultaContaPorIndice(banco->contas, novaConta->numero, *qtdContas);

    if (indice != -1)
    {
        printf("\nEsta conta ja existe.\n");
        return;
    }

    // realoca mais memória para o vetor de contas
    banco->contas = (Conta *)realloc(banco->contas, (*qtdContas + 1) * sizeof(Conta));

    if (banco->contas == NULL)
    {
        printf("Falha ao realocar memoria para uma nova conta\n");
        exit(EXIT_FAILURE);
    }

    banco->contas[*qtdContas] = *novaConta;
    (*qtdContas)++;
}

void deposita(Conta *contas, int qtdContas, int numeroConta, float valor, int *qtdTransacoes)
{
    int indice = consultaContaPorIndice(contas, numeroConta, qtdContas);
    int confirma;

    if (indice == -1)
    {
        printf("\nConta nao encontrada!\n");
        return;
    }

    Conta *contaProcurada = &contas[indice];
    printf("Depositar: %.2f na conta de numero '%d' ?\nTecle 1 para confirmar e 0 para cancelar: ", valor, contaProcurada->numero);
    scanf("%d", &confirma);

    if (confirma == 1)
    {
        contaProcurada->saldo += valor;
        printf("\nDeposito realizado com sucesso!\n");
        printf("Novo saldo: %.2f\n", contaProcurada->saldo);

        Transacao *novaTransacao;
        novaTransacao = criaTransacao();
        novaTransacao->data = criaDataAtual();
        strcpy(novaTransacao->tipo, "Deposito");
        novaTransacao->valor = valor;
        adicionaTransacao(contaProcurada, novaTransacao, qtdTransacoes);
    }
    else
    {
        printf("\nOperacao cancelada!\n");
    }
}

void saca(Conta *contas, int qtdContas, int numeroConta, float valor, int *qtdTransacoes)
{
    int indice = consultaContaPorIndice(contas, numeroConta, qtdContas);
    int confirma;

    if (indice == -1)
    {
        printf("\nConta nao encontrada!\n");
        return;
    }

    Conta *contaProcurada = &contas[indice];

    if (contaProcurada->saldo < valor)
    {
        printf("\nSaldo da conta insuficente!\n");
        return;
    }

    printf("Sacar: %.2f da conta de numero '%d' ?\nTecle 1 para confirmar e 0 para cancelar: ", valor, contaProcurada->numero);
    scanf("%d", &confirma);

    if (confirma == 1)
    {
        contaProcurada->saldo -= valor;
        printf("\nSaque realizado com sucesso!\n");
        printf("Novo saldo: %.2f\n", contaProcurada->saldo);

        Transacao *novaTransacao;
        novaTransacao = criaTransacao();
        novaTransacao->data = criaDataAtual();
        strcpy(novaTransacao->tipo, "Saque");
        novaTransacao->valor = -valor;
        adicionaTransacao(contaProcurada, novaTransacao, qtdTransacoes);
    }
    else
    {
        printf("\nOperacao cancelada!\n");
    }
}

void consultaSaldo(Conta *contas, int qtdContas, int numeroConta)
{
    int indice = consultaContaPorIndice(contas, numeroConta, qtdContas);

    if (indice == -1)
    {
        printf("\nConta nao encontrada!\n");
        return;
    }

    Conta *contaProcurada = &contas[indice];
    printf("\nConta de numero %d, saldo = %.2f\n", contaProcurada->numero, contaProcurada->saldo);
}

int consultaChavePix(Conta *contas, int qtdContas, char *chave)
{
    int i;
    for (i = 0; i < qtdContas; i++)
    {
        if (strcmp(contas[i].titular->cpf, chave) == 0)
        {
            return i;
        }
    }
    return -1;
}

void realizaPix(Conta *contas, int qtdContas, int *qtdTransacoes, char *chaveOrigem, char *chaveDestino)
{
    printf("\nChave de origem: %s\n", chaveOrigem);
    printf("Chave de destino: %s\n", chaveDestino);

    int indiceOrigem = consultaChavePix(contas, qtdContas, chaveOrigem);
    int indiceDestino = consultaChavePix(contas, qtdContas, chaveDestino);

    if (indiceOrigem == -1)
    {
        printf("\nChave pix de origem '%s' nao encontrada\n", chaveOrigem);
        return;
    }

    if (indiceDestino == -1)
    {
        printf("\nChave pix de destino '%s' nao encontrada\n", chaveDestino);
        return;
    }

    printf("\nChave de origem encontrada na conta de nome: '%s'\n", contas[indiceOrigem].titular->nome);
    printf("Chave de destino encontrada na conta de nome: '%s'\n", contas[indiceDestino].titular->nome);


    Conta *contaOrigem = &contas[indiceOrigem];
    Conta *contaDestino = &contas[indiceDestino];

    int confirma;
    float valor;
    printf("\nValor: ");
    scanf("%f", &valor);

    if (contaOrigem->saldo < valor)
    {
        printf("\nSaldo da conta insuficente!\n");
        return;
    }

    printf("Enviar pix de: %.2f para %s chave '%s' ?\nTecle 1 para confirmar e 0 para cancelar: ", valor, contaDestino->titular->nome, contaDestino->titular->cpf);
    scanf("%d", &confirma);

    if (confirma == 1)
    {
        contaOrigem->saldo -= valor;
        contaDestino->saldo += valor;
        printf("\nPix enviado com sucesso!\n");
        printf("Novo saldo conta de origem: %.2f\n", contaOrigem->saldo);
        printf("Novo saldo conta de destino: %.2f\n", contaDestino->saldo);

        Transacao *transacaoOrigem = criaTransacao();
        transacaoOrigem->data = criaDataAtual();
        strcpy(transacaoOrigem->tipo, "PIX Enviado");
        transacaoOrigem->valor = -valor;
        adicionaTransacao(contaOrigem, transacaoOrigem, qtdTransacoes);

        Transacao *transacaoDestino = criaTransacao();
        transacaoDestino->data = criaDataAtual();
        strcpy(transacaoDestino->tipo, "PIX Recebido");
        transacaoDestino->valor = valor;
        adicionaTransacao(contaDestino, transacaoDestino, qtdTransacoes);
    }
    else
    {
        printf("\nOperacao cancelada!\n");
        return;
    }
}

void alteraDados(Conta *contas, int qtdContas, int numeroConta)
{
    int indice = consultaContaPorIndice(contas, numeroConta, qtdContas);

    if (indice == -1)
    {
        printf("\nConta nao encontrada!\n");
        return;
    }

    Conta *contaProcurada = &contas[indice];

    int reply;
    printf("\nQuais dados alterar: 1 - Nome e 2 - renda\n->: ");
    scanf("%d", &reply);

    if (reply == 1)
    {
        printf("Informe o novo nome: ");
        getchar();
        char novoNome[120];
        fgets(novoNome, sizeof(novoNome), stdin);
        novoNome[strcspn(novoNome, "\n")] = '\0';

        strcpy(contaProcurada->titular->nome, novoNome);
    }
    else if (reply == 2)
    {
        float novaRenda;
        printf("Informe a nova renda: ");
        scanf("%f", &novaRenda);

        contaProcurada->titular->renda = novaRenda;
    }
    else
    {
        printf("\nAlternativa invalida!\n");
        return;
    }
}

void geraExtrato(Conta *contas, int numeroConta, int qtdContas, int qtdTransacoes)
{
    int indice = consultaContaPorIndice(contas, numeroConta, qtdContas);

    if (indice == -1)
    {
        printf("\nConta nao encontrada\n");
        return;
    }

    Conta *contaProcurada = &contas[indice];

    printf("\nExtrato da conta: %d\n", numeroConta);
    printf("----------------------------------------\n");

    int i;
    for (i = 0; i < qtdTransacoes; i++)
    {
        Transacao transacao = contaProcurada->transacoes[i];

        // evitar transacoes com dados invalidos
        if (transacao.data.dia >= 1 && transacao.data.dia <= 31)
        {
            printf("Data da transacao: %02d/%02d/%d\n", contaProcurada->transacoes[i].data.dia, contaProcurada->transacoes[i].data.mes, contaProcurada->transacoes[i].data.ano);
            printf("Tipo de transacao: %s\n", contaProcurada->transacoes[i].tipo);
            printf("Valor: %.2f\n", contaProcurada->transacoes[i].valor);
            printf("----------------------------------------\n");
        }
    }
}

void exibeMenu()
{
    char menu[] = "\n\t\t\t>>>> AGIOTAGENS & CIA <<<<\n1 - Abrir Conta\n2 - Depositar\n3 - Sacar\n4 - Consultar saldo\n5 - Realizar transferencia pix\n6 - Alterar dados do titular\n7 - Gera extrato bancario\n0 - sair\n\ndigite aqui ->: ";
    printf("%s", menu);
}