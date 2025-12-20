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

// Function to delete K-th node (1-based)
Node *deleteK(Node *head, int K)
{

    // Case 1: Empty list
    if (head == nullptr)
    {
        return head;
    }

    // Case 2: Deleting head node
    if (K == 1)
    {
        Node *temp = head; // store old head
        head = head->next; // move head
        delete temp;       // free memory
        return head;
    }

    Node *temp = head;    // current node
    Node *prev = nullptr; // previous node
    int count = 0;

    // Traverse list
    while (temp != nullptr)
    {
        count++;

        // When K-th node is found
        if (count == K)
        {

            // prev exists because K != 1
            prev->next = temp->next; // bypass K-th node
            delete temp;             // delete K-th node
            break;
        }

        prev = temp;       // move prev
        temp = temp->next; // move temp
    }

    // If K > length, loop ends naturally and list is unchanged
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
        10 -> 20 -> 30 -> 40 -> NULL
    */

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    int K = 3;

    head = deleteK(head, K);

    traverse(head);

    return 0;
}
