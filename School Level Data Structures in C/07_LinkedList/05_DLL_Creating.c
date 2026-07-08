#include <stdio.h>
#include <stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
}*first = NULL;
void createDLL(int A[], int n){
    struct node *t, *last;
    first = (struct node*)malloc(sizeof(struct node));
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;
    for(int i = 1; i<n; i++){
        t = (struct node*)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}
int display(struct node *p){
    printf("\nThe Doubly Linked List has:");
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

int main(){
    int A[] = {10, 20, 30, 40, 50};
    createDLL(A, 5);
    display(first);
    return 0;
}