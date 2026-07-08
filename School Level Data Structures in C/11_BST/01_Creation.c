#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};
struct node *root = NULL;
void insert(int key){
    struct node *t = root;
    struct node *r = NULL;
    if(root==NULL){
        root = (struct node*)malloc(sizeof(struct node));
        root->data = key;
        root->lchild = root->rchild = NULL;
        return;
    }
    while(t!=NULL){
        r=t;
        if(key == t->data){
            return;
        }else if(key < t->data){
            t=t->lchild;
        }else{
            t=t->rchild;
        }
    }
    t = (struct node*)malloc(sizeof(struct node));
    t->data = key;
    t->lchild = t->rchild = NULL;
    if(key < r->data){
        r->lchild = t;
    }else{
        r->rchild = t;
    }
}
struct node *search(struct node *t, int key){
    while(t!=NULL){
        if(key==t->data){
            return t;
        }else if(key<t->data){
            t=t->lchild;
        }else{
            t=t->rchild;
        }
    }
    return NULL;
}
struct node *Rsearch(struct node *t, int key){
    if(t==NULL){
        return NULL;
    }if(key==t->data){
        return t;
    }else if(key<t->data){
        return Rsearch(t->lchild, key);
    }else{
        return Rsearch(t->rchild, key);
    }
}
void preorder(struct node *t){
    if(t!=NULL){
        printf("%d ", t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}
//inorder predecessor - right most element of the left subtree or largest element in left subtree
//inorder successor - leftmost element of the right subtree or smallest element in right subtree
int height(struct node *p){
    int x, y;
    if(p!=NULL){
        return 0;
    }
    x = height(p->lchild);
    y = height(p->rchild);
    return (x>y)? x + 1 : y + 1;
}
struct node *Inpre(struct node *p){
    while(p && p->rchild !=NULL){
        p=p->rchild;
    }
    return p;
}
struct node *InSucc(struct node *p)
{
    while(p && p->lchild != NULL)
        p = p->lchild;

    return p;
}
struct node *Delete(struct node *p, int key)
{
    struct node *q;

    if(p == NULL)
        return NULL;

    // Leaf node
    if(p->lchild == NULL && p->rchild == NULL)
    {
        if(p == root)
            root = NULL;

        free(p);
        return NULL;
    }

    if(key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if(key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        if(Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);

            p->data = q->data;

            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p->rchild);

            p->data = q->data;

            p->rchild = Delete(p->rchild, q->data);
        }
    }

    return p;
}
int main()
{
    struct node *temp;

    // Insert nodes
    insert(30);
    insert(20);
    insert(40);
    insert(10);
    insert(25);
    insert(35);
    insert(50);
    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");
    temp = search(root, 25);
    if(temp != NULL)
        printf("25 found using Iterative Search\n");
    else
        printf("25 not found\n");

    temp = Rsearch(root, 35);
    if(temp != NULL)
        printf("35 found using Recursive Search\n");
    else
        printf("35 not found\n");

    return 0;
}