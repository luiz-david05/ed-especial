#include <stdio.h>

/* Um sistema de equações lineares do tipo: ax + by = c, dx + ey =f
pode ser resolvido segundo mostrado abaixo:
x = ce -bf / ae - bd, y = af - cd / ae - cd
Escreva um algoritmo que leia os coeficientes a, b, c, d, e e f, 
calcule e escreva os valores de x e y. */

int main() {
    int a, b, c, d, e, f;
    printf("Digite os valores das variaveis a, b, c, d, e, f: ");
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    int x = (c * e - b * f) / (a * e - b * d);
    int y = (a * f - c * d) / (a * e - b * d);

    printf("Resultado: x = %d, y = %d\n", x, y);

    return 0;
}