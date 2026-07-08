#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
};
struct node *root = NULL;

struct qnode{
    struct node *data;
    struct qnode *next;
};
struct qnode *front = NULL;
struct qnode *rear = NULL;

void enqueue(struct node *x){
    struct qnode *t;
    t = (struct qnode*)malloc(sizeof(struct qnode));

    if(t==NULL){
        printf("HEAP IS FULL! NODE NOT CREATED\n");
    }else{
        t->data = x;
        t->next = NULL;

        if(front == NULL){
            front = rear = t;
        }else{
            rear->next = t;
            rear = t;
        }
    }
}

struct node *dequeue(){
    struct node *x = NULL;

    if(front == NULL){
        return NULL;
    }

    struct qnode *p;
    p = front;

    x = p->data;
    front = front->next;

    free(p);

    if(front == NULL){
        rear = NULL;
    }

    return x;
}

int isempty(){
    return front == NULL;
}

// tree creation
void createTree(){
    struct node *p;
    struct node *t;
    int x;

    printf("Enter Root Value: ");
    scanf("%d", &x);

    root = (struct node*)malloc(sizeof(struct node));

    root->data = x;
    root->lchild = root->rchild = NULL;

    enqueue(root);

    while(!isempty()){

        p = dequeue();

        printf("Enter left child of %d (-1 for no Value): ", p->data);
        scanf("%d", &x);

        if(x!=-1){
            t = (struct node*)malloc(sizeof(struct node));

            t->data = x;
            t->rchild = t->lchild = NULL;

            p->lchild = t;

            enqueue(t);
        }

        printf("Enter right child of %d (-1 for no Value): ", p->data);
        scanf("%d", &x);

        if(x!=-1){
            t = (struct node*)malloc(sizeof(struct node));

            t->data = x;
            t->rchild = t->lchild = NULL;

            p->rchild = t;

            enqueue(t);
        }
    }
}

void preorder(struct node *t){
    if(t!=NULL){
        printf("%d ", t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

void inorder(struct node *t){
    if(t!=NULL){
        inorder(t->lchild);
        printf("%d ", t->data);
        inorder(t->rchild);
    }
}
void postorder(struct node *t){
    if(t!=NULL){
        postorder(t->lchild);
        postorder(t->rchild);
        printf("%d ", t->data);
    }
}
int main()
{
    createTree();

    printf("\nInorder Traversal:\n");
    inorder(root);

    printf("\nPreorder Traversal:\n");
    preorder(root);

    printf("\nPostorder Traversal:\n");
    postorder(root);

    return 0;
}