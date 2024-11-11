#include <stdio.h>
#include <stdlib.h>

/*Função que recebe como parâmetros um vetor de números reais(vet) de tamanho n e retorne quantos números negativos serão armazenados nesse vetor.*/

int negativos(int n, float* vet);

int main(){
    int resultado, tamanho_vet;
    float* vet;

    printf("Tamanho para o vetor: ");
    scanf("%d", &tamanho_vet);

    vet = (float*) malloc(tamanho_vet*sizeof(float)); //Alocação dinâmica

    for (int i = 0; i < tamanho_vet; i++){
        printf("Digite um numero: ");
        scanf("%f", &vet[i]);
    }
    resultado = negativos(tamanho_vet,vet);
    printf("Qtd numeros negativos: %d", resultado);

    // Liberação de memória alocada
    free(vet);

    return 0;

}

int negativos(int n, float* vet){
    int contador = 0;
    for(int i = 0; i < n; i++){ //Vai pecorrer o vetor
        if(vet[i] < 0){ //Quando o número for negativo
            contador++;
        }
    }
    return contador;
}