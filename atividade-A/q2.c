#include <stdio.h>

/* Leia um valor em horas e um valor em minutos, calcule e escreva o equivalente em minutos. */

int main() {
    int hr, min;
    printf("Digite a hora: ");
    scanf("%d", &hr);
    printf("Digite os minutos: ");
    scanf("%d", &min);

    printf("Tempo somente em minutos: %d\n", hr * 60 + min);

    return 0;
}