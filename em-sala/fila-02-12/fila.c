#include<stdio.h>
#include<stdlib.h>
#include"fila.h"

Fila* criar_fila() {
    printf("Criando fila\n");
    Fila* f;
    f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = f->tam = 0;
    return f;
}

int enfileirar(Fila*f, int valor) {    
    if (!esta_cheia(f)) {
        printf("Enfileirando %d\n", valor);
        f->vet[f->fim++] = valor;
        if (f->fim == MAX)
            f->fim = 0;
        f->tam++;
        return 1;
    }
    return 0;
}

int desenfileirar(Fila*f, int* valor) {    
    if (!esta_vazia(f)) {        
        *valor = f->vet[f->ini++];
        printf("Desenfileirando %d\n", *valor);
        if (f->ini == MAX)
            f->ini = 0;
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
        printf("A fila estah vazia!\n");
        return;
    }
    int j = f->ini;
    for (int i = 0; i<f->tam; i++) {
        printf("%d ", f->vet[j++]);
        if (j==MAX)
            j = 0;
    }
    printf("\n");
}

void liberar(Fila *f) {
    printf("Destruindo a fila\n");
    free(f);
}