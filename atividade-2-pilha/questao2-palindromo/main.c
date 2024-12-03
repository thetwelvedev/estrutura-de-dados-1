#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha* p = criarPilha();

    palindromoPila(p);

    esvaziarPilha(p);

    return 0;
}


//gcc main.c pilha.c -o main
//.\main.exe