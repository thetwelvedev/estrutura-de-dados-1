#include <stdio.h>
#include <stdlib.h>

/*Implemente um TAD, minimizando o espaço de memória utilizando, para representar uma matriz triangular inferior. Nesse tipo de matriz, todos os elementos
acima da diagonal têm valor zero*/

float** criaMatrizTriangularInferior(int n);

int main(){
    float** matrizTriangular; // Sendo mat[i][j] para matriz diagonal inferior i >=j vai ter elemento não nulo
    int n;

    printf("Informe a dimensao da Matriz Quadrada: ");
    scanf("%d", &n);

    matrizTriangular = criaMatrizTriangularInferior(n); //Aqui armazenamos a matriz retornada na função na matriz que foi definida na main

    //Preenchendo a matriz com 1
    for(int i = 0; i < n; i++) { // Linha
        for(int j = 0; j <= i; j++) { /*Coluna - quando for a linha 0 só vai colocar 1(j vai ser só 0) elemento, quando for linha 1 vai colocar 2(j vai ser 0 e 1) elementos e assim sucessivamente*/
            matrizTriangular[i][j] = 1;
        }
    }

    //Printando a matriz triangular inferior
    printf("Matriz Triangular Inferior\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) { 
            if(i < j){
                printf(" 0.0 "); //A parte nula da matriz
            } else {
                printf(" %.1f ", matrizTriangular[i][j]);
            }
        }
        printf("\n");
    }

    //Liberação de memória alocada
    for(int i = 0; i < n; i++){
        free(matrizTriangular[i]);
    }
    free(matrizTriangular);

    return 0;
}

//Apenas os elementos da diagonal principal e os elementos abaixo dela são alocados.
float** criaMatrizTriangularInferior(int n){
    float** matTriInf =  (float**) malloc(n*sizeof(float*));
    for(int i =0; i < n; i++){
        matTriInf[i] =  (float*) malloc((i+1)*sizeof(float));
        /*Se for uma matriz 3X3
        Na linha 0, ela aloca espaço para 1 elemento.
        Na linha 1, ela aloca espaço para 2 elementos.
        Na linha 2, ela aloca espaço para 3 elemento*/
    }
    return matTriInf;
}
