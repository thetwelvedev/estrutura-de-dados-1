#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include <windows.h>
#include"fila.h"

int main() {
    srand(time(NULL));

    Fila *fila_norte = criar_fila();
    Fila *fila_sul = criar_fila();
    int id_veiculo = 101;

    while (1) {
        Veiculo novo = gerar_veiculo(id_veiculo++);
        if (strcmp(novo.direcao, "NORTE") == 0) {
            enfileirar(fila_norte, novo);
        } else {
            enfileirar(fila_sul, novo);
        }

        printf("\nFila atual:\n");
        printf("[NORTE: ");
        for (int i = fila_norte->ini; i < fila_norte->fim && i < MAX; i++) {
            printf("%d ", fila_norte->vet[i].id);
        }
        printf("]\n");

        printf("Aguardando (SUL): ");
        for (int i = fila_sul->ini; i < fila_sul->fim && i < MAX; i++) {
            printf("%d ", fila_sul->vet[i].id);
        }
        printf("\n");

        controlar_ponte(fila_norte, fila_sul);

        Sleep(2000);
    }

    liberar(fila_norte);
    liberar(fila_sul);
    return 0;
}
