#include <stdio.h>
#include <string.h>

// Função para determinar o vencedor
char* determinarVencedor(char* rajesh, char* sheldon) {
    //vê a possibilidade que é empate quando os dois colocam a mesma coisa
    if (strcmp(rajesh, sheldon) == 0) {
        return "empate";
    }
    //Vê as posibilidades que o rajesh ganha
    if ((strcmp(rajesh, "tesoura") == 0 && (strcmp(sheldon, "papel") == 0 || strcmp(sheldon, "lagarto") == 0)) ||
        (strcmp(rajesh, "papel") == 0 && (strcmp(sheldon, "pedra") == 0 || strcmp(sheldon, "spock") == 0)) ||
        (strcmp(rajesh, "pedra") == 0 && (strcmp(sheldon, "tesoura") == 0 || strcmp(sheldon, "lagarto") == 0)) ||
        (strcmp(rajesh, "lagarto") == 0 && (strcmp(sheldon, "spock") == 0 || strcmp(sheldon, "papel") == 0)) ||
        (strcmp(rajesh, "spock") == 0 && (strcmp(sheldon, "tesoura") == 0 || strcmp(sheldon, "pedra") == 0))) {
        return "rajesh";
    } else{
        return "sheldon";//Se não pe emapate e nem vitória do rajesh é vitória do sheldon
    }
}

int main() {
    int num_entradas;
    char rajesh[20], sheldon[20];

    scanf("%d", &num_entradas);

    for (int i = 0; i < num_entradas; i++) {
        scanf("%s %s", rajesh, sheldon);
        printf("%s\n", determinarVencedor(rajesh, sheldon));
    }

    return 0;
}
