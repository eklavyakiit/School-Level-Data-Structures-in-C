#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

//------------------- Create -------------------

void create(int A[], int n)
{
    struct Node *t, *last;
    int i;

    if (n == 0)
        return;

    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    head->prev = head;

    last = head;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];

        t->next = head;
        t->prev = last;

        last->next = t;
        head->prev = t;

        last = t;
    }
}

//------------------- Display Forward -------------------

void Display()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    struct Node *p = head;

    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);

    printf("\n");
}

//------------------- Display Backward -------------------

void DisplayReverse()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    struct Node *p = head->prev;

    do
    {
        printf("%d ", p->data);
        p = p->prev;
    } while (p != head->prev);

    printf("\n");
}

//------------------- Count -------------------

int Count()
{
    if (head == NULL)
        return 0;

    int count = 0;
    struct Node *p = head;

    do
    {
        count++;
        p = p->next;
    } while (p != head);

    return count;
}

//------------------- Insert at Beginning -------------------

void InsertFirst(int x)
{
    struct Node *t;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (head == NULL)
    {
        t->next = t;
        t->prev = t;
        head = t;
    }
    else
    {
        t->next = head;
        t->prev = head->prev;

        head->prev->next = t;
        head->prev = t;

        head = t;
    }
}

//------------------- Insert at End -------------------

void InsertLast(int x)
{
    struct Node *t;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (head == NULL)
    {
        t->next = t;
        t->prev = t;
        head = t;
    }
    else
    {
        t->next = head;
        t->prev = head->prev;

        head->prev->next = t;
        head->prev = t;
    }
}

//------------------- Insert at Position -------------------

void Insert(int pos, int x)
{
    if (pos < 0 || pos > Count())
        return;

    if (pos == 0)
    {
        InsertFirst(x);
        return;
    }

    struct Node *p = head;

    for (int i = 0; i < pos - 1; i++)
        p = p->next;

    struct Node *t = (struct Node *)malloc(sizeof(struct Node));

    t->data = x;
    t->next = p->next;
    t->prev = p;

    p->next->prev = t;
    p->next = t;
}

//------------------- Delete First -------------------

int DeleteFirst()
{
    if (head == NULL)
        return -1;

    int x;

    if (head->next == head)
    {
        x = head->data;
        free(head);
        head = NULL;
        return x;
    }

    struct Node *p = head;

    x = p->data;

    head->prev->next = head->next;
    head->next->prev = head->prev;

    head = head->next;

    free(p);

    return x;
}

//------------------- Delete Last -------------------

int DeleteLast()
{
    if (head == NULL)
        return -1;

    if (head->next == head)
        return DeleteFirst();

    struct Node *last = head->prev;

    int x = last->data;

    last->prev->next = head;
    head->prev = last->prev;

    free(last);

    return x;
}

//------------------- Delete at Position -------------------

int Delete(int pos)
{
    if (pos < 1 || pos > Count())
        return -1;

    if (pos == 1)
        return DeleteFirst();

    struct Node *p = head;

    for (int i = 1; i < pos; i++)
        p = p->next;

    int x = p->data;

    p->prev->next = p->next;
    p->next->prev = p->prev;

    free(p);

    return x;
}

//------------------- Search -------------------

struct Node *Search(int key)
{
    if (head == NULL)
        return NULL;

    struct Node *p = head;

    do
    {
        if (p->data == key)
            return p;

        p = p->next;

    } while (p != head);

    return NULL;
}

//------------------- Main -------------------

int main()
{
    int A[] = {10, 20, 30, 40, 50};

    create(A, 5);

    printf("Forward : ");
    Display();

    printf("Backward : ");
    DisplayReverse();

    InsertFirst(5);
    InsertLast(60);
    Insert(3, 25);

    printf("After Insertions : ");
    Display();

    DeleteFirst();
    DeleteLast();
    Delete(3);

    printf("After Deletions : ");
    Display();

    printf("Count = %d\n", Count());

    if (Search(40))
        printf("40 Found\n");
    else
        printf("40 Not Found\n");

    return 0;
}