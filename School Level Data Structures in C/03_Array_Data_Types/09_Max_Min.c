#include <stdio.h>

int main(){

    int arr[]={10,20,80,40,50};
    int n=5;

    int max=arr[0];

    for(int i=1;i<n;i++){

        if(arr[i]>max){
            max=arr[i];
        }
    }

    printf("%d",max);

    return 0;
}