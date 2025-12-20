#include <bits/stdc++.h>
using namespace std;

// Node structure definition
class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

// Traversal function
void traveral(Node *head)
{
    // Step 1: Create a temporary pointer
    Node *temp = head;

    // Step 2: Loop until temp becomes Null
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    // Creating a sample linked list: 10 -> 20 -> 30 -> null
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    traveral(head); // Output: 10 20 30
}