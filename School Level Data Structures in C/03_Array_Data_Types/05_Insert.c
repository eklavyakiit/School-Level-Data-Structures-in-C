// The Shifting Loop: Moves elements one spot to the right, starting from the back (n) 
//down to the target index, to create a vacancy.

// The Insertion: Overwrites the vacant target index with the new value.

// The Tracker Update: Increments n++ because the element tracker must now account for 
//the newly added size.
#include<stdio.h>
int main(){
    int arr[10] = {10, 20, 30 ,40, 50};
    int n=5;
    int index = 2;
    int value = 25;

    for(int i =n; i>index; i--){
        arr[i] = arr[i-1];
    }
    arr[index] = value;
    n++;
    for(int i =0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}