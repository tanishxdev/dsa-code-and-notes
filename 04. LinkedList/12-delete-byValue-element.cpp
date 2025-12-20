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

// Function to delete first occurrence of a value
Node *deleteByValue(Node *head, int value)
{

    // Case 1: Empty list
    if (head == nullptr)
    {
        return head;
    }

    // Case 2: Value found at head
    if (head->data == value)
    {
        Node *temp = head; // store old head
        head = head->next; // move head
        delete temp;       // free memory
        return head;
    }

    Node *temp = head;    // current node
    Node *prev = nullptr; // previous node

    // Traverse the list
    while (temp != nullptr)
    {

        // If target value is found
        if (temp->data == value)
        {
            prev->next = temp->next; // bypass node
            delete temp;             // delete node
            break;                   // delete ONLY first occurrence
        }

        prev = temp;       // move prev
        temp = temp->next; // move temp
    }

    // If value not found, list remains unchanged
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
        10 -> 20 -> 30 -> 20 -> 40 -> NULL
    */

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(20);
    head->next->next->next->next = new Node(40);

    int target = 20;

    head = deleteByValue(head, target);

    traverse(head);

    return 0;
}
