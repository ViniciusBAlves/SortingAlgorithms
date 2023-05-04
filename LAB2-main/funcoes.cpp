#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int medianas(int v[],int i,int f){
    int med = (i+f)/2;
    int first = v[i];
    int mid = v[med];
    int last = v[f];
    int med_i;
    if(first < mid){
        if(mid < last){
            med_i = med;
        }
        else{
            if(first < last){
                med_i = f;
            }
            else{
                med_i = i;
            }
        }
    }
    else{
        if(last < mid){
            med_i = med;
        }
        else{
            if(last < first){
                med_i = f;
            }
            else{
                med_i = i;
            }
        }
    }
    return med_i;
}
//HOARE
int particiona_HOARE(int c[], int i, int f, int pivo,int *swaps){
    *swaps = *swaps + 1;
    troca(&c[i],&c[pivo]);
    int cp = c[i];
    int l = i, r = f;
    while(l < r){
        while(c[r] > cp && l < r) r--;
        *swaps = *swaps + 1;
        troca(&c[l],&c[r]);
        while(c[l] <= cp && l < r) l++;
        *swaps = *swaps + 1;
        troca(&c[r],&c[l]);
    }
    c[r] = cp;
    return l;
}

int particiona_LOMUTO(int c[],int i,int f,int pivo,int *swaps){
    troca(&c[pivo],&c[f]);
    *swaps = *swaps + 1;
    int x = c[f];
    int p = i-1;
    for(int j = i; j < f;j++){
        if(c[j] <= x){
            p++;
            *swaps = *swaps + 1;
            troca(&c[p],&c[j]);
        }
    }
    *swaps = *swaps + 1;
    troca(&c[p+1],&c[f]);
    return(p+1);
}

int choose_rand(int c[],int i,int f){
    int r;
    srand(time(NULL));
    r = i + 1 + (rand() % (f-i));
    return r;
}

void quicksort(int c[],int i,int f, int op, int *swaps, int *rec)
{
    int k;
    if(f > i){
        if(op == 0){
            int pivo = medianas(c,i,f);
            k = particiona_HOARE(c, i, f,pivo,swaps);
        }
        else if(op == 1){
            int pivo = medianas(c,i,f);
            k = particiona_LOMUTO(c,i,f,pivo,swaps);
        }
        else if(op == 2){
            int pivo = choose_rand(c,i,f);
            k = particiona_HOARE(c, i, f,pivo,swaps);
        }
        else if(op == 3){
            int pivo = choose_rand(c,i,f);
            k = particiona_LOMUTO(c,i,f,pivo,swaps);
        }
        *rec = *rec + 1;
        quicksort(c, i, k-1,op,swaps,rec);
        *rec = *rec + 1;
        quicksort(c, k+1, f,op,swaps,rec);
    }
}

