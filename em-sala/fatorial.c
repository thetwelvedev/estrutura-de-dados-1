/* programa que lê um número e imprime seu fatorial */
#include<stdio.h>
int fat(int n); /* protótipo da função */
/* Função principal */
int main (void){
    int n;
    scanf("%d" ,&n);
    printf("Fatorial = %d\n", fat(n));
    return(0);
}
/* Função para calcular o valor do fatorial */
int fat(int n){
    int i;
    int f=1;
    for(i=1; i<=n;i++)
    f=f*i;
    return f;
}