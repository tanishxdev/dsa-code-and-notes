#include <iostream>
using namespace std;

// Node structure
class Node
{
public:
    int data;   // value stored in node
    Node *next; // pointer to next node

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Function to delete the head node
Node *deleteHead(Node *head)
{

    // Case 1: Empty list
    if (head == nullptr)
    {
        return nullptr;
    }

    // Store old head node
    Node *temp = head;

    // Move head to next node
    head = head->next;

    // Free memory of old head
    delete temp;

    // Return new head
    return head;
}
// Helper function to print linked list
void traverse(Node *head)
{
    // Step 1:
    // We never move `head` directly because:
    // - `head` is the starting point of the linked list
    // - Losing `head` means losing access to the entire list
    // So we create a temporary pointer for traversal
    Node *temp = head;

    // Step 2:
    // Traverse the list until we reach the end
    // The end of a linked list is marked by `nullptr`
    while (temp != nullptr)
    {
        // Step 3:
        // Print the data stored in the current node
        // `temp->data` accesses the value of the node temp is pointing to
        cout << temp->data << " ";

        // Step 4:
        // Move temp to the next node
        // This is the ONLY way to move forward in a singly linked list
        // If we forget this step, the loop becomes infinite
        temp = temp->next;
    }

    // Step 5:
    // Print a newline after traversal for clean output formatting
    cout << endl;
}

/*
Why this function is needed

* Linked lists do **not** support index-based access
* To view or verify the list, we must **traverse from head to null**
* This function is commonly used after:

  * insertion
  * deletion
  * updates
  * debugging

  Why the loop stops at `nullptr`

* `nullptr` means:

  * current node does not exist
  * we have crossed the last node
* Every valid node always points to:

  * another node **or**
  * `nullptr` (end of list)

  Time Complexity (Why)

* The loop runs **once per node**
* If there are `n` nodes, loop runs `n` times
* Each iteration does constant work (print + pointer move)

➡ **Time Complexity = O(n)**

Space Complexity (Why)

* Only one extra pointer `temp` is used
* No recursion
* No extra data structures

➡ **Space Complexity = O(1)**

Common mistakes to watch for

* ❌ Using `head` instead of `temp`
* ❌ Forgetting `temp = temp->next`
* ❌ Using `temp->next != nullptr` (misses last node)
* ❌ Printing after moving temp (skips first node)

This traversal logic is the **base pattern** for:

* length calculation
* search
* deletion
* insertion
 */
int main()
{
    /*
        Initial linked list:
        10 -> 20 -> 30 -> NULL
    */

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // Delete head node
    head = deleteHead(head);

    // Print updated list
    traverse(head);

    return 0;
}

/*
DRY RUN

Initial Linked List in memory:
head → 10 → 20 → 30 → NULL

--------------------------------------------------
Call: head = deleteHead(head)
--------------------------------------------------

Inside deleteHead(head):

1) head is NOT null, so we continue.

2) temp = head
   temp → 10 → 20 → 30 → NULL

3) head = head->next
   head → 20 → 30 → NULL
   temp → 10 → 20 → 30 → NULL

4) delete temp
   Node containing 10 is removed from heap

Remaining list in memory:
head → 20 → 30 → NULL

5) return head

--------------------------------------------------
Back in main:
--------------------------------------------------

head now points to:
20 → 30 → NULL

--------------------------------------------------
Call: traverse(head)
--------------------------------------------------

temp → 20 → 30 → NULL
print 20

temp → 30 → NULL
print 30

temp → NULL
stop

Output:
20 30
*/
