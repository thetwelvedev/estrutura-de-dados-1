#include <stdio.h>

void selection_sort(int* vet, int tam){
    int min_idx;
    
    for (int i = 0; i < tam - 1; i++) {
        // Encontra o menor elemento na sublista não ordenada
        min_idx = i;
        for (int j = i + 1; j < tam; j++) {
            if (vet[j] < vet[min_idx]) {
                min_idx = j;
            }
        }
        // Troca o menor elemento com o primeiro elemento não ordenado
        if (min_idx != i) {
            int temp = vet[i];
            vet[i] = vet[min_idx];
            vet[min_idx] = temp;
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
    
    selectionSort(vet, tam);
    
    printf("Vetor ordenado:\n");
    imprimirVetor(vet, tam);
    
    return 0;
}