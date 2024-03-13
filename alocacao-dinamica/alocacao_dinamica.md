## Alocação dinâmica

A alocação dinâmica é um recurso que permite alocar memória durante a execução do programa. Isso é útil quando não sabemos a quantidade de memória que será necessária para armazenar os dados.

### Uso de memória

Informalmente, existem três maneiras de reservar espaço de memória:

1. Variáveis Globais (e estáticas):

    - O espaço para variáveis globais existe enquanto o programa estives em execução.
    - Essas variáveis têm escopo global e podem ser acessadas por qualquer parte do programa.

2. Variáveis Locais:

    - O espaço para variáveis locais existe apenas durante a execução da função que as declarou.
    - Esse espaço é liberado para outros usos quando execução da função termina.

3. Alocação Dinâmica de Memória:
    - É possível solicitar ao sistema, em tempo de execução, um espaço de memória de tamanho específico.
    - Esse espaço permanece reservado até ser explicitamente liberado.
    - Permite a alocação e acesso dinâmico de memória entre diferentes partes do programa.
    - É crucial liberar o espaço alocado quando não for mais necessário para evitar vazamento de memória.


Quando solicitamos a execução de um programa ao sistema operacional, seu código em linguagem de máquina é 
carregado na memória. O sistema operacional reserva espaço para variáveis globais e estáticas do programa. 
O restante da memória livre é utilizado por variáveis locais e variáveis alocadas dinamicamente. Cada chamada 
de função resulta na reserva de espaço para as variáveis locais, pertencentes à pilha de execução, que é 
desempilhada ao término da função. A parte não ocupada pela pilha pode ser requisitada dinamicamente. Caso a 
pilha cresça além do espaço disponível, ocorre um "estouro", levando ao término do programa com erro. Da mesma 
forma, se o espaço livre for insuficiente para uma alocação dinâmica, o programa pode tratar o erro, como exibir 
uma mensagem de "Memória insuficiente" e interromper a execução. Essa gestão eficiente da memória é crucial para 
a estabilidade do programa.


### Funções da biblioteca padrão `stdlib`

A biblioteca padrão `stdlib.h` fornece funções para alocação e liberação de memória dinâmica. As funções mais
comuns são:

- `malloc`: aloca um bloco de memória de tamanho especificado.

- `free`: libera um bloco de memória previamente alocado.

- `exit`: termina a execução do programa.

### Exemplo de alocação dinâmica

```c
#include <stdio.h>

int main() {
    int *p;
    p = (int *) malloc(sizeof(int));
    if (p == NULL) {
        printf("Memória insuficiente\n");
        exit(1);
    }
    *p = 10;
    printf("%d\n", *p);
    free(p);
    return 0;
}
```

Neste exemplo, a função `malloc` aloca um bloco de memória do tamanho de um inteiro e retorna um ponteiro para
o início desse bloco. O ponteiro é armazenado na variável `p`. Em seguida, o valor 10 é armazenado no endereço
apontado por `p`. Por fim, a função `free` libera o bloco de memória alocado.

### Exemplo de alocação dinâmica de um vetor

```c

#include <stdio.h>

int main() {
    int *v;
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    v = (int *) malloc(n * sizeof(int));
    if (v == NULL) {
        printf("Memória insuficiente\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        v[i] = i;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    free(v);
    return 0;
}
```

Neste exemplo, a função `malloc` aloca um bloco de memória do tamanho de `n` inteiros e retorna um ponteiro
para o início desse bloco. O ponteiro é armazenado na variável `v`. Em seguida, os valores de 0 a `n-1` são
armazenados nos endereços apontados por `v`. Por fim, a função `free` libera o bloco de memória alocado.


A biblioteca padrão `stdlib` fornece funções para alocação e liberação de memória dinâmica. A função básica 
para alocação é `malloc`, que recebe o número de bytes desejados e retorna o endereço inicial da memória alocada. 
Por exemplo, para alocar dinamicamente um vetor de inteiros com 10 elementos, podemos usar:

```c
int *v;
v = (int *) malloc(10 * sizeof(int));
```

Se a alocação for bem-sucedida, `v` armazenará o endereço inicial da memória alocada, permitindo que o tratemos 
como um vetor estático. A função `malloc` retorna `NULL` se a alocação falhar, então podemos verificar isso e tratar
 o erro adequadamente. Para liberar a memória alocada, usamos a função `free`, passando o ponteiro da memória a ser 
 liberada:

```c
free(v);
```

É importante lembrar que só podemos passar para `free` um ponteiro que tenha sido alocado dinamicamente, e não podemos 
acessar a memória após liberá-la.

A alocação dinâmica é útil quando não conhecemos o tamanho do vetor em tempo de compilação, como no exemplo de calcular a 
média e a variância de um conjunto de números fornecidos pelo usuário. Nesse caso, podemos ler o número de valores, alocar dinamicamente o vetor, realizar os cálculos e, finalmente, liberar a memória alocada:

```c
#include <stdio.h>
#include <stdlib.h>

double calcularMedia(int n, int *v)
{
    int i;
    double soma = 0;

    for (i = 0; i < n; i++) {
        soma += v[i];
    }

    return soma / n;
}

double calcularVariancia(int n, int *v, double m) {
    int i;
    double soma = 0;

    for (i = 0; i < n; i++) {
        soma += (v[i] - m) * (v[i] - m);
    }

    return soma / n;
}

int main()
{
    int *v, i, n;
    double media, variancia;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    v = (int *) malloc(n * sizeof(int));

    if (v == NULL) {
        printf("Memoria insuficiente.\n");

        return 1;
    }

    printf("Digite os elementos do vetor de tamanho %d\n", n);
    for (i = 0; i < n; i++) {
        printf("->: ");
        scanf("%d", &v[i]);
    }

    media = calcularMedia(n, v);
    variancia = calcularVariancia(n, v, media);

    printf("Media = %.1lf, Variancia = %.1lf\n", media, variancia);
    free(v);

    return 0;
}
```
Essa abordagem permite lidar com conjuntos de dados de tamanho variável de forma eficiente e dinâmica. No entanto, 
é importante lembrar que a alocação dinâmica de memória requer cuidados especiais para evitar vazamento de memória 
e corrupção de dados.