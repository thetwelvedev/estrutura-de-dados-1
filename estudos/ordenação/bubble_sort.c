#include <stdio.h>

void bubble_sort(int* vet, int tam) {
    int temp, troca;

    for(int i = 0; i < tam - 1; i++){
        troca = 0; //Antes de cada iteração é resetado a troca
        for(int j = 0; j < tam - 1 - i; j++){ //Como cada iteração o elemento maior vai para o final adicona o -i
            if(vet[j] > vet[j+1]){
                temp = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = temp;
                troca++;
            }
        }
        if(troca == 0){
            break;
        }
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

    printf("Array antes da ordenacao: ");
    printArray(arr, n);

    bubble_sort(arr, n);

    printf("Array depois da ordenacao: ");
    printArray(arr, n);

    return 0;
}
