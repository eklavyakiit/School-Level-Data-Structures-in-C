#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
}*first = NULL;

void createCLL(int A[], int n ){
    struct node *t, *last;
    first = (struct node*)malloc(sizeof(struct node));
    first->data = A[0];
    first->next = first;
    last=first;

    for(int i = 1; i<n; i++){
        t = (struct node*)malloc(sizeof(struct node));
        t->data = A[i];
        t->next=first;
        last->next=t;
        last=t;
    }

}
void display(struct node *p){
    if(p==NULL){
        return;
    }
    do{
        printf("%d ", p->data);
        p=p->next;
    }while(p!=first);
    printf("\n");
}
int main(){
    int A[] = {10, 20, 30, 40, 50};
    createCLL(A, 5);
    display(first);
    return 0;
}