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

    poli = (double*) malloc(grau*sizeof(double)); //Alocação dinâmica

    for(int i = 0; i <= grau; i++){//vai pecorrer do x^0 até x^grau
        printf("Digite o valor do coefinete de x^%d: ", i);
        scanf("%lf", &poli[i]); // Usar %lf para double
    }

    printf("\nCoefientes do polinomio:\n");
    for(int i = 0; i <= grau; i++){
        printf("%.1f ", poli[i]);
    }

    out = (double*) malloc((grau-1)*sizeof(double)); //Alocação dinâmica
    deriva(poli , grau, out);

    printf("\nCoefientes da derivada:\n");
    for(int i = 0; i <= (grau-1); i++){
        printf("%.1f ", out[i]);
    }
}

void deriva(double* poli, int grau, double* out){
    for(int i = 0; i <= grau; i++){
        out[i] = (i+1) * poli[i+1]; /*derivada =  n * ax^n-1, onde 'n' vai ser 'i+1' e 'a' vai ser poli[i+1], pois o poli[i] quando i for 0, vai ser o coefiente que 
        não tem variável ligada, logo quando derivar ele vai sumir então não vai ser armazenado no vetor out, isso serve também para i+1*/
    }
}