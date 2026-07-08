#include <stdio.h>

int main(){

    int arr[]={10,20,30,40,50};
    int n=5;
    int key=40;

    for(int i=0;i<n;i++){

        if(arr[i]==key){
            printf("Found at index %d",i);
            break;
        }
    }

    return 0;
}