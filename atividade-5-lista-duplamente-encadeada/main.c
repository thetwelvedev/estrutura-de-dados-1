#include<stdio.h>
#include<stdlib.h>
#include"doubly_linked_list.h"

int main(){
    DoublyList *L = create_list();

    list_insert_begin(L, 5);
    
    list_insert_end(L, 10);
    list_insert_end(L, 20);
    list_insert_end(L, 30);
    list_insert_end(L, 40);
    list_insert_end(L, 50);
    list_insert_end(L, 60);

    list_insert_begin(L, 2);

    printf("----BEFORE REMOVING ELEMENTS----\n");
    list_print(L);

    // Verifica a posição do elemento 20
    int inicio, fim;
    int valor = 20;
    if (posicao_elemento(L, valor, &inicio, &fim)) {
        printf("O elemento %d esta na posicao %d a partir do inicio e %d a partir do fim.\n", valor, inicio, fim);
    } else {
        printf("O elemento %d nao foi encontrado na lista.\n", valor);
    }

    list_remove(L, 2);
    list_remove(L, 5);
    list_remove(L, 60);
    list_remove(L, 30);

    printf("----AFTER REMOVING ELEMENTS----\n");
    list_print(L);
    
    list_destroy(L);
    return 0;
}
