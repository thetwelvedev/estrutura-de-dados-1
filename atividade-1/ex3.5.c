#include <stdio.h>
#include <stdlib.h>

/*Função que calcula a derivada de um polinômio. Cada polinômio é representado como exemplificado no exercício anterior.
onde out é o vetor, de dimensão grau-1, no qual a função deve guardar os coeficientes do polinômio resultante da derivada.*/

void deriva(double* poli, int grau, double* out);

int main(){
    double* poli;
    double* out;
    int grau;

    printf("Digite o grau do polinomio: ");
    scanf("%d", &grau);

    poli = (double*) malloc((grau + 1) *sizeof(double)); //Alocação dinâmica

    for(int i = 0; i <= grau; i++){//vai pecorrer do x^0 até x^grau
        printf("Digite o valor do coefinete de x^%d: ", i);
        scanf("%lf", &poli[i]); // Usar %lf para double
    }

    printf("\nCoefientes do polinomio:\n");
    for(int i = 0; i <= grau; i++){
        printf("%.1f ", poli[i]);
    }

    out = (double*) malloc(grau * sizeof(double)); //Alocação dinâmica
    deriva(poli , grau, out);

    printf("\nCoefientes da derivada:\n");
    for(int i = 0; i < grau; i++){
        printf("%.1f ", out[i]);
    }
    
    // Liberação de memória alocada
    free(poli);
    free(out);

    return 0;

}

void deriva(double* poli, int grau, double* out) {
    // A derivada de um polinômio de grau n tem grau n-1
    for (int i = 1; i <= grau; i++) {
        out[i - 1] = poli[i] * i; // Derivada do termo de grau i é i * coeficiente
    }
}