#include <stdio.h>
#include <stdlib.h>

/*Função que receba como parâmetro um vetor de números inteiros(vet) de tamanho n e inverta a ordem dos elementos armazenados nesse vetor*/

void inverte(int n, int* vet);

int main(){
    int tamanho_vet;
    int* vet;

    printf("Tamanho para o vetor: ");
    scanf("%d", &tamanho_vet);

    vet = (int*) malloc(tamanho_vet*sizeof(int)); //Alocação dinâmica

    for (int i = 0; i < tamanho_vet; i++){
        printf("Digite um numero: ");
        scanf("%d", &vet[i]);
    }

    printf("Vetor normal: \n");
    for (int i = 0; i < tamanho_vet; i++){
        printf("%d ", vet[i]);
    }
    
    inverte(tamanho_vet, vet);
    printf("\nVetor invertido: \n");
    for (int i = 0; i < tamanho_vet; i++){
        printf("%d ", vet[i]);
    }

    // Liberação de memória alocada
    free(vet);

    return 0;
}

void inverte(int n, int* vet){
    int aux;
    for (int i = 0; i < n / 2; i++){ //Como vai inverter só precisa pecorrer metade, já que a outra metade já vai ser modificada
        aux =  vet[i]; //Vai guardar o valor para a troca
        vet[i] = vet[n - i - 1]; //Aqui ele vai receber o valor da posição certa na frente por isso n(tamanho do vetor) - i(indice atual) - 1(pois o vetor começa de 0)
        vet[n - i - 1] = aux;
    }

}