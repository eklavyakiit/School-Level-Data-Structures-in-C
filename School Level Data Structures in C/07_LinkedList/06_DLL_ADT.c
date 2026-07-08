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
}
int reverseDisplay(struct node *p){
    printf("\nDouble Linked List in Reverse:");
    while(p->next!=NULL){
        p=p->next;
    }
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->prev;
    }
}
//searching
struct node* search(struct node *p, int key){
    if(p==NULL){
        printf("\nNot Found");
        return NULL;
    }if(p->data == key){
        printf("\nFound: %d", p);
        return p;
    }
    return search(p->next, key);
}
//node count
int count(struct node *p){
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}
//insert (beginning)
void insertbeginning(int x){
    struct node *t;
    t = (struct node*)malloc(sizeof(struct node));
    t->data = x;
    t->next = first;
    t->prev = NULL;
    if(first!=NULL){
        first->prev = t;
    }
    first = t;
}
//insert (any pos)
void insertAnyPos(int pos, int x){
    struct node *p=first;
    struct node *t;
    if(pos<0 || pos>count(first)){
        return;
    }
    if(pos==0){
        insertbeginning(x);
        return;
    }
    for(int i = 0; i<pos-1; i++){
        p=p->next;
    }
    t = (struct node*)malloc(sizeof(struct node));
    t->data = x;
    t->next = p->next;
    t->prev = p;
    if(p->next!=NULL){
        p->next->prev = t;
    }
    p->next = t;
}
int delete(int pos){
    struct node *p=first;
    int x=-1;
    if(pos<1 || pos>count(first)){
        return -1;
    }
    if(pos==1){
        first = first->next;
        if(first){
            first->prev=NULL;
        }
        x = p->data;
        free(p);
        return x;
    }
    for(int i=1; i<pos; i++){
        p=p->next;
    }
    p->prev->next=p->next;
    if(p->next!=NULL){
        p->next->prev=p->prev;
    }
    x = p->data;
    free(p);
    return x;
}
//reverse 
void reverseDLL(){
    struct node *p = first;
    struct node *temp = NULL;
    while(p!=NULL){
        temp = p->next;
        p->next = p->prev;
        p->prev = p->next;
        if(p->prev==NULL){
            first = p;
        }
        p=p->prev;
    }
}
int main(){
    int A[] = {10, 20, 30, 40, 50};
    createDLL(A, 5);
    display(first);
    reverseDisplay(first);
    search(first, 30);
    insertbeginning(20);
    insertAnyPos(3, 55);
    delete(4);
    display(first);
    reverseDLL(first);
}