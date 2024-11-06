#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int vetor[5321];
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int colisoes, valorRandom;

    //Inicializa o vetor com valores -1, indicando que as posições estão vazias
    for (int i = 0; i < tamanho; i++){
        vetor[i] = -1;
    }
    
    colisoes = 0; 
    srand((unsigned) time(NULL)); //Semente para geração de números aleatórios
    

    for(int i = 0; i < 2000; i++){
        valorRandom = rand() % 1000000 + 1; //números aleatórios no intervalo de 1 a 10^6
        
        // Verifica se a posição no vetor já está ocupada (colisão)
        if(vetor[valorRandom % tamanho] != -1){
            colisoes++;
        }
        
        // Armazena o número aleatório na posição calculada -> inserções
        vetor[valorRandom % tamanho] = valorRandom;
    }
    printf("Numero de colisoes: %d\n", colisoes);
    
    return 0;
}