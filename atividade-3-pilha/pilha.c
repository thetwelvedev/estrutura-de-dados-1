#include <stdio.h>
//Testar se importa ou não o pilha.h
#define MAX 100
typedef struct pilha {
    int topo;
    int v[MAX];
} Pilha;


typedef struct pilha Pilha;

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