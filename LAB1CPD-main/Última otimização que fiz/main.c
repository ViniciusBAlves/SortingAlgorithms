#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


int main(int argc, char *argv[]){
    FILE *entrada, *saida;
    int tamanho_vetor;
	int *vetor =(int*) malloc(sizeof(int)*1000000);
    char arqsai[15];

    entrada = fopen(argv[1],"r");    //Abre o primeiro arquivo de entrada passado como argumento para leitura
    if(entrada == NULL){
        printf("Arquivo de entrada invalido\n");
    }
    else{
        strcpy(arqsai,"saida1.txt");
        saida = fopen(arqsai,"w");  //Abre um arquivo de saida para escrita
        while (fscanf(entrada,"%d", &tamanho_vetor) != EOF) {  //le o primeiro elemento do vetor (tamanho), e se não for o final do arquivo, armazena numa variavel
            for (int i=0; i<tamanho_vetor; i++)
                fscanf(entrada,"%d", &vetor[i]); //le o resto dos elementos da linha e armazena em um vetor
            shellsort(vetor,tamanho_vetor,saida);
        }
    }
    fclose(entrada);
    fclose(saida);
    entrada = fopen(argv[2],"r");   //Abre o segundo arquivo de entrada passado como argumento para leitura
    if(entrada == NULL){
        printf("Segundo arquivo de entrada invalido\n");
    }
    else{
        strcpy(arqsai,"saida2.txt");//Abre um novo arquivo de saida para escrita
        saida = fopen(arqsai,"w");
        while (fscanf(entrada,"%d", &tamanho_vetor) != EOF) {  //le o primeiro elemento do vetor (tamanho), e caso não seja o final do arquivo, armazena numa variavel
            for (int i=0; i<tamanho_vetor; i++)
                fscanf(entrada,"%d", &vetor[i]); //le o resto dos elementos da linha e armazena em um vetor
            shellsort2(vetor,tamanho_vetor,saida);
        }
    }
    fclose(entrada);
    fclose(saida);
    return 0;
}


