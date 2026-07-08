#include<stdio.h>
void ascending(int n){
    if(n>0){
        printf("%d", n);
        ascending(n-1);
    }
}
int main(){
    ascending(7);
    return 0;
}