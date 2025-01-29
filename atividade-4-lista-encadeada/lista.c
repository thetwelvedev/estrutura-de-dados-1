#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

List* create_list() {
    List *lista = (List *) malloc(sizeof(List));
    lista->head = NULL;
    lista->len = 0;
    return lista;
}
void list_insert(List *L, int v) {
    Nodo *new = (Nodo*) malloc(sizeof(Nodo));
    L->len++;
    new->info = v;
    new->next = L->head;
    L->head = new;
}

int is_empty(List *L) {
    return (L->head == NULL);
}

/*
* list_destroy_iterativo não estará visível para o usuário
porque não adicionamos o cabeçalho dela no list.h
*/
void list_destroy_iterativo(List *L) {
    Nodo *p, *ant;
    p = L->head;
    while (p!=NULL) {
        ant = p;
        p = p->next;
        free(ant);
    }
    free(L);
}

/*
* nodos_list_destroy não estará visível para o usuário
porque não adicionamos o cabeçalho dela no list.h
*/
void nodos_list_destroy(Nodo *head) {
    if (head!=NULL) {
        nodos_list_destroy(head->next);
        free(head);
    }
}

void list_destroy(List *L) {
    nodos_list_destroy(L->head);
    free(L);
}

Nodo* search(List *L, int key) {
    for(Nodo *p = L->head; p!=NULL; p=p->next)
        if (p->info==key)
            return p;
    return NULL;
}

/*
* search_nodo não estará visível para o usuário
porque não adicionamos o cabeçalho dela no list.h
*/
Nodo* search_nodo(Nodo* head, int key) {
    if (head==NULL)
        return head;
    if (head->info==key)
        return head;
    search_nodo(head->next, key);
}

/*
* search_recursivo não estará visível para o usuário
porque não adicionamos o cabeçalho dela no list.h
*/
Nodo* search_recursivo(List *L, int key) {
    return search_nodo(L->head, key);
}

void list_print(List *L) {
    printf("Lista: ");
    for(Nodo *p = L->head; p!=NULL; p=p->next)
        printf("%d ", p->info);
    printf("\n");
}

void list_remove(List *L, int v) {
    Nodo *p, *ant;
    p = L->head;
    ant = NULL;
    while (p!=NULL && p->info!=v) {
        ant = p;
        p = p->next;
    }
    if (p==NULL)//node not found
        return;
    if (ant==NULL) //v was found and it is the first node of the list
        L->head = p->next;
    else//v was found and it is not the first node of the list
        ant->next = p->next;
    L->len--;
    free(p);
}

/*
* remove_recursive não estará visível para o usuário
porque não adicionamos o cabeçalho dela no list.h
*/
int removed = 0;//if removed==1 then decrement the lenght of the list
Nodo * remove_recursive(Nodo *head, int v) {
    Nodo *aux;
    if (head!=NULL) {
        if (head->info==v) {
            aux = head;
            head = head->next;
            free(aux);
            removed = 1;
            }
        else 
            head->next = remove_recursive(head->next, v);
    }
    return head;
}

/*
* list_remove_recursive não estará visível para o usuário
porque não adicionamos o cabeçalho dela no list.h
*/
void list_remove_recursive(List *L, int v) {
    L->head = remove_recursive(L->head, v);
    if (removed)
        L->len--;
}

//EX1 - Soma dos Elementos
int lis_sum(List* L){
    int soma = 0;
    for(Nodo* p = L->head; p!= NULL ; p=p->next){
        soma += p->info;
    }
    return soma;
}

//EX2 - Inverter a lista
void reverse_list(List* L){
    if (is_empty(L)){
        return;
    }
    Nodo *ant = NULL;
    Nodo *curr = L->head;
    Nodo *prox = NULL;

    while(curr!= NULL){
        prox = curr->next;
        curr->next = ant; //Referencia
        ant = curr;
        curr = prox;
    }
    L->head = ant;
}
//EX3 - Mesclar Duas Listas
List* merge_sorted_lists(List* L1, List* L2){
    List* merged = create_list();
    Nodo *p1 = L1->head, *p2 = L2->head;

    while (p1 != NULL && p2 != NULL) {
        if (p1->info < p2->info) {
            list_insert(merged, p1->info);
            p1 = p1->next;
        } else {
            list_insert(merged, p2->info);
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        list_insert(merged, p1->info);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        list_insert(merged, p2->info);
        p2 = p2->next;
    }

    reverse_list(merged); // Para manter a ordem crescente
    return merged;
}

//EX4 - Remover Elementos Duplicados
void remove_duplicates(List *L){
    Nodo *current = L->head;
    while (current != NULL) {
        Nodo *runner = current;
        while (runner->next != NULL) {
            if (runner->next->info == current->info) {
                Nodo *temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
                L->len--;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

//EX5 - Verificar Palíndromo
int is_palindrome(List *L) {
    if (is_empty(L)) 
        return 1; // Lista vazia é um palíndromo por definição.

    // Alocando dinamicamente memória para armazenar os elementos.
    int *arr = (int *)malloc(L->len * sizeof(int));
    if (arr == NULL) {
        printf("Erro: Falha ao alocar memória.\n");
        return 0;
    }

    int i = 0;
    for (Nodo *p = L->head; p != NULL; p = p->next) {
        arr[i++] = p->info;
    }

    // Verificando se é palíndromo.
    for (int j = 0; j < i / 2; j++) {
        if (arr[j] != arr[i - j - 1]) {
            free(arr); // Liberando memória antes de retornar.
            return 0;
        }
    }

    free(arr); // Liberando memória alocada dinamicamente.
    return 1;
}


//EX6 - Rotacionar a Lista
void rotate_list(List *L, int k){
    if (is_empty(L) || k <= 0) return;

    k = k % L->len;
    if (k == 0) return;

    Nodo *tail = L->head;
    Nodo *new_tail = NULL;
    int count = 1;

    while (count < L->len - k) {
        tail = tail->next;
        count++;
    }

    new_tail = tail;
    tail = tail->next;
    new_tail->next = NULL;

    Nodo *new_head = tail;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    tail->next = L->head;
    L->head = new_head;
}

//EX7 - Intercalar Listas
List* intercalate_lists(List *L1, List *L2){
    List* intercalated = create_list();
    Nodo *p1 = L1->head, *p2 = L2->head;

    while (p1 != NULL || p2 != NULL) {
        if (p1 != NULL) {
            list_insert(intercalated, p1->info);
            p1 = p1->next;
        }
        if (p2 != NULL) {
            list_insert(intercalated, p2->info);
            p2 = p2->next;
        }
    }

    reverse_list(intercalated); // Para manter a ordem correta
    return intercalated;
}

//EX8 - Encontrar o K-ésimo Elemento
int get_kth_element(List *L, int k){
    if (k < 0 || k >= L->len) return -1;

    Nodo *p = L->head;
    for (int i = 0; i < k; i++) {
        p = p->next;
    }
    return p->info;
}

//EX9 - Dividir a Lista
void split_list(List *L, List **even_list, List **odd_list){
    *even_list = create_list();
    *odd_list = create_list();

    for (Nodo *p = L->head; p != NULL; p = p->next) {
        if (p->info % 2 == 0) {
            list_insert(*even_list, p->info);
        } else {
            list_insert(*odd_list, p->info);
        }
    }
    reverse_list(*even_list);
    reverse_list(*odd_list);
}

//EX10 - Ordenar Lista
void sort_list(List *L){
    if (is_empty(L)) return;

    for (Nodo *i = L->head; i != NULL; i = i->next) {
        for (Nodo *j = i->next; j != NULL; j = j->next) {
            if (i->info > j->info) {
                int temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }
}