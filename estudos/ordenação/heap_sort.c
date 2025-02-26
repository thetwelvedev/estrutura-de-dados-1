#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int vet[], int n, int i) {
    int maior = i;          // Inicializa o maior como a raiz
    int esquerda = 2 * i + 1; // Filho da esquerda
    int direita = 2 * i + 2;  // Filho da direita

    if (esquerda < n && vet[esquerda] > vet[maior]) // Se o filho da esquerda for maior que a raiz
        maior = esquerda;
    if (direita < n && vet[direita] > vet[maior])// Se o filho da direita for maior que o maior atual
        maior = direita;
    if (maior != i) { // Se o maior não for a raiz
        trocar(&vet[i], &vet[maior]);
        heapify(vet, n, maior); // Recursivamente ajusta o heap
    }
}
void heapSort(int vet[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) // Constrói um Heap Máximo
        heapify(vet, n, i);
    for (int i = n - 1; i > 0; i--) {  // Extrai elementos do heap um por um
        trocar(&vet[0], &vet[i]); // Move a raiz para o final
        heapify(vet, i, 0); // Chama heapify na árvore reduzida
    }
}

// Função para imprimir o vetor
void imprimirVetor(int vet[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", vet[i]);
    printf("\n");
}

// Função principal
int main() {
    int vet[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(vet) / sizeof(vet[0]);

    printf("Vetor original: ");
    imprimirVetor(vet, n);

    heapSort(vet, n);

    printf("Vetor ordenado: ");
    imprimirVetor(vet, n);

    return 0;
}
