#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"
#include <string.h>

int select_h(int h, int tam, int op){
    int ciura[8] = {1, 4, 10, 23, 57, 132, 301, 701};   //sequencia definida de ciura
    int i = 0;
    if(op == 1){
        while (h < tam){
            h = h*2;
        }
    }
    else if(op == 2){
        while (h < tam){
            h = 3*h +1;
        }
    }
    else if(op == 3){                                   //caso o tamanho do vetor seja maior que a sequencia definida de ciura, calcular o incremento usando a formula h = 2.25h
        if(ciura[7] < tam){
            h = ciura[7];
            do{
                h = 2.25*h;
            }while(h < tam);
        }
        else{
            while (ciura[i] <= tam){                    //else, selecionar o maior incremento menor que o tamanho
            i++;
            }
            h = ciura[i];
        }
    }
    return h;
}

void shellsort(int V[], int tam, FILE *saida){
    int i, j, aux, h = 1;
    int *vec =(int*) malloc(sizeof(int)*1000000);
    int ciura[8] = {1, 4, 10, 23, 57, 132, 301, 701};
    int op;
    for(i = 0;i < tam;i++)
        vec[i] = V[i];          //copia o vetor para um vetor auxiliar
    for(op = 1; op < 4; op++){
        h = select_h(h,tam,op); //seleciona o incremento com base na sequencia (shell, knust ou ciura) e no tamanho do vetor
        for(i = 0;i < tam;i++){
        V[i] = vec[i];
        fprintf(saida,"%d\t",V[i]);}    //escreve o vetor original no arquivo de saida e a sequencia usada
        if(op == 1){
            fprintf(saida, "%s", " SEQ = SHELL\n");}
        else if(op == 2){
            fprintf(saida, "%s", " SEQ = KNUST\n");}
        else if(op == 3){
            fprintf(saida, "%s", " SEQ = CIURA\n");}
        while(h > 1){
            switch (op){                //diminui o incremento de acordo com a sequencia usada
                case 1: h /= 2;         //SHELL
                        break;
                case 2: h /= 3;         //KNUTH
                        break;
                case 3: if(h > ciura[7])//CIURA
                            h /= 2.25;
                        else{
                            for(i=0; ciura[i] < h; i++);
                            h = ciura[i-1];
                        }
                        break;
                default: printf("Operacao invalida\n");
                        break;
            }
            for(i = h; i < tam; i++){   //compara o valor de V[i] com o valor de V separado por h posições
                aux = V[i];             //caso V[i] seja menor que V[i-h], troca-se os valores de posição, else i++ até o fim do vetor
                j = i - h;
                while (j >= 0 && aux < V[j]) {
                    V [j+h] = V[j];
                    j -= h;
                }
                V[j+h] = aux;
            }
            for(i = 0;i < tam;i++){
                fprintf(saida,"%d\t",V[i]); //imprime os novos valores do vetor no arquivo de saida, junto com seu incremento
            }
            fprintf(saida,"%s"," INCR = ");
            fprintf(saida, "%d",h);
            fprintf(saida, "%c", '\n');
        }
    }
}
void shellsort2(int V[], int tam, FILE *saida){
    int i, j, aux, h = 1;
    int *vec =(int*) malloc(sizeof(int)*1000000);
    int ciura[8] = {1, 4, 10, 23, 57, 132, 301, 701};
    int op;
    float ms;
    clock_t start, end;
    for(i = 0;i < tam;i++)
        vec[i] = V[i];          //copia o vetor para um vetor auxiliar
    for(op = 1; op < 4; op++){
        h = select_h(h,tam,op); //seleciona o incremento com base na sequencia (shell, knust ou ciura) e no tamanho do vetor
        start = clock();        //começa o relogio
        for(i = 0;i < tam;i++)
            V[i] = vec[i];
        if(op == 1){
            fprintf(saida, "%s","SHELL, ");}
        else if(op == 2){
            fprintf(saida, "%s","KNUST, ");}
        else if(op == 3){
            fprintf(saida, "%s","CIURA, ");}
        while(h > 1){
            switch (op){        //diminui o incremento de acordo com a sequencia usada
                case 1: h /= 2;
                        break;
                case 2: h /= 3;
                        break;
                case 3: if(h > ciura[7])
                            h /= 2.25;
                        else{
                            for(i=0; ciura[i] < h; i++);
                            h = ciura[i-1];
                        }
                        break;
                default: printf("Operacao invalida\n");
                        break;
            }
            for(i = h; i < tam; i++){       //compara o valor de V[i] com o valor de V separado por h posições
                aux = V[i];                 //caso V[i] seja menor que V[i-h], troca-se os valores de posição, else i++ até o fim do vetor
                j = i - h;
                while (j >= 0 && aux < V[j]) {
                    V [j+h] = V[j];
                    j -= h;
                }
                V[j+h] = aux;
            }
        }
        end = clock();          //termina o relogio
        ms = (float)(end-start)/CLOCKS_PER_SEC;     //calcula o tempo em segundos
        fprintf(saida, "%d, %f\n",i,ms);
    }
}
