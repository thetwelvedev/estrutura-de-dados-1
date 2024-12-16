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

    // Testando soma dos elementos
    printf("Soma dos elementos: %d\n", lis_sum(lista1));

    // Testando inversão da lista
    reverse_list(lista1);
    printf("Lista invertida: ");
    list_print(lista1);

    // Inserindo elementos na lista2
    list_insert(lista2, 8);
    list_insert(lista2, 6);
    list_insert(lista2, 4);
    printf("Lista 2: ");
    list_print(lista2);

    // Testando mesclagem de listas ordenadas
    List* lista_merged = merge_sorted_lists(lista1, lista2);
    printf("Lista mesclada: ");
    list_print(lista_merged);

    // Testando remoção de duplicados
    remove_duplicates(lista1);
    printf("Lista sem duplicados: ");
    list_print(lista1);

    // Testando verificação de palíndromo
    printf("Lista eh palindromo? %s\n", is_palindrome(lista1) ? "Sim" : "Nao");

    // Testando rotação da lista
    rotate_list(lista1, 2);
    printf("Lista rotacionada: ");
    list_print(lista1);

    // Testando intercalação de listas
    List* lista_intercalada = intercalate_lists(lista1, lista2);
    printf("Lista intercalada: ");
    list_print(lista_intercalada);

    // Testando obtenção do k-ésimo elemento
    int k = 3;
    printf("%d-esimo elemento da lista1: %d\n", k, get_kth_element(lista1, k));

    // Testando divisão da lista
    List* pares = create_list();
    List* impares = create_list();
    split_list(lista1, &pares, &impares);
    printf("Lista de pares: ");
    list_print(pares);
    printf("Lista de impares: ");
    list_print(impares);

    // Testando ordenação da lista
    sort_list(lista1);
    printf("Lista ordenada: ");
    list_print(lista1);

    // Liberando memória
    list_destroy(lista1);
    list_destroy(lista2);
    list_destroy(lista_merged);
    list_destroy(lista_intercalada);
    list_destroy(pares);
    list_destroy(impares);

    return 0;
}
