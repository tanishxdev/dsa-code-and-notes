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

// Function to insert a node at head
Node *insertHead(Node *head, int value)
{

    // Step 1:
    // Create a new node with given value
    Node *temp = new Node(value);

    // Step 2:
    // Make new node point to the old head
    temp->next = head;

    // Step 3:
    // Return new node as head
    return temp;
}
// Helper function to print the linked list
void traverse(Node *head)
{
    // Create a temporary pointer so that
    // the original `head` pointer is not modified.
    // `head` is the only entry point to the linked list.
    Node *temp = head;

    // Traverse the linked list until we reach the end.
    // The end of a linked list is identified by `nullptr`.
    while (temp != nullptr)
    {
        // Print the data stored in the current node.
        // `temp->data` accesses the value of the node
        // that `temp` is currently pointing to.
        cout << temp->data << " ";

        // Move the temporary pointer to the next node.
        // This step is mandatory to move forward in the list.
        // Missing this line will cause an infinite loop.
        temp = temp->next;
    }

    // Print a newline after traversal for clean formatting.
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

    // Insert at head
    head = insertHead(head, 5);

    traverse(head);

    return 0;
}
