#ifndef _CALC_H_
#define _CALC_H_
#include "pilha.h"

typedef struct calc{
    char f[21];/* formato para impressão */
    Pilha *p;/* pilha de operandos */
}Calc;

Calc* calc_cria(char *formato);
void calc_operando(Calc *c, float v);
void calc_operador(Calc *c, char op);
void calc_libera(Calc *c);

#endif