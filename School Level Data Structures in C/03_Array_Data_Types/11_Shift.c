//Left Shift
#include <stdio.h>
int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    printf(" Your Original Array:\n");
    for(int i= 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    for(int i = 0; i<n-1; i++){
        arr[i] = arr[i+1];
    }
    arr[n-1] = 0;
    printf("\nYour Left Shifted Array:\n");
    for(int i= 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}