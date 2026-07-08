#include <stdio.h>
int main(){
    int arr[10] = {10,20,30,40,50};
    int n=5;
    int index = 2;
    //Core logic: Copy all elements to the left from the index to be deleted and reduce the size,
    for(int i = 2; i<n; i++){
        arr[i] = arr[i+1];
    }
    n--;
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}