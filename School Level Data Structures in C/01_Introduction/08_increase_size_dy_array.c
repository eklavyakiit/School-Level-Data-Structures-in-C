#include <stdio.h>
#include <stdlib.h>
int main(){
    int *p = (int*)malloc(5* (sizeof(int)));
    for(int i = 0; i<5; i++){
        p[i] = i+1;
    }
printf("\nOld Array:\n");
    for(int i = 0; i<5; i++){
        printf("%d ", p[i]);
    }

    int *q = (int*)malloc(10*(sizeof(int)));
    for(int i=0; i<5; i++){
        q[i] = p[i];
    }
    free(p);
    for(int i = 5; i<10; i++){
        q[i] = i+1;
    }
    p=q;
printf("\nNew Bigger Array:\n");
    for(int i=0; i<10; i++){
        printf("%d ", q[i]);
    }
    return 0;
}
