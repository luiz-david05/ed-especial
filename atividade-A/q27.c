#include <stdio.h>

/* Leia um número inteiro de segundos, calcule e escreva quantas horas,
 quantos minutos e quantos segundos ele corresponde. */
 
 int main() {
	int seg;
	printf("Digite o numero de segundos: ");
	scanf("%d", &seg);
	
	int resto = seg;
	int hr = resto / 3600;
	resto %= 3600;
	int min = resto / 60;
	int resto_seg = resto %= 60;
	
	printf("Resultado: %d Horas; %d Minutos e %d Segundos\n", hr, min, resto_seg);
	
	return 0;
 }
