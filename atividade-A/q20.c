#include <stdio.h>

/* Leia uma temperatura em °C, calcule e escreva a equivalente em °F. 
(t°F = (9 * t°C + 160) / 5) */

int main() {
    float temp_c;
    printf("Digite a temperatura em celsius: ");
    scanf("%f", &temp_c);

    float temp_f = (9 * temp_c + 160) / 5;
    printf("Temperatura em fahrenheint: %.1f\n", temp_f);

    return 0;
}