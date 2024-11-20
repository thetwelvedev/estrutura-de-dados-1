#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char* nome;

    int tamanho;

    printf("Digite o tamanho do seu nome: ");
    scanf("%d", &tamanho);
    getchar();// Para consumir o '\n' deixado pelo scanf

    //+1 para armazenar o "/0"
    nome = (char*) malloc((tamanho+1) * sizeof(char));

    printf("Digite seu nome: ");
    fgets(nome, tamanho+1, stdin);

    for(int i = 0; i < 4; i++){
        printf("%c", nome[i]);
    }

    free(nome);

    return 0;    
}