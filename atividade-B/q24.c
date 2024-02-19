#include <stdio.h>

/* Leia um valor em m, calcule e escreva o equivalente em cm. */

int main() {
	float m;
	printf("Digite o valor em metros: ");
	scanf("%f", &m);
	
	float cm = m * 100;
	printf("Valor em centimetros = %.1f\n", cm);
	
	return 0;
}
