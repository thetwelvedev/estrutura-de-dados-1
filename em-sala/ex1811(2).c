#include <stdio.h>
#include <math.h>

typedef struct ponto {
    float x;
    float y;
} Ponto;

typedef struct circulo {
    Ponto p;
    float r;
} Circulo;



void lerCoordenadaOrigem(Circulo* circulo) {
    printf("Digite a coordenada x da origem: ");
    scanf("%f", &circulo->p.x); // Aqui eu acesso o Ponto p no struct circulo e lá o struct p acesso o x então fica (*circulo) = p.x
    printf("Digite a coordenada y da origem: ");
    scanf("%f", &circulo->p.y); 
    printf("Digite o raio da origem: ");
    scanf("%f", &circulo->r); 
}
void lerCoordenadaPonto(Ponto* ponto) {
    printf("Digite a coordenada x: ");
    scanf("%f", &ponto->x);
    printf("Digite a coordenada y: ");
    scanf("%f", &ponto->y); 
}

int distanciaDeDoisPonto(Circulo c, Ponto p1, Ponto p2){
    //d = raiz((x2-x1)^2 +(y2-y1)^2);
    float d = sqrt(pow((p2.x - p1.x),2) + pow((p2.y - p1.y),2));
    if(d  <= c.r){
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Ponto p1, p2;
    Circulo c;
    lerCoordenadaOrigem(&c); 
    lerCoordenadaPonto(&p2);
    distanciaDeDoisPonto(c, p1, p2);

    if(distanciaDeDoisPonto(c, p1, p2) == 1){
        printf("Esta dentro do circulo");
    } else{
        printf("Nao esta dentro do circulo");
    }

    return 0;
}