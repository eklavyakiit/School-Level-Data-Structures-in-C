#include<stdio.h>
#include <stdlib.h>
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Bubble(int A[], int n){
    int flag = 0;
    for(int i = 0; i<n-1; i++){
        int flag = 0;
        for(int j = 0; j<n-1-i; j++){
            if(A[j]>A[j+1]){
                swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}
int main(){
    int A[] = {8, 5, 7, 3, 2};
    int n = 5;
    Bubble(A, 5);
     for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}