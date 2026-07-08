#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

struct Node *createNode(int coeff, int exp)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->coeff = coeff;
    temp->exp = exp;
    temp->next = NULL;
    return temp;
}

struct Node *addPolynomial(struct Node *p1, struct Node *p2)
{
    struct Node *head = NULL, *last = NULL, *temp;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp > p2->exp)
        {
            temp = createNode(p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else if (p1->exp < p2->exp)
        {
            temp = createNode(p2->coeff, p2->exp);
            p2 = p2->next;
        }
        else
        {
            temp = createNode(p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }

        if (head == NULL)
        {
            head = last = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }

    while (p1 != NULL)
    {
        temp = createNode(p1->coeff, p1->exp);

        if (head == NULL)
            head = last = temp;
        else
        {
            last->next = temp;
            last = temp;
        }

        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        temp = createNode(p2->coeff, p2->exp);

        if (head == NULL)
            head = last = temp;
        else
        {
            last->next = temp;
            last = temp;
        }

        p2 = p2->next;
    }

    return head;
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%dx^%d", p->coeff, p->exp);

        if (p->next != NULL)
            printf(" + ");

        p = p->next;
    }

    printf("\n");
}
int main()
{
    struct Node *p1 = NULL, *p2 = NULL, *p3 = NULL;

    /* Polynomial 1 : 5x^3 + 4x^2 + 7x + 3 */

    p1 = createNode(5, 3);
    p1->next = createNode(4, 2);
    p1->next->next = createNode(7, 1);
    p1->next->next->next = createNode(3, 0);

    /* Polynomial 2 : 6x^2 + 5 */

    p2 = createNode(6, 2);
    p2->next = createNode(5, 0);

    printf("Polynomial 1 : ");
    display(p1);

    printf("Polynomial 2 : ");
    display(p2);

    p3 = addPolynomial(p1, p2);

    printf("Result : ");
    display(p3);

    return 0;
}