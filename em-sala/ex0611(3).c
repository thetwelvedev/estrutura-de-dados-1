#include <stdio.h>
//Ponteiro de ponteiro
int main(){
	int x = 5; //Espaço de memória 6422296(&x)
    int *p1 = &x; // Esse ponteiro recebe o espaço de memória 6422296(&x) - espaço de memória 6422292(p1)
    int **p2 = &p1;// Esse ponteiro recebe esse  6422292 espaço de memória

    printf("X Valor = %d Memoria = %p\n", x, &x);
    printf("P1 Valor = %d Memoria = %p\n", *p1, p1);
    printf("P2 Valor = %p Memoria = %p\n", *p2, p2); //Aqui ele aponta só pro ponteiro pois **p2 = p2 -> p1 -> x
    printf("P2 Valor = %d Memoria = %p\n", **p2, p2);

	return 0;
}