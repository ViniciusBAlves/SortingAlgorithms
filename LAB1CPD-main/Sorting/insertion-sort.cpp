#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>

#include "aux-functions.h"

//--------------------------------------------------------------
void insertion_sort(int C[], int tam, int print_ok, int check){
//--------------------------------------------------------------
    clock_t start_clock, end_clock;
    long changes = 0;
    int i, j, chave;

    if (print_ok) {
        printf ("Array before: ");
        print_array(C, tam);
    }

    start_clock = clock();
    for(j=1; j<tam; j++){
        chave = C[j];
        i = j-1;
        while((i>=0) && (C[i]>chave)){
            C[i+1] = C[i];
            i--;
            changes++;
        }
        C[i+1] = chave;
    }
    end_clock = clock();

    if (check)
        check_correctness(C, tam);
    
    if (print_ok) {
        printf ("Array after: ");
        print_array(C, tam);
    }
    
    
    printf("insertion,%d,%ld,%f\n", tam, changes, (end_clock - start_clock)/(double)CLOCKS_PER_SEC);
}

