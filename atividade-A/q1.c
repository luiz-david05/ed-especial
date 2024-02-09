#include <stdio.h>

// compilar: gcc nome_do_arquivo.c -o nome_do_executavel
// executar: ./nome_do_executavel | ./nome_do_executavel.exe

int main() {
    float n;
    printf("Velocidade em m/s: ");
    scanf("%f", &n);

    printf("Velocidade em km/h: %.2f\n", n * 3.6);
    
    return 0;
}