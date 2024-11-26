#include <stdio.h>

void retira_zero(int M, int N, char *resposta) {
    int soma = M + N;
    int n = 0;
    char aux;

    // Limpa o buffer de resposta manualmente
    for (int i = 0; i < 11; i++) {
        resposta[i] = '\0';
    }

    while (soma) {
        if (soma % 10) //Verifica o se o último digito é zero, se não for ele o if é ativado
            resposta[n] = (soma % 10) + '0'; //Armazena no array -> essa soma tranforma o o número em string
            n++;
        soma /= 10; //Descarta o último digito
    }//como ele armazena de traz pra frente a string fica invertida

    // Inverte a string para obter o número correto
    for (int i = 0; i < n / 2; ++i) {
        aux = resposta[i];
        resposta[i] = resposta[n - i - 1];
        resposta[n - i - 1] = aux;
    }
}

int main() {
    int M, N;
    char resposta[11];

    while (scanf("%d %d", &M, &N)) {
        if (!M && !N) 
            break;

        retira_zero(M, N, resposta);
        printf("%s\n", resposta);
    }

    return 0;
}