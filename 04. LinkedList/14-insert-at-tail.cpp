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
