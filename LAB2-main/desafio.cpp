#include <stdio.h>
#include <stdlib.h>

unsigned long int swap;

void count(int c[],int left[],int right[],int n){
    int i = 0, j = 0, k = 0;
	while (i < n/2 || j < (n-(n/2))){
		if(i < n/2 && j < (n-(n/2))){
			if (left[i] < right[j]){
				c[k++] = left[i++];
			}
            else{
				c[k++] = right[j++];
				swap += n/2 - i;
			}
		}
        else if (i < n/2){
			c[k++] = left[i++];
		}
        else{
		    c[k++] = right[j++];
		}
	}
}
void swaps(int c[],int n){
    if(n<=1)
        return;
    else{
        int i;
        int left[n/2];
        int right[n-(n/2)];
        for (i = 0; i < n/2; i++)
            left[i]  = c[i];
        for (i = 0; i < (n-(n/2)); i++)
            right[i] = c[i+n/2];
        swaps(left,(n/2));
        swaps(right,(n-(n/2)));
        count(c,left,right,n);
    }
}
int main(){
    int i;
    int *vetor =(int*) malloc(sizeof(int)*500000);
    int tamanho_vetor;
    while(scanf("%d",&tamanho_vetor) != EOF){
        swap = 0;
        if(tamanho_vetor != 0){
            for(i = 0;i < tamanho_vetor;i++)
                scanf("%d",&vetor[i]);
            swaps(vetor,tamanho_vetor);
            printf("%lu\n",swap);
        }
    }
    return 0;
}