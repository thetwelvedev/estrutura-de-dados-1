#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct pilha {
    int topo;
    int v[MAX];
} Pilha;

Pilha* criarPilha() {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if (!p) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    p->topo = 0; // Inicializa o topo como 0
    return p;
}

void esvaziarPilha(Pilha* p) {
    free(p);
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

void colocarElemento(Pilha* p, int valor) {
    if (pilhaCheia(p)) {
        printf("Pilha está cheia.\n");
        exit(1);
    }
    p->v[p->topo++] = valor; // Armazena o valor no topo e incrementa o índice do topo
}

int removerElemento(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Pilha está vazia.\n");
        exit(1);
    }
    return p->v[--p->topo]; // Decrementa o topo e retorna o valor removido
}

// Função para exibir os elementos da pilha
void imprimirPilha(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Pilha está vazia.\n");
        return;
    }
    printf("Elementos da pilha: ");
    for (int i = 0; i < p->topo; i++) {
        printf("%d ", p->v[i]);
    }
    printf("\n");
}

int main() {
    Pilha* p = criarPilha();

    colocarElemento(p, 10);
    colocarElemento(p, 20);
    colocarElemento(p, 30);

    imprimirPilha(p);
    printf("Elemento no topo: %d\n", acessarTopo(p));
    printf("Tamanho da pilha: %d\n", tamanhoPilha(p));

    printf("Elemento removido: %d\n", removerElemento(p));
    imprimirPilha(p);
    
    printf("Elemento no topo: %d\n", acessarTopo(p));
    printf("Tamanho da pilha: %d\n", tamanhoPilha(p));

    esvaziarPilha(p);

    return 0;
}
