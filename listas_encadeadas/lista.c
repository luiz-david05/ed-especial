#include "lista.h"
#include <stdlib.h>
#include "stdio.h"

Lista* criaLista()
{
    return NULL;
}

Lista* inserirInicio(Lista* lista, int valor)
{
    Lista* novaLista = (Lista*)malloc(sizeof(Lista));

    novaLista->valor = valor;
    novaLista->prox = lista;

    return novaLista;
}

int estaVazia(Lista* lista)
{
    if (lista == NULL) {
        return 1;
    }

    return 0;
}

Lista* inserirFinal(Lista* lista, int valor)
{
    if (estaVazia(lista))
    {
        return inserirInicio(lista, valor);
    }

    Lista* novaLista = (Lista*)malloc(sizeof(Lista));
    novaLista->valor = valor;

    Lista* ultimo = lista;
    while (ultimo->prox != NULL)
    {
        ultimo = ultimo->prox;
    }

    ultimo->prox = novaLista;
    novaLista->prox = NULL;

    return lista;
}

Lista* inserirPos(Lista* lista, int valor, int pos) {
    if (pos < 0) {
        printf("Posição inválida!!!\n");
        return lista;
    }

    if (pos == 0) {
        return inserirInicio(lista, valor);
    }

    Lista* novaLista = (Lista*)malloc(sizeof(Lista));
    novaLista->valor = valor;

    Lista* atual = lista;
    int i;

    for (i = 0; atual != NULL && i < pos - 1; i++) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        // se a pos é maior que o tam da lista, inseri no final
        free(novaLista);
        return inserirFinal(lista, valor);
    }

    novaLista->prox = atual->prox;
    atual->prox = novaLista;

    return lista;
}

void listarElementos(Lista* lista)
{
    printf(">> ITENS DA LISTA <<\n");
    if (estaVazia(lista))
    {
        printf("!!! Lista Vazia !!!\n\n");
        return;
    }
    for (Lista *atual = lista; atual != NULL; atual = atual->prox)
    {
        printf("> %d\n", atual->valor);
    }
    printf("NULL\n");
    printf("--------------------\n");
}

// Lista *removerInicio(Lista *l)
// {
//     if (estaVazia(l))
//     {
//         printf("Lista vazia!\n");
//         return l;
//     }

//     Lista *proximoElemento = l->prox;
//     free(l);

//     return proximoElemento;
// }

// // void removeFinal(Lista* l) {
// //     if (estaVazia(l)) {
// //         printf("Lista vazia!\n");
// //         return;
// //     }

// //     Lista* ultimoElemento = l;
// //     Lista* penultimoElemento = NULL;

// //     // Traverse to the last element
// //     while (ultimoElemento->prox != NULL) {
// //         penultimoElemento = ultimoElemento;
// //         ultimoElemento = ultimoElemento->prox;
// //     }

// //     // If there was only one element in the list
// //     if (penultimoElemento == NULL) {
// //         free(ultimoElemento);
// //         l = NULL; // Set the list to NULL since it's now empty
// //     } else {
// //         free(ultimoElemento);
// //         penultimoElemento->prox = NULL; // Remove the last element
// //     }
// // }
