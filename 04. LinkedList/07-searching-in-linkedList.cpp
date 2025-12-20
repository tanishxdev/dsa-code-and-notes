#include <iostream>
using namespace std;

// Node structure
class Node
{
public:
    int data;   // value stored
    Node *next; // pointer to next node

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Function to search target in linked list
bool search(Node *head, int target)
{

    // Temporary pointer to traverse list
    // We do NOT move head directly
    Node *temp = head;

    // Traverse the list node by node
    while (temp != nullptr)
    {

        // Compare current node's data with target
        if (temp->data == target)
        {
            // Target found, no need to continue
            return true;
        }

        // Move to next node
        temp = temp->next;
    }

    // Traversal finished and target not found
    return false;
}

int main()
{
    /*
        Creating linked list:
        10 -> 20 -> 30 -> 40 -> NULL
    */

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    int target = 30;

    // Searching for target
    bool found = search(head, target);

    if (found)
        cout << "Value found in linked list" << endl;
    else
        cout << "Value not found in linked list" << endl;

    return 0;
}
