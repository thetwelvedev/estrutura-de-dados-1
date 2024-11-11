#include <stdio.h>
#include <stdlib.h>
/*Criar um programa em C que armazene e manipule as notas de provas de vários alunos em várias 
disciplinas, usando alocação dinâmica para lidar com um número flexível de alunos e disciplinas.*/

void alocarMatriz(int* num, int* numDiciplinas, double ***notas);
void coletarNotas(int* num, int* numDiciplinas, double ***notas);
void mediaPorAluno(int* num, int* numDiciplinas, double ***notas);
void mediaPorDisciplina(int* num, int* numDiciplinas, double ***notas);
void liberarMemoria(int* num, double*** notas);

int main(){
    double **notas;
    int num, numDiciplinas;

    //Solicitação de dados
    printf("Digite um numero de alunos: ");
    scanf("%d", &num);
    printf("Digite um numero de disciplinas: ");
    scanf("%d", &numDiciplinas);

    //Alocação dinâmica
    alocarMatriz(&num, &numDiciplinas, &notas);
    
    //Pegar dados 
    coletarNotas(&num, &numDiciplinas, &notas);

    //Calcular e exibir média
    mediaPorAluno(&num, &numDiciplinas, &notas);
    mediaPorDisciplina(&num, &numDiciplinas, &notas);

    //Liberação de memória alocada
    liberarMemoria(&num, &notas);

    return 0;
}

//O notas tá *notas pois ele tá sendo acessado pelo ponteiro triplo
void alocarMatriz(int* num, int* numDiciplinas, double ***notas){
    //*num tá assim pois quero o valor e não o endereço de memória
    *notas = (double**) malloc((*num) * sizeof(double*));
    for(int i = 0; i < *num; i++){
        (*notas)[i] = (double*) malloc((*numDiciplinas) *sizeof(double));
    }
}

void coletarNotas(int* num, int* numDiciplinas, double ***notas){
    //*num e *numDiciplinas estão assim pois quero os valores e não o endereço de memória
    for(int i = 0; i < *num; i++){
        printf("---Notas do Aluno %d---\n", i+1);
        for(int j = 0; j < *numDiciplinas; j++){
            printf("Digite a nota da disciplina %d: ", j+1);
            scanf("%lf", &(*notas)[i][j]);
        }
    }
}

//Calcular e exibir a média de cada aluno (média das notas em todas as disciplinas).
void mediaPorAluno(int* num, int* numDiciplinas, double ***notas){
    printf("Media por aluno: \n");
    for(int i = 0; i < *num; i++){
        //Zerar as variáveis para cada próximo ciclo
        double media = 0;
        printf("Aluno %d - ", i+1);
        for(int j = 0; j < *numDiciplinas; j++){
            media += (*notas)[i][j];
        }
        media /= *numDiciplinas;
        printf("Media: %.2f\n", media);
    }
}

//Calcular e exibir a média de cada disciplina (média das notas de todos os alunos para uma disciplina específica).
void mediaPorDisciplina(int* num, int* numDiciplinas, double ***notas){
    printf("Media por Disciplina: \n");
    for(int j = 0; j < *numDiciplinas; j++){
        //Zerar as variáveis para cada próximo ciclo
        double media = 0;
        printf("Disciplina %d - ", j+1);
        for(int i = 0; i < *num; i++){
            media += (*notas)[i][j];
        }
        media /= *num;
        printf("Media: %.2f\n", media);
    }
}
/*Ao inverter linha por coluna, os dados que ficavam na linha que antes era as notas de um aluno só mas disciplinas diferentes, agora são mesma disciplina e 
alunos diferentes, fazendo agora eu conseguir pegar a média de forma mas fácil*/

void liberarMemoria(int* num, double*** notas){
    for(int i = 0; i < *num; i++){
        free((*notas)[i]);
    }
    free((*notas));
}