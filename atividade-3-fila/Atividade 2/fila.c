#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

Fila* criar_fila() {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = f->tam = 0;
    return f;
}

int enfileirar(Fila* f, Pedido valor) {
    if (!esta_cheia(f)) {
        f->vet[f->fim++] = valor;
        if (f->fim == MAX) f->fim = 0;
        f->tam++;
        return 1;
    }
    return 0;
}

int desenfileirar(Fila* f) {
    if (!esta_vazia(f)) {
        f->ini++;
        if (f->ini == MAX) f->ini = 0;
        f->tam--;
        return 1;
    }
    return 0;
}

int esta_vazia(Fila *f) {
    return (f->tam == 0);
}

int esta_cheia(Fila *f) {
    return (f->tam == MAX);
}

void imprime(Fila *f) {
    if (esta_vazia(f)) {
        printf("A fila esta vazia!\n");
        return;
    }
    for (int i = f->ini; i < f->fim && i < MAX; i++) {
        printf("[ID %d - %dkg - %s] ", f->vet[i].id, f->vet[i].peso, f->vet[i].endereco);
    }
    printf("\n");
}

void liberar(Fila *f) {
    free(f);
}
