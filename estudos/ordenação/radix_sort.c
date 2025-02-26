#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Base decimal

int getMax(int vet[], int n) {
    int max = vet[0];
    for (int i = 1; i < n; i++) {
        if (vet[i] > max)
            max = vet[i];
    }
    return max;
}

void countingSort(int vet[], int n, int exp) {
    int output[n]; // Vetor de saída
    int count[MAX] = {0}; // Contagem dos dígitos de 0 a 9

    for (int i = 0; i < n; i++) // Conta as ocorrências de cada dígito
        count[(vet[i] / exp) % 10]++;

    for (int i = 1; i < MAX; i++) // Atualiza count[i] para armazenar a posição correta de cada dígito
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {  // Constrói o vetor de saída
        output[count[(vet[i] / exp) % 10] - 1] = vet[i];
        count[(vet[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) // Copia o vetor ordenado para vet[]
        vet[i] = output[i];
}

void radixSort(int vet[], int n) { // Função principal do Radix Sort
    int max = getMax(vet, n); // Obtém o maior número para definir o número de dígitos
    for (int exp = 1; max / exp > 0; exp *= 10) // Aplica Counting Sort para cada dígito, começando do menos significativo
        countingSort(vet, n, exp);
}

// Função para imprimir o vetor
void printArray(int vet[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", vet[i]);
    printf("\n");
}

// Programa principal
int main() {
    int vet[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(vet) / sizeof(vet[0]);

    printf("Vetor original:\n");
    printArray(vet, n);

    radixSort(vet, n);

    printf("Vetor ordenado:\n");
    printArray(vet, n);

    return 0;
}
