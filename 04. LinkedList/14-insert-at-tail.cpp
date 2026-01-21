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

// Function to insert a node at the tail
Node *insertTail(Node *head, int value)
{

    // Case 1: Empty list
    // If head is null, the new node itself becomes the head
    if (head == nullptr)
    {
        return new Node(value);
    }

    // Temporary pointer to traverse the list
    Node *temp = head;

    // Move temp until it reaches the last node
    // Last node is identified by temp->next == nullptr
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    // temp is now the last node
    // Attach the new node at the end
    temp->next = new Node(value);

    // Head remains unchanged
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
        10 -> 20 -> 30 -> NULL
    */

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // Insert at tail
    head = insertTail(head, 40);

    traverse(head);

    return 0;
}

/*
DRY RUN (insertTail with value = 40)

Initial Linked List:
head → 10 → 20 → 30 → NULL

--------------------------------------------------
Call: head = insertTail(head, 40)
--------------------------------------------------

Inside insertTail(head, value):

1) head is NOT NULL, so we do not create a new head.

2) temp = head
   temp → 10 → 20 → 30 → NULL

------------------------------------
Traversal to find last node
------------------------------------

First check:
temp->next = 20 (not NULL)
Move temp:
temp → 20 → 30 → NULL

Second check:
temp->next = 30 (not NULL)
Move temp:
temp → 30 → NULL

Third check:
temp->next = NULL
Stop loop.

Now temp is pointing to the LAST node:
temp → 30 → NULL

------------------------------------
Insert new node
------------------------------------

Create new node:
new Node(40)

Attach it:
temp->next = new Node(40)

Now list becomes:
head → 10 → 20 → 30 → 40 → NULL

Return head.

--------------------------------------------------
Back in main:
--------------------------------------------------

head → 10 → 20 → 30 → 40 → NULL

--------------------------------------------------
Call: traverse(head)
--------------------------------------------------

temp → 10 → 20 → 30 → 40 → NULL
print 10
print 20
print 30
print 40
stop

Output:
10 20 30 40
*/
