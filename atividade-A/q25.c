#include <stdio.h>

/*  Leia um número inteiro de metros, calcule e escreva quantos Km
 e quantos metros ele corresponde.*/
 
 int main() {
	int m;
	printf("Digite o valor em metros: ");
	scanf("%d", &m);
	
	int km = m / 1000;
	printf("Valor em metros = %d", km);
	
	return 0;
 }
