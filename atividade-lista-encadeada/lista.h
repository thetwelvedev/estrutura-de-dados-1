#ifndef _LISTA_H_
#define _LISTA_H_

typedef struct nodo {
    int info;
    struct nodo *next;
}Nodo;

typedef struct list {
    Nodo *head;
    int len;
}List;

List* create_list();
void list_insert(List *L, int v);
int is_empty(List *L);
void list_destroy(List *L);
Nodo* search(List *L, int key);
void list_print(List *L);
void list_remove(List *L, int v);

//atividade 1 de Soma dos Elementos
int lis_sum(List* L);
//atividade 2 de Inverter a lista
void reverse_list(List* L);
//atividade 3 de Mesclar Duas Listas
List* merge_sorted_lists(List* L1, List* L2);
#endif