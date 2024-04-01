Tendo as seguintes estruturas:

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Ponto;

typedef struct {
    Ponto p1;
    int raio;
} Circulo;
```

1. Na função main(), crie a variável p1 do tipo Ponto e faça a atribuição de valores quaisquer para seus campos x e y. Em
seguida, peça para o usuário digitar esses valores.

```c
int main() {
    Ponto p1 = {1, 2};

    printf("Valor de x e y: ");
    scanf("%d %d", &p1.x, &p1.y);

    printf("Valores dos pontos x: %d e y: %d \n", p1.x, p1.y);

    return 0;
}
```

2. Crie uma variável c1 do tipo Circulo e faça a atribuição de valores quaisquer para os seus 3 campos. Em seguida, peça
para o usuário digitar esses valores.

```c
int main() {
    Pontos p1 = {1, 2};
    Circulo c1 = {p1, 3.0};

    printf("Digite os valores dos pontos x e y: ");
    scanf("%d %d", &c1.p.x, &c1.p.y);

    printf("Digite o valor do raio do circulo: ");
    scanf("%f", &c1.raio);
    
    printf("Valores de x e y no circulo: x = %d e y = %d.\n",c1.p.x, c1.p.y);
    printf("Valor do raio do circulo: %d", c1.raio);

    return 0;
}

3. Crie uma variável 'Circulo *c2'. Inicialize a variável com uma área alocada dinamicamente, e faça a atribuição de
valores quaisquer para os seus 3 campos. Em seguida, peça para o usuário digitar esses valores. 
    
```c
int main() {
   Circulo *c2;
   c2 = (Circulo *)malloc(sizeof(Circulo));

    printf("Digite os valores dos pontos x e y: ");
    scanf("%d %d", &c2->p.x, &c2->p.y);

    printf("Digite o valor do raio do circulo: ");
    scanf("%d", &c2->raio);
    
    printf("Valores de x e y no circulo: x = %d e y = %d.\n",c2->p.x, c2->p.y);
    printf("Valor do raio do circulo: %d", c2->raio);

    free(c2);

    return 0;
}
```

4. Crie uma função void mostraCirculo(Circulo *c), a qual mostra na tela os valores de todos os campos de um
círculo. 

```c
void mostraCirculo(Circulo *c) {
    printf("Valores de x e y no circulo: x = %d e y = %d.\n",c->p.x, c->p.y);
    printf("Valor do raio do circulo: %d", c->raio);
}
```

5. Crie uma função void atribuiAleatorio(Circulo *c), a qual atribui valores aleatórios entre 0 e 99 para os
campos do círculo passado como parâmetro. Chame a função na main, passando como parâmetro em uma vez a
variável c1 e, em outra, a variável c2. 

```c
void atribuiAleatorio(Circulo *c) {
    c->p.x = rand() % 100;
    c->p.y = rand() % 100;
    c->raio = rand() % 100;
}

int main() {
    srand(time(NULL));
    Ponto p1 = {1, 2};
    Circulo c1 = {p1, 3};
    Circulo *c2;
    c2 = (Circulo *)malloc(sizeof(Circulo));

    atribuiAleatorio(&c1);
    atribuiAleatorio(c2);

    mostraCirculo(&c1);
    mostraCirculo(c2);

    free(c2);

    return 0;
}
```

6. Crie uma variável 'Circulo *c3' na main. Inicialize a variável com o endereço de c1. Altere os campos usando o
ponteiro c3 e depois chame a função mostraCirculo para mostrar os valores tanto de c1 quanto de c3.

```c
int main() {
    srand(time(NULL));
    Ponto p1 = {1, 2};
    Circulo c1 = {p1, 3};
    Circulo *c2;
    c2 = (Circulo *)malloc(sizeof(Circulo));
    Circulo *c3 = &c1;

    atribuiAleatorio(&c1);
    atribuiAleatorio(c2);
    atribuiAleatorio(c3);

    mostrarCirculo(&c1);
    mostrarCirculo(c2);
    mostrarCirculo(c3);

    free(c2);

    return 0;
}
```

7. Crie um vetor na main: 'Circulo vet[10];' Desenvolva uma função chamada atribuiAleatorioVetor(Circulo *c,
int n), a qual atribui valores aleatórios entre 0 e 99 para os campos de cada elemento círculo do vetor. A chamada na
main será feita com atribuiAleatorioVetor(vet, 10);

```c
void atribuiAleatorioVetor(Circulo *c, int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        atribuiAleatorio(&c[i]);
    }
}
```

8. Crie uma função void mostraCirculoVetor(Circulo *c, int n), a qual mostra na tela os valores de todos os
campos de um vetor de círculo. Tente reutilizar a função já desenvolvida no exercício 4. 

```c
void mostraCirculoVetor(Circulo *c, int tamanho) {
    int i;
    printf("Dados do vetor de circulos:\n");
    for (i = 0; i < tamanho; i++) {
        printf("Circulo n[%d]\n", i + 1);
        mostraCirculo(&c[i]);
    }
}
```