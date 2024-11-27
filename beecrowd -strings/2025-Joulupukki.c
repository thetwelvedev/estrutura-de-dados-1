#include <stdio.h>
#include <string.h>

void corrigirNomeJoulupukki(char* linha) {
    // Para percorrer a linha e procurar "oulupukk"
    for (int i = 0; linha[i] != '\n' && linha[i] != '\0'; i++) {
        if (strncasecmp(&linha[i+1], "oulupukk", 8) == 0) { //Vai comparar a palavra depois da primeira letra como a primeira e última podem ser diferentes, vai ser só miolo mas a mudança vai ser a palavra inteira
            linha[i] = 'J';
            linha[i + 1] = 'o';
            linha[i + 2] = 'u';
            linha[i + 3] = 'l';
            linha[i + 4] = 'u';
            linha[i + 5] = 'p';
            linha[i + 6] = 'u';
            linha[i + 7] = 'k';
            linha[i + 8] = 'k';
            linha[i + 9] = 'i';
        }
    }
}

 
int main() {
    int N;
    char linha[101];

    scanf("%d\n", &N);

    for (int i = 0; i < N; i++) {
        scanf(" %101[^\n]", linha);
        
        corrigirNomeJoulupukki(linha);

        printf("%s\n", linha);
    }

    return 0;
}