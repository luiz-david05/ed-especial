// #include "lista_circular.h"
// #include <stdlib.h>
// #include <stdio.h>

// Lista* criaLista(Lista* lista) {
//     return NULL;
// }

// Lista* criaNo(int valor) {
//     Lista* novoNo = (Lista*) malloc(sizeof(Lista));
//     novoNo->valor = valor;
//     novoNo->prox = NULL;

//     return novoNo;
// }

// int estaVazia(Lista* lista) {
//     if (lista == NULL) {
//         return 0;
//     }

//     return 1;
// }

// Lista* inserirInicio(Lista* lista, int valor) {
//     Lista* novoNo = criaNo(valor);

//     if (estaVazia(lista)) {
//         novoNo->prox = novoNo;
//     } else {
//         // aponta para o inico da lista
//         Lista* temp = lista;
//         // numa lista circular o ultimo nó aponta de volta para o  inicio da lista, ou seja: temp->prox == lista
//         while (temp->prox != lista) {
//             temp = temp->prox;
//         }

//         temp->prox = novoNo;
//         novoNo->prox = lista;
//     }

//     return novoNo;
// }

// void imprimirLista(Lista* lista) {
//     if (estaVazia(lista)) {
//         printf("A lista está vazia!!!\n");
//         return;
//     }
//     Lista* temp = lista;
//     do {
//         printf("%d -> ", lista->valor);
//         temp = temp->prox;
//     } while (temp != lista);
//     printf("(início)\n");
// }


#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura de um nó da lista circular
typedef struct lista {
    int valor;
    struct lista* prox;
} Lista;

// Função para criar uma nova lista vazia
Lista* criaLista() {
    return NULL;
}

// Função para criar um novo nó
Lista* criarNo(int valor) {
    Lista* novoNo = (Lista*)malloc(sizeof(Lista));
    novoNo->valor = valor;
    novoNo->prox = NULL;
    return novoNo;
}

// Função para inserir um nó no início da lista circular
Lista* inserirInicio(Lista* lista, int valor) {
    Lista* novoNo = criarNo(valor);
    
    if (lista == NULL) {
        // Lista vazia, novo nó aponta para ele mesmo
        novoNo->prox = novoNo;
    } else {
        // Encontrar o último nó da lista
        Lista* temp = lista;
        while (temp->prox != lista) {
            temp = temp->prox;
        }
        // Atualizar o ponteiro do último nó para o novo nó
        temp->prox = novoNo;
        novoNo->prox = lista;
    }
    
    return novoNo; // O novo nó é agora o início da lista
}

// Função para imprimir a lista circular
void imprimirLista(Lista* lista) {
    if (lista == NULL) return;
    Lista* temp = lista;
    do {
        printf("%d -> ", temp->valor);
        temp = temp->prox;
    } while (temp != lista);
    printf("(início)\n");
}

// Função principal para testar a criação e manipulação da lista
int main() {
    Lista* lista = criaLista(); // Inicializa uma lista vazia

    // Inserir valores na lista
    lista = inserirInicio(lista, 10);
    lista = inserirInicio(lista, 20);
    lista = inserirInicio(lista, 30);

    // Imprimir a lista
    imprimirLista(lista);

    // Liberar memória (não implementado neste exemplo)

    return 0;
}
