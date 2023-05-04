#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>

#include "aux-functions.h"

//--------------------------------------------------------------
void bubble_sort(int C[], int tam, int print_ok, int check){
//--------------------------------------------------------------
    clock_t start_clock, end_clock;
    long changes = 0, swap_elements;
    int i, j, k, chave;
    if (print_ok) {
        printf("Array before:");
        print_array(C, tam);
    }
    
    start_clock = clock();
    j = tam-1;
    k = 0;
    do {
        swap_elements = 0;
        for (i=0; i<j; i++) {
            if (C[i]>C[i+1]) {
                chave = C[i];
                C[i] = C[i+1];
                C[i+1] = chave;
                k = i; // swap location
                changes++;
                swap_elements = 1;
            }
        }
        j = k;
    }
    while (swap_elements);
    end_clock = clock();
        
    if (check)
        check_correctness(C, tam);
    if (print_ok) {
        printf ("Array after: ");
        print_array(C, tam);
    }

    printf("bubble,%d,%ld,%f\n", tam, changes, (end_clock - start_clock)/(double)CLOCKS_PER_SEC);
 }

