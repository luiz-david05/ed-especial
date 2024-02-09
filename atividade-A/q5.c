#include <stdio.h>

int main()
{
    int n;
    printf("Digite o numero de 3 digitos: ");
    scanf("%d", &n);

    int c, d, u, resto;
    resto = n;
    c = resto / 100;
    resto %= 100;
    d = resto / 10;
    resto %= 10;
    u = resto;

    printf("SOMA DOS ELEMENTOS DE %d = (%d + %d + %d) %d", n, c, d, u, c + d + u);

    return 0;
}