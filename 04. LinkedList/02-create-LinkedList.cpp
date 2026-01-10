#include <bits/stdc++.h>
using namespace std;

// Node class represents a node in the linked list
class Node
{
public:
    int value;  // Better: 'value' instead of generic 'data'
    Node *next; // Pointer to next node

    // Constructor with value and next
    Node(int val, Node *nextPtr)
    {
        value = val;
        next = nextPtr;
    }

    // Constructor with only value
    Node(int val)
    {
        value = val;
        next = nullptr; // nullptr is better than NULL in C++
    }
};

int main()
{
    // Create an array with meaningful name
    vector<int> values = {2, 5, 8, 7};

    // Create first node with descriptive name
    Node *headNode = new Node(values[0]);

    // Print memory address of node
    cout << "Memory address of headNode: " << headNode << '\n';

    // Print value stored in node
    cout << "Value in headNode: " << headNode->value << '\n';

    // Clean up memory (important!)
    delete headNode;

    return 0;
}
/*

## **`this->` ke baare mein detail:**
### **What is `this`?**
- `this` ek **pointer** hai jo current object ko point karta hai
- Har non-static member function ke paas automatically `this` pointer available hota hai
- Yeh usi object ka address store karta hai jis par function call hua hai

### **When to use `this->`?**
1. **Parameter aur member variable ka naam same ho:**
```cpp
class Node {
    int value;
public:
    Node(int value) {
        this->value = value;  // Clear - left side is member, right is parameter
    }
};
```

2. **Clarity ke liye (optional but good practice):**
```cpp
void setValue(int val) {
    this->value = val;  // Clearly shows we're modifying member variable
}
```

3. **Chain function calls ke liye:**
```cpp
class Node {
public:
    Node* setNext(Node* nxt) {
        this->next = nxt;
        return this;  // Returns current object for chaining
    }
};

// Usage: node->setNext(n2)->setNext(n3);
```

### **Without `this->` (your original code):**
```cpp
Node(int data1, Node* next1) {
    data = data1;    // Compiler samajh jata hai ki left wala member hai
    next = next1;    // right wala parameter hai
}
```
---

**Summary:**
- `this->` use karna optional hai, but clarity ke liye helpful hai
*/