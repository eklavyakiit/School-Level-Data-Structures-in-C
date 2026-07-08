#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;  
}*first = NULL;

void createCLL(int A[], int n){
    struct node *t, *last;
    first = (struct node*)malloc(sizeof(struct node));
    first->data = A[0];
    first->next = first;
    last = first;

    for(int i=1; i<n; i++){
        t = (struct node*)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = first;
        last->next = t;
        last = t;
    }
}
void display(struct node *p){
    if(p==NULL){
        return;
    }
    printf("Your new updated List is: ");
    do{
        printf("%d ", p->data);
        p=p->next;
    }while(p!=first);
    printf("\n");
}
//insert beginning
void insertBeginning(int x){
    struct node *t, *p;
    t = (struct node*)malloc(sizeof(struct node));
    t->data = x;
    if(first == NULL){
        first = t;
        first->next = first;
    }else{
        p=first;
        while(p->next!=first){
            p=p->next;
        }
        p->next = t;
        t->next = first;
        first =t;
    }
}
//insert at end
void insertEnd(int x){
    struct node *t, *p;
    t = (struct node*)malloc(sizeof(struct node));
    t->data = x;
    if(first == NULL){
        first = t;
        first->next = t;
    }else{
        p=first;
        while(p->next != first){
            p=p->next;
        }
        p->next = t;
        t->next = first;
    }

}
//insert at any pos
void insert(int x, int index){
    struct node *t, *p;
    t = (struct node*)malloc(sizeof(struct node));
    t->data = x;
    if(first == NULL){
        first = t;
        first->next = first;
    }else{
        p=first;
        for(int i =0; i<index-1; i++){
            p=p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}
int deleteFirst(){
    struct node *p, *temp;
    int x = -1;
    if(first==NULL){
        return x;
    }
    if(first->next == first){
        x=first->data;
        free(first);
        first=NULL;
        return x;
    }
    p = first;
    while(p->next!=first){
        p=p->next;
    }
    temp=first;
    p->next=first->next;
    first = first->next;
    x = temp->data;
    free(temp);
    return x;
}
//delete at end position
int deleteEnd(){
    struct node *p, *q;
    int x = -1;
    if(first == NULL){
        return x;
    }
    if(first->next == first){
        x = first->data;
        free(first);
        first = NULL;
        return x;
    }
    p=q=first;
    while(p->next != first){
        q=p;
        p=p->next;
    }
    q->next=first;
    x = p->data;
    free(p);
    return x;
}
//delete at any position
int delete(int index){
    struct node *p, *q;
    int x = -1;

    if(first == NULL){
        return x;
    }

    // Delete first node
    if(index == 0){
        return deleteFirst();
    }

    p = first;
    q = NULL;

    // Move p to the node at index
    for(int i = 0; i < index; i++){
        q = p;
        p = p->next;

        // If we've come back to first before reaching index
        if(p == first){
            return -1;   // Invalid index
        }
    }

    q->next = p->next;
    x = p->data;
    free(p);

    return x;
}
int main(){
    int A[] = {10, 20, 30, 40, 50};
    createCLL(A, 5);
    insertBeginning(5);
    display(first);
    insertEnd(55);
    display(first);
    insert(25,1);
    display(first);
    deleteFirst(first);
    display(first);
    deleteEnd(first);
    display(first);
    delete(0);
    display(first);
    return 0;
}