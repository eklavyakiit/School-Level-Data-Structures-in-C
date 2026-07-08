#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
};
struct node *root = NULL;
int height(struct node *p) {
    int x, y;
    if (p == NULL)
        return 0;
    x = height(p->lchild);
    y = height(p->rchild);
    return (x > y) ? x + 1 : y + 1;
}
// Inorder predecessor: rightmost (largest) node of the given subtree.
// Call as InPre(p->lchild) to get the predecessor of p.
struct node *InPre(struct node *p) {
    while (p && p->rchild != NULL)
        p = p->rchild;
    return p;
}
struct node *InSucc(struct node *p) {
    while (p && p->lchild != NULL)
        p = p->lchild;
    return p;
}
struct node *Delete(struct node *p, int key) {
    struct node *q;

    if (p == NULL)
        return NULL;             

    if (key < p->data) {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data) {
        p->rchild = Delete(p->rchild, key);
    }
    else {
        if (p->lchild == NULL && p->rchild == NULL) {
            if (p == root)
                root = NULL;
            free(p);
            return NULL;
        }
        else if (height(p->lchild) > height(p->rchild)) {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }

    return p;
}
struct node *insert(struct node *p, int key) {
    if (p == NULL) {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        return p;
    }
    if (key < p->data)
        p->lchild = insert(p->lchild, key);
    else if (key > p->data)
        p->rchild = insert(p->rchild, key);
    return p;
}

void inorder(struct node *p) {
    if (p == NULL)
        return;
    inorder(p->lchild);
    printf("%d ", p->data);
    inorder(p->rchild);
}

int main() {
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    printf("Before deletion: ");
    inorder(root);
    printf("\n");

    root = Delete(root, 30);

    printf("After deleting 30: ");
    inorder(root);
    printf("\n");

    return 0;
}