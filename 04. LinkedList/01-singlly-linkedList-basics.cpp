#include <bits/stdc++.h>
using namespace std;

// GOAL:
// Build the foundation of a Singly Linked List by:
// 1) Creating a Node class
// 2) Dynamically allocating nodes in heap
// 3) Connecting nodes using next pointers
// 4) Forming a linked structure (10 -> 20 -> 30 -> NULL)
// 5) Traversing the list using a temporary pointer
// 6) Understanding how data and pointers move in memory

// ------------------------------
// Singly Linked List Node
// ------------------------------
class Node
{
public:
    int data;   // stores the value of the node
    Node *next; // pointer to the next node in the list

    // Constructor to initialize a new node
    Node(int value)
    {
        data = value; // store the given value
        next = NULL;  // since this node is newly created,
                      // it does not point to any next node yet
    }
};

int main()
{
    // --------------------------------------------------
    // Step 1: Create individual nodes
    // --------------------------------------------------

    Node *first = new Node(10);  // Node1: [10 | NULL]
    Node *second = new Node(20); // Node2: [20 | NULL]
    Node *third = new Node(30);  // Node3: [30 | NULL]

    // At this moment, all three nodes are isolated:
    // first  -> [10 | NULL]
    // second -> [20 | NULL]
    // third  -> [30 | NULL]

    // --------------------------------------------------
    // Step 2: Link the nodes to form a linked list
    // --------------------------------------------------

    first->next = second; // 10 now points to 20
    second->next = third; // 20 now points to 30

    // Now the structure is:
    // first -> second -> third -> NULL
    // 10     -> 20     -> 30    -> NULL

    // --------------------------------------------------
    // Step 3: Traverse and print the list
    // --------------------------------------------------

    Node *temp = first; // temp is a traversal pointer
                        // it starts from the head of the list

    while (temp != NULL)
    {
        cout << temp->data << " "; // print current node's data
        temp = temp->next;         // move to the next node
    }

    // Output: 10 20 30

    return 0;
}

/*
--------------------------------------------------
DRY RUN (Step-by-step memory flow)
--------------------------------------------------

After node creation:

first  -> [10 | NULL]
second -> [20 | NULL]
third  -> [30 | NULL]

After linking:

first  -> [10 | *] ----> second -> [20 | *] ----> third -> [30 | NULL]
             |                           |
             ----------------------------

Traversal:

temp = first (10)
print 10, temp moves to 20

temp = second (20)
print 20, temp moves to 30

temp = third (30)
print 30, temp moves to NULL

Loop stops.

--------------------------------------------------
TIME COMPLEXITY
--------------------------------------------------
Traversal visits each node once:
O(n)

--------------------------------------------------
SPACE COMPLEXITY
--------------------------------------------------
We use only one extra pointer (temp):
O(1)
--------------------------------------------------
*/
