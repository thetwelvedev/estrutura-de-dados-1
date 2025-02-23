#include <stdio.h>

void selection_sort(int* vet, int tam){
    int min_index;
    for(int i = 0; i < tam - 1; i++){
        min_index = i; //Aqui fica o atual indice do elemento de comparação do array
        for(int j = i + 1; j < tam - 1; j++){
            if(vet[j] < vet[min_index]){
                min_index = j; //Aqui captura o menor indice através da comparação do menor valor
            }
        }
        if(min_index != i){//Aqui se indece atual for diferente do menor indice ele troca de posição os elementos
            int temp = vet[i];
            vet[i] = vet[min_index];
            vet[min_index] = temp;
        }
    }    
}


// Função para imprimir o vetor
void imprimirVetor(int vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main() {
    int vet[] = {64, 25, 12, 22, 11};
    int tam = sizeof(vet) / sizeof(vet[0]);
    
    printf("Vetor original:\n");
    imprimirVetor(vet, tam);
    
    selection_sort(vet, tam);
    
    printf("Vetor ordenado:\n");
    imprimirVetor(vet, tam);
    
    return 0;
}