#include <stdio.h>

int main() {
    float valor_dolar;
    printf("Valor em dolar: ");
    scanf("%f", &valor_dolar);
    
    float cotacao;
    printf("Valor da cotacao: ");
    scanf("%f", &cotacao);

    printf("Valor: R$%.2f", valor_dolar * cotacao);

    return 0;
}

 /* decimals in c

printf("%.nf\n",a);//specify value of n
maximum value of n is 6 also is its default value
for e.g. printf("%.2f",a); will display decimal number upto two digits after the decimal place
you can know more about displaying data as
%d: decimal value (int) 
%c: character (char) 
%s: string (const char *) 
%u: unsigned decimal value (unsigned int) 
%ld: long int (long) 
%f: float value (float or double) 
%x: decimal value in Hexadecimal format 
%o: decimal value in octal format
*/