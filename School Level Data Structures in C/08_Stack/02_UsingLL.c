#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *top = NULL;
void push(int x){
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    if(t==NULL){
        printf("Stack Overflow");
        return;
    }else{
        t->data = x;
        t->next = top;
        top = t;
    }
}
int pop(){
    struct node *p;
    int x = -1;
    if(top == NULL){
        printf("Stack is Empty!");
    }else{
        p = top;
        top= top->next;
        x = p->data;
        free(p);
    }
    return x;
}
int peek(int pos){
    int x = -1;
    struct node *p;
    p = top;
    for(int i = 0; p!=NULL && i<pos-1; i++){
        p=p->next;
    }
    if(p!=NULL){
        printf("%d", p->data);
    }else{
        return x;
    }
}
int display(){
    struct node *p = top;
    while(p!=NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    display();
    pop();
    display();

}