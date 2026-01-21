#include <bits/stdc++.h>
using namespace std;

/*
GOAL:
1) Create a Singly Linked List using dynamic memory
2) Connect nodes using next pointers
3) Traverse the list using a moving pointer
4) Count how many nodes exist
5) Return the total length of the list
*/

// ------------------------------
// Node structure
// ------------------------------
class Node
{
public:
    int data;   // Stores the value of this node
    Node *next; // Stores the address of the next node

    // Constructor to create a new node
    Node(int val)
    {
        data = val;  // Store given value
        next = NULL; // New node does not point to anything yet
    }
};

// ------------------------------
// Function to calculate length
// ------------------------------
int Length(Node *head)
{
    /*
    We use 'head' here as a moving pointer.
    This does NOT affect the original head in main()
    because this head is only a copy of that address.
    */

    int count = 0; // Stores how many nodes we have seen

    // Step through the list until we hit NULL
    while (head != NULL)
    {
        count++;           // One node found
        head = head->next; // Move to next node
    }

    // When head becomes NULL, list has ended
    return count;
}

int main()
{
    /*
    We will build this list in memory:

        5 → 10 → 15 → NULL
    */

    // Step 1: Create first node and store its address in head
    Node *head = new Node(5);

    // Step 2: Create second node
    Node *second = new Node(10);

    // Step 3: Create third node
    Node *third = new Node(15);

    // Step 4: Create fourth node
    Node *fourth = new Node(25);

    // Step 4: Connect first node to second node
    head->next = second;

    // Step 5: Connect second node to third node
    second->next = third;

    // Step 6: Connect third node to fourth node
    third->next = fourth;

    // Step 7: Pass head to Length() to count nodes
    cout << "Length: " << Length(head); // Output: 3
}
