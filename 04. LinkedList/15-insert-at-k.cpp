#include <iostream>
using namespace std;

// =======================
// High - level logic
// =======================
// Node class → defines the building block of linked list
// insertHead → handles fastest insertion (O(1))
// insertAtK → generalized insertion logic using traversal
// traverse → verifies structure by printing nodes
// main → ties everything together and validates output

// =======================
// Node structure
// =======================
// Purpose:
// Each Node represents ONE element of the linked list.
// It stores:
// 1) data  -> actual value
// 2) next  -> address of the next node
class Node
{
public:
    int data;   // Holds the value of the node
    Node *next; // Points to the next node in the list

    // Constructor
    // Why constructor?
    // - Ensures every node is created in a valid state
    // - `next` must start as nullptr (end of list by default)
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// =======================
// Insert at head helper
// =======================
// Purpose:
// Inserts a new node at the BEGINNING of the linked list
// and returns the new head.
//
// Why separate function?
// - Head insertion is a very common operation
// - Reused in multiple problems (insert at K, insert at beginning)
Node *insertHead(Node *head, int value)
{
    // Create a new node with given value
    Node *node = new Node(value);

    // Link new node to the current head
    // New node now points to old head
    node->next = head;

    // New node becomes the new head
    return node;
}

// =======================
// Insert at K-th position
// =======================
// Purpose:
// Inserts a new node at position K (1-based index)
//
// Example:
// K = 1 → insert at head
// K = 3 → insert after 2nd node
Node *insertAtK(Node *head, int value, int K)
{
    // Case 1: Insert at head
    // Why handle separately?
    // - Head insertion does NOT need traversal
    // - Simpler and O(1)
    if (K == 1)
    {
        return insertHead(head, value);
    }

    // temp is used to traverse the list safely
    // We NEVER move head directly
    Node *temp = head;

    // count tracks the current node position
    // We start from 1 because head is position 1
    int count = 1;

    // Traverse until we reach (K-1)th node
    // Why (K-1)?
    // - To insert at K, we must stand at previous node
    while (temp != nullptr)
    {
        // When temp is at (K-1)th position
        if (count == K - 1)
        {
            // Create the new node to insert
            Node *node = new Node(value);

            // CRITICAL POINTER ORDER
            // Step 1: New node points to the next node
            // (preserve the existing link)
            node->next = temp->next;

            // Step 2: Previous node points to new node
            temp->next = node;

            // Insertion done, break out of loop
            break;
        }

        // Move to next node
        count++;
        temp = temp->next;
    }

    // Return head because head never changes (except K=1)
    return head;
}

// =======================
// Helper traversal function
// =======================
// Purpose:
// Prints the entire linked list from head to null
//
// Why needed?
// - Linked list has no index-based access
// - Traversal is the only way to view list contents
void traverse(Node *head)
{
    // Temporary pointer for traversal
    Node *temp = head;

    // Traverse until end of list
    while (temp != nullptr)
    {
        // Print current node's data
        cout << temp->data << " ";

        // Move to next node
        temp = temp->next;
    }

    // Newline for clean output formatting
    cout << endl;
}

// =======================
// Main function
// =======================
// Purpose:
// - Creates a sample linked list
// - Calls insertAtK to modify the list
// - Prints the final result
int main()
{
    /*
        Initial linked list:
        10 -> 20 -> 30 -> NULL

        Operation:
        Insert value 25 at position K = 3

        Expected output:
        10 -> 20 -> 25 -> 30 -> NULL
    */

    // Creating the linked list manually
    Node *head = new Node(10);       // First node
    head->next = new Node(20);       // Second node
    head->next->next = new Node(30); // Third node

    // Insert 25 at position 3
    head = insertAtK(head, 25, 3);

    // Print updated linked list
    traverse(head);

    return 0;
}

/*
DRY RUN (insertAtK with value = 25, K = 3)

Initial Linked List:
head → 10 → 20 → 30 → NULL

--------------------------------------------------
Call: head = insertAtK(head, 25, 3)
--------------------------------------------------

K != 1, so we do NOT insert at head.

Initialize:
temp = head → 10 → 20 → 30 → NULL
count = 1

------------------------------------
Iteration 1:
------------------------------------
count = 1
temp → 10
count != K-1 (2), so move forward

temp = 20
count = 2

------------------------------------
Iteration 2:
------------------------------------
count = 2   (this is K-1 position)
temp → 20

Now perform insertion:

Create new node:
node = new Node(25)

node → 25 → NULL

Step 1:
node->next = temp->next
node → 25 → 30 → NULL

Step 2:
temp->next = node
20 → 25 → 30

Linked List becomes:
head → 10 → 20 → 25 → 30 → NULL

Break loop.

--------------------------------------------------
Back in main:
--------------------------------------------------

head → 10 → 20 → 25 → 30 → NULL

--------------------------------------------------
Call: traverse(head)
--------------------------------------------------

temp → 10 → 20 → 25 → 30 → NULL
print 10
print 20
print 25
print 30
stop

Output:
10 20 25 30
*/
