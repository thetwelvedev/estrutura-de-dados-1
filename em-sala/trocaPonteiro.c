#include <stdio.h>

void troca(int* x, int* y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

int main(){
    int x, y;
    x = 10;
    y = 9;
    printf("X = %d e Y = %d\n", x, y);
    troca(&x, &y);
    printf("X = %d e Y = %d\n", x, y);

}