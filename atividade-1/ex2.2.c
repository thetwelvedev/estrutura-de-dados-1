#include <stdio.h>
#include <math.h>

/*Função que calcule a área da superfície e o volume de uma esfera de raio r.
A área da superfície e o volume são dados, respectivamente, por 4πr² e 4/3πr³.
*/
#define PI 3.1415926535 //passando pi como contante

void calc_esfera(float r, float* area, float* volume);

int main(){
    float r, area = 0, volume = 0; //Tem que inicializar as variáveis que vou passar o endereço de memória

    printf("Digite o raio da esfera: ");
    scanf("%f", &r);

    calc_esfera(r, &area, &volume);
    printf("Esfera de raio %.2f tem area da superficie: %.2f e volume: %.2f\n", r, area, volume);

    return 0;
}

void calc_esfera(float r, float* area, float* volume){
    *area = 4.0 * PI * pow(r,2); //Vai colocar o valor nessa váriavel que foi apontada
    *volume = (4.0/3.0) * PI * pow(r,3);
}