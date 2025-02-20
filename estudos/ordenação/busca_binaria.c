#include <stdio.h>

int busca_binaria(int tam, int* vet, int elem){
    int ini = 0;
    int meio;
    int fim = tam -1;

    while (ini <= fim){
        meio = (ini + fim) / 2;
        if(elem > vet[meio]){
            ini = meio + 1;
        }
        else if(elem < vet[meio]){
            fim = meio - 1;
        }
        else {
            return meio;
        }
    }
    return -1;
}

int main(){
    int vetor[] = {1, 7, 13, 24, 35};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]); 

    int resultado = busca_binaria(tamanho, vetor, 24);

    printf("A posicao do elemento e %d\n", resultado);

    return 0;
}