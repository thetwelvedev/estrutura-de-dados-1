#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha* p = criarPilha();

    colocarElemento(p, 10);
    colocarElemento(p, 20);
    colocarElemento(p, 30);

    printf("Elemento no topo: %d\n", acessarTopo(p));
    printf("Tamanho da pilha: %d\n", tamanhoPilha(p));

    printf("Elemento removido: %d\n", removerElemento(p));
    
    printf("Elemento no topo: %d\n", acessarTopo(p));
    printf("Tamanho da pilha: %d\n", tamanhoPilha(p));

    esvaziarPilha(p);

    return 0;
}


//gcc main.c pilha.c -o main
//.\main.exe