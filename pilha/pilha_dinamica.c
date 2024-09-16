#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Exemplo de alocação dinâmica

// Aloca memória para a pilha e inicializa o topo
struct pilha {
    int topo;
    int *vet;
    int max;
};

Pilha* criaPilha(int max) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if (p == NULL) {
        fprintf(stderr, "Erro na alocacao de memoria para a pilha.\n");
        exit(EXIT_FAILURE);
    }
    p->topo = -1;
    p->max = max;
    p->vet = (int*) malloc(max * sizeof(int));
    if (p->vet == NULL) {
        free(p);
        fprintf(stderr, "Erro na alocacao de memoria para os elementos da pilha.\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

void push(Pilha* p, int e) {
    if (p->topo == p->max-1) {
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
    return p->topo == p->max-1;
}

void freePilha(Pilha* p) {
    if (p) {
        free(p->vet);
        free(p);
        printf("Memoria da pilha liberada!");
    }
}