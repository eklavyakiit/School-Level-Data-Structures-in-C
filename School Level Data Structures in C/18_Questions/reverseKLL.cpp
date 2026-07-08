#include <iostream>
using namespace std;

// Definition of Node
class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Insert at end
void insert(Node *&head, int x)
{
    Node *newNode = new Node(x);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Display Linked List
void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL\n";
}

// Reverse every k nodes
Node* reverseKGroup(Node* head, int k)
{
    // Check if k nodes exist
    Node* temp = head;
    int count = 0;

    while (temp != NULL && count < k)
    {
        temp = temp->next;
        count++;
    }

    // Less than k nodes left
    if (count < k)
        return head;

    // Reverse first k nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    count = 0;

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Connect remaining list
    head->next = reverseKGroup(curr, k);

    return prev;
}

int main()
{
    Node* head = NULL;

    // Create Linked List
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 7);
    insert(head, 8);

    cout << "Original List:\n";
    display(head);

    int k;

    cout << "\nEnter k: ";
    cin >> k;

    head = reverseKGroup(head, k);

    cout << "\nAfter Reversing Every " << k << " Nodes:\n";
    display(head);

    return 0;
}