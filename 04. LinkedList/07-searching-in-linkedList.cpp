#include <iostream>
using namespace std;

/*
GOAL:
1) Build a Singly Linked List in heap memory
2) Traverse it node by node using a temporary pointer
3) Compare each node’s data with a given key
4) Return true if key is found, otherwise false
*/

// ------------------------------
// Node structure
// ------------------------------
class Node
{
public:
    int data;   // Stores the value of this node
    Node *next; // Stores the address of the next node

    // Constructor
    Node(int val)
    {
        data = val;     // Assign value
        next = nullptr; // No next node yet
    }
};

// ------------------------------
// Function to search a value
// ------------------------------
bool searchInLL(Node *head, int key)
{
    /*
    We do NOT move 'head' directly.
    We use a temporary pointer to walk through the list.
    */

    // Step 1: Start temp at the first node
    Node *temp = head;

    // Step 2: Move until temp reaches NULL
    while (temp != nullptr)
    {
        // Step 3: Check if current node contains the key
        if (temp->data == key)
        {
            return true; // Key found
        }

        // Step 4: Move temp to the next node
        temp = temp->next;
    }

    // Step 5: If we reached NULL, key was not found
    return false;
}

int main()
{
    /*
    We create this linked list in memory:

        10 → 20 → 30 → 40 → NULL
    */

    // Step 1: Create first node
    Node *head = new Node(10);

    // Step 2: Attach more nodes
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    // Step 3: Value to search
    int key = 300;

    // Step 4: Search in linked list
    bool found = searchInLL(head, key);

    // Step 5: Print result
    if (found)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl; // This will print because 300 is not in the list
}
