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

typedef struct
{
    Titular *titular;
    int numero;
    float saldo;
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

    // printf("Digite o nome do titular: ");
    // fgets(titular->nome, sizeof(titular->nome), stdin); // Use fgets para ler strings
    // titular->nome[strcspn(titular->nome, "\n")] = '\0'; // Remova o caractere de nova linha

    // printf("Digite o cpf do titular(no formato ***.***.***-**): ");
    // fgets(titular->cpf, sizeof(titular->cpf), stdin);
    // titular->cpf[strcspn(titular->cpf, "\n")] = '\0';

    // printf("Preencher os campos do endereco do titular.\n");
    // printf("Logradouro: ");
    // fgets(titular->endereco.logradouro, sizeof(titular->endereco.logradouro), stdin);
    // titular->endereco.logradouro[strcspn(titular->endereco.logradouro, "\n")] = '\0';

    // printf("Numero: ");
    // scanf("%d", &titular->endereco.numero);
    // printf("\nCEP (no formato: **.***-***): ");
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

    novoBanco->contas = NULL;

    return novoBanco;
}

void adicionaContaAoBanco(Banco *banco, Conta *novaConta, int *qtdContas)
{
    int indice = consultaContaPorIndice(banco->contas, novaConta->numero, qtdContas);

    if (indice != -1) {

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

void listaContasBanco(Banco *banco, int qtdContas)
{
    if (qtdContas > 0)
    {
        int i;
        printf("\n\t\tContas do banco\n");
        for (i = 0; i < qtdContas; i++)
        {
            printf("Numero da conta: '%d' - CPF do titular: %s\n", banco->contas->numero, banco->contas->titular->cpf);
            printf("---------------------------------------------------------\n");
        }
    } else {
        printf("\nSem contas para exibir.\n");
    }
}

int main()
{
    srand(time(NULL));

    Banco *meuBanco = CriaBanco();
    int qtdContas = 0;

    Conta *novaConta = criaConta();
    adicionaContaAoBanco(meuBanco, novaConta, &qtdContas);

    listaContasBanco(meuBanco, qtdContas);

    free(meuBanco);
    free(novaConta);

    return 0;
}