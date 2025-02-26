#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* vet, int low, int high) {
    int pivot = vet[high];
    int i = (low - 1);  
    // Coloca todos os elementos menores que o pivô à esquerda
    for (int j = low; j < high; j++) {
        if (vet[j] < pivot) {
            i++;    // incrementa o índice do menor elemento
            swap(&vet[i], &vet[j]);
        }
    }
    swap(&vet[i + 1], &vet[high]); // Coloca o pivô no lugar correto
    return (i + 1);  // Retorna o índice do pivô
}

void quick_sort(int vet[], int low, int high) {
    if (low < high) {
        // Encontra o ponto de partição (índice do pivô)
        int pi = partition(vet, low, high);
        quick_sort(vet, low, pi - 1);  // Sublista à esquerda do pivô
        quick_sort(vet, pi + 1, high); // Sublista à direita do pivô
    }
}

// Função para imprimir o array
void printArray(int vet[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main() {
    int vet[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(vet) / sizeof(vet[0]);

    printf("Array original: ");
    printArray(vet, n);

    // Chama a função Quick Sort
    quickSort(vet, 0, n - 1);

    printf("Array ordenado: ");
    printArray(vet, n);

    return 0;
}