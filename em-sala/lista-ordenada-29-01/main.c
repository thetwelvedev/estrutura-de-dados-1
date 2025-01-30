#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    // Criando listas para testes
    List* lista1 = create_list();
    List* lista2 = create_list();

    // Inserindo elementos na lista1
    list_insert(lista1, 5);
    list_insert(lista1, 3);
    list_insert(lista1, 2);
    list_insert(lista1, 5); // Elemento duplicado para teste
    list_print(lista1);

    // Testando ordenação da lista
    sort_list(lista1);
    printf("Lista ordenada: ");
    list_print(lista1);

    // Liberando memória
    list_destroy(lista1);
    list_destroy(lista2);

    return 0;
}