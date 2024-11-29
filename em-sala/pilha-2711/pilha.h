#ifndef _PILHA_H_
#define _PILHA_H_
#define MAX 100

typedef struct pilha {
    int topo;
    int v[MAX];
} Pilha;


typedef struct pilha Pilha;

Pilha* criarPilha();
void esvaziarPilha(Pilha* p);
void colocarElemento(Pilha* p, int valor);
int removerElemento(Pilha* p, int *valor);
int tamanhoPilha(Pilha* p);
int pilhaVazia(Pilha* p);
int pilhaCheia(Pilha* p);
int acessarTopo(Pilha* p);

#endif