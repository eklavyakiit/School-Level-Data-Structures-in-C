#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void Enqueue(int x)
{
    struct Node *t;

    t = (struct Node *)malloc(sizeof(struct Node));

    if(t == NULL)
    {
        printf("Queue is Full\n");
    }
    else
    {
        t->data = x;

        if(front == NULL)
        {
            front = rear = t;
            rear->next = front;
        }
        else
        {
            t->next = front;
            rear->next = t;
            rear = t;
        }
    }
}

int Dequeue()
{
    int x = -1;

    if(front == NULL)
    {
        printf("Queue is Empty\n");
    }
    else if(front == rear)
    {
        x = front->data;

        free(front);

        front = rear = NULL;
    }
    else
    {
        struct Node *p = front;

        x = p->data;

        front = front->next;

        rear->next = front;

        free(p);
    }

    return x;
}

void Display()
{
    if(front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    struct Node *p = front;

    do
    {
        printf("%d ", p->data);

        p = p->next;

    }while(p != front);

    printf("\n");
}

int main()
{
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);

    Display();

    printf("Deleted = %d\n", Dequeue());

    Display();

    Enqueue(50);

    Display();

    return 0;
}