#include <stdio.h>

void bubble_Sort(int vet[], int tam) {
    int i, j, temp;
    int trocado;

    // Percorre o array
    for (i = 0; i < tam - 1; i++) {
        trocado = 0; // Flag para saber se houve troca 

        for (j = 0; j < tam - i - 1; j++) { //Diminui a comparação a cada iteração
            if (vet[j] > vet[j + 1]) { // Compara elementos adjacentes
                // Troca os elementos
                temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
                trocado = 1; // Vai informar que houve troca
            }
        }
        if (trocado == 0) //0 trocas significa que está ordenado
            break;
    }
}

// Função para imprimir um array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função principal
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array antes da ordenação: ");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Array depois da ordenação: ");
    printArray(arr, n);

    return 0;
}
