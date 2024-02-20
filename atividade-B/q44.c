#include <stdio.h>

/* Sabendo que latão é constituído de 70% de cobre e 30% de zinco, escreva um algoritmo que calcule a
quantidade de cada um desses componentes para se obter certa quantidade de latão (em kg), informada
pelo usuário.*/

int main() {
    float qtd_latao;
    printf("Digite a quantidade de latao: ");
    scanf("%f", &qtd_latao);

    float cobre = qtd_latao * 0.7;
    float zinco = qtd_latao * 0.3;

    printf("Resultado: %.1f de cobre e %.1f de zinco", cobre, zinco);

    return 0;
}