#pragma once
#define LISTA_CIRCULAR

// struct lista refere-se à estrutura do nó, e Lista é o tipo definido para esse nó.
typedef struct lista {
    int valor;
    struct lista* prox;
} Lista;

Lista* criaLista();
Lista* criaNo(int valor);
int estaVazia(Lista* lista);
Lista* inserirInicio(Lista* lista, int valor);
void imprimirLista(Lista* lista);