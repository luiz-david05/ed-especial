// Defina um TAD para implementar matrizes quadradas simétricas, de acordo
// com a representação sugerida no capítulo 8. 

#ifndef MS_H
#define MS_H

typedef struct matriz_simetrica MatrizSimetrica;

MatrizSimetrica* ms_cria(int n);
void ms_libera(MatrizSimetrica* m);
float ms_acessa(MatrizSimetrica* m, int i, int j);
void ms_atribui(MatrizSimetrica* m, int i, int j, float v);

#endif