#include <bits/stdc++.h>
using namespace std;

// ⭐ Approach 1:
// ⭐ Approach 2:
// ⭐ Approach 3:

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
int Length(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
int main()
{

    // Create three nodes
    Node *head = new Node(5);
    Node *second = new Node(10);
    Node *third = new Node(15);

    // Link first and second nodes
    head->next = second;

    // Link second and third nodes
    second->next = third;

    // Traverse the Linked List
    cout << Length(head);
    
}