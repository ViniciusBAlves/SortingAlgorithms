#ifndef aux_functions_h
#define aux_functions_h

#include <cstdio>
#include <cstdlib>

#define BUBBLE_SORT 0
#define INSERTION_SORT 1
#define INSERTION_BINARY_SORT 2
#define SHELL_SORT 3

#define ELEMENTS_CRESCENT    0
#define ELEMENTS_DECRESCENT  1
#define ELEMENTS_RANDOM      2

// aux functions
void print_array(int C[], int tam);
void check_correctness (int C[], int tam);
int binary_search (int C[], int low, int high, int key);

// tests
void small_test(int type_algorithm);
void large_test(int type_algorithm, int elements_type, int size);
void individual_tests(int type_sorting, int type_elements, int size);
void scale_tests(int type_sorting, int type_elements, int start_size, int number_cases);

// sorting algorithms
void insertion_sort(int C[], int tam, int print_ok, int check);
void bubble_sort(int C[], int tam, int print_ok, int check);
void insertion_binary_sort(int C[], int tam, int print_ok, int check);
void shell_sort(int C[], int tam, int print_ok, int check);


#endif /* aux_functions_h */
