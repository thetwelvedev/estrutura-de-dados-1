#include <stdio.h>

//Retorne o n-ésimo termo da série de Fibonacci 1 1 2 3 5 8 13 21 ...
//Os dois primeiros termos são 1 e cada termo sequinte f(n + 2)= f(n-1) + f(n-2)

int fibonacci(int n);

int main(){
    int number, resultado;

    printf("Digite um numero: ");
    scanf("%d", &number);
    
    resultado = fibonacci(number);

    printf("termo %d: %d\n", number, resultado);

    return 0;
}

int fibonacci(int n){//Usando a recursividade, onde ela vai chamar a própria função para pegar os valores
    if(n <= 2){//Caso base
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}