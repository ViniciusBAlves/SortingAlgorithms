#include "aux-functions.h"

int main() {
    // LARGE TESTS
    int start_size=10000, scale = 4;
    int type_elements =
        //ELEMENTS_CRESCENT;
        ELEMENTS_DECRESCENT;
        //ELEMENTS_RANDOM;
    
    //scale_tests(BUBBLE_SORT, type_elements, start_size, scale);
    //scale_tests(INSERTION_SORT, type_elements, start_size, scale);
    //scale_tests(INSERTION_BINARY_SORT, type_elements, start_size, scale);
    scale_tests(SHELL_SORT, type_elements, start_size, scale);

    return 0;
}
