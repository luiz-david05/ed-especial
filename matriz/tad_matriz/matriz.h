#ifndef MATRIZ_H
#define MATRIZ_H
typedef struct matriz Matriz;

Matriz* cria_matriz(int linhas, int colunas);
void libera_matriz(Matriz* mat);
float acessa_matriz(Matriz* mat, int i, int j);
void atribui_matriz(Matriz* mat, int i, int j, float valor);
int qtd_linhas(Matriz* mat);
int qtd_colunas(Matriz* mat);

int eh_quadrada_simetrica(Matriz* matriz);
Matriz* cria_transposta(Matriz* matriz);
void imprime_matriz(Matriz* mat);

#endif