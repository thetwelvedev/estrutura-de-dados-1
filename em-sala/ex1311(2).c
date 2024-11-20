#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tamanhoString(char* nome){
    int contador = 0;
    for(int  i = 0; nome[i] != '\0' && nome[i] != '\n'; i++){ //Se uma condição for falsa o loop para, se o valor for '\0' ou '\n'
        contador++; //Vai acrescentando até chegar no final da string
    }
    return contador;
}

int main(){
    char nome[20];

    printf("Digite seu nome: ");
    fgets(nome, 20, stdin); //Insere automaticamente o \0

    printf("Tem %d letras", (tamanhoString(nome))); //nome funciona como um ponteiro para o seu primeiro elemento logo não precisa do &

    return 0;    
}