#include <stdio.h>

/* Leia uma temperatura em °F, calcule e escreva a equivalente em °C. (t°C = (5 * t°F - 160) / 9). */

int main() {
    float temp_f;
    printf("Digite a temperatura em fahrenheit: ");
    scanf("%f", &temp_f);

    float temp_c = (5 * temp_f - 160) / 9;
    printf("Temperatura em celsius = %.1f\n", temp_c);

    return 0;
}