#include <iostream>
using namespace std;

// =======================
// Node structure
// =======================
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

// =======================
// Insert at head helper
// =======================
// Used when target is present at head
Node *insertHead(Node *head, int value)
{
    Node *node = new Node(value);
    node->next = head;
    return node;
}

// =======================
// Insert before given value
// =======================
Node *insertBeforeValue(Node *head, int value, int target)
{

    // Case 1: Empty list
    // Nothing to insert before
    if (head == nullptr)
    {
        return head;
    }

    // Case 2: Target is at head
    // Insert before head = insert at head
    if (head->data == target)
    {
        return insertHead(head, value);
    }

    // Temporary pointer for traversal
    Node *temp = head;

    // Traverse until second last node
    // We check temp->next because we want to stop BEFORE target
    while (temp->next != nullptr)
    {

        // If next node contains the target
        if (temp->next->data == target)
        {

            // Create new node
            Node *node = new Node(value);

            // Pointer order is CRITICAL
            // Step 1: new node points to target
            node->next = temp->next;

            // Step 2: previous node points to new node
            temp->next = node;

            // Insertion done
            break;
        }

        // Move forward
        temp = temp->next;
    }

    // Head does not change in this operation
    return head;
}

// =======================
// Traversal helper
// =======================
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
        10 -> 20 -> 30 -> 40 -> NULL

        Insert 25 before target = 30

        Expected:
        10 -> 20 -> 25 -> 30 -> 40 -> NULL
    */

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    head = insertBeforeValue(head, 25, 30);

    traverse(head);

    return 0;
}
