#pragma once
#define BANCO

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
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    Data data;
    char tipo[7];
    float valor;
} Transacao;

typedef struct
{
    Titular *titular;
    int numero;
    float saldo;
    Transacao *transacoes;
} Conta;

typedef struct
{
    Endereco endereco;
    Conta *contas;
    char nome[120];
} Banco;

Titular *criaTitular();
Data criaDataAtual();
Transacao *criaTransacao();
Conta *criaConta();
Banco *criaBanco();
int consultaContaPorIndice(Conta *contas, int numeroConta, int qtdContas);
void adicionaContaAoBanco(Banco *banco, Conta *novaConta, int *qtdContas);
void adicionaTransacao(Conta *conta, Transacao *novaTransacao, int *qtdTransacoes);
void deposita(Conta *contas, int qtdContas, int numeroConta, int *qtdTransacoes, float valor);
void saca(Conta *contas, int qtdContas, int numeroConta, int *qtdTransacoes, float valor);
void consultaSaldo(Conta *contas, int qtdContas, int numeroConta);
int consultaChavePix(Conta *contas, int qtdContas, char *chave);
void realizaPix(Conta *contas, int qtdContas, int *qtdTransacoes);
void alteraDados(Conta *contas, int qtdContas, int numeroConta);
void geraExtrato(Conta *contas, int qtdTransacoes, int numeroConta, int qtdContas);
void exibeMenu();
