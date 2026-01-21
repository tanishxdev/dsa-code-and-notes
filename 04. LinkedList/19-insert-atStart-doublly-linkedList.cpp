#include <bits/stdc++.h>
using namespace std;

/*
GOAL:
1) Understand how a Doubly Linked List node works
2) Insert nodes at the START of the list
3) Maintain both `prev` and `next` pointers correctly
4) Build a list like:
      30 <-> 20 <-> 10 <-> NULL
5) Traverse and print the list
*/

// ------------------------------
// Doubly Linked List Node
// ------------------------------
class Node
{
public:
    int data;   // Stores the value of this node
    Node *prev; // Points to the previous node
    Node *next; // Points to the next node

    // Constructor
    Node(int data)
    {
        this->data = data; // Store value
        this->prev = NULL; // Initially no previous node
        this->next = NULL; // Initially no next node
    }
};

// ------------------------------
// Insert at Start
// ------------------------------
Node *insertAtStart(Node *head, int val)
{
    /*
    We are inserting a new node BEFORE the current head.

    Before:
        head → A ↔ B ↔ C

    After inserting X:
        X ↔ A ↔ B ↔ C
        head should now point to X
    */

    // Step 1: Create a new node in heap
    Node *newNode = new Node(val);

    // Step 2: If the list is empty
    // new node itself becomes the head
    if (head == nullptr)
    {
        return newNode;
    }

    // Step 3: Connect new node to old head
    newNode->next = head; // newNode → old head

    // Step 4: Since new node is at start,
    // it has no previous node
    newNode->prev = NULL;

    // Step 5: Old head's prev should point to new node
    head->prev = newNode;

    // Step 6: Move head to new node
    head = newNode;

    // Step 7: Return updated head
    return head;
}

// ------------------------------
// Print Doubly Linked List
// ------------------------------
void printDLL(Node *head)
{
    // temp is used for traversal so that
    // the original head is not lost
    Node *temp = head;

    // Move forward using next pointers
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    /*
    We will build the list like this:

    Start with empty:
    NULL

    Insert 10:
    10

    Insert 20:
    20 ↔ 10

    Insert 30:
    30 ↔ 20 ↔ 10
    */

    // Step 1: Start with empty list
    Node *head = NULL;

    // Step 2: Insert nodes at start
    head = insertAtStart(head, 10);
    head = insertAtStart(head, 20);
    head = insertAtStart(head, 30);

    // Step 3: Print the list
    printDLL(head);
}
