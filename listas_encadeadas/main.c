#include "lista.h"

int main() {
    Lista* lista = criaLista();
    lista = inserirInicio(lista, 1);
    lista = inserirInicio(lista, 2);
    lista = inserirInicio(lista, 3);
    lista = inserirFinal(lista, 0);
    listarElementos(lista);
    // posicao maior que o tamanho da lista, vai para o fim da lista
    lista = inserirPos(lista, 5, 6);
    listarElementos(lista);

    return 0;
}