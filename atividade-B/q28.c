#include <stdio.h>

/* Leia um n�mero inteiro de horas, calcule e escreva quantas semanas, quantos dias e 
quantas horas ele corresponde.*/

int main() {
	int hr;
	printf("Digite o numero de horas: ");
	scanf("%d", &hr);
	
	int resto = hr;
	int semanas = resto / (24 * 7);
	int resto_hr = resto %= 24 * 7;
	
	printf("Resultado: %d Semanas e %d horas\n", semanas, resto_hr);
	
	return 0;
}