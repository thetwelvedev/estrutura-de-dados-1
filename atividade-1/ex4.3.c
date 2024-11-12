#include <stdio.h>
#include <stdlib.h>

/*Implemente um TAD, minimizando o espaço de memória utilizando, para representar uma matriz triangular superior. Em uma matriz triangular superior, 
todos os elementos abaixo da diagonal têm valor zero*/

float** criaMatrizTriangularSuperior(int n);

int main(){
    float** matrizTriangular; // Sendo mat[i][j] para matriz diagonal superior i <= j vai ter elemento não nulo
    int n;

    printf("Informe a dimensao da Matriz Quadrada: ");
    scanf("%d", &n);

    matrizTriangular = criaMatrizTriangularSuperior(n); //Aqui armazenamos a matriz retornada na função na matriz que foi definida na main

    //Preenchendo a matriz com 1
     for(int i = 0; i < n; i++) { // Linha
        for(int j = i; j < n; j++) { /*Coluna - Aqui igual j = i, pois no primeiro laço vai de 0 a 2, no segundo 1 a 2, no terceiro só 2, acessando assim só a diagonal principal*/
            matrizTriangular[i][j] = 1;
        }
    }

    //Printando a matriz triangular superior
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) { 
            if(i > j){
                printf(" 0.0 "); //A parte nula da matriz
            } else {
                printf(" %.1f ", matrizTriangular[i][j]);
            }
        }
        printf("\n");
    }

    //Liberação de memória alocada
    for(int i = 0; i < n; i++)
        free(matrizTriangular[i]);
    free(matrizTriangular);

    return 0;

}

float** criaMatrizTriangularSuperior(int n){
    float** matTriSup =  (float**) malloc(n*sizeof(float*));
    for(int i =0; i < n; i++){
        matTriSup[i] =  (float*) malloc((n-i)*sizeof(float));//n-i pois tem que ir de forma decrescente
        /*Se for uma matriz 3X3
        Na linha 0, ela aloca espaço para 3 elemento.
        Na linha 1, ela aloca espaço para 2 elementos.
        Na linha 2, ela aloca espaço para 1 elemento*/
    }
    return matTriSup;

}