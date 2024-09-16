#include <stdio.h>
#include "pilha.h"

#define MAX 5


int main() {
    Pilha* p = criaPilha(MAX);

    int elemento = MAX;
    while (elemento >= 1) {
        push(p, elemento);
        printf("Empilhei %d\n", elemento);
        elemento -= 1;
    }
    
    while (!isEmpty(p)) {
        int elemento = pop(p);
        printf("Desempilhei %d\n", elemento);
    }

    int e = pop(p);

    freePilha(p);

    return 0;
}