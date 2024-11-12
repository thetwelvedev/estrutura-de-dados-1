#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Implemente duas versões de uma função, seguindo as diferentes estratégias discutidas para alocar matrizes, 
que determine se uma matriz é simétrica quadrada ou não*/

bool matrizQuadradaVetorSimples(int m, int n, float* mat);
bool matrizQuadradaVetorDePonteiros(int m, int n, float** mat);

int main(){
    float *mat1 = NULL; //Tive que fazer pois dava o erro "'mat1' is used uninitialized in this function [-Wuninitialized]"
    float **mat2 = NULL;
    int m, n;

    printf("Digite o numero de linhas: ");
    scanf("%d", &m);
    printf("Digite o numero de colunas: ");
    scanf("%d", &n);

    if(matrizQuadradaVetorSimples(m, n, mat1) == true){
        printf("Essa matriz e simetrica quadrada");
    } else{
        printf("Essa matriz nao e simetrica quadrada");
    }
    printf("\n");
    if(matrizQuadradaVetorDePonteiros(m, n, mat2) == true){
        printf("Essa matriz e simetrica quadrada");
    } else{
        printf("Essa matriz nao e simetrica quadrada");
    }

    // Liberar memória alocada em matriz de ponteiros
    free(mat1);
    for (int i = 0; i < m; i++) {
            free(mat2[i]);
        }
        free(mat2);

    return 0;
}

bool matrizQuadradaVetorSimples(int m, int n, float* mat){
    mat = (float*) malloc(m*n*sizeof(float));//Alocação dinâmica
    //Acionar elementos a matriz
    for(int i = 0; i < m; i++){//linha
        for(int j = 0; j < n; j++){//Coluna
            printf("Digite o valor na posicao [%d][%d] : ", i+1, j+1);
            scanf("%f", &mat[i*n+j]);
        }
    }
    if(m == n){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {/*Coluna - *Esse loop limita j a pecorrer apenas elementos antes da linha atual de i.  
        Isso significa que ele começa de 0 e vai até i-1. Dessa forma, percorremos apenas uma metade da matriz*/
                if (mat[i*n+j] != mat[j*n+i]) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool matrizQuadradaVetorDePonteiros(int m, int n, float** mat){
    mat = (float**) malloc(m*sizeof(float*)); //Alocação dinâmica
    for(int i = 0; i < m; i++){
        mat[i] = (float*) malloc(m*sizeof(float));
    }
    //Acionar elementos a matriz
    for(int i = 0; i < m; i++){//linha
        for(int j = 0; j < n; j++){//Coluna
            printf("Digite o valor na posicao [%d][%d] : ", i+1, j+1);
            scanf("%f", &mat[i][j]);
        }
    }
    if(m == n){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {/*Coluna - *Esse loop limita j a pecorrer apenas elementos antes da linha atual de i.  
        Isso significa que ele começa de 0 e vai até i-1. Dessa forma, percorremos apenas uma metade da matriz*/
                if (mat[i][j] != mat[j][i]) {
                    return false;
                }
            }
        }
    }
    return true;
}
