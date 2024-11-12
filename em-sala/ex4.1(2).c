#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool matrizQuadradaVetorSimples(int m, int n, float** mat);
bool matrizQuadradaVetorDePonteiros(int m, int n, float*** mat);

int main(){
    float *mat1 = NULL; 
    float **mat2 = NULL;
    int m, n;

    printf("Digite o numero de linhas: ");
    scanf("%d", &m);
    printf("Digite o numero de colunas: ");
    scanf("%d", &n);

    if(matrizQuadradaVetorSimples(m, n, &mat1) == true){
        printf("Essa matriz e simetrica quadrada\n");
    } else{
        printf("Essa matriz nao e simetrica quadrada\n");
    }

    if(matrizQuadradaVetorDePonteiros(m, n, &mat2) == true){
        printf("Essa matriz e simetrica quadrada\n");
    } else{
        printf("Essa matriz nao e simetrica quadrada\n");
    }

    // Liberar memória alocada em matriz de vetor simples
    free(mat1);
    
    // Liberar memória alocada em matriz de ponteiros
    for (int i = 0; i < m; i++) {
        free(mat2[i]);
    }
    free(mat2);

    return 0;
}

bool matrizQuadradaVetorSimples(int m, int n, float** mat){
    *mat = (float*) malloc(m*n*sizeof(float)); // Alocação dinâmica
    // Acionar elementos a matriz
    for(int i = 0; i < m; i++){ //linha
        for(int j = 0; j < n; j++){ //Coluna
            printf("Digite o valor na posicao [%d][%d] : ", i+1, j+1);
            scanf("%f", &(*mat)[i*n+j]);
        }
    }
    if(m == n){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++){
                if ((*mat)[i*n+j] != (*mat)[j*n+i]) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool matrizQuadradaVetorDePonteiros(int m, int n, float*** mat){
    *mat = (float**) malloc(m*sizeof(float*)); // Alocação dinâmica
    for(int i = 0; i < m; i++){
        (*mat)[i] = (float*) malloc(m*sizeof(float));
    }
    // Acionar elementos a matriz
    for(int i = 0; i < m; i++){ //linha
        for(int j = 0; j < n; j++){ //Coluna
            printf("Digite o valor na posicao [%d][%d] : ", i+1, j+1);
            scanf("%f", &(*mat)[i][j]);
        }
    }
    if(m == n){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++){
                if ((*mat)[i][j] != (*mat)[j][i]) {
                    return false;
                }
            }
        }
    }
    return true;
}
