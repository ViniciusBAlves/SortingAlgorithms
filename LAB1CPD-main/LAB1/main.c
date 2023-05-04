#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


int main(int argc, char *argv[]){
    FILE *saida, *entrada;
    int tamanho_vetor;
	int vetor[1000000];
    char arqsai[30];

    printf("Digite o nome do arquivo de saida\n");
    scanf("%s",&arqsai);
    entrada = fopen(argv[1],"r");
    saida = fopen(arqsai,"w");
    if(entrada == NULL){
        printf("Arquivo de entrada invalido\n");
    }
    else{
        while (fscanf(entrada,"%d", &tamanho_vetor) != EOF) {
            for (int i=0; i<tamanho_vetor; i++)
                fscanf(entrada,"%d", &vetor[i]);
            printf ("\nNumero de elementos na entrada % d\n", tamanho_vetor);	
            shellsort(vetor,tamanho_vetor,saida);
        }
    }
    fclose(entrada);
    fclose(saida);
    return 0;
}
            

    