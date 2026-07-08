#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
}*first = NULL;

void createNode(int A[], int n){
    struct node *t, *last;
    first = (struct node*)malloc(sizeof(struct node));
    first -> data = A[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i<n; i++){
        t = (struct node*)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
//display
void display(struct node*p){
    printf("\nYour New List Contents are:");
    while(p!=NULL){
        printf("%d ", p->data);
         p = p->next;
    }
}
//count nodes
int countNodes(struct node*p){
    int count = 0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}
//sum
int sum(struct node*p){
    int sum = 0;
    while(p!=NULL){
        sum = sum + p->data;
        p=p->next;
    }
    return sum;
}
//max
int max(struct node*p){
    int max = p->data;
    while(p!=NULL){
        if(p->data > max){
           max = p->data;
        }
        p = p->next;
    }
    return max;
}
//min
int min(struct node*p){
    int min = p->data;
    while(p!=NULL){
        if(p->data < min){
            min = p->data;
        }
        p = p->next;
    }
    return min;
}
//search
int search(struct node*p, int key){
    int index=0;
    while(p!=NULL){
        if(p->data == key){
            return index;
        }
        p=p->next;
        index++;
    }
    return -1;
}
//inserting at any index
void insert(struct node **head, int index, int x){
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->data = x;
    if(index == 0){
        t->next = *head;
        *head = t;
        return;
    }
    struct node *p = *head;
    for(int i = 0; i<index-1 && p!=NULL; i++){
        p = p->next;
        if(p!=NULL){
            t->next = p->next;
            p->next = t;
        }
    }
    struct node *q = *head;
    printf("\nInserting at any Index: ");
    while(q!=NULL){
        printf("%d ", q->data);
        q=q->next;
    }
}

//inserting at last
void insertLast(struct node **head, int x){
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    if(*head==NULL){
        *head=t;
        return;
    }
    struct node *p = *head;
    while(p->next !=NULL){
        p = p->next;
    }
    p->next = t;    
    struct node *q = *head;
    printf("\nInserting at Last Position: ");
    while(q!=NULL){
        printf("%d ", q->data);
        q=q->next;
    }
}

//inserting in sorted
void insertSorted(struct node **head, int x){
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    //beginning postion
    if(*head == NULL || (*head)->data >= x){
        t->next = *head;
        *head = t;
        return;
    }
    //at any index
    struct node *p = *head;
    while(p->next!=NULL && p->next->data < x){
        p = p->next;
    }
    t->next = p->next;
    p->next = t;
    //print
    struct node *q = *head;
    printf("\nInserted at Sorted List: ");
    while(q!=NULL){
        printf("%d ", q->data);
        q=q->next;
    }
}
//deleting
int deleteNode(struct node **head, int index)
{
    if(*head == NULL)
        return -1;

    struct node *p = *head;
    int x;

    // Delete first node
    if(index == 0)
    {
        *head = p->next;
        x = p->data;
        free(p);
        return x;
    }

    struct node *q = NULL;

    for(int i = 0; i < index && p != NULL; i++)
    {
        q = p;
        p = p->next;
    }

    if(p != NULL)
    {
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }

    return -1;
}
//remove duplicates
void removeDuplicates(struct node **head){
    struct node *q = *head;
    struct node *p = q->next;
    while(p!=NULL){
        if(p->data!=q->data){
            q=p;
            p=p->next;
        }
        else{
            q->next = p->next;
            free(p);
            p=q->next;
        }
    }

}
//reversing
void reverse(struct node **head){
    struct node *p = *head;
    struct node *q = NULL;
    struct node *r = NULL;

    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next = r;
    }
    *head = q;
}

int main(){
    int A[]={10, 20, 30, 40, 50};
    createNode(A, 5);
    display(first);
    printf("\nTotal number of nodes: %d", countNodes(first));
    printf("\nThe Sum of all nodes is: %d", sum(first));
    printf("\nThe maximum element is: %d", max(first));
    printf("\nThe minimum element is: %d", min(first));
    printf("\nThe Given element is found at index: %d", search(first, 40));
    insert(&first, 2, 25);
    insertLast(&first, 55);
    insertSorted(&first, 45);
    deleteNode(&first, 7);
    display(first);
    reverse(&first);
    display(first);
    return 0;
}