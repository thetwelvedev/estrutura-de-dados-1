#ifndef FILA_H_
#define FILA_H_

#define MAX 100

// Estrutura para um pedido de entrega
typedef struct {
    int id;
    int peso;
    char endereco[100]; // Endereço fictício do pedido
} Pedido;

// Estrutura da fila circular para gerenciar os pedidos
typedef struct fila {
    int ini;
    int fim;
    int tam;
    Pedido vet[MAX]; // Fila de pedidos
} Fila;

Fila* criar_fila();
int enfileirar(Fila* f, Pedido valor);
int desenfileirar(Fila* f);
int esta_vazia(Fila *f);
int esta_cheia(Fila *f);
void imprime(Fila *f);
void liberar(Fila *f);

#endif
