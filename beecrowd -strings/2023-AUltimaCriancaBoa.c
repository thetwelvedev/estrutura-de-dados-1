#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Função para copiar uma palavra para outra
void copiarPalavra(char* palavra01, const char* palavra02) {
    int i;
    // Copia cada caractere de palavra02 para palavra01
    for (i = 0; i < strlen(palavra02); i++) {
        palavra01[i] = palavra02[i];
    }
    // Adiciona o caractere de término de string '\0' no final de palavra01
    palavra01[i] = '\0';
}

// Função para comparar duas palavras, ignorando diferenças de maiúsculas e minúsculas
const char* compararPalavra(const char* palavra01, const char* palavra02) {
    for (int i = 0; i <= 81; i++) {
        // Se a primeira palavra terminar, retorna a segunda palavra
        if (palavra01[i] == '\0') return palavra02;
        // Se a segunda palavra terminar, retorna a primeira palavra
        else if (palavra02[i] == '\0') return palavra01;

        int letraPalavra01 = palavra01[i], letraPalavra02 = palavra02[i]; 

        // Converte letras maiúsculas para minúsculas
        if (palavra01[i] < 97) letraPalavra01 += 32;
        if (palavra02[i] < 97) letraPalavra02 += 32;

        // Compara as letras das duas palavras
        if (letraPalavra01 > letraPalavra02) return palavra01;
        else if (letraPalavra01 < letraPalavra02) return palavra02;
    } 
    return palavra01;  // Se forem iguais, retorna palavra01
}

int main() {
    // Aloca dinamicamente memória para as duas palavras, com capacidade para até 80 caracteres
    char* palavra01 = (char*)malloc(81 * sizeof(char)); 
    char* palavra02 = (char*)malloc(81 * sizeof(char)); 

    // Verifica se a alocação de memória foi bem-sucedida
    if (palavra01 == NULL || palavra02 == NULL) {
        printf("Falha na alocação de memória\n");
        return 1; // Encerra o programa em caso de erro de alocação
    }

    palavra01[0] = '\0';  // Inicializa palavra01 como uma string vazia
    int i = 0;

    // Lê palavras da entrada até o final do arquivo (EOF)
    while (scanf(" %80[^\n]", palavra02) != EOF) {
        if (i > 0) {
            // Se não for a primeira palavra, compara as palavras e copia a maior para palavra01
            copiarPalavra(palavra01, compararPalavra(palavra01, palavra02));
        } else {
            // Se for a primeira palavra, apenas copia palavra02 para palavra01
            copiarPalavra(palavra01, palavra02);
        }
        i++;
    }

    // Imprime a palavra final
    printf("%s\n", palavra01); 

    // Libera a memória alocada
    free(palavra01); 
    free(palavra02);

    return 0;
}
