#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

int main(int argc, char *argv[]){
    FILE *entrada, *saida;
    int tamanho_vetor,swaps,rec;
	int *vetor =(int*) malloc(sizeof(int)*1000000);
    int op = med_hoare;
    float seg;
    clock_t start,end;
    entrada = fopen(argv[1],"r");    //Abre o primeiro arquivo de entrada passado como argumento para leitura
    if(entrada == NULL){
        printf("Arquivo de entrada invalido\n");
    }
    else{
        printf("a");
        while(op < 4){
            if(op == med_hoare){
                saida = fopen("stats-mediana-hoare.txt","w");
            }
            else if(op == med_lomuto){
                saida = fopen("stats-mediana-lomuto.txt","w");                
            }
            else if(op == aleat_hoare){
                saida = fopen("stats-aleat-hoare.txt","w");
            }
            else if(op == aleat_lomuto){
                saida = fopen("stats-aleat-lomuto.txt","w");
            }
            while (fscanf(entrada,"%d", &tamanho_vetor) != EOF) {  //le o primeiro elemento do vetor (tamanho), e se n�o for o final do arquivo, armazena numa variavel
                for (int i=0; i<tamanho_vetor; i++){
                    fscanf(entrada,"%d", &vetor[i]); //le o resto dos elementos da linha e armazena em um vetor
                }
                fprintf(saida,"TAMANHO ENTRADA %d\n",tamanho_vetor);
                start = clock();
                swaps = 0;
                rec = 0;            
                quicksort(vetor,0,(tamanho_vetor-1),op,&swaps,&rec);
                end = clock();
                seg = (float)(end-start)/CLOCKS_PER_SEC;
                fprintf(saida,"SWAPS %d\nRECURSOES %d\nTEMPO %f\n",swaps,rec,seg);
            }
            op++;
            rewind(entrada);
            fclose(saida);
        }
    }
}