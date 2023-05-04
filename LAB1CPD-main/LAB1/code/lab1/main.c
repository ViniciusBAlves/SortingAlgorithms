#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define SIZELINE 100000

int main(){
    FILE* entrada;
    FILE* saida;
    char separador[] = {" \n"};
    char *palavra, linha[100000];
    char arqent[50],arqsai[50];
    int j;

    printf("Digite o nome do arquivo de entrada\n");
    scanf("%s",&arqent);
    entrada = fopen(arqent,"r");
    if(entrada == NULL){
        printf("Arquivo invalido\n");
        return 1;
    }
    else{
        while(fgets(linha,SIZELINE,entrada)){
            int V[10000];
            int i = 0;
            palavra = strtok(linha,separador);
            while(palavra != NULL){
                V[i] = atoi(palavra);
                i++;
                palavra = strtok(NULL,separador);
            }
            shellsort(V,i);
            printf("\nNovo Vetor\n");
        }
        fclose(entrada);
    }
    return 0;
}
