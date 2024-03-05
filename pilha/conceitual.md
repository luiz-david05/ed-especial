# Conceito de pilha - Estrutura de dados

### O que é uma pilha?

```
Uma pilha é uma estrutura de dados que segue o princípio de LIFO (Last In, First Out), ou seja,
o último elemento a ser inserido é o primeiro a ser retirado.
```

### Operações básicas

```
push(e):  - insere um elemento no topo da pilha
pop():e - remove o elemento do topo da pilha
top():e - retorna o elemento do topo da pilha
isEmpty():b - retorna verdadeiro se a pilha estiver vazia
isFull():b - retorna verdadeiro se a pilha estiver cheia
```

### Implementação

Primeiro definir qual estrategia de implementação será utilizada:

1 - Alocação estática
    - A pilha terá um tamanho fixo
    - A pilha será um vetor de tamanho fixo
    - A pilha terá um ponteiro para o topo
    - A pilha terá um tamanho máximo
    - A pilha terá um tamanho atual
    - A pilha terá um vetor de elementos

2 - Alocação dinâmica
    - A pilha terá um tamanho variável
    - A pilha será um vetor de tamanho variável
    - A pilha terá um ponteiro para o topo
    - A pilha terá um tamanho máximo
    - A pilha terá um tamanho atual
    - A pilha terá um vetor de elementos

### Exemplo de implementação

1. Alocação estática

```c


#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int topo;
    int vet[MAX];
} Pilha;

Pilha* criaPilha() {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
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
```

2. Alocação dinâmica

```c

#include <stdio.h>
#include <stdlib.h>

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
```