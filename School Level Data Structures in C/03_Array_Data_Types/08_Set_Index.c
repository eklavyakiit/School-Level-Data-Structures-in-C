#include <stdio.h>

int main(){

    int arr[]={10,20,30,40,50};

    arr[2]=100;

    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}