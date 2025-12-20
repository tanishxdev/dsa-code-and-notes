#include <bits/stdc++.h>
using namespace std;

/*
    Node class:
    - Ye Linked List ke ek single node ka structure define karti hai
    - Har node ke paas:
        1) data  -> actual value
        2) next  -> next node ka address
*/
class Node
{
public:
    int data;   // Node me store hone wala data
    Node *next; // Next node ka pointer

    /*
        Constructor:
        - Jab bhi new Node(value) likhenge,
          ye constructor call hoga
        - data ko value assign karega
        - next ko NULL set karega (important for last node)
    */
    Node(int value)
    {
        data = value; // data initialize
        next = NULL;  // initially kisi next node se connected nahi
    }
};

/*
    Function: convertArrayToLL
    Purpose:
    - Ek array ko Linked List me convert karna
    - Head node ka address return karna
*/
Node *convertArrayToLL(vector<int> &arr)
{
    // Edge case: empty array
    if (arr.size() == 0)
        return nullptr;

    // Step 1: Create head node
    Node *head = new Node(arr[0]);

    // Step 2: Mover pointer (used for traversal)
    Node *mover = head;

    // Step 3: Create remaining nodes
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]); // new node in heap
        mover->next = temp;            // link current node to new node
        mover = temp;                  // move mover forward
    }

    return head; // return starting point of Linked List
}

/*
    Function: printLinkedList
    Purpose:
    - Linked List ko print karna
    - Head se traverse karke NULL tak jana
*/
void printLinkedList(Node *head)
{
    Node *temp = head; // traversal pointer

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    /*
        Step 1: Array create karte hain
    */
    vector<int> arr = {10, 20, 30, 40, 50};

    /*
        Step 2: Array ko Linked List me convert karte hain
    */
    Node *head = convertArrayToLL(arr);

    /*
        Step 3: Linked List print karke verify karte hain
    */
    printLinkedList(head);

    return 0;
}
