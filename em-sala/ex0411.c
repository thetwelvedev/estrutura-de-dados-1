#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int vetor[5321];  // Declara um vetor de 5321 posições
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);  // Calcula o tamanho do vetor
    int colisoes, valorRandom;

    // Inicializa o vetor com valores -1, indicando que as posições estão vazias
    for (int i = 0; i < tamanho; i++){
        vetor[i] = -1;
    }
    
    colisoes = 0;  // Inicializa o contador de colisões
    srand((unsigned) time(NULL));  // Semente para geração de números aleatórios
    
    // Gera 2000 números aleatórios e tenta armazená-los no vetor
    for(int i = 0; i < 2000; i++){
        valorRandom = rand() % 1000000 + 1;  // Gera um número aleatório entre 1 e 1.000.000
        
        // Verifica se a posição no vetor já está ocupada (colisão)
        if(vetor[valorRandom % tamanho] != -1){
            colisoes++;  // Incrementa o contador de colisões
        }
        
        // Armazena o número aleatório na posição calculada
        vetor[valorRandom % tamanho] = valorRandom;
    }
    
    // Imprime o número total de colisões
    printf("Numero de colisoes: %d\n", colisoes);
    return 0;
}
