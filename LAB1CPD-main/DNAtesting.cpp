#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argv, char *argc[]){
    FILE *ent;
    FILE *sai;
    char sep[] = {" ,.&*%\?!;/'@\"$#=><()][}{:\n\t"};
    int conjuntos, tamanho, numero;
    ent = fopen(argc[1],"r");
    sai = fopen(argc[2],"w");
    if(ent == NULL)
        printf("Arquivo de entrada invalido");
    else{
        fscanf(ent,"%d",&conjuntos);
        for(int i=0; i < conjuntos; i++){
            fscanf(ent,"%d",&tamanho);
            fscanf(ent,"%d",&numero);
            char sequencias[numero][tamanho];
            int contador[numero] = {0};
            for(int j = 0; j < numero; j++){
                fscanf(ent,"%s",&sequencias[j]);
                printf("%s\t",sequencias[j]);
                for(int k = 0;k < tamanho;k++){
                    for(int x = k+1; x < tamanho;x++){
                        if(sequencias[j][k] > sequencias[j][x] && sequencias[j][x] != '\0'){
                            contador[j]++;
                        }
                    }
                }
                printf("Contador %d\n",contador[j]);
            }

        }
    }
}
