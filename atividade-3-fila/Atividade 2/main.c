#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h> 
#include "fila.h"

Pedido gerar_pedido(int id) {
    Pedido p;
    p.id = id;
    p.peso = rand() % 11;  // Peso entre 0 e 10 kg
    p.endereco[0] = 'A' + (id % 26); // Gera letras de 'A' a 'Z'
    p.endereco[1] = '\0'; // Apenas uma letra para o endereço
    return p;
}

int main() {
    srand(time(NULL));

    Fila* fila_pedidos = criar_fila();
    int id_pedido = 101;
    int capacidade_drone = 10;
    int carga_atual = 0; 

    while (1) {
        // Simula a chegada de um novo pedido
        Pedido novo_pedido = gerar_pedido(id_pedido++);
        printf("Novo pedido recebido: ID %d, Peso %dkg, Endereço: Rua %c\n", novo_pedido.id, novo_pedido.peso, novo_pedido.endereco[0]);
        enfileirar(fila_pedidos, novo_pedido);

        // Exibe o estado da fila de pedidos
        printf("\nFila de entregas: ");
        imprime(fila_pedidos);

        // Processa a entrega
        if (fila_pedidos->tam > 0) {
            Pedido pedido_atual = fila_pedidos->vet[fila_pedidos->ini];

            // Verifica se o pedido pode ser entregue
            if (pedido_atual.peso + carga_atual <= capacidade_drone) {
                // Drone sai para entrega
                printf("Drone saiu para entrega do pedido %d.\n", pedido_atual.id);
                carga_atual += pedido_atual.peso;
                desenfileirar(fila_pedidos); // Pedido entregue
                printf("Pedido %d entregue!\n", pedido_atual.id);
                carga_atual -= pedido_atual.peso;

                Sleep(2000);

                // Drone retorna à base
                printf("Drone retornou a base.\n");
            } else {
                // Pedido não pode ser entregue (excede a capacidade restante do drone)
                printf("Pedido %d não pode ser entregue (excede capacidade restante).\n", pedido_atual.id);
                desenfileirar(fila_pedidos); // Pedido descartado (aguarda próxima chance)
            }
        }
        
        Sleep(2000);
    }

    liberar(fila_pedidos);
    return 0;
}
