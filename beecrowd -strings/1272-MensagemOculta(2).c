#include <stdio.h>
#include <string.h>

void mensagemOculta(char* msg){
        int index = 0; //Tem que ter um index separado para resposta pois eles só vai adicionar as primeiras letras
        int identificaPrimeiraLetra = 1;
        char msgOculta[51];
        int tamanho = 0;
        for(int i = 0; msg[i] != '\0'; i++){ //Pega o tamanho da string até chegar no '\0'
            tamanho++;
        }
        for(int i = 0; i < tamanho; i++){
            if(identificaPrimeiraLetra && msg[i] != ' '){ //Uma variável para representar se é a primeira letra e não é um espaço vazio
                msgOculta[index] = msg[i];
                index++;
                identificaPrimeiraLetra = 0; //Isso informa que atualmente não está mais na primeira letra e serve para não pegar as letras internas
            }
            else if(!identificaPrimeiraLetra &&msg[i] == ' '){ //Se tiver num espaço reativa o identificaPrimeiraLetra
                identificaPrimeiraLetra = 1;
            }
        }
        msgOculta[index] = '\0'; //simboliza o termino da string
        printf("%s\n", msgOculta);
}
 
int main() {
    int N;
    char palavra[51];

    scanf("%d\n", &N);
    
    for(int i = 0; i < N; i++){
        fgets(palavra, 51, stdin);
        palavra[strcspn(palavra, "\n")] = '\0'; // Remove o '\n' no final da string
        mensagemOculta(palavra);
    }
 
    return 0;
}