#include <stdio.h>
#include <stdlib.h>

/*Função que receba como parâmetro um vetor de números inteiros(vet) de tamanho n e retorne quantos números pares estão armazenados nesse vetor*/

int pares(int n, int* vet);

int main(){
    int resultado, tamanho_vet;
    int* vet;

    printf("Tamanho para o vetor: ");
    scanf("%d", &tamanho_vet);

    vet = (int*) malloc(tamanho_vet*sizeof(int)); //Alocação dinâmica

    for (int i = 0; i < tamanho_vet; i++){
        printf("Digite um numero: ");
        scanf("%d", &vet[i]);
    }
    resultado = pares(tamanho_vet, vet);
    printf("Qtd numeros pares: %d", resultado);
}

int pares(int n, int* vet){
    int contador = 0;
    for(int i = 0; i < n; i++){ //Vai pecorrer o vetor
        if(vet[i] % 2 == 0){ //Quando o número for par
            contador++;
        }
    }
    return contador;
}