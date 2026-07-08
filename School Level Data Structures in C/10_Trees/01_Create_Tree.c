#include<stdio.h>
#include<stdlib.h>

// ================= TREE NODE =================

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Node *root = NULL;


// ================= QUEUE =================

struct QNode
{
    struct Node *data;
    struct QNode *next;
};

struct QNode *front = NULL;
struct QNode *rear = NULL;


void Enqueue(struct Node *x)
{
    struct QNode *t;

    t = (struct QNode *)malloc(sizeof(struct QNode));

    if(t == NULL)
    {
        printf("Queue Full\n");
    }
    else
    {
        t->data = x;
        t->next = NULL;

        if(front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}


struct Node *Dequeue()
{
    struct Node *x = NULL;

    if(front == NULL)
        return NULL;

    struct QNode *p = front;

    x = p->data;

    front = front->next;

    free(p);

    if(front == NULL)
        rear = NULL;

    return x;
}


int isEmpty()
{
    return front == NULL;
}


// ================= CREATE TREE =================

void CreateTree()
{
    struct Node *p;
    struct Node *t;

    int x;

    printf("Enter Root Value : ");
    scanf("%d",&x);

    root = (struct Node *)malloc(sizeof(struct Node));

    root->data = x;
    root->lchild = NULL;
    root->rchild = NULL;

    Enqueue(root);

    while(!isEmpty())
    {
        p = Dequeue();

        printf("Enter Left Child of %d (-1 for NULL): ",p->data);
        scanf("%d",&x);

        if(x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));

            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;

            p->lchild = t;

            Enqueue(t);
        }

        printf("Enter Right Child of %d (-1 for NULL): ",p->data);
        scanf("%d",&x);

        if(x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));

            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;

            p->rchild = t;

            Enqueue(t);
        }
    }
}


// ================= LEVEL ORDER =================

void LevelOrder(struct Node *root)
{
    struct Node *p;

    if(root == NULL)
        return;

    Enqueue(root);

    while(!isEmpty())
    {
        p = Dequeue();

        printf("%d ",p->data);

        if(p->lchild)
            Enqueue(p->lchild);

        if(p->rchild)
            Enqueue(p->rchild);
    }
}


int main()
{
    CreateTree();

    printf("\nLevel Order Traversal:\n");

    LevelOrder(root);

    return 0;
}