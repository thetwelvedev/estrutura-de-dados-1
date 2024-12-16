#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#define MAX 100

Fila* criar_fila(){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini = f->fim = f->tam = 0;
    return f;
}

int enfileirar(Fila*f, int valor){
    if(!esta_cheia(f)){
        f->v[f->fim++] = valor;
        printf("Enfileirando %d\n", valor);
        if(f->fim == MAX){
            f->fim = 0;
        }
        f->tam++;
        return 1;
    }
    return 0;
}

int desenfileirar(Fila*f){
    if(!esta_vazia(f)){
        int valor = f->v[f->ini++];
        printf("Desenfileirando %d\n", valor);
        if(f->ini == MAX){
            f->ini = 0;
        }
        f->tam--;
        return 1;
    }
    return 0;
}

int esta_vazia(Fila *f){
    return f->tam == 0;
}

int esta_cheia(Fila *f){
    return f->tam == MAX;
}

void imprime(Fila *f){
    if(esta_vazia(f)){
        printf("Ela esta vazia!\n");
        return;
    }
    int j = f->ini;
    for (int i = 0; i < f->tam; i++){
        printf("%d ", f->v[j++]);
        if (j == MAX) {
            j = 0;
        }
    }
    printf("\n");
}

void liberar(Fila *f){
    free(f);
}
