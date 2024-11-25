#include <stdio.h>
#include <string.h>

void nomeIngles(char* nome){
    int tamanho = 0;
    for(int i = 0; nome[i] != '\0'; i++){ //Pega o tamanho da string até chegar no '\0'
        tamanho++;
    }
    if(tamanho == 5){
         printf("3\n");
    }
    else{
        char one[4] = {'o', 'n', 'e'};
        int mesmaLetra = 0;
        for(int i = 0; i < 3; i++){
            if(nome[i] == one[i]){ //Vai verificar se tem a mesma letra na posição correta
                mesmaLetra++;
            }
        }
        if(mesmaLetra > 1){ //Como a criança erra uma letra tem que ter duas letras certas
            printf("1\n");
        }
        else{ //Se não for o 1 e nem o 3, então é 2
                printf("2\n");
        }

    }
}

int main() {
    int N;
    char palavra[6]; //Um tamanho a mais para o '\0'

    scanf("%d\n", &N);
    
    for(int i = 0; i < N; i++){
        fgets(palavra, 6, stdin);
        palavra[strcspn(palavra, "\n")] = '\0'; // Remove o '\n' no final da string
        nomeIngles(palavra);
    }
 
    return 0;
}