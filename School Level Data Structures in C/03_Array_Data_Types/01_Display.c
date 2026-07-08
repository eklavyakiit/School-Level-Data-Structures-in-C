#include <stdio.h>
int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array one by one:\n ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}