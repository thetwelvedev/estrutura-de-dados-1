#ifndef FILA_H_
#define FILA_H_

#define MAX 100

typedef struct fila
{
    int ini;
    int fim;
    int tam;
    int vet[MAX];
} Fila;

Fila* criar_fila();
int enfileirar(Fila*f, int valor);
int desenfileirar(Fila*f, int* valor);
int esta_vazia(Fila *f);
int esta_cheia(Fila *f);
void imprime(Fila *f);
void liberar(Fila *f);

#endif