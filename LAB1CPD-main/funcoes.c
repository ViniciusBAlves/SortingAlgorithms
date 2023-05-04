#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"
#include <string.h>

int select_h(int h, int tam, int op){
    int ciura[8] = {1, 4, 10, 23, 57, 132, 301, 701};
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
    else if(op == 3){
        if(ciura[7] < tam){
            h = ciura[7];
            do{
                h = 2.25*h;
            }while(h < tam);
        }
        else{
            while (ciura[i] <= tam){
            i++;
            }
            h = ciura[i];
        }
    }
    return h;
}

void shellsort(int V[], int tam, char arqsai[], FILE *saida){
    int i, j, aux, h = 1;
    int *vec =(int*) malloc(sizeof(int)*1000000);
    int ciura[8] = {1, 4, 10, 23, 57, 132, 301, 701};
    int op;
    float ms;
    clock_t start, end;
    for(i = 0;i < tam;i++)
        vec[i] = V[i];
    for(op = 1; op < 4; op++){
        h = select_h(h,tam,op);
        start = clock();
        for(i = 0;i < tam;i++){
        V[i] = vec[i];
        if(strcmp(arqsai, "saida1.txt") == 0){
            fprintf(saida,"%d\t",V[i]);}
        }
        if(op == 1){
            if(strcmp(arqsai, "saida1.txt") == 0){
                fprintf(saida, "%s", " SEQ = SHELL\n");}
            else{
                fprintf(saida, "%s","SHELL, ");}
        }
        else if(op == 2){
            if(strcmp(arqsai, "saida1.txt") == 0){
                fprintf(saida, "%s", " SEQ = KNUST\n");}
            else{
                fprintf(saida, "%s","KNUST, ");}
        }
        else if(op == 3){
            if(strcmp(arqsai, "saida1.txt") == 0){
                fprintf(saida, "%s", " SEQ = CIURA\n");}
            else{
                fprintf(saida, "%s","CIURA, ");}
        }
        while(h > 1){
            switch (op){
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
            for(i = h; i < tam; i++){
                aux = V[i];
                j = i - h;
                while (j >= 0 && aux < V[j]) {
                    V [j+h] = V[j];
                    j -= h;
                }
                V[j+h] = aux;
            }
            if(strcmp(arqsai, "saida1.txt") == 0){
                for(i = 0;i < tam;i++){
                    fprintf(saida,"%d\t",V[i]);
                }
                fprintf(saida,"%s"," INCR =");
                fprintf(saida, "%d",h);
                fprintf(saida, "%c", '\n');
            }
        }
        end = clock();
        ms = (float)(end-start)/CLOCKS_PER_SEC;
        if(strcmp(arqsai, "saida2.txt") == 0){
            fprintf(saida, "%d, %f\n",i,ms);}
    }
}