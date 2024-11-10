#include <stdio.h>
#include <math.h>

/*Função que calcule as raízes de uma equação do segundo grau, do tipo ax^2+bx+c = 0.
Tem retornar o número de raízes reais e distintas 
*/

int raizes(float a, float b, float c, float* x1, float* x2);

int main(){
    float n1, n2, n3, raiz1 = 0, raiz2 = 0;
    int resultado;

    printf("Equacao de segundo grau -> ax^2+bx+c = 0\n");
    printf("Digite o valor de 'a': ");
    scanf("%f", &n1);
    printf("Digite o valor de 'b': ");
    scanf("%f", &n2);
    printf("Digite o valor de 'c': ");
    scanf("%f", &n3);
    
    resultado = raizes(n1, n2, n3, &raiz1, &raiz2);

    printf("Numero de raizes: %d raiz 1: %.1f e raiz 2: %.1f\n",resultado, raiz1, raiz2);

    return 0;
}

int raizes(float a, float b, float c, float* x1, float* x2){
    float delta, r1, r2;

    //Calcular o delta para determinar o número de raízes
    delta = pow(b,2) - 4*a*c;

    if(delta > 0){
        //Calcular o valor das raízes
        r1 = (-b + sqrt(delta))/(2*a);
        r2 = (-b - sqrt(delta))/(2*a);

        //Vai armazenar o valor nas variáveis apontadas
        *x1 = r1;
        *x2 = r2;
        return 2;
    } else if(delta == 0){//A equação tem duas raízes iguais
        //Calcular o valor da raíz real e igual, como delta = 0, tiro o delta do cálculo
        r1 = (-b)/(2*a);

        *x1 = *x2 = r1; //Vai armazenar o valor nas variáveis apontadas
        return 1;
    } else { //delta < 0 - A equação não tem raízes reais 
        return 0;
    }
}