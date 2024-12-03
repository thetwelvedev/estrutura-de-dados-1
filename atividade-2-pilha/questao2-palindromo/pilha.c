#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "pilha.h"
#define MAX 100

void palindromoPila(Pilha* p){
    char vetor[MAX];
    printf("Digite um nome: ");
    scanf("%s", p->v); //Armazena nome na pilha

    //Ajusta o tamanho do topo de acordo com o tamanho da palavra
    p->topo = strlen(p->v);

    //Verifica se é palindromo
    int palindromo = 0;
    for (int i = 0; i < tamanhoPilha(p)/2; i++) {
        if(p->v[i] == removerElemento(p)){ //Vai comparar os primeiros elementos da pilha com os últimos
            palindromo = 1;
        } else{
            break;
        }
    }
    //Vai imprimir se for palindromo
    if(palindromo){
            printf("E Palindromo\n");
        } else {
            printf("Nao e palindromo\n");
    }
}

Pilha* criarPilha(){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = 0; //Topo está em 0
    return p;
}

void esvaziarPilha(Pilha* p){
    free(p);
}

void colocarElemento(Pilha* p, int valor){
    if(pilhaCheia(p)){
        printf("Pilha está vazia.\n");
        exit(1);
    }
    p->v[p->topo++] =  valor; //Dessa forma ele armazena no topo e com o incremento no topo(indice) vai ser um valor cima para  o próximo valor a ser armazenado
}

int removerElemento(Pilha* p){
    int valorRemovido;
    if(p->topo == 0){
        printf("Pilha está vazia.\n");
        exit(1);
    }
    valorRemovido =  p->v[--p->topo]; /*o valor de topo(indice) fica uma posição acima do valor que está no topo, para quando for colocar um elemento ele ser inserido acima do atual valor no topo
    Então tem que decrementar antes para acessar o valor que está no topo*/
    return valorRemovido;
}

int tamanhoPilha(Pilha* p){
    return p->topo; //pois o topo(indice) está sempre um posição acima do topo(elemento), mas como o indice começa do 0, então o valor do indice é equivalente ao tamanho
}

int pilhaVazia(Pilha* p){
    return p->topo == 0; //Se o topo(indice) estiver em 0 quer dizer que nenhum elemento foi colocado
}

int pilhaCheia(Pilha* p){
    return p->topo >= MAX;
}

int acessarTopo(Pilha* p){
    return p->v[p->topo-1]; //pois o topo(indice) está sempre um posição acima do topo(elemento)
}
//Aqui eu faço todas as funções que são declaradas em pilha.h e rodam em main.c