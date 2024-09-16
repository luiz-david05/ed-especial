#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Exemplo de alocação estática

// Aloca memória para a pilha e inicializa o topo
#define MAX 10

struct pilha {
    int topo;
    int vet[MAX];
};

// Cria uma pilha vazia
Pilha* criaPilha() {
    // Aloca memória para a pilha
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));

    if (!p) {
        perror("Falha na alocação de memória");
        exit(EXIT_FAILURE);
    }
    p->topo = -1;
    return p;
}

void push(Pilha* p, int e) {
    if (p->topo == MAX-1) {
        printf("Pilha cheia\n");
        return;
    }
    p->vet[++p->topo] = e;
}

int pop(Pilha* p) {
    if (p->topo == -1) {
        printf("Pilha vazia\n");
        return -1;
    }
    return p->vet[p->topo--];
}

int top(Pilha* p) {
    if (p->topo == -1) {
        printf("Pilha vazia\n");
        return -1;
    }
    return p->vet[p->topo];
}

int isEmpty(Pilha* p) {
    return p->topo == -1;
}

int isFull(Pilha* p) {
    return p->topo == MAX-1;
}

void freePilha(Pilha* p) {
    if (p) {
        free(p);
        printf("Memoria da pilha liberada!");
    }
}