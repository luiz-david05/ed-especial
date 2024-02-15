#include <stdio.h>
#include <math.h>

/* Leia o valor do raio de uma esfera, calcule e escreva seu volume.
 (v = (4 * p * r3) / 3) (p = 3,14)*/

 int main() {
    double pi = 3.14;
    float raio;
    printf("Digite o valor do raio: ");
    scanf("%f", &raio);

    float volume = (4 * pi * (pow(raio, 3))) / 3;
    printf("Volume = %.2f", volume);

    return 0;
 }