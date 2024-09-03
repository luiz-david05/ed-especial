#include "lista_circular.h"

int main() {
    Lista* lista = criaLista();

    lista = inserirInicio(lista, 1);
    lista = inserirInicio(lista, 2);
    lista = inserirInicio(lista, 3);

    imprimirLista(lista);

    return 0;
}