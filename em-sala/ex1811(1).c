#include <stdio.h>

/*struct ponto{
    int x;
    int y;
};

typedef struct ponto Ponto;*/

typedef struct ponto {
    int x;
    int y;
} Ponto;


void lerCoordenada(Ponto* ponto) {
    printf("Digite a coordenada x: ");
    scanf("%d", &ponto->x); //(*ponto).x -> Ler os valores e altera diretamente diretamente no endereço da variável
    printf("Digite a coordenada y: ");
    scanf("%d", &ponto->y); 
}

void imprimirCoordenada(Ponto ponto) {
    printf("Coordenada: (%d, %d)\n", ponto.x, ponto.y);
}

int main() {
    Ponto p; 

    p.x = 0;
    p.y = 0;
    imprimirCoordenada(p);
    lerCoordenada(&p);
    imprimirCoordenada(p);

    return 0;
}