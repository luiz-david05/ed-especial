#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct ponto {
    int x;
    int y;
} Ponto;

typedef struct circulo {
    Ponto p;
    int raio;
} Circulo;

void mostraCirculo(Circulo *c) {
    printf("Valores dos pontos x e y do circulo: x = %d e y = %d\n", c->p.x, c->p.y);
    printf("Valor do raio do circulo: %d\n", c->raio);
}

void atribuiAleatorio(Circulo *c) {
    c->p.x = rand() % 100;
    c->p.y = rand() % 100;
    c->raio = rand() % 100;
}

void atribuiAleatorioVetor(Circulo *c, int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        atribuiAleatorio(&c[i]);
    }
}

void mostraCirculoVetor(Circulo *c, int tamanho) {
    int i;
    printf("Dados do vetor de circulos:\n");
    for (i = 0; i < tamanho; i++) {
        printf("Circulo n[%d]\n", i + 1);
        mostraCirculo(&c[i]);
    }
}

int main() {
    srand(time(NULL));
    Circulo vetor[10];

    atribuiAleatorioVetor(vetor, 10);
    mostraCirculoVetor(vetor, 10);

    return 0;
}