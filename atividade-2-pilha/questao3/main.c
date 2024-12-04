#include <stdio.h>
#include "pilha.h"
#include "calc.h"

int main() {
    char c;
    float v;
    Calc *calc;

    /* Cria calculadora com formato de duas casas decimais */
    calc = calc_cria("%.2f\n");

    do {
        /* lê o próximo caractere não branco */
        scanf(" %c", &c);

        /* verifica se é um operador válido */
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            calc_operador(calc, c);
        }
        /* devolve o caractere lido e tenta ler um número */
        else {
            ungetc(c, stdin);
            if (scanf("%f", &v) == 1) {
                calc_operando(calc, v);
            }
        }

    } while (c != '\n'); /* Continua até o final da expressão */

    /* Libera a memória alocada para a calculadora */
    calc_libera(calc);

    return 0;
}
