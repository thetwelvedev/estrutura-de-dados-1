#include <stdio.h>

//Soma dos n números naturais ímpares.

int soma_impares(int n);

int main(){
    int number, resultado;

    printf("Digite um numero: ");
    scanf("%d", &number);
    
    resultado = soma_impares(number);

    printf("Numero %d: soma: %d\n", number, resultado);

    return 0;
}

int soma_impares(int n){
    int soma = 0; //Inicializo a variável para não ficar com lixo de memória
    for(int i = 0; i <= n; i++){
        if(i % 2 != 0){ //Detecta se é ímpar, tem que ser o i pois é cada valor até chegar em 5
            soma += i;
        }
    }
    return soma;
}