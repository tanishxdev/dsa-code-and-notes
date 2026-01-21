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

// Function to delete the tail node
Node *deleteTail(Node *head)
{

    // Case 1: Empty list OR single node list
    if (head == nullptr || head->next == nullptr)
    {
        delete head; // safe even if head is nullptr
        return nullptr;
    }

    // Temporary pointer for traversal
    Node *temp = head;

    // Move temp until it reaches the second last node
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    // temp->next is the tail node
    delete temp->next;    // free tail memory
    temp->next = nullptr; // mark new tail

    return head;
}

// Helper function to print list
void traverse(Node *head)
{
    // STEP 1:
    // We create a temporary pointer `temp`
    // Reason:
    // - `head` is the only reference to the linked list
    // - Modifying `head` will permanently lose the list
    // - Traversal must NEVER disturb head
    Node *temp = head;

    // STEP 2:
    // Traverse the linked list until `temp` becomes nullptr
    // `nullptr` is the official marker of the end of a linked list
    // Every valid node must point to either:
    // - another node
    // - OR nullptr (last node)
    while (temp != nullptr)
    {
        // STEP 3:
        // Print the data stored in the current node
        // `temp->data` accesses the value inside the node
        cout << temp->data << " ";

        // STEP 4:
        // Move `temp` to the next node
        // This line is CRITICAL:
        // - Without it, `temp` never changes
        // - The loop becomes infinite
        // - Program may hang or crash
        temp = temp->next;
    }

    // STEP 5:
    // Print a newline for clean output formatting
    // This has no impact on logic, only readability
    cout << endl;
}

/*
🤔 What this function actually does (in simple words)

Starts from the head
Visits every node exactly once
Prints the value of each node
Stops precisely at the end of the list

🤔 Why temp != nullptr is the correct condition

temp == nullptr means:

there is no node at this position
traversal is complete

If we used:
while (temp->next != nullptr)


then:

the last node would never be printed
because the loop would stop one step early

So:
Always check the current node, not the next node.

 */
int main()
{
    /*
        Initial list:
        10 -> 20 -> 30 -> NULL
    */

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // Delete tail
    head = deleteTail(head);

    // Print updated list
    traverse(head);

    return 0;
}

/*
DRY RUN

Initial Linked List in memory:
head → 10 → 20 → 30 → NULL

--------------------------------------------------
Call: head = deleteTail(head)
--------------------------------------------------

Inside deleteTail(head):

1) head != NULL and head->next != NULL
   So we do NOT return early.

2) temp = head
   temp → 10 → 20 → 30 → NULL

3) Loop condition:
   while (temp->next->next != NULL)

   First check:
   temp->next = 20
   temp->next->next = 30  (not NULL)
   So loop runs.

   Move temp forward:
   temp → 20 → 30 → NULL

   Second check:
   temp->next = 30
   temp->next->next = NULL
   Condition fails → exit loop.

Now temp is pointing to SECOND LAST node:
temp → 20 → 30 → NULL

4) temp->next is the tail node (30)
   delete temp->next
   Node containing 30 is removed from heap

5) temp->next = NULL
   Now 20 becomes the new tail

Linked List becomes:
head → 10 → 20 → NULL

6) return head

--------------------------------------------------
Back in main:
--------------------------------------------------

head → 10 → 20 → NULL

--------------------------------------------------
Call: traverse(head)
--------------------------------------------------

temp → 10 → 20 → NULL
print 10

temp → 20 → NULL
print 20

temp → NULL
stop

Output:
10 20
*/
