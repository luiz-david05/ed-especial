#ifndef LISTA
#define LISTA

struct lista {
    int valor;
    struct lista* prox;
};

typedef struct lista Lista;

Lista* novaLista();
Lista* inserirInicio(Lista* lista, int valor);
Lista* inserirFinal(Lista *lista, int valor);
Lista* removerInicio(Lista* lista);
// void removeFinal(Lista* lista);
void listarElementos(Lista* lista);
int estaVazia(Lista* lista);
void listarElementos(Lista* lista);

#endif