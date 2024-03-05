#include <stdio.h>
#include <stdlib.h>

// Exemplo de alocação dinâmica

// Aloca memória para a pilha e inicializa o topo
typedef struct {
    int topo;
    int* vet;
    int max;
} Pilha;

Pilha* criaPilha(int max) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = -1;
    p->max = max;
    p->vet = (int*) malloc(max * sizeof(int));
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

int main() {
    Pilha* p = criaPilha(5);

    int elemento = 5;
    while (elemento >= 1) {
        push(p, elemento);
        printf("Empilhei %d\n", elemento);
        elemento -= 1;
    }
    
    while (!isEmpty(p)) {
        int elemento = pop(p);
        printf("Desempilhei %d\n", elemento);
    }
    return 0;
}