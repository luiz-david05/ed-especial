## Vetores

A forma mais simples de estruturar dados é por meio de vetores. Em C, um vetor é uma sequência de 
elementos do mesmo tipo. A declaração de um vetor é feita da seguinte forma:

```c
// define um vetor de inteiros com 10 posições (elementos)
int v[10];
```

Inicializar um vetor é feito da seguinte forma:

```c
int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// ou

int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
```

A declaração acima define um vetor de inteiros dimensionados com 10 elementos, 
reserva um espaço de memória contínuo para armazenar 10 inteiros. Assim, se cada 
int ocupa 4 bytes, o vetor `v` ocupará 40 bytes de memória.

Acessar um elemento do vetor é feito por meio de um índice, que é um número inteiro
que varia de 0 a n-1, onde n é o número de elementos do vetor. Por exemplo, para
acessar o terceiro elemento do vetor `v`, fazemos:

```c
v[2] = 10;
```

### Aritmética de ponteiros

Em C, um vetor é um ponteiro para o primeiro elemento do vetor. Assim, podemos 
acessar os elementos do vetor por meio de aritmética de ponteiros. Por exemplo:

```c
v[2] = 10; <=> *(v + 2) = 10;
```

## Passagem de vetores para funções

Passar um vetor para uma função consiste em passar o endereço da primeira posição do vetor. Para passar um valor de endereço, a função chamada deve ter um parâmetro do tipo ponteiro para armazenar este valor. Assim, se passar uma função um vetor de int, a função deve ter um parâmetro do tipo `int*`. Por exemplo:

```c
void funcao(int* v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
}
```

```c
int main() {
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    funcao(v, 10);
}
```

A expressão "passar um vetor para uma função" deve ser interpretada como "passar o endereço inicial do vetor". Os elementos do vetor não são copiados para a função, o argumento copiado é apenas o endereço do primeiro elemento do vetor. Assim, qualquer alteração feita nos elementos do vetor dentro da função, refletirá no vetor original.
