#include <stdio.h>
#include <math.h>

/*Função que retorne a aproximação do valor de p, de acordo com a fórmula de Leibniz: pi = 4*(1-1/3+1/5-1/7+1/9-1/11...)
*/

double pi(int n);

int main(){
    int number;
    double resultado;

    printf("Digite o numero de termos: ");
    scanf("%d", &number);
    
    resultado = pi(number);

    printf("Numero de termos %d: pi aproximado: %f\n", number, resultado);

    return 0;
}

double pi(int n){
    double E = 0.0;
    for(int i = 0; i < n; i++){
        E += (pow(-1,i))/(2*i+1);
    }
    return 4*E;
}