#include <stdio.h>
//O número inteiro é primo ou não
//Return 1 se for primo e 0 se não for 

int primo(int n);

int main(){
    int number, resultado;

    printf("Digite um numero: ");
    scanf("%d", &number);
    
    resultado = primo(number);

    if(resultado == 1){
        printf("Primo!\n");
    } else if(resultado == 0){
        printf("Nao e primo!\n");
    }
}

int primo(int n){
    int contador = 0;

    for(int i = 1; i <= n;i++){//Vai verificar a divisão do 1 até n
        if(n % i == 0){ //Ver se é divísel pois se for o resto é 0
            contador++;
        }
    }
    if(contador == 2){ //O número primo só divível por 1 e por ele mesmo
        return 1;
    } else{
        return 0;
    }
}