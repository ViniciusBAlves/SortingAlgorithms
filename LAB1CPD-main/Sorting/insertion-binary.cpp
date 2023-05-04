#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>

#include "aux-functions.h"

//--------------------------------------------------------------
void insertion_binary_sort(int C[], int tam, int print_ok, int check){
//--------------------------------------------------------------
    clock_t start_clock, end_clock;
    long changes = 0;
    int j, chave;
    int insertion_place;

    if (print_ok) {
        printf ("Array before: ");
        print_array(C, tam);
    }

    start_clock = clock();
    for(j=1; j<tam; j++){
        insertion_place = binary_search(C, 0, j, C[j]);
        chave = C[j];
        // Movimenta elementos para direita
        for (int k=j-1; k>=insertion_place; k--) {
            C[k+1] = C[k];
            changes++;
        }
        C[insertion_place] = chave;
    }
    end_clock = clock();

    if (check)
        check_correctness(C, tam);
    
    if (print_ok) {
        printf ("Array after: ");
        print_array(C, tam);
    }
    
    
    printf("insertion-binary,%d,%ld,%f\n", tam, changes, (end_clock - start_clock)/(double)CLOCKS_PER_SEC);
}

//--------------------------------------------------------------
void shell_sort(int C[], int tam, int print_ok, int check){
//--------------------------------------------------------------
    clock_t start_clock, end_clock;
    long changes = 0;
    int i, j, chave;
    int h = 1;

    if (print_ok) {
        printf ("Array before: ");
        print_array(C, tam);
    }

    start_clock = clock();
    while (h < tam) h = 3*h+1;
    while ( h > 1) {
        h /= 3;
        for(i = h; i < tam; i++) {
            chave = C[i];
            j = i - h;
            while (j >= 0 && chave < C[j]) {
                C [j+h] = C[j];
                changes++;
                j -= h;
                //if (j<h) break;
            }
            C [j+h] = chave;
        }
    }
    end_clock = clock();

    if (check)
        check_correctness(C, tam);
    
    if (print_ok) {
        printf ("Array after: ");
        print_array(C, tam);
    }
    
    printf("shell,%d,%ld,%f\n", tam, changes, (end_clock - start_clock)/(double)CLOCKS_PER_SEC);
}


