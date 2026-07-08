#include<stdio.h>
void descending(int n){
    if(n>0){
        descending(n-1);
        printf("%d", n);
    }
}
int main(){
    descending(7);
    return 0;
}