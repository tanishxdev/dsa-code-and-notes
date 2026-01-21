#include <bits/stdc++.h>
using namespace std;

/*
GOAL:
1) Take an array of integers
2) Create one Linked List node for each array element
3) Connect all nodes using next pointers
4) Return the head of the Linked List
5) Traverse the list and print it
*/

/*
    Node class:
    - This defines the structure of ONE Linked List node
    - Every node has:
        1) data  -> stores the value
        2) next  -> stores the address of the next node
*/
class Node
{
public:
    int data;   // Value stored in this node
    Node *next; // Address of the next node

    /*
        Constructor:
        - Runs when we do: new Node(value)
        - Allocates memory in heap
        - Stores value in data
        - Sets next = NULL (very important for the last node)
    */
    Node(int value)
    {
        data = value; // store the given value
        next = NULL;  // initially this node does not point to any other node
    }
};

/*
    Function: convertArrayToLL
    Purpose:
    - Converts an array into a Linked List
    - Creates nodes in heap
    - Links them one by one
    - Returns the head pointer
*/
Node *convertArrayToLL(vector<int> &arr)
{
    // If array is empty, Linked List cannot be created
    if (arr.size() == 0)
        return nullptr;

    // Step 1:
    // Create the first node using arr[0]
    // This becomes the HEAD of the Linked List
    Node *head = new Node(arr[0]);

    // Step 2:
    // Mover pointer will walk along the list and attach new nodes
    // We never move head — only mover moves
    Node *mover = head;

    // Step 3:
    // Create remaining nodes from arr[1] to arr[n-1]
    for (int i = 1; i < arr.size(); i++)
    {
        // Create a new node in heap
        Node *temp = new Node(arr[i]);

        // Link current node to this new node
        mover->next = temp;

        // Move mover forward to the newly created node
        mover = temp;
    }

    // head still points to the first node
    // so we return it as the entry point of the Linked List
    return head;
}

/*
    Function: printLinkedList
    Purpose:
    - Traverse the Linked List from head
    - Print data of each node
*/
void printLinkedList(Node *head)
{
    // temp is used to walk through the list
    // head is never modified
    Node *temp = head;

    // Keep moving until we hit NULL (end of list)
    while (temp != NULL)
    {
        cout << temp->data << " "; // print current node value
        temp = temp->next;         // move to next node
    }

    cout << endl;
}

int main()
{
    /*
        Step 1:
        Create an array
    */
    vector<int> arr = {10, 20, 30, 40, 50};

    /*
        Step 2:
        Convert array to Linked List
        This returns the address of the first node (head)
    */
    Node *head = convertArrayToLL(arr);

    /*
        Step 3:
        Print the Linked List
        Expected output:
        10 20 30 40 50
    */
    printLinkedList(head);

    return 0;
}
