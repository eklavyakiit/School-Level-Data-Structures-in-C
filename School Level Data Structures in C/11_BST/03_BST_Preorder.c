#include <stdio.h>
#include <stdlib.h>

// ================= NODE =================

struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

struct Node *root = NULL;

// ================= STACK =================

struct Stack
{
    int size;
    int top;
    struct Node **S;
};

void Push(struct Stack *st, struct Node *x)
{
    if (st->top == st->size - 1)
        printf("Stack Overflow\n");
    else
        st->S[++st->top] = x;
}

struct Node *Pop(struct Stack *st)
{
    if (st->top == -1)
        return NULL;

    return st->S[st->top--];
}

struct Node *StackTop(struct Stack *st)
{
    if (st->top == -1)
        return NULL;

    return st->S[st->top];
}

int IsEmpty(struct Stack *st)
{
    return st->top == -1;
}

// ================= CREATE NODE =================

struct Node *CreateNode(int key)
{
    struct Node *t;

    t = (struct Node *)malloc(sizeof(struct Node));

    t->data = key;
    t->lchild = NULL;
    t->rchild = NULL;

    return t;
}

// ================= CREATE BST FROM PREORDER =================

struct Node *CreateFromPreorder(int pre[], int n)
{
    struct Node *p;
    struct Node *t;

    struct Stack st;

    st.size = n;
    st.top = -1;
    st.S = (struct Node **)malloc(st.size * sizeof(struct Node *));

    root = CreateNode(pre[0]);
    p = root;

    int i = 1;

    while (i < n)
    {
        if (pre[i] < p->data)
        {
            t = CreateNode(pre[i]);

            p->lchild = t;

            Push(&st, p);

            p = t;

            i++;
        }
        else
        {
            if (IsEmpty(&st) || pre[i] < StackTop(&st)->data)
            {
                t = CreateNode(pre[i]);

                p->rchild = t;

                p = t;

                i++;
            }
            else
            {
                p = Pop(&st);
            }
        }
    }

    free(st.S);

    return root;
}

// ================= INORDER =================

void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

// ================= PREORDER =================

void Preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

// ================= MAIN =================

int main()
{
    int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int n = sizeof(pre) / sizeof(pre[0]);

    root = CreateFromPreorder(pre, n);

    printf("Inorder Traversal:\n");
    Inorder(root);

    printf("\n\nPreorder Traversal:\n");
    Preorder(root);

    return 0;
}