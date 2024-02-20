#include <stdio.h>
#include <math.h>

/* Escreva um algoritmo que, tendo como dados de entrada 2 pontos quaisquer no plano, ponto1 (x1,y1) e
ponto2 (x2,y2), escreva a distância entre eles, conforme fórmula abaixo. 
    d = raiz (x2 - x1)**2 + (y2 - y1)**2
*/

int main() {
    int x1, x2, y1, y2;
    printf("Digite as coordenadas do ponto x1 e y1: ");
    scanf("%d %d", &x1, &y1);
    printf("Digite as coordenadas do ponto x2 e y2: ");
    scanf("%d %d", &x2, &y2);

    int d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); 

    printf("Resultado: distancia = %d\n", d);

    return 0;
}