#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

#define TAM_PALAVRA 50
#define TAM_LINHA 1000

typedef struct ocorrencia {
    int linha;
    int quantidade;
    struct ocorrencia *proximo;
} Ocorrencia;

typedef struct no_palavra {
    char palavra[TAM_PALAVRA];
    Ocorrencia *ocorrencias;
    struct no_palavra *proximo;
} NoPalavra;

NoPalavra* criar_no_palavra(char *palavra, int linha) {
    NoPalavra *novo_no = (NoPalavra*) malloc(sizeof(NoPalavra));
    strcpy(novo_no->palavra, palavra);
    novo_no->ocorrencias = NULL;
    novo_no->proximo = NULL;

    //Criar a primeira ocorrência da palavra
    Ocorrencia *nova_ocorrencia = (Ocorrencia*) malloc(sizeof(Ocorrencia));
    nova_ocorrencia->linha = linha;
    nova_ocorrencia->quantidade = 1;
    nova_ocorrencia->proximo = NULL;
    novo_no->ocorrencias = nova_ocorrencia;

    return novo_no;
}

void inserir_ocorrencia(Ocorrencia **lista, int linha) {
    Ocorrencia *atual = *lista;
    Ocorrencia *anterior = NULL;

    while (atual != NULL && atual->linha != linha) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {//Primeira vez que aparece nesta linha
        Ocorrencia *nova_ocorrencia = (Ocorrencia*) malloc(sizeof(Ocorrencia));
        nova_ocorrencia->linha = linha;
        nova_ocorrencia->quantidade = 1;
        nova_ocorrencia->proximo = NULL;

        if (anterior == NULL)
            *lista = nova_ocorrencia;
        else
            anterior->proximo = nova_ocorrencia;
    } else {//Palavra já apareceu nesta linha, então só incrementamos
        atual->quantidade++;
    }
}

void inserir_palavra(NoPalavra **dicionario, char *palavra, int linha) {
    NoPalavra *atual = *dicionario;
    NoPalavra *anterior = NULL;

    while (atual != NULL && strcmp(atual->palavra, palavra) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) { 
        NoPalavra *novo_no = criar_no_palavra(palavra, linha);
        if (anterior == NULL) 
            *dicionario = novo_no;
        else 
            anterior->proximo = novo_no;
    } else { 
        inserir_ocorrencia(&(atual->ocorrencias), linha);
    }
}

void imprimir_indice(NoPalavra *dicionario) {
    NoPalavra *atual = dicionario;
    while (atual != NULL) {
        printf("%s: ", atual->palavra);
        Ocorrencia *ocorrencia_atual = atual->ocorrencias;
        while (ocorrencia_atual != NULL) {
            printf("(%d,%d)", ocorrencia_atual->linha, ocorrencia_atual->quantidade);
            if (ocorrencia_atual->proximo != NULL)
                printf(", ");
            ocorrencia_atual = ocorrencia_atual->proximo;
        }
        printf("\n");
        atual = atual->proximo;
    }
}

void destruir_dicionario(NoPalavra *dicionario) {
    while (dicionario != NULL) {
        NoPalavra *temp = dicionario;
        dicionario = dicionario->proximo;

        //Liberar a lista de ocorrências
        Ocorrencia *ocorrencia_atual = temp->ocorrencias;
        while (ocorrencia_atual != NULL) {
            Ocorrencia *temp_ocorrencia = ocorrencia_atual;
            ocorrencia_atual = ocorrencia_atual->proximo;
            free(temp_ocorrencia);
        }

        free(temp);
    }
}

int main() {
    FILE *arquivo = fopen("teste3.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    NoPalavra *dicionario = NULL;
    char linha[TAM_LINHA];
    int numero_linha = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char *palavra = strtok(linha, " \n");
        while (palavra != NULL) {
            inserir_palavra(&dicionario, palavra, numero_linha);
            palavra = strtok(NULL, " \n");
        }
        numero_linha++;
    }

    fclose(arquivo);

    printf("\nSAIDA: \n");
    imprimir_indice(dicionario);
    
    destruir_dicionario(dicionario);
    return 0;
}
