#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "calc.h"

/* Função para criar a calculadora */
Calc* calc_cria(char *formato){
    Calc* c = (Calc*) malloc(sizeof(Calc));
    strcpy(c->f, formato);
    c->p = criarPilha(); /* cria pilha vazia */
    return c;
}

/* Função para colocar no topo da pilha o valor passado como parâmetro */
void calc_operando(Calc *c, float v){
    /* empilha operando */
    colocarElemento(c->p,v);
    /* imprime o topo da pilha */
    //printf(c->f, v);
}
/* Função para retirar dois valores dois valores do topo da pilha, efetuar a operação correspondente e colocar o resultado no topo da pilha */
void calc_operador(Calc *c, char op){
    float v1, v2, v;
    /* desempilha operandos */
    if(pilhaVazia(c->p))
        v2=0.0;
    else
        v2 = removerElemento(c->p);
    if(pilhaVazia(c->p))
        v1=0.0;
    else
        v1 = removerElemento(c->p);
    /* faz a operação */
    switch (op){
        case '+': v = v1 + v2; break;
        case '-': v = v1 - v2; break;
        case '*': v = v1 * v2; break;
        case '/': v = v1 / v2; break;
    }
    /* empilha o resultado */
    colocarElemento(c->p,v);
    /* imprime o topo da pilha */
    printf(c->f,v);
}

/* Função para liberar a calculadora */
void calc_libera(Calc *c){
    esvaziarPilha(c->p);
    free(c);
}