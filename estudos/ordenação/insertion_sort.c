#include <stdio.h>

void insertion_sort(int* vet, int tam) {
    for (int i = 1; i < tam; i++) {
        int chave = vet[i];  // O elemento a ser inserido na parte ordenada
        int j = i - 1;
        // uma posição à frente para abrir espaço para a chave
        while (j >= 0 && vet[j] > chave) {
            vet[j + 1] = vet[j];
            j--;
        }
        // Coloca a chave na posição correta
        vet[j + 1] = chave;
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
    int vet[] = {75, 38, 7, 12, 101};
    int tam = sizeof(vet) / sizeof(vet[0]);
    
    printf("Vetor original:\n");
    imprimirVetor(vet, tam);
    
    insertion_sort(vet, tam);
    
    printf("Vetor ordenado:\n");
    imprimirVetor(vet, tam);
    
    return 0;
}
