#include <stdio.h>
#include <stdlib.h>

int main() {

    int rows = 2, cols = 3;

    int **arr;

    // allocate rows
    arr = (int**)malloc(rows * sizeof(int*));

    // allocate columns for each row
    for(int i=0; i<rows; i++){
        arr[i] = (int*)malloc(cols * sizeof(int));
    }

    // assign values
    int value = 1;

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            arr[i][j] = value++;
        }
    }

    // print array
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // free memory
    for(int i=0; i<rows; i++){
        free(arr[i]);
    }

    free(arr);

    return 0;
}