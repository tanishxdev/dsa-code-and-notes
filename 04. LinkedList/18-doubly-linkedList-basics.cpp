#include <bits/stdc++.h>
using namespace std;

// GOAL:
// Build the foundation of a Doubly Linked List by:
// 1) Creating a Node class with data, next, and prev
// 2) Dynamically allocating nodes in heap
// 3) Connecting nodes in both forward and backward directions
// 4) Forming a linked structure (10 <-> 20 <-> 30 <-> NULL)
// 5) Traversing the list using next pointers
// 6) Understanding how bidirectional pointers move in memory

// ------------------------------
// Doubly Linked List Node
// ------------------------------
class Node
{
public:
    int data;   // stores the value of the node
    Node *next; // pointer to the next node
    Node *prev; // pointer to the previous node

    // Constructor to initialize a new node
    Node(int value)
    {
        data = value; // store the given value
        next = NULL;  // no next node yet
        prev = NULL;  // no previous node yet
    }
};

int main()
{
    // --------------------------------------------------
    // Step 1: Create individual nodes
    // --------------------------------------------------

    Node *first = new Node(10);  // Node1: [NULL | 10 | NULL]
    Node *second = new Node(20); // Node2: [NULL | 20 | NULL]
    Node *third = new Node(30);  // Node3: [NULL | 30 | NULL]

    // At this moment, all three nodes are isolated:
    // first  -> [NULL | 10 | NULL]
    // second -> [NULL | 20 | NULL]
    // third  -> [NULL | 30 | NULL]

    // --------------------------------------------------
    // Step 2: Link the nodes (both directions)
    // --------------------------------------------------

    first->next = second; // 10 -> 20
    second->prev = first; // 20 <- 10

    second->next = third; // 20 -> 30
    third->prev = second; // 30 <- 20

    // Now the structure is:
    // NULL <- 10 <-> 20 <-> 30 -> NULL

    // --------------------------------------------------
    // Step 3: Traverse forward and print
    // --------------------------------------------------

    Node *temp = first; // start traversal from head

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next; // move forward
    }

    // Output: 10 20 30

    return 0;
}

/*
--------------------------------------------------
DRY RUN (Step-by-step memory flow)
--------------------------------------------------

After node creation:

first  -> [NULL | 10 | NULL]
second -> [NULL | 20 | NULL]
third  -> [NULL | 30 | NULL]

After linking:

NULL <- [10] <-> [20] <-> [30] -> NULL

Meaning:
10.next = 20
20.prev = 10
20.next = 30
30.prev = 20

Traversal:

temp = first (10)
print 10, move to 20

temp = second (20)
print 20, move to 30

temp = third (30)
print 30, move to NULL

Loop stops.

--------------------------------------------------
TIME COMPLEXITY
--------------------------------------------------
Traversal visits each node once:
O(n)

--------------------------------------------------
SPACE COMPLEXITY
--------------------------------------------------
Only one traversal pointer (temp) is used:
O(1)
--------------------------------------------------
*/
