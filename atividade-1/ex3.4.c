#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Função que permita a avaliação de polinômios. Cada polinômio é definido por um vetor que contém seus coefientes. Por exemplo, o 
polinômio de grau 2, 3x²+2x+12, terá um vetor de coefientes igual a v[]={12,2,3}*/

double avalia (double* poli, int grau, double x);

int main(){
    double* poli;
    int grau;
    double x, resultado;

    printf("Digite o grau do polinomio: ");
    scanf("%d", &grau);

    poli = (double*) malloc(grau*sizeof(double)); //Alocação dinâmica

    for(int i = 0; i <= grau; i++){//vai pecorrer do x^0 até x^grau
        printf("Digite o valor do coefinete de x^%d: ", i);
        scanf("%lf", &poli[i]); // Usar %lf para double
    }
    printf("Digite um valor para X: ");
    scanf("%lf", &x);

    resultado = avalia(poli , grau, x);
    printf("P(x) = %.2f", resultado);

    // Liberação de memória alocada
    free(poli);

    return 0;
}

double avalia (double* poli, int grau, double x){
    double px;
    for(int i = 0; i <= grau; i++){//vai pecorrer do x^0 até x^grau
        px += poli[i] * pow(x,i); //Fórmula p(x) = c0 + c1*x + c2*x^2 + ... + cn*x^n
    }
    return px;
}