#include <stdio.h>

void operacoes(int a, int b, int *soma, int *diff, int *mult, double *div) {
    *soma = a + b;
    *diff = a - b;
    *mult = a * b;
    *div = (double) a / b;
}

int main() {
    int n1, n2, soma, diff, mult;
    double div;
    printf("Digite os 2(dois) valores: ");
    scanf("%d %d", &n1, &n2);

    operacoes(n1, n2, &soma, &diff, &mult, &div);
    printf("Soma = %d, Subtracao = %d, Multiplicao = %d, Divisao = %.1lf\n", soma, diff, mult, div);

    return 0;
}
 