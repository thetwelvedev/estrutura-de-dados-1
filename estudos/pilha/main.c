#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    Pilha* p = criarPilha();

    colocarElemento(p, 10);
    colocarElemento(p, 20);
    colocarElemento(p, 30);
    colocarElemento(p, 40);
    
    //Mostrar os elementos
    int tam = tamanhoPilha(p);
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", acessarTopo(p));
        removerElemento(p);
    }
    
    esvaziarPilha(p);

    return 0;
}
