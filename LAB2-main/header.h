#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b);
int mediana(int v[],int i, int j);
int medianas(int v[],int tamanho);
void quicksort(int c[],int i,int f, int op, int *swaps, int *rec);
int particiona_HOARE(int c[], int i, int f,int pivo,int *swaps);
int particiona_LOMUTO(int c[],int i,int f,int pivo,int *swaps);
enum{med_hoare,med_lomuto,aleat_hoare,aleat_lomuto};