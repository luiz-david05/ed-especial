#include "lista.h"

int main() {
    Lista* lista = novaLista();
    lista = inserirInicio(lista, 11);
    lista = inserirInicio(lista, 25);
    lista = inserirInicio(lista, 10);
    lista = inserirFinal(lista, 12);
    listarElementos(lista);

    return 0;
}