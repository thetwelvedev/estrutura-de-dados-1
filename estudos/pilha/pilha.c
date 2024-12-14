#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#define MAX 100

Pilha* criarPilha(){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = 0;
    return p;
}

void esvaziarPilha(Pilha* p){
    free(p);
}

void colocarElemento(Pilha* p, int valor){
    if(pilhaCheia(p)){
        printf("Pilha está cheia!");
        exit(1);
    }
    p->v[p->topo++] = valor;
}

int removerElemento(Pilha* p){
    int valorRemovido;
    if(pilhaVazia(p)){
        printf("Pilha está vazia!");
        exit(1);
    }
    valorRemovido = p->v[--p->topo];
    return valorRemovido;
}

int tamanhoPilha(Pilha* p){
    return p->topo;
}

int pilhaCheia(Pilha* p){
    return p->topo == MAX;
}

int pilhaVazia(Pilha* p){
    return p->topo == 0;
}

int acessarTopo(Pilha* p){
    return p->v[p->topo-1];
}