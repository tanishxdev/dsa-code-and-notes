#include <bits/stdc++.h>
using namespace std;

/*
GOAL:
Build and understand a basic Singly Linked List traversal by:
1) Creating a Node class
2) Creating nodes dynamically in heap
3) Connecting nodes using next pointers
4) Forming a list: 10 → 20 → 30 → NULL
5) Traversing the list using a temporary pointer
6) Printing all node values in order
*/

// ------------------------------
// Singly Linked List Node
// ------------------------------
class Node
{
public:
    int data;   // Stores the value of the node
    Node *next; // Stores the address of the next node

    // Constructor to create a new node
    Node(int value)
    {
        data = value; // Store the given value in data
        next = NULL;  // Since this is a new node, it does not point to anyone yet
    }
};

// ------------------------------
// Traversal Function
// ------------------------------
void traversal(Node *head)
{
    /*
    We do NOT move the head pointer because:
    If head is lost, the entire linked list is lost.

    So we create a temporary pointer to walk through the list.
    */

    // Step 1: Copy head into a temporary pointer
    Node *temp = head;

    // Step 2: Move temp until it reaches NULL
    while (temp != nullptr)
    {
        // Step 3: Print the current node's data
        cout << temp->data << " ";

        // Step 4: Move temp to the next node
        temp = temp->next;
    }
}

int main()
{
    /*
    We will build this linked list in memory:

        10 → 20 → 30 → NULL
    */

    // Step 1: Create first node and store its address in head
    Node *head = new Node(10);

    // Step 2: Create second node and connect it to first node
    head->next = new Node(20);

    // Step 3: Create third node and connect it to second node
    head->next->next = new Node(30);

    // Step 4: Call traversal to print the linked list
    traversal(head); // Output: 10 20 30
}

/*
    Time Complexity: O(n)
    Space Complexity: O(1)
*/

/*

Below is the **exact RAM-level picture** of what thisprogram creates, with **pointer arrows**.

---

## 1️⃣ When this line runs

```cpp
Node *head = new Node(10);
```

A node is created in **heap memory**.

```
Heap:
+--------------------+
|  data = 10         |
|  next = NULL       |
+--------------------+
     ^
     |
   head (in stack)
```

Explanation

* `head` is a pointer stored in **stack**
* The actual node lives in **heap**
* `head` stores the **address** of that node

---

## 2️⃣ After this line

```cpp
head->next = new Node(20);
```

Second node is created and first node points to it.

```
Heap:
+--------------------+      +--------------------+
|  data = 10         | ---> |  data = 20         |
|  next = 0x200      |      |  next = NULL       |
+--------------------+      +--------------------+
     ^
     |
   head
```

Explanation

* `head->next` stores the address of the second node
* So now 10 is linked to 20

---

## 3️⃣ After this line

```cpp
head->next->next = new Node(30);
```

Third node is created and second node points to it.

```
Heap:
+--------------------+      +--------------------+      +--------------------+
|  data = 10         | ---> |  data = 20         | ---> |  data = 30         |
|  next = 0x200      |      |  next = 0x300      |      |  next = NULL       |
+--------------------+      +--------------------+      +--------------------+
     ^
     |
   head
```

This is your final linked list:

```
head → 10 → 20 → 30 → NULL
```

---

## 4️⃣ When traversal starts

```cpp
Node *temp = head;
```

```
Stack:
head ───┐
        ├──► Node(10)
temp ───┘
```

Both `head` and `temp` point to the **same first node**.

---

## 5️⃣ During traversal loop

### First iteration

```
temp → 10 → 20 → 30 → NULL
```

Prints `10`
Moves to `20`

### Second iteration

```
temp → 20 → 30 → NULL
```

Prints `20`
Moves to `30`

### Third iteration

```
temp → 30 → NULL
```

Prints `30`
Moves to `NULL`

Loop stops.

---

## 6️⃣ Why we NEVER move `head`

If we did:

```cpp
head = head->next;
```

Memory would become:

```
20 → 30 → NULL
```

Node `10` would still exist in heap,
but we lost its address → **memory leak + list corrupted**

That is why:

> Head is sacred.
> Temp is disposable.

*/