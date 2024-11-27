#include <stdio.h>

int tamanho(char* frase){
    int c = 0;
    for(int i = 0; frase[i] != '\0'; i++){
        c++;
    }
    return c;
}

void salvar(char* maior, char* palavra){
    int i;
    for(i = 0; palavra[i] != '\0' && palavra[i] != ' '; i++){
        maior[i] = palavra[i];
    }
    maior[i] = '\0';
}

//Conta a quantidade de letras em cada palavra.
void contarLetras(char* frase, char* maiorPalv){
    int c  = 0;
    for(int i = 0; frase[i] != '\0'; i++){
        if(frase[i] == ' ' && frase[i+1] != '\0'){
            printf("%d-", c);
            if(c >= tamanho(maiorPalv)){//Verifica se a palavra atual é maior que a palavra guardada em maior
                salvar(maiorPalv, &frase[i-c]);
            }
            c = 0;
        }else if(frase[i+1] == '\0'){
            c++;
            printf("%d\n", c);
            if(c >= tamanho(maiorPalv)){//Verifica se a palavra atual é maior que a palavra guardada em maior
                salvar(maiorPalv, &frase[i-c+1]);
            }
            c = 0;
        }else{
            c++;
        }
    }
}

int main() {
    char frase[101], maior[101] = {'\0'};
    while (scanf(" %100[^\n]",frase), frase[0] != '0'){
        contarLetras(frase, maior);
    }
    printf("\nThe biggest word: %s\n", maior);
    return 0;
}