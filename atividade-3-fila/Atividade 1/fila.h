#ifndef FILA_H_
#define FILA_H_

#define MAX 100

typedef struct {
    int id;
    char direcao[6]; // "NORTE" ou "SUL"
} Veiculo;

typedef struct fila {
    int ini;
    int fim;
    int tam;
    Veiculo vet[MAX]; // Alterado para armazenar Veiculos
} Fila;

Fila* criar_fila();
int enfileirar(Fila*f, Veiculo valor);
int desenfileirar(Fila*f);
int esta_vazia(Fila *f);
int esta_cheia(Fila *f);
void imprime(Fila *f);
void liberar(Fila *f);

// Declaração das funções para gerar e controlar veículos
Veiculo gerar_veiculo(int id); 
void controlar_ponte(Fila *norte, Fila *sul);


#endif
