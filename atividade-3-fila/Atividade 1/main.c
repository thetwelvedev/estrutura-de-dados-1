#include<stdio.h>
#include<stdlib.h>
#include"fila.h"

int main() {
    Fila *f = criar_fila();
    int v;
    enfileirar(f, 10);
    enfileirar(f, 20);
    enfileirar(f, 30);
    enfileirar(f, 40);
    imprime(f);
    desenfileirar(f);
    imprime(f);
    liberar(f);
    return 0;
}