#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

void Enqueue(int x){
    struct node *t;
    t = (struct node*)malloc(sizeof(struct node));
    if(t==NULL){
        printf("MEMORY FULL, NODE NOT CREATED");
    }else{
        t->data = x;
        t->next = NULL;
        if(front == NULL){
            front = rear = t;
        } else{
            rear->next = t;
            rear = t;
        }
    }
}
int Dequeue(){
    int x = -1;
    if(front == NULL){
        printf("Queue is EMPTY\n");
    }else{
        struct node *p;
        p = front;
        x = p->data;
        front = front->next;
        free(p);
        if(front == NULL){
            printf("All items deleted!");
            rear = NULL;
        }
    }
    return x;
}
void Display(){
    struct node *p = front;
    while(p){
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}
int main(){
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Enqueue(50);
    Enqueue(60);
    Enqueue(70);
    Display();
    Dequeue();
    Dequeue();
    Display();
    return 0;
}