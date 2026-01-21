#include <iostream>
using namespace std;

// Node structure
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Function to delete first occurrence of a value
Node *deleteByValue(Node *head, int value)
{

    // Case 1: Empty list
    if (head == nullptr)
    {
        return head;
    }

    // Case 2: Value found at head
    if (head->data == value)
    {
        Node *temp = head; // store old head
        head = head->next; // move head
        delete temp;       // free memory
        return head;
    }

    Node *temp = head;    // current node
    Node *prev = nullptr; // previous node

    // Traverse the list
    while (temp != nullptr)
    {

        // If target value is found
        if (temp->data == value)
        {
            prev->next = temp->next; // bypass node
            delete temp;             // delete node
            break;                   // delete ONLY first occurrence
        }

        prev = temp;       // move prev
        temp = temp->next; // move temp
    }

    // If value not found, list remains unchanged
    return head;
}

// Helper function to print list
void traverse(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    /*
        Initial list:
        10 -> 20 -> 30 -> 20 -> 40 -> NULL
    */

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(20);
    head->next->next->next->next = new Node(40);

    int target = 20;

    head = deleteByValue(head, target);

    traverse(head);

    return 0;
}
/*
DRY RUN (value = 20)

Initial Linked List:
head → 10 → 20 → 30 → 20 → 40 → NULL

--------------------------------------------------
Call: head = deleteByValue(head, 20)
--------------------------------------------------

Inside deleteByValue(head, value):

1) head is NOT NULL.
2) head->data = 10, which is NOT equal to 20.
   So we do not delete the head.

Initialize:
temp = head → 10 → 20 → 30 → 20 → 40 → NULL
prev = NULL

------------------------------------
Iteration 1:
------------------------------------
temp → 10
10 != 20

Move pointers:
prev = 10
temp = 20

------------------------------------
Iteration 2:
------------------------------------
temp → 20   (target found)

prev → 10
temp → 20
temp->next → 30

Execute:
prev->next = temp->next
So:
10 → 30

delete temp
Node containing first 20 is removed from memory.

Linked List becomes:
head → 10 → 30 → 20 → 40 → NULL

Loop breaks (only first occurrence is deleted).

--------------------------------------------------
Back in main:
--------------------------------------------------

head → 10 → 30 → 20 → 40 → NULL

--------------------------------------------------
Call: traverse(head)
--------------------------------------------------

temp → 10 → 30 → 20 → 40 → NULL
print 10
print 30
print 20
print 40
stop

Output:
10 30 20 40
*/
