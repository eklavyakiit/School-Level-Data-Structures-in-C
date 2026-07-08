#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
};

struct Node *root = NULL;

/* ================= HEIGHT ================= */

int NodeHeight(struct Node *p)
{
    int hl, hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return (hl > hr) ? hl + 1 : hr + 1;
}

/* ================= BALANCE FACTOR ================= */

int BalanceFactor(struct Node *p)
{
    int hl, hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl - hr;
}

/* ================= LL ROTATION ================= */

struct Node *LLRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (root == p)
        root = pl;

    return pl;
}

/* ================= RR ROTATION ================= */

struct Node *RRRotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if (root == p)
        root = pr;

    return pr;
}

/* ================= LR ROTATION ================= */

struct Node *LRRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if (root == p)
        root = plr;

    return plr;
}

/* ================= RL ROTATION ================= */

struct Node *RLRotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->rchild = pr;
    prl->lchild = p;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if (root == p)
        root = prl;

    return prl;
}

/* ================= INSERT ================= */

struct Node *RInsert(struct Node *p, int key)
{
    struct Node *t = NULL;

    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));

        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;

        return t;
    }

    if (key < p->data)
        p->lchild = RInsert(p->lchild, key);

    else if (key > p->data)
        p->rchild = RInsert(p->rchild, key);

    p->height = NodeHeight(p);

    /* LL */
    if (BalanceFactor(p) == 2 &&
        BalanceFactor(p->lchild) == 1)
        return LLRotation(p);

    /* LR */
    if (BalanceFactor(p) == 2 &&
        BalanceFactor(p->lchild) == -1)
        return LRRotation(p);

    /* RR */
    if (BalanceFactor(p) == -2 &&
        BalanceFactor(p->rchild) == -1)
        return RRRotation(p);

    /* RL */
    if (BalanceFactor(p) == -2 &&
        BalanceFactor(p->rchild) == 1)
        return RLRotation(p);

    return p;
}

/* ================= INORDER ================= */

void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

/* ================= MAIN ================= */

int main()
{
    root = RInsert(root, 30);
    root = RInsert(root, 20);
    root = RInsert(root, 10);
    root = RInsert(root, 25);
    root = RInsert(root, 40);
    root = RInsert(root, 50);

    printf("Inorder : ");
    Inorder(root);

    return 0;
}