#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

Fila* criar_fila() {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = f->tam = 0;
    return f;
}

int enfileirar(Fila* f, Veiculo valor) {
    if (!esta_cheia(f)) {
        f->vet[f->fim++] = valor;
        if (f->fim == MAX)
            f->fim = 0;
        f->tam++;
        return 1;
    }
    return 0;
}

int desenfileirar(Fila* f) {
    if (!esta_vazia(f)) {
        f->ini++;
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
        printf("A fila esta vazia!\n");
        return;
    }
    for (int i = f->ini; i < f->fim && i < MAX; i++) {
        printf("%d ", f->vet[i].id);
    }
    printf("\n");
}

void liberar(Fila *f) {
    free(f);
}

// Funções de controle da ponte e veículos
Veiculo gerar_veiculo(int id) {
    Veiculo v;
    v.id = id;
    if (rand() % 2 == 0) {
        strcpy(v.direcao, "NORTE");
    } else {
        strcpy(v.direcao, "SUL");
    }
    return v;
}

void controlar_ponte(Fila *norte, Fila *sul) {
    static int direcao_norte = 1; // 1 para NORTE, 0 para SUL
    int max_veiculos = 10;

    if (direcao_norte) {
        printf("\nPonte aberta na direcao: NORTE\n");
    } else {
        printf("\nPonte aberta na direcao: SUL\n");
    }

    for (int i = 0; i < max_veiculos && !esta_vazia(direcao_norte ? norte : sul); i++) {
        Veiculo v;
        if (direcao_norte) {
            v = norte->vet[norte->ini];
            desenfileirar(norte);
        } else {
            v = sul->vet[sul->ini];
            desenfileirar(sul);
        }
        printf("Veiculo %d atravessou a ponte.\n", v.id);
    }

    direcao_norte = !direcao_norte;
}
