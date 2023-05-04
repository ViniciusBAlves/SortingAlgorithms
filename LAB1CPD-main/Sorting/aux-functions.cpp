#include <cstdio>
#include <cstdlib>

//--------------------------------------------------------------
void print_array(int C[], int tam) {
//--------------------------------------------------------------
    printf ("[");
  for (int i=0; i<tam-1; i++) {
    printf("%d, ", C[i]);
  }
  printf ("%d]\n", C[tam-1]);
}


//--------------------------------------------------------------
void check_correctness (int C[], int tam) {
//--------------------------------------------------------------
  for (int i=0; i<tam-1; i++) {
      if (C[i]>C[i+1]) {
          printf ("\n***** INCORRECT ORDERING *****");
          return;
      }
  }
}

//--------------------------------------------------------------
int binary_search (int C[], int low, int high, int key)
//--------------------------------------------------------------
{
    int mid;

    if (low == high)
        return low;

    mid = low + ((high - low) / 2);

    if (key > C[mid])
        return binary_search (C, mid + 1, high, key);
    else if (key < C[mid])
        return binary_search (C, low, mid, key);

    return mid;
}

