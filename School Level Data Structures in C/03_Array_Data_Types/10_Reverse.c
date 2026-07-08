#include <stdio.h>
int main(){
    int arr[]={10,20,30,40,50};
    int n = 5;
    int temp;
    printf("Your Original Array is:\n");
    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    for(int i=0; i<n/2; i++){
        temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
    printf("\nYour Reversed Array is:\n");
    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}