#pragma once
#define PILHA_H

// pop, push, is_empty, is_full, top, free

typedef struct pilha Pilha;

Pilha* criaPilha();
void push(Pilha* p, int e);
int pop(Pilha* p);
int top(Pilha* p);
int isEmpty(Pilha* p);
int isFull(Pilha* p);
void freePilha(Pilha* p);