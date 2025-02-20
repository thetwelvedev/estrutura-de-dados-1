#include <stdio.h>

int busca_sequencial(int tam, int* vet, int elem){
    for(int i = 0; i < tam; i++){
        if(elem == vet[i]){
            return i;
        }
    }
    return -1;

}

int main(){
    int vetor[] = {1, 7, 13, 24, 35};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]); 

    int resultado = busca_sequencial(tamanho, vetor, 35);

    printf("A posicao do elemento e %d\n", resultado);

    return 0;
}