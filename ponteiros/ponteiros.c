#include <stdio.h>

int main() {
    int a = 10;
    // atribuindo o endereço de 'a' para o ponteiro 'p'
    int *p = &a;

    // mudando o conteudo de 'a' através do ponteiro
    *p = 20;
    printf("%d\n", a);

    return 0;
}

// Output: 20