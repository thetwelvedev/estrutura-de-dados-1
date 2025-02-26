#include <stdio.h>

void merge(int vet[], int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = vet[esquerda + i];
    for (j = 0; j < n2; j++)
        R[j] = vet[meio + 1 + j];
    i = 0;  // Índice do primeiro subvetor
    j = 0;  // Índice do segundo subvetor
    k = esquerda; // Índice do vetor original
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vet[k] = L[i];
            i++;
        } else {
            vet[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {// Copia os elementos restantes de L[], se houver
        vet[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {// Copia os elementos restantes de R[], se houver
        vet[k] = R[j];
        j++;
        k++;
    }
}
void merge_sort(int vet[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        // Ordena a primeira e a segunda metade
        merge_sort(vet, esquerda, meio);
        merge_sort(vet, meio + 1, direita);
        // Mescla as duas metades ordenadas
        merge(vet, esquerda, meio, direita);
    }
}

// Função para imprimir o vetor
void printVet(int vet[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        printf("%d ", vet[i]);
    printf("\n");
}

// Programa principal para testar o Merge Sort
int main() {
    int vet[] = {12, 11, 13, 5, 6, 7};
    int tamanho = sizeof(vet) / sizeof(vet[0]);

    printf("Vetor original:\n");
    printVet(vet, tamanho);

    mergeSort(vet, 0, tamanho - 1);

    printf("Vetor ordenado:\n");
    printVet(vet, tamanho);

    return 0;
}
