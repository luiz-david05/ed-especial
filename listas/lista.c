#include "lista.h"
#include <stdlib.h>
#include "stdio.h"

Lista* novaLista() {
    return NULL;
}

Lista* inserirInicio(Lista* l, int valor) {
    Lista* novaLista = (Lista *)malloc(sizeof(Lista));

    novaLista->valor = valor;
    novaLista->prox = l; // = NULL

    return novaLista;
}

int estaVazia(Lista* l) {
   if (l == NULL) return 1;

   return 0; 
}

Lista* inserirFinal(Lista* l, int valor) {
    if (estaVazia(l)) {
        return inserirInicio(l, valor);
    }

    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->valor = valor;

    Lista* ultimo = l;
    while (ultimo->prox != NULL) {
        ultimo = ultimo->prox;
    }

    ultimo->prox = novo;
    novo->prox = NULL;

    return l;
}

Lista* removerInicio(Lista* l) {
    if (estaVazia(l)) {
        printf("Lista vazia!\n");
        return l;
    }

    Lista* proximoElemento = l->prox;
    free(l);

    return proximoElemento;
}

// void removeFinal(Lista* l) {
//     if (estaVazia(l)) {
//         printf("Lista vazia!\n");
//         return;
//     }

//     Lista* ultimoElemento = l;
//     Lista* penultimoElemento = NULL;

//     // Traverse to the last element
//     while (ultimoElemento->prox != NULL) {
//         penultimoElemento = ultimoElemento;
//         ultimoElemento = ultimoElemento->prox;
//     }

//     // If there was only one element in the list
//     if (penultimoElemento == NULL) {
//         free(ultimoElemento);
//         l = NULL; // Set the list to NULL since it's now empty
//     } else {
//         free(ultimoElemento);
//         penultimoElemento->prox = NULL; // Remove the last element
//     }
// }

void listarElementos(Lista* l) {
    printf(">> ITENS DA LISTA <<\n");
    if (estaVazia(l)) {
        printf("!!! Lista Vazia !!!\n\n");
        return;
    }
    for (Lista* p = l; p != NULL; p = p->prox) {
        printf("> %d\n", p->valor);
    }
    printf("--------------------\n");
}