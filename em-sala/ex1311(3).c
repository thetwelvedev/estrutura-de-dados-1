#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lerNomeIdade(char** nomes, int* idades){
    char* nomeMaisVelho = NULL;  // Modificado para ponteiro de char pois é uma string, pois dentro de cada linha da matriz nomes tem uma string de 20 caracteres
    int idadeMaisVelho = 0;
    for(int i = 0; i < 5; i++){
        printf("Digite seu nome: ");
        fgets(nomes[i], 20, stdin);
        fflush(stdin);
        nomes[i][strcspn(nomes[i], "\n")] = 0;

        printf("Digite sua idade: ");
        scanf("%d", &idades[i]);
        fflush(stdin);

        if (nomeMaisVelho == NULL && idadeMaisVelho == 0){ //Vai colocar a primeira pessoa para comparar
            nomeMaisVelho = nomes[i];
            idadeMaisVelho = idades[i];
        }
        else{
            if(idadeMaisVelho < idades[i]){ //Vai ver que é mais velho
                nomeMaisVelho = nomes[i];
                idadeMaisVelho = idades[i];
            }
        }
    }
    printf("Pessoa mais velha: %s Idade: %d", nomeMaisVelho, idadeMaisVelho);
}

int main(){
    char** nomes;
    int* idades;

    nomes = (char**)malloc(5 * sizeof(char*));
    for(int i = 0; i < 5; i++) {
        nomes[i] = (char*)malloc(20 * sizeof(char));
    }

    idades = (int*) malloc(5 * sizeof(int));

    lerNomeIdade(nomes, idades);

    // Liberação de memória
    for(int i = 0; i < 5; i++) {
        free(nomes[i]);
    }
    free(nomes);
    free(idades); 

    return 0;    
}