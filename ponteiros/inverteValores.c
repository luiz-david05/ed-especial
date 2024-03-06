#include <stdio.h>

// parametros por referência
void inverteValores(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a, b;
    printf("Digite os dois(2) valores: ");
    // recebe os endereco de memória das variáveis
    scanf("%d %d", &a, &b);

    inverteValores(&a, &b);

    printf("a = %d, b = %d\n", a, b);

    return 0;
}