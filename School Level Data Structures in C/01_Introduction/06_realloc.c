#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr;
    ptr = (int*)calloc(3, (sizeof(int)));
    ptr[0] = 2;
    ptr[1] = 5;
    ptr[2] = 4;

    ptr = realloc(ptr, 5*sizeof(int));

    ptr[3]= 1;
    ptr[4] = 0;

    for(int i = 0; i<5; i++){
        printf("%d ", ptr[i]);
    }
    free(ptr);
    return 0;
}