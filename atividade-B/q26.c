#include <stdio.h>

/* Leia um número inteiro de dias, calcule e
 escreva quantas semanas e quantos dias ele corresponde.*/
 
 int main() {
	int dias;
	printf("Digite o numero de dias: ");
	scanf("%d", &dias);
 	
	int resto = dias;
	int semanas = resto / 7;
	int resto_dias = resto %= 7;
	
	printf("Resultado: %d semanas e %d dias", semanas, resto_dias);
	
	return 0;
 }
