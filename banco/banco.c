#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char logradouro[250];
    int numero;
    char cep[9];
    char uf[3];
} Endereco;

typedef struct
{
    Endereco endereco;
    char nome[120];
    char cpf[15];
    float renda;
} Titular;

typedef struct {
    char data[11];
    char tipo[7];
    float valor;
}Transacoes;

typedef struct
{
    Titular *titular;
    int numero;
    float saldo;
    Transacoes transacoes;
} Conta;

typedef struct
{
    Endereco endereco;
    Conta *contas;
    char nome[120];
} Banco;

Titular *criaTitular()
{
    Titular *titular;
    titular = (Titular *)malloc(sizeof(Titular));

    if (titular == NULL)
    {
        printf("Falha ao alocar memoria\n");
        exit(EXIT_FAILURE);
    }

    strcpy(titular->nome, "Luiz David Silva");
    strcpy(titular->cpf, "123.456.789-00");

    // printf("Informe o nome do titular: ");
    // fgets(titular->nome, sizeof(titular->nome), stdin);
    // titular->nome[strcspn(titular->nome, "\n")] = '\0';

    // printf("Informe o cpf do titular(no formato ***.***.***-**): ");
    // fgets(titular->cpf, sizeof(titular->cpf), stdin);
    // titular->cpf[strcspn(titular->cpf, "\n")] = '\0';

    // printf("\nInforme a renda mensal do titular: ");
    // scanf("%d", &titular->renda);

    // printf("Preencher os campos do endereco do titular.\n");
    // printf("Logradouro: ");
    // fgets(titular->endereco.logradouro, sizeof(titular->endereco.logradouro), stdin);
    // titular->endereco.logradouro[strcspn(titular->endereco.logradouro, "\n")] = '\0';

    // printf("Numero: ");
    // scanf("%d", &titular->endereco.numero);
    // printf("\nCEP (no formato: *****-***): ");
    // fgets(titular->endereco.cep, sizeof(titular->endereco.cep), stdin);
    // titular->endereco.cep[strcspn(titular->endereco.cep, "\n")] = '\0';

    // printf("\nUF: ");
    // fgets(titular->endereco.uf, sizeof(titular->endereco.uf), stdin);
    // titular->endereco.uf[strcspn(titular->endereco.uf, "\n")] = '\0';

    return titular;
}

Conta *criaConta()
{
    Conta *novaConta;
    novaConta = (Conta *)malloc(sizeof(Conta));

    if (novaConta == NULL)
    {
        printf("Falha ao alocar memoria\n");
        exit(EXIT_FAILURE);
    }

    novaConta->titular = criaTitular();

    printf("\nO numero da conta foi gerado automaticamente e de forma pseudoaleatoria.\nSaldo da conta inicializado em 0.\n");
    novaConta->numero = rand() % 10000;
    novaConta->saldo = 0.0;

    printf("\nConta '%d' criada com sucesso!\n", novaConta->numero);

    return novaConta;
}

Banco *CriaBanco()
{
    Banco *novoBanco;
    novoBanco = (Banco *)malloc(sizeof(Banco));

    if (novoBanco == NULL)
    {
        printf("Falha ao alocar memoria\n");
        exit(EXIT_FAILURE);
    }

    strcpy(novoBanco->nome, "Vasco Bank");
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

// void consultaConta(Conta *contas, int numeroConta, int qtdContas) {
//     int indice = consultaContaPorIndice(contas, numeroConta, qtdContas);

//     if (indice != -1) {
//         printf("\nConta encontrada!\n");
//         printf("\nNumero da conta: '%d' - CPF do titular: %s\n", contas[indice].numero, contas[indice].titular->cpf);
//     } else {
//         printf("\nConta nao encontrada\n");
//     }
// }

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
        printf("Falha ao realocar memoria\n");
        exit(EXIT_FAILURE);
    }

    banco->contas[*qtdContas] = *novaConta;
    (*qtdContas)++;
}

void listaContasBanco(Banco *banco, int qtdContas)
{
    if (qtdContas > 0)
    {
        int i;
        printf("\n\t\tContas do banco\n\n");
        for (i = 0; i < qtdContas; i++)
        {
            printf("Numero da conta: '%d' - CPF do titular: %s\n", banco->contas[i].numero, banco->contas[i].titular->cpf);
            printf("---------------------------------------------------------\n");
        }
    }
    else
    {
        printf("\nSem contas para exibir.\n");
    }
}

void deposita(Conta *contas, int qtdContas, int numeroConta) {
    int indice = consultaContaPorIndice(contas, numeroConta, qtdContas);
    int confirma;

    if (indice == -1) {
        printf("\nConta nao encontrada!\n");
        return;
    }

    Conta *contaProcurada = &contas[indice];
    float valor;
    printf("\nValor do deposito: ");
    scanf("%f", &valor);
    printf("Depositar: %.2f na conta de numero '%d' ?\nTecle 1 para confirmar e 0 para cancelar: ", valor, contaProcurada->numero);
    scanf("%d", &confirma);

    if (confirma == 1) {
        contaProcurada->saldo += valor;
        printf("\nDeposito realizado com sucesso!\n");
        printf("Novo saldo: %.2f\n", contaProcurada->saldo);
    } else {
        printf("\nOperacao cancelada!\n");
    }
}

void saca(Conta *contas, int qtdContas, int numeroConta) {
    int indice = consultaContaPorIndice(contas, numeroConta, qtdContas);
    int confirma;

    if (indice == -1) {
        printf("\nConta nao encontrada!\n");
        return;
    }

    Conta *contaProcurada = &contas[indice];
    float valor;
    printf("\nValor do saque: ");
    scanf("%f", &valor);
        
    if (contaProcurada->saldo < valor) {
        printf("\nSaldo da conta insuficente!\n");
        return;
    }

    printf("Sacar: %.2f da conta de numero '%d' ?\nTecle 1 para confirmar e 0 para cancelar: ", valor, contaProcurada->numero);
    scanf("%d", &confirma);

    if (confirma == 1) {
        contaProcurada->saldo -= valor;
        printf("\nSaque realizado com sucesso!\n");
        printf("Novo saldo: %.2f\n", contaProcurada->saldo);
    } else {
        printf("\nOperacao cancelada!\n");
    }
}

void consultaSaldo(Conta *contas, int qtdContas, int numeroConta) {
    int indice = consultaContaPorIndice(contas, numeroConta, qtdContas);

    if (indice == -1) {
        printf("\nConta nao encontrada!\n");
        return;
    }

    Conta *contaProcurada = &contas[indice];
    printf("\nConta de numero %d, saldo = %.2f\n", contaProcurada->numero, contaProcurada->saldo);
}

void exibeMenu()
{
    char menu[] = "\n\t\t\t>>>> VASCO BANK <<<<\n1 - Abrir Conta\n2 - Depositar\n3 - Sacar\n4 - Consultar saldo\n5 - Realizar transferencia pix\n6 - Alterar dados\n7 - Gerar extrato Bancario\n0 - sair\n\ndigite aqui ->: ";
    printf("%s", menu);
}

int main()
{
    srand(time(NULL));

    Banco *vascoBank = CriaBanco();
    int qtdContas = 0;

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
            int numeroConta;
            printf("\nNumero da conta: ");
            scanf("%d", &numeroConta);
            deposita(vascoBank->contas, qtdContas, numeroConta);
        } else if (opcao == 3) {
            printf("\nSacar\n");
            int numeroConta;
            printf("\nNumero da conta: ");
            scanf("%d", &numeroConta);
            saca(vascoBank->contas, qtdContas, numeroConta);
        } else if (opcao == 4) {
            printf("\nConsultar Saldo\n");
            int numeroConta;
            printf("\nNumero da conta: ");
            scanf("%d", &numeroConta);
            consultaSaldo(vascoBank->contas, qtdContas, numeroConta);
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