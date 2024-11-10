#include <stdio.h>

//vértice inferior esquerdo(x0,y0)
//vértice superio direito(x1,y1)
//return 1 se o ponto estiver dentro do retângulo e 0 se não

int dentro_ret(int x0, int y0, int x1, int y1, int x, int y);

int main(){
    int x, y, x0 = 0, y0 = 0 , x1 = 2, y1 = 2;
    x = 1 , y = 1;
    printf("Dentro: %d\n", dentro_ret(x0, y0, x1, y1, x, y)); // Dentro do triângulo - saída 1
    x = 3 , y = 3;
    printf("Fora: %d\n", dentro_ret(x0, y0, x1, y1, x, y)); // Fora do triângulo - saída 0
}

int dentro_ret(int x0, int y0, int x1, int y1, int x, int y){
    if((x >= x0 && x <= x1) &&(y >= y0 && y <= y1)){ //Essa condição faz sempre o valores x e y que representam um ponto estejavam dentro do intervalo do retângulo
        return 1;
    } else {
        return 0;
    }
}