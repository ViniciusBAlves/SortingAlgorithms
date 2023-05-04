#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>

#include "aux-functions.h"

//--------------------------------------------------------------
void small_test(int type_algorithm) {
//--------------------------------------------------------------
    int arr1[10] = {12,2,5,4,8,7,6,9,1,15};
    int arr2[10] = {1,2,3,4,5,6,7,8,9,10};
    int arr3[10] = {10,9,8,7,6,5,4,3,2,1};
    
    switch (type_algorithm) {
        case BUBBLE_SORT:
            bubble_sort(arr1, 10, 1, 1);
            bubble_sort(arr2, 10, 1, 1);
            bubble_sort(arr3, 10, 1, 1);
            break;
        case INSERTION_SORT:
            insertion_sort(arr1, 10, 1, 1);
            insertion_sort(arr2, 10, 1, 1);
            insertion_sort(arr3, 10, 1, 1);
            break;
        case INSERTION_BINARY_SORT:
            insertion_binary_sort(arr1, 10, 1, 1);
            insertion_binary_sort(arr2, 10, 1, 1);
            insertion_binary_sort(arr3, 10, 1, 1);
            break;
        case SHELL_SORT:
            //shell_sort(arr1, 10, 1, 1);
            //shell_sort(arr2, 10, 1, 1);
            //shell_sort(arr3, 10, 1, 1);
            break;
    }
}

//--------------------------------------------------------------
void large_test(int type_algorithm, int elements_type, int size) {
//--------------------------------------------------------------
    int arr[size];
 
    switch (elements_type) {
        case ELEMENTS_CRESCENT: for (int i=0; i<size; i++) arr[i] = i; break;
        case ELEMENTS_DECRESCENT: for (int i=0; i<size; i++) arr[i] = size-i; break;
        case ELEMENTS_RANDOM: for (int i=0; i<size; i++) arr[i] = rand() % size+1; break;
    }
    
    switch (type_algorithm) {
        case BUBBLE_SORT: bubble_sort(arr, size, 0, 1); break;
        case INSERTION_SORT: insertion_sort(arr, size, 0, 1); break;
        case INSERTION_BINARY_SORT: insertion_binary_sort(arr, size, 0, 1); break;
        case SHELL_SORT: shell_sort(arr, size, 0, 1); break;
        default: printf("Unexepected type of algorithm");
    }
}

//--------------------------------------------------------------
void individual_tests(int type_sorting, int type_elements, int size) {
//--------------------------------------------------------------
    large_test(type_sorting, type_elements, size);
}

//--------------------------------------------------------------
void scale_tests(int type_sorting, int type_elements, int start_size, int number_cases) {
//--------------------------------------------------------------

    int size = start_size;
    
    for (int i=0; i<number_cases; i++) {
        large_test(type_sorting, type_elements, size);
        size *= 10;
    }
}

// SMALL TESTS
//small_test(BUBBLE_SORT);
//small_test(INSERTION_SORT);

// INDIVIDUAL TESTS
//individual_tests(BUBBLE_SORT, ELEMENTS_RANDOM, 1000);
