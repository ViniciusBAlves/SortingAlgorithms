#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


int main(int argc, char *argv[]){
    FILE *entrada, *saida;
    int tamanho_vetor;
	int *vetor =(int*) malloc(sizeof(int)*1000000);
    char arqsai[15];

    entrada = fopen(argv[1],"r");
    if(entrada == NULL){
        printf("Arquivo de entrada invalido\n");
    }
    else{
        strcpy(arqsai,"saida1.txt");
        saida = fopen(arqsai,"w");
        while (fscanf(entrada,"%d", &tamanho_vetor) != EOF) {
            for (int i=0; i<tamanho_vetor; i++)
                fscanf(entrada,"%d", &vetor[i]);
            shellsort(vetor,tamanho_vetor,arqsai,saida);
        }
    }
    fclose(entrada);
    fclose(saida);
    entrada = fopen(argv[2],"r");
    if(entrada == NULL){
        printf("Segundo arquivo de entrada invalido\n");
    }
    else{
        strcpy(arqsai,"saida2.txt");
        saida = fopen(arqsai,"w");
        while (fscanf(entrada,"%d", &tamanho_vetor) != EOF) {
            for (int i=0; i<tamanho_vetor; i++)
                fscanf(entrada,"%d", &vetor[i]);
            shellsort(vetor,tamanho_vetor,arqsai,saida);
        }
    }
    fclose(entrada);
    fclose(saida);
    return 0;
}
            

    