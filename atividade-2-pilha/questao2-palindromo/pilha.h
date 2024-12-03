#ifndef _PILHA_H_
#define _PILHA_H_
#define MAX 100
typedef struct pilha {
    int topo;
    char v[MAX];
} Pilha;

Pilha* criarPilha();
void esvaziarPilha(Pilha* p);
void colocarElemento(Pilha* p, int valor);
int removerElemento(Pilha* p);
int tamanhoPilha(Pilha* p);
int pilhaVazia(Pilha* p);
int pilhaCheia(Pilha* p);
int acessarTopo(Pilha* p);
void palindromoPila(Pilha* p);

#endif
//Aqui eu defino tudo que vai rodar na main