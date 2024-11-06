#include <stdio.h>

int main(){
	int valor = 10;
    //int* p = &valor; -> Não faça isso
	int* p;
	p = &valor; //Guarda o endereço da variável valor no ponteiro p
    printf("%p\n", p); //Endereço de memória
    printf("%d\n", *p); //Acessa o valor no espaço de memória

	return 0;
}