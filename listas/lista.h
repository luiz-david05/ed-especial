#ifndef LISTA
#define LISTA

struct lista {
    int valor;
    struct lista* prox;
};

typedef struct lista Lista;

Lista* criaLista();
Lista* inserirInicio(Lista* lista, int valor);
int estaVazia(Lista* lista);
Lista* inserirFinal(Lista *lista, int valor);
Lista *inserirPos(Lista* lista, int valor, int pos);
void listarElementos(Lista* lista);
// Lista* removerInicio(Lista* lista);
// // void removeFinal(Lista* lista);
// void listarElementos(Lista* lista);

#endif