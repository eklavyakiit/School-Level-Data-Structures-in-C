#include <stdio.h>
#include <stdlib.h>

// Function returns a pointer to a pointer (int**)
int** create2DArray(int rows, int cols) {
    // 1. Allocate memory for an array of row pointers
    int** arr = (int**)malloc(rows * sizeof(int*));
    
    // 2. Allocate memory for each individual row
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }

    // 3. Populate the array with some data
    int count = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = count++;
        }
    }

    return arr;
}

int main() {
    int rows = 3, cols = 4;
    int** myArr = create2DArray(rows, cols);

    // Print the array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", myArr[i][j]);
        }
        printf("\n");
    }

    // CRITICAL: Always free the memory when done!
    for (int i = 0; i < rows; i++) {
        free(myArr[i]); // Free individual rows
    }
    free(myArr); // Free the row pointer array

    return 0;
}