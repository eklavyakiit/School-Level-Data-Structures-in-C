#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};
void createQueue(struct Queue *q, int size){
    q->size = size;
    q->Q = (int*)malloc(q->size * sizeof(int));
    q->front = q->rear = 0;
}
void CircularEnqueue(struct Queue *q, int x){
    if((q->rear+1)%q->size == q->front){
        printf("Circular Queue is FULL\n");
    }else{
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}
int CircularDequeue(struct Queue *q){
    int x = -1;
    if(q->front == q->rear){
        printf("Queue is EMPTY\n");
    }else{
        q->front = (q->front+1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}
void Display(struct Queue q){
    for(int i = (q.front + 1)%q.size; i!= (q.rear+1)%q.size; i = (i+1)%q.size){
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}
int main(){
    struct Queue q;
    createQueue(&q, 5);
    CircularEnqueue(&q, 10);
    CircularEnqueue(&q, 20);
    CircularEnqueue(&q, 30);
    CircularEnqueue(&q, 40);
    Display(q);
     printf("Deleted = %d\n", CircularDequeue(&q));
    printf("Deleted = %d\n", CircularDequeue(&q));

    Display(q);

    CircularEnqueue(&q, 50);
    CircularEnqueue(&q, 60);

    Display(q);

    return 0;
}