#include <stdio.h>
#include <string.h>

void imprimir_arvore(int N){
    //Parte das folhas da árvore
    for (int i = 1; i <= N; i += 2) { //O i só assume valor impar, pois começa dp 1 e soma +2 toda iteração
        int espacos = (N - i ) / 2; /*N = número de astericos, i = valor a ser diminuido pois tanto mais asterisco menos espaço necessario e 
        divide por 2 pois foi observado que a divisão inteira da sua linha equidistante é quantidade de espaço necessária
        ex.: entrada: 7 -> *(1) é equidistante de *******(2) e ***(3) é de *****(5)*/
        //os espaços
        for (int j = 1; j <= espacos; j++){ // Coloca os espaços necessários como foi dito na explicação acima
            printf(" ");
        }
        //Os asteriscos
        for (int j = 1; j <= i; j++){ // i é o parametro pois ele vai a quantidade de astericos por linha.
            printf("*");
        }
        printf("\n");
    }
    //Base da árvore
    for (int i = 1; i <= 3; i += 2) { // i vai assumir 1 e 3.
        int espacoBase = (N - i ) / 2; //Mantém a mesma lógica pois a base tem alinhar com a árvore, então leva como base também os asteriscos da árvore
        for (int j = 1; j <= espacoBase; j++){
            printf(" ");
        }
        for (int j = 1; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int N;

    // Lê os casos de teste até EOF
    while (scanf("%d", &N) != EOF) {
        imprimir_arvore(N);
        printf("\n");  // Linha em branco após cada árvore
    }

    return 0;
}