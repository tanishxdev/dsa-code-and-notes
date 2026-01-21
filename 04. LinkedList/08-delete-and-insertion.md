# LINKED LIST — DELETION & INSERTION (FOUNDATION + MINDSET)

---

## What We Covered Here

### Deletion (4 types)

1. Deleting the **head** of a linked list
2. Deleting the **tail** of a linked list
3. Deleting the **K-th node (1-based index)**
4. Deleting a node **by value (first occurrence)**

### Insertion (4 types)

5. Inserting at the **head**
6. Inserting at the **tail**
7. Inserting at the **K-th position**
8. Inserting **before a given value**

---

## Core Mindset Before Starting

> **Every Linked List problem is a pointer problem, not a data problem.**

Deletion & insertion are **NOT** about values.
They are about **breaking and rebuilding links safely**.

If traversal is weak → everything breaks.
If pointer order is wrong → list is corrupted.

---

# PART A — DELETION IN SINGLY LINKED LIST

---

## Universal Deletion Rule (Very Important)

> **To delete a node, you must control the pointer BEFORE it.**

Why?

* You cannot jump backward in a singly linked list
* You must redirect the previous node’s `next`

---

## 1. Deletion of Head

---

### Problem

Delete the **first node** of the linked list.

```
head → [A] → [B] → [C] → null
```

After deletion:

```
head → [B] → [C] → null
```

---

### Intuition (How to Think)

* `head` always points to the **first node**
* Deleting head means:

  * The **second node becomes the new head**
* But in **C++**, memory does NOT auto-delete

  * Old head node must be **freed manually**
* In **JavaScript**, garbage collector handles it

So the steps are:

1. Store current head in a temporary pointer
2. Move `head` to `head->next`
3. Delete old head (C++ only)
4. Return new head

---

### Edge Cases

1. **Empty list**

   ```
   head → null
   ```

   Nothing to delete → return `null`

2. **Single node**

   ```
   head → [A] → null
   ```

   After deletion:

   ```
   head → null
   ```

---

### Pseudocode

```
DELETE_HEAD(head):
    IF head == null:
        RETURN null

    temp ← head
    head ← head.next
    delete temp   // C++ only

    RETURN head
```

---

### C++ Code

#### Version 1 — Simple / Clean (Only Required Function)

```cpp
Node* deleteHead(Node* head) {
    if (head == nullptr)
        return nullptr;

    Node* temp = head;
    head = head->next;
    delete temp;

    return head;
}
```

---

#### Version 2 — Deep / Explained (Complete Program)

```cpp
#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;        // value stored in node
    Node* next;      // pointer to next node

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to delete the head node
Node* deleteHead(Node* head) {

    // Case 1: Empty list
    if (head == nullptr) {
        return nullptr;
    }

    // Store old head node
    Node* temp = head;

    // Move head to next node
    head = head->next;

    // Free memory of old head
    delete temp;

    // Return new head
    return head;
}

// Helper function to print linked list
void traverse(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    /*
        Initial linked list:
        10 -> 20 -> 30 -> NULL
    */

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // Delete head node
    head = deleteHead(head);

    // Print updated list
    traverse(head);

    return 0;
}
```

---

### Dry Run (C++)

Initial list:

```
head → 10 → 20 → 30 → NULL
```

Steps:

1. `temp = head` → temp points to `10`
2. `head = head->next` → head now points to `20`
3. `delete temp` → node `10` removed from memory

Final list:

```
head → 20 → 30 → NULL
```

**Output:**

```
20 30
```

---

### JavaScript Code

#### Version 1 — Simple / Clean (Only Required Function)

```javascript
function deleteHead(head) {
    if (head === null) return null;

    head = head.next;
    return head;
}
```

---

#### Version 2 — Deep / Explained (Complete Code)

```javascript
// Node structure
class Node {
    constructor(data) {
        this.data = data;   // value stored
        this.next = null;   // reference to next node
    }
}

// Function to delete the head node
function deleteHead(head) {

    // Case 1: Empty list
    if (head === null) {
        return null;
    }

    // Move head to next node
    // Old head becomes unreachable
    // Garbage Collector will clean it
    head = head.next;

    return head;
}

// Helper function to print linked list
function traverse(head) {
    let temp = head;
    let result = "";
    while (temp !== null) {
        result += temp.data + " ";
        temp = temp.next;
    }
    console.log(result.trim());
}

// Main execution
// Initial list: 1 -> 2 -> 3 -> null
let head = new Node(1);
head.next = new Node(2);
head.next.next = new Node(3);

// Delete head
head = deleteHead(head);

// Print updated list
traverse(head);
```

---

### Dry Run (JavaScript)

Initial list:

```
head → 1 → 2 → 3 → null
```

Steps:

1. `head = head.next`
2. Head now points to node `2`
3. Node `1` becomes unreachable → GC deletes it

Final list:

```
head → 2 → 3 → null
```

**Output:**

```
2 3
```

---

### Time & Space Complexity (Deep Explanation)

#### Time Complexity — **O(1)**

**Why O(1):**

* We do **not traverse** the list
* Only a **constant number of operations**:

  * pointer reassignment
  * one delete (C++)
* List size does NOT matter

So execution time stays the same → **O(1)**.

---

#### Space Complexity — **O(1)**

**Why O(1):**

* Only one extra pointer `temp` (C++)
* No recursion
* No additional data structures

**Important clarification:**

* Deleted node memory is freed
* Input list memory is NOT counted in space complexity

Hence, constant extra space → **O(1)**.

---

### Interview Insight

> Deleting head is the **simplest delete operation** in a linked list.

If an interviewer asks:

> “Why is deleting head O(1) but deleting tail O(n)?”

Correct answer:

* Head is directly accessible
* Tail requires traversal in singly linked list
---

## 2. Deletion of Tail

---

### Problem

Delete the **last node** of the linked list.

```
head → A → B → C → null
```

After deletion:

```
head → A → B → null
```

---

### Critical Observation

To delete the **last node**, you **cannot directly reach it safely** in a singly linked list.

**Why?**

* Each node only knows about the **next node**
* There is **no backward pointer**
* To delete a node, you must have access to the node **before it**

So:

> To delete the tail, you must stop at the **second last node**

Because:

* Second last node’s `next` points to the tail
* Only that node can change `next` to `null`

---

### Edge Cases (Must Handle)

1. **Empty list**

   ```
   head → null
   ```

   Nothing to delete → return `null`

2. **Single node**

   ```
   head → A → null
   ```

   Deleting tail deletes the **only node**
   → list becomes empty → return `null`

These cases must be handled **before traversal**.

---

### Why We Use `temp->next->next`

Visual explanation:

```
temp             →  B
temp->next       →  C   (tail)
temp->next->next →  null
```

So the condition:

```
temp->next->next != null
```

means:

* `temp` is **NOT yet** at second last node

When it becomes `null`, `temp` is exactly at:

```
second last node
```

---

### Pseudocode

```
DELETE_TAIL(head):
    IF head == null OR head.next == null:
        delete head
        RETURN null

    temp ← head

    WHILE temp.next.next != null:
        temp ← temp.next

    delete temp.next
    temp.next ← null

    RETURN head
```

---

### C++ Code

#### Version 1 — Simple / Clean (Only Required Function)

```cpp
Node* deleteTail(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* temp = head;

    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    return head;
}
```

---

#### Version 2 — Deep / Explained (Complete Program)

```cpp
#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to delete the tail node
Node* deleteTail(Node* head) {

    // Case 1: Empty list OR single node list
    if (head == nullptr || head->next == nullptr) {
        delete head;   // safe even if head is nullptr
        return nullptr;
    }

    // Temporary pointer for traversal
    Node* temp = head;

    // Move temp until it reaches the second last node
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    // temp->next is the tail node
    delete temp->next;     // free tail memory
    temp->next = nullptr; // mark new tail

    return head;
}

// Helper function to print list
void traverse(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    /*
        Initial list:
        10 -> 20 -> 30 -> NULL
    */

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // Delete tail
    head = deleteTail(head);

    // Print updated list
    traverse(head);

    return 0;
}
```

---

### Dry Run (C++)

Initial list:

```
head → 10 → 20 → 30 → NULL
```

Steps:

1. `temp = head` → points to `10`
2. Check `temp->next->next` → `20->next` is `30` (not null) → move temp
3. `temp = 20`
4. Now `temp->next->next` → `30->next` is `null` → stop loop
5. `temp->next` is tail (`30`)
6. Delete node `30`
7. Set `temp->next = null`

Final list:

```
head → 10 → 20 → NULL
```

**Output:**

```
10 20
```

---

### JavaScript Code

#### Version 1 — Simple / Clean (Only Required Function)

```javascript
function deleteTail(head) {
    if (head === null || head.next === null) {
        return null;
    }

    let temp = head;

    while (temp.next.next !== null) {
        temp = temp.next;
    }

    temp.next = null;
    return head;
}
```

---

#### Version 2 — Deep / Explained (Complete Code)

```javascript
// Node structure
class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

// Function to delete tail node
function deleteTail(head) {

    // Case 1: Empty or single node list
    if (head === null || head.next === null) {
        return null;
    }

    // Temporary pointer for traversal
    let temp = head;

    // Move until second last node
    while (temp.next.next !== null) {
        temp = temp.next;
    }

    // temp.next is the tail
    // Just disconnect it (GC handles memory)
    temp.next = null;

    return head;
}

// Helper function
function traverse(head) {
    let temp = head;
    let result = "";
    while (temp !== null) {
        result += temp.data + " ";
        temp = temp.next;
    }
    console.log(result.trim());
}

// Main execution
// Initial list: 1 -> 2 -> 3 -> null
let head = new Node(1);
head.next = new Node(2);
head.next.next = new Node(3);

// Delete tail
head = deleteTail(head);

// Print updated list
traverse(head);
```

---

### Dry Run (JavaScript)

Initial list:

```
head → 1 → 2 → 3 → null
```

Steps:

1. `temp = 1`
2. Check `temp.next.next` → `2.next` is `3` → move temp
3. `temp = 2`
4. `temp.next.next` → `3.next` is `null` → stop
5. `temp.next = null` → node `3` removed

Final list:

```
head → 1 → 2 → null
```

**Output:**

```
1 2
```

---

### Time & Space Complexity (Deep Explanation)

#### Time Complexity — **O(n)**

**Why O(n):**

* We must **traverse the list** to reach the second last node
* In the worst case, we visit `n-1` nodes
* Each step is constant time

Since traversal grows with list size → **O(n)**

**Important contrast:**

* Delete head → O(1)
* Delete tail → O(n) (singly linked list limitation)

---

#### Space Complexity — **O(1)**

**Why O(1):**

* Only one extra pointer (`temp`)
* No recursion
* No extra data structures

Input list memory is **not counted**.

---

### Interview Insight

> Tail deletion is expensive in a **singly linked list**.

If interviewer asks:

> “How can we make tail deletion O(1)?”

Correct answer:

* Use a **doubly linked list**
* Or maintain a **tail pointer** (with extra handling)
---
## 3. Deletion of K-th Node (1-based)

---

### Problem

Delete the node at position `K`.

---

### Why This Is Important

This problem **combines all deletion scenarios** in one place:

* Deleting **head** (`K = 1`)
* Deleting **tail** (`K = length`)
* Deleting a **middle node**
* Handling **invalid K**
* Handling **empty list**

That’s why this is called a **master deletion problem**.
If this is clear, other delete problems become easy.

---

### Case Analysis

| Case        | What should happen | Why                           |
| ----------- | ------------------ | ----------------------------- |
| List empty  | Return head        | Nothing exists to delete      |
| K = 1       | Delete head        | Head is the K-th node         |
| K > length  | Do nothing         | K-th node does not exist      |
| Middle node | Relink nodes       | Skip the K-th node            |
| Tail node   | Same relink logic  | Tail is just a special middle |

---

### Intuition

* We must **traverse**, because linked list has no index
* Maintain:

  * `temp` → current node
  * `prev` → node before `temp`
* Maintain a counter starting from `1`
* When `count == K`:

  * Bypass the node
  * Delete it (C++)
  * Stop traversal

Key idea:

> To delete a node, you must have access to the **previous node**




This “why” is not optional.
This is the **core law** of singly linked lists.

---

### Why do we need the **previous node** to delete a node?

Because in a **singly linked list**, every node only knows **one thing**:

```
its next node
```

It does **not** know who is pointing to it.

Memory looks like this:

```
prev → temp → next
```

`temp` knows:

```
temp->next = next
```

But `temp` does NOT know:

```
who is pointing to me?
```

That pointer is stored inside `prev`.

---

### What actually means “delete a node” in a linked list?

Deleting is **not** removing the box from memory first.
Deleting is:

```
Cutting the chain so the list skips this node
```

So we must change:

```
prev->next
```

From:

```
prev->next = temp
```

To:

```
prev->next = temp->next
```

Only then does the list bypass `temp`.

```
Before:
prev → temp → next

After:
prev → next
```

Now `temp` is disconnected, so it is safe to `delete temp`.

---

### What if you don’t have `prev`?

Suppose you are standing at `temp`.

You can see:

```
temp->next
```

But you cannot reach:

```
prev->next
```

You cannot rewire the list.

Trying to do:

```cpp
delete temp;
```

will remove memory, but the list still has:

```
prev → (dangling pointer)
```

Now the list is **corrupted**.

This is called a **dangling pointer bug**.

---

### Why arrays don’t have this problem

Arrays use indexes:

```
arr[k-1] = arr[k+1]
```

So shifting is easy.

Linked lists don’t have indexes.
They only have **pointers**.

So to remove a node, you must control the pointer that is pointing to it.

That pointer is stored in **prev**.

---

### One-line interview truth

> In a singly linked list, you cannot delete a node unless you can modify the pointer that points to it — which belongs to the previous node.

That is why:

```
temp alone is not enough.
prev is mandatory.
```

---

### Pseudocode

```
DELETE_K(head, K):
    IF head == null:
        RETURN head

    IF K == 1:
        delete head
        RETURN head.next

    temp ← head
    prev ← null
    count ← 0

    WHILE temp != null:
        count++

        IF count == K:
            prev.next ← temp.next
            delete temp
            BREAK

        prev ← temp
        temp ← temp.next

    RETURN head
```

---

### C++ Code

#### Version 1 — Simple / Clean (Only Required Function)

```cpp
Node* deleteK(Node* head, int K) {
    if (head == nullptr) return head;

    if (K == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev = nullptr;
    int count = 0;

    while (temp != nullptr) {
        count++;

        if (count == K) {
            prev->next = temp->next;
            delete temp;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}
```

---

#### Version 2 — Deep / Explained (Complete Program)

```cpp
#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to delete K-th node (1-based)
Node* deleteK(Node* head, int K) {

    // Case 1: Empty list
    if (head == nullptr) {
        return head;
    }

    // Case 2: Deleting head node
    if (K == 1) {
        Node* temp = head;     // store old head
        head = head->next;     // move head
        delete temp;           // free memory
        return head;
    }

    Node* temp = head;         // current node
    Node* prev = nullptr;      // previous node
    int count = 0;

    // Traverse list
    while (temp != nullptr) {
        count++;

        // When K-th node is found
        if (count == K) {

            // prev exists because K != 1
            prev->next = temp->next;  // bypass K-th node
            delete temp;              // delete K-th node
            break;
        }

        prev = temp;           // move prev
        temp = temp->next;     // move temp
    }

    // If K > length, loop ends naturally and list is unchanged
    return head;
}

// Helper function to print list
void traverse(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    /*
        Initial list:
        10 -> 20 -> 30 -> 40 -> NULL
    */

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    int K = 3;

    head = deleteK(head, K);

    traverse(head);

    return 0;
}
```

---

### Dry Run (C++)

Initial list:

```
10 → 20 → 30 → 40 → NULL
```

K = `3`

| Step | temp | prev | count | Action |
| ---- | ---- | ---- | ----- | ------ |
| 1    | 10   | null | 1     | move   |
| 2    | 20   | 10   | 2     | move   |
| 3    | 30   | 20   | 3     | delete |

After deletion:

```
10 → 20 → 40 → NULL
```

**Output:**

```
10 20 40
```

---

### JavaScript Code

#### Version 1 — Simple / Clean (Only Required Function)

```javascript
function deleteK(head, K) {
    if (head === null) return head;

    if (K === 1) {
        return head.next;
    }

    let temp = head;
    let prev = null;
    let count = 0;

    while (temp !== null) {
        count++;

        if (count === K) {
            prev.next = temp.next;
            break;
        }

        prev = temp;
        temp = temp.next;
    }

    return head;
}
```

---

#### Version 2 — Deep / Explained (Complete Code)

```javascript
// Node structure
class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

// Function to delete K-th node (1-based)
function deleteK(head, K) {

    // Case 1: Empty list
    if (head === null) {
        return head;
    }

    // Case 2: Delete head
    if (K === 1) {
        return head.next; // old head becomes unreachable (GC handles it)
    }

    let temp = head;   // current node
    let prev = null;   // previous node
    let count = 0;

    while (temp !== null) {
        count++;

        if (count === K) {
            prev.next = temp.next; // bypass K-th node
            break;
        }

        prev = temp;
        temp = temp.next;
    }

    return head;
}

// Helper function
function traverse(head) {
    let temp = head;
    let res = "";
    while (temp !== null) {
        res += temp.data + " ";
        temp = temp.next;
    }
    console.log(res.trim());
}

// Main execution
// Initial list: 1 -> 2 -> 3 -> 4 -> null
let head = new Node(1);
head.next = new Node(2);
head.next.next = new Node(3);
head.next.next.next = new Node(4);

head = deleteK(head, 2);

traverse(head);
```

---

### Dry Run (JavaScript)

Initial list:

```
1 → 2 → 3 → 4 → null
```

K = `2`

Steps:

1. temp = 1, count = 1
2. temp = 2, count = 2 → delete

Final list:

```
1 → 3 → 4 → null
```

**Output:**

```
1 3 4
```

---

### Time & Space Complexity (Deep Explanation)

#### Time Complexity — **O(n)**

**Why O(n):**

* We may need to traverse the entire list
* In worst case (`K > length` or deleting tail):

  * All `n` nodes are visited
* Each iteration does constant work

Hence, traversal dominates → **O(n)**.

---

#### Space Complexity — **O(1)**

**Why O(1):**

* Only a few pointers are used:

  * `temp`
  * `prev`
  * `count`
* No recursion
* No extra data structures

Extra space does **not grow with list size** → **O(1)**.

---

### Interview Insight

> Deletion by position tests whether you **understand pointers**, not syntax.

Common interviewer follow-ups:

* What if `K` is invalid?
* What if list has one node?
* Why prev is needed?
* Why deletion of head is special?
---

## 4. Deletion by Value (First Occurrence)

---

### Problem

Delete the **first node** whose value equals `target`.

> Only the **first occurrence** should be removed.
> If value appears multiple times, stop after deleting the first one.

---

### Key Difference from K-th Delete

* ❌ No position (`K`) is given
* ❌ No counter needed
* ✅ Comparison is based on **data value**
* ✅ Traversal stops when value is found

So mentally:

> “Scan the list → match value → delete once → stop”

---

### Edge Cases (Must Handle)

1. **Empty list**

   ```
   head → null
   ```

   Nothing to delete → return `head`

2. **Value present at head**

   ```
   head → [X] → A → B → null
   ```

   Head itself must be deleted

3. **Value present in middle / tail**

   ```
   head → A → [X] → C → null
   ```

   Relink using previous node

4. **Value not present**

   ```
   head → A → B → C → null
   ```

   List remains unchanged

---

### Intuition (How to Think)

* We must **traverse**, because no direct access
* Track:

  * `temp` → current node
  * `prev` → node before `temp`
* At each step:

  * Compare `temp->data` with `value`
* When match is found:

  * Bypass current node
  * Delete it (C++)
  * Stop traversal (first occurrence only)

Key rule:

> To delete a node safely, you must have access to its **previous node**

---

### Pseudocode

```
DELETE_BY_VALUE(head, value):
    IF head == null:
        RETURN head

    IF head.data == value:
        delete head
        RETURN head.next

    temp ← head
    prev ← null

    WHILE temp != null:
        IF temp.data == value:
            prev.next ← temp.next
            delete temp
            BREAK
        prev ← temp
        temp ← temp.next

    RETURN head
```

---

### C++ Code

#### Version 1 — Simple / Clean (Only Required Function)

```cpp
Node* deleteByValue(Node* head, int value) {
    if (head == nullptr) return head;

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr) {
        if (temp->data == value) {
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}
```

---

#### Version 2 — Deep / Explained (Complete Program)

```cpp
#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to delete first occurrence of a value
Node* deleteByValue(Node* head, int value) {

    // Case 1: Empty list
    if (head == nullptr) {
        return head;
    }

    // Case 2: Value found at head
    if (head->data == value) {
        Node* temp = head;      // store old head
        head = head->next;      // move head
        delete temp;            // free memory
        return head;
    }

    Node* temp = head;          // current node
    Node* prev = nullptr;       // previous node

    // Traverse the list
    while (temp != nullptr) {

        // If target value is found
        if (temp->data == value) {
            prev->next = temp->next; // bypass node
            delete temp;             // delete node
            break;                   // delete ONLY first occurrence
        }

        prev = temp;           // move prev
        temp = temp->next;     // move temp
    }

    // If value not found, list remains unchanged
    return head;
}

// Helper function to print list
void traverse(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    /*
        Initial list:
        10 -> 20 -> 30 -> 20 -> 40 -> NULL
    */

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(20);
    head->next->next->next->next = new Node(40);

    int target = 20;

    head = deleteByValue(head, target);

    traverse(head);

    return 0;
}
```

---

### Dry Run (C++)

Initial list:

```
10 → 20 → 30 → 20 → 40 → NULL
```

Target = `20`

| Step | temp | prev | Action |
| ---- | ---- | ---- | ------ |
| 1    | 10   | null | move   |
| 2    | 20   | 10   | delete |

After deletion:

```
10 → 30 → 20 → 40 → NULL
```

**Output:**

```
10 30 20 40
```

---

### JavaScript Code

#### Version 1 — Simple / Clean (Only Required Function)

```javascript
function deleteByValue(head, value) {
    if (head === null) return head;

    if (head.data === value) {
        return head.next;
    }

    let temp = head;
    let prev = null;

    while (temp !== null) {
        if (temp.data === value) {
            prev.next = temp.next;
            break;
        }
        prev = temp;
        temp = temp.next;
    }

    return head;
}
```

---

#### Version 2 — Deep / Explained (Complete Code)

```javascript
// Node structure
class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

// Function to delete first occurrence of a value
function deleteByValue(head, value) {

    // Case 1: Empty list
    if (head === null) {
        return head;
    }

    // Case 2: Value at head
    if (head.data === value) {
        return head.next; // old head becomes unreachable (GC handles it)
    }

    let temp = head;
    let prev = null;

    // Traverse list
    while (temp !== null) {

        if (temp.data === value) {
            prev.next = temp.next; // bypass node
            break;                 // delete only first match
        }

        prev = temp;
        temp = temp.next;
    }

    return head;
}

// Helper function
function traverse(head) {
    let temp = head;
    let res = "";
    while (temp !== null) {
        res += temp.data + " ";
        temp = temp.next;
    }
    console.log(res.trim());
}

// Main execution
// Initial list: 1 -> 2 -> 3 -> 2 -> 4 -> null
let head = new Node(1);
head.next = new Node(2);
head.next.next = new Node(3);
head.next.next.next = new Node(2);
head.next.next.next.next = new Node(4);

head = deleteByValue(head, 2);

traverse(head);
```

---

### Dry Run (JavaScript)

Initial list:

```
1 → 2 → 3 → 2 → 4 → null
```

Target = `2`

Steps:

1. temp = 1 → no match
2. temp = 2 → match → bypass & stop

Final list:

```
1 → 3 → 2 → 4 → null
```

**Output:**

```
1 3 2 4
```

---

### Time & Space Complexity (Deep Explanation)

#### Time Complexity — **O(n)**

**Why O(n):**

* In worst case:

  * Value is at the end
  * OR value does not exist
* We may need to check **every node**
* Each comparison is constant time

Hence, traversal dominates → **O(n)**.

---

#### Space Complexity — **O(1)**

**Why O(1):**

* Only a few pointers:

  * `temp`
  * `prev`
* No recursion
* No extra data structures

Extra space does not depend on list size → **O(1)**.

---

### Interview Insight

> Deletion by value tests whether you understand **pointer relinking**, not counting.

Common follow-up questions:

* What if value appears multiple times?
* How to delete **all occurrences**?
* What if value is not present?

---

# PART B — INSERTION IN SINGLY LINKED LIST

---

## Universal Insertion Rule

> **Always connect the new node to the list BEFORE breaking existing links.**

Wrong order = lost nodes.

---
## 5. Insert at Head

---

### Intuition

* A new node is created
* This new node becomes the **first node**
* Its `next` should point to the **old head**
* Finally, return this new node as the updated head

Key idea:

> Head insertion does **not depend on list length**

---

### How to Think (Pointer Perspective)

Before insertion:

```
head → A → B → C → null
```

After inserting `X` at head:

```
head → X → A → B → C → null
```

What changed?

* Only **two pointer operations**
* No traversal
* Old list remains intact

---

### C++ Code

#### Version 1 — Simple / Clean (Only Required Function)

```cpp
Node* insertHead(Node* head, int value) {
    Node* temp = new Node(value);
    temp->next = head;
    return temp;
}
```

---

#### Version 2 — Deep / Explained (Complete Program)

```cpp
#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to insert a node at head
Node* insertHead(Node* head, int value) {

    // Step 1:
    // Create a new node with given value
    Node* temp = new Node(value);

    // Step 2:
    // Make new node point to the old head
    temp->next = head;

    // Step 3:
    // Return new node as head
    return temp;
}

// Helper function to print list
void traverse(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    /*
        Initial list:
        10 -> 20 -> 30 -> NULL
    */

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // Insert at head
    head = insertHead(head, 5);

    traverse(head);

    return 0;
}
```

---

### Dry Run (C++)

Initial list:

```
head → 10 → 20 → 30 → NULL
```

Insert value = `5`

Steps:

1. Create new node `5`
2. `temp->next = head` → `5 → 10`
3. Return `temp` as new head

Final list:

```
head → 5 → 10 → 20 → 30 → NULL
```

**Output:**

```
5 10 20 30
```

---

### JavaScript Code

#### Version 1 — Simple / Clean (Only Required Function)

```javascript
function insertHead(head, value) {
    let temp = new Node(value);
    temp.next = head;
    return temp;
}
```

---

#### Version 2 — Deep / Explained (Complete Code)

```javascript
// Node structure
class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

// Function to insert node at head
function insertHead(head, value) {

    // Step 1: Create new node
    let temp = new Node(value);

    // Step 2: Point new node to old head
    temp.next = head;

    // Step 3: Return new node as head
    return temp;
}

// Helper function
function traverse(head) {
    let temp = head;
    let res = "";
    while (temp !== null) {
        res += temp.data + " ";
        temp = temp.next;
    }
    console.log(res.trim());
}

// Main execution
// Initial list: 1 -> 2 -> 3 -> null
let head = new Node(1);
head.next = new Node(2);
head.next.next = new Node(3);

// Insert at head
head = insertHead(head, 0);

traverse(head);
```

---

### Dry Run (JavaScript)

Initial list:

```
1 → 2 → 3 → null
```

Insert value = `0`

Steps:

1. New node created → `0`
2. `0.next = 1`
3. New head is `0`

Final list:

```
0 → 1 → 2 → 3 → null
```

**Output:**

```
0 1 2 3
```

---

### Time & Space Complexity (Deep Explanation)

#### Time Complexity — **O(1)**

**Why O(1):**

* No traversal is needed
* Operations performed:

  * create one node
  * update one pointer
* These steps are constant-time operations

So time does **not depend on list size** → **O(1)**.

---

#### Space Complexity — **O(1)** (Extra Space)

**Why O(1):**

* Only one new node is created
* No extra helper structures
* No recursion

**Important clarification:**

* Memory for the new node is part of the **output list**
* Space complexity measures **extra working memory**, not the final data structure

Hence, **O(1)** extra space.

---

### Interview Insight

> Insert at head is the **fastest insertion** in a singly linked list.

Common interviewer follow-up:

* Why is insert at head O(1) but insert at tail O(n)?
* Answer: Head is directly accessible, tail needs traversal (unless tail pointer exists)
---
## 6. Insert at Tail

---

### Intuition

* To insert at tail, we must reach the **last node**
* Last node is identified by:
  `next == null`
* Once we reach it:

  * Create a new node
  * Attach it to `last->next`
  * New node’s `next` will be `null`

Key idea:

> In a **singly linked list**, tail is **not directly accessible**, so traversal is required.

---

### How to Think (Pointer Perspective)

Before insertion:

```
head → A → B → C → null
```

Insert `X` at tail:

```
head → A → B → C → X → null
```

What changes?

* Only the **last node’s `next`**
* But finding the last node requires traversal

---

### Edge Case (Very Important)

**Empty list**

```
head → null
```

If list is empty:

* New node itself becomes the head
* No traversal needed

---

### C++ Code

#### Version 1 — Simple / Clean (Only Required Function)

```cpp
Node* insertTail(Node* head, int value) {
    if (head == nullptr) {
        return new Node(value);
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = new Node(value);
    return head;
}
```

---

#### Version 2 — Deep / Explained (Complete Program)

```cpp
#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to insert a node at the tail
Node* insertTail(Node* head, int value) {

    // Case 1: Empty list
    // If head is null, the new node itself becomes the head
    if (head == nullptr) {
        return new Node(value);
    }

    // Temporary pointer to traverse the list
    Node* temp = head;

    // Move temp until it reaches the last node
    // Last node is identified by temp->next == nullptr
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // temp is now the last node
    // Attach the new node at the end
    temp->next = new Node(value);

    // Head remains unchanged
    return head;
}

// Helper function to print list
void traverse(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    /*
        Initial list:
        10 -> 20 -> 30 -> NULL
    */

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // Insert at tail
    head = insertTail(head, 40);

    traverse(head);

    return 0;
}
```

---

### Dry Run (C++)

Initial list:

```
head → 10 → 20 → 30 → NULL
```

Insert value = `40`

Steps:

1. `temp = head` → points to `10`
2. Move temp → `20`
3. Move temp → `30`
4. `temp->next == null` → stop
5. `temp->next = new Node(40)`

Final list:

```
head → 10 → 20 → 30 → 40 → NULL
```

**Output:**

```
10 20 30 40
```

---

### JavaScript Code

#### Version 1 — Simple / Clean (Only Required Function)

```javascript
function insertTail(head, value) {
    if (head === null) {
        return new Node(value);
    }

    let temp = head;

    while (temp.next !== null) {
        temp = temp.next;
    }

    temp.next = new Node(value);
    return head;
}
```

---

#### Version 2 — Deep / Explained (Complete Code)

```javascript
// Node structure
class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

// Function to insert node at tail
function insertTail(head, value) {

    // Case 1: Empty list
    if (head === null) {
        return new Node(value);
    }

    // Temporary pointer for traversal
    let temp = head;

    // Traverse until last node
    while (temp.next !== null) {
        temp = temp.next;
    }

    // Attach new node at the end
    temp.next = new Node(value);

    // Head remains unchanged
    return head;
}

// Helper function
function traverse(head) {
    let temp = head;
    let res = "";
    while (temp !== null) {
        res += temp.data + " ";
        temp = temp.next;
    }
    console.log(res.trim());
}

// Main execution
// Initial list: 1 -> 2 -> 3 -> null
let head = new Node(1);
head.next = new Node(2);
head.next.next = new Node(3);

// Insert at tail
head = insertTail(head, 4);

traverse(head);
```

---

### Dry Run (JavaScript)

Initial list:

```
1 → 2 → 3 → null
```

Insert value = `4`

Steps:

1. temp = 1 → move
2. temp = 2 → move
3. temp = 3 → stop (`next == null`)
4. Attach `4` after `3`

Final list:

```
1 → 2 → 3 → 4 → null
```

**Output:**

```
1 2 3 4
```

---

### Time & Space Complexity (Deep Explanation)

#### Time Complexity — **O(n)**

**Why O(n):**

* We must traverse from head to the last node
* In worst case, we visit all `n` nodes
* Each step is constant time

So traversal dominates → **O(n)**.

**Important comparison:**

* Insert at head → O(1)
* Insert at tail → O(n) (without tail pointer)

---

#### Space Complexity — **O(1)** (Extra Space)

**Why O(1):**

* Only one new node is created
* One temporary pointer is used
* No recursion or extra structures

Extra working space is constant → **O(1)**.

---

### Interview Insight

> Insert at tail is costly in a **singly linked list** without a tail pointer.

Follow-up answers:

* How to make it O(1)?
  → Maintain a `tail` pointer
  → Or use a doubly linked list
---

## 7. Insert at K-th Position

---

### Important Rule

> Valid K is **1 to (length + 1)**

**Why this rule exists:**

* `K = 1` → insert **before head**
* `K = length` → insert before last node
* `K = length + 1` → insert **after last node (tail)**
* Anything beyond this means:

  * There is **no valid node** to attach after
  * Linked list structure will break

So we must **never insert blindly**.

---

### Case Handling

* **K = 1** → insert at head
* **K > length + 1** → invalid (no insertion)
* **Else** → insert somewhere in the middle or end

This branching avoids:

* null pointer access
* broken links
* memory leaks

---

### Key Pointer Order (CRITICAL)

1. `newNode->next = temp->next`
2. `temp->next = newNode`

**Why this exact order matters:**

If you reverse it:

```cpp
temp->next = newNode;
newNode->next = temp->next; // WRONG
```

You lose the original link permanently.

Correct order ensures:

* Old connection is preserved
* New node is safely placed between nodes

---

### Pseudocode

```
INSERT_AT_K(head, value, K):

    IF K == 1:
        INSERT at head
        RETURN new head

    temp ← head
    count ← 1

    WHILE temp is not NULL:
        IF count == K - 1:
            CREATE newNode(value)
            newNode.next ← temp.next
            temp.next ← newNode
            BREAK

        count ← count + 1
        temp ← temp.next

    RETURN head
```

---

### C++ Code

#### Version 1 — Simple / Clean (Only Required Function)

```cpp
Node* insertAtK(Node* head, int value, int K) {
    if (K == 1) {
        return insertHead(head, value);
    }

    Node* temp = head;
    int count = 1;

    while (temp != nullptr) {
        if (count == K - 1) {
            Node* node = new Node(value);
            node->next = temp->next;
            temp->next = node;
            break;
        }
        count++;
        temp = temp->next;
    }

    return head;
}
```

---

#### Version 2 — Deep / Explained (Complete Program)

```cpp
#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Insert at head helper
Node* insertHead(Node* head, int value) {
    Node* node = new Node(value);
    node->next = head;
    return node;
}

// Insert at K-th position
Node* insertAtK(Node* head, int value, int K) {

    // Case 1: Insert at head
    if (K == 1) {
        return insertHead(head, value);
    }

    Node* temp = head;
    int count = 1;

    // Traverse to (K-1)th node
    while (temp != nullptr) {

        if (count == K - 1) {

            // Create new node
            Node* node = new Node(value);

            // Correct pointer order
            node->next = temp->next;
            temp->next = node;

            break;
        }

        count++;
        temp = temp->next;
    }

    return head;
}

// Helper traversal
void traverse(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    /*
        Initial list:
        10 -> 20 -> 30 -> NULL
        Insert 25 at K = 3
    */

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    head = insertAtK(head, 25, 3);

    traverse(head);

    return 0;
}
```

---

### Dry Run (C++)

Initial list:

```
10 → 20 → 30 → NULL
```

Insert `25` at `K = 3`

| Step   | temp | count | Action       |
| ------ | ---- | ----- | ------------ |
| Start  | 10   | 1     | not K-1      |
| Move   | 20   | 2     | count == K-1 |
| Insert | —    | —     | link node    |

Pointer update:

```
node->next = 30
20->next = node
```

Final list:

```
10 → 20 → 25 → 30 → NULL
```

---

### JavaScript Code

#### Version 1 — Simple / Clean (Only Required Function)

```javascript
function insertAtK(head, value, K) {
    if (K === 1) {
        return insertHead(head, value);
    }

    let temp = head;
    let count = 1;

    while (temp !== null) {
        if (count === K - 1) {
            let node = new Node(value);
            node.next = temp.next;
            temp.next = node;
            break;
        }
        count++;
        temp = temp.next;
    }

    return head;
}
```

---

#### Version 2 — Deep / Explained (Complete Code)

```javascript
class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

// Insert at head
function insertHead(head, value) {
    let node = new Node(value);
    node.next = head;
    return node;
}

// Insert at K-th position
function insertAtK(head, value, K) {

    // Case 1: insert at head
    if (K === 1) {
        return insertHead(head, value);
    }

    let temp = head;
    let count = 1;

    while (temp !== null) {

        if (count === K - 1) {

            let node = new Node(value);

            // Correct pointer order
            node.next = temp.next;
            temp.next = node;

            break;
        }

        count++;
        temp = temp.next;
    }

    return head;
}

// Helper traversal
function traverse(head) {
    let temp = head;
    let result = "";
    while (temp !== null) {
        result += temp.data + " ";
        temp = temp.next;
    }
    console.log(result.trim());
}

// Main
// Initial list: 1 → 2 → 4 → null
let head = new Node(1);
head.next = new Node(2);
head.next.next = new Node(4);

// Insert 3 at K = 3
head = insertAtK(head, 3, 3);

traverse(head);
```

---

### Dry Run (JavaScript)

Initial list:

```
1 → 2 → 4 → null
```

Insert `3` at `K = 3`

* Stop at node `2`
* Attach `3` between `2` and `4`

Final list:

```
1 → 2 → 3 → 4 → null
```

---

### Time & Space Complexity (Deep Explanation)

#### Time Complexity — **O(n)**

**Why:**

* We may need to traverse up to `K-1` nodes
* In worst case, `K = length + 1`
* That means full traversal of list

Traversal cost grows with list size → **O(n)**

---

#### Space Complexity — **O(1)**

**Why:**

* Only one new node is created (required output)
* Only one temp pointer used
* No recursion
* No extra data structures

Extra memory does **not depend on list size** → **O(1)**

---

### Interview Insight

> Insert at K is a **generalized insertion** problem.
---
## 8. Insert Before a Given Value

---

### Intuition

* We **cannot insert directly before a node** in a singly linked list
* Because we don’t have a pointer to the **previous node**
* So the trick is:

  * **Stop one node before the target**
  * Then insert exactly like **middle insertion**

Key idea in one line:

> To insert before `target`, you must stand at the node whose `next` is `target`.

---

### Why Head Needs Special Handling

If the **target value is present at head**:

```
head → [target] → ...
```

Then “insert before target” means:

```
head → [new] → [target] → ...
```

This is **exactly the same as insert at head**.

That’s why:

* We must check `head->data == target`
* And directly call `insertHead`

---

### Pseudocode

```
INSERT_BEFORE_VALUE(head, value, target):

    IF head == null:
        RETURN head

    IF head.data == target:
        INSERT at head
        RETURN new head

    temp ← head

    WHILE temp.next != null:
        IF temp.next.data == target:
            CREATE newNode(value)
            newNode.next ← temp.next
            temp.next ← newNode
            BREAK
        temp ← temp.next

    RETURN head
```

---

### C++ Code

#### Version 1 — Simple / Clean (Only Required Function)

```cpp
Node* insertBeforeValue(Node* head, int value, int target) {
    if (head == nullptr) return head;

    if (head->data == target) {
        return insertHead(head, value);
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        if (temp->next->data == target) {
            Node* node = new Node(value);
            node->next = temp->next;
            temp->next = node;
            break;
        }
        temp = temp->next;
    }

    return head;
}
```

---

#### Version 2 — Deep / Explained (Complete Program)

```cpp
#include <iostream>
using namespace std;

// =======================
// Node structure
// =======================
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// =======================
// Insert at head helper
// =======================
// Used when target is present at head
Node* insertHead(Node* head, int value) {
    Node* node = new Node(value);
    node->next = head;
    return node;
}

// =======================
// Insert before given value
// =======================
Node* insertBeforeValue(Node* head, int value, int target) {

    // Case 1: Empty list
    // Nothing to insert before
    if (head == nullptr) {
        return head;
    }

    // Case 2: Target is at head
    // Insert before head = insert at head
    if (head->data == target) {
        return insertHead(head, value);
    }

    // Temporary pointer for traversal
    Node* temp = head;

    // Traverse until second last node
    // We check temp->next because we want to stop BEFORE target
    while (temp->next != nullptr) {

        // If next node contains the target
        if (temp->next->data == target) {

            // Create new node
            Node* node = new Node(value);

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
void traverse(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    /*
        Initial list:
        10 -> 20 -> 30 -> 40 -> NULL

        Insert 25 before target = 30

        Expected:
        10 -> 20 -> 25 -> 30 -> 40 -> NULL
    */

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    head = insertBeforeValue(head, 25, 30);

    traverse(head);

    return 0;
}
```

---

### Dry Run (C++)

Initial list:

```
10 → 20 → 30 → 40 → NULL
```

Target = `30`, value = `25`

Steps:

1. `temp = 10` → `temp->next = 20` (not target)
2. Move temp → `temp = 20`
3. `temp->next = 30` → target found
4. Create node `25`
5. `25->next = 30`
6. `20->next = 25`

Final list:

```
10 → 20 → 25 → 30 → 40 → NULL
```

---

### JavaScript Code

#### Version 1 — Simple / Clean (Only Required Function)

```javascript
function insertBeforeValue(head, value, target) {
    if (head === null) return head;

    if (head.data === target) {
        return insertHead(head, value);
    }

    let temp = head;

    while (temp.next !== null) {
        if (temp.next.data === target) {
            let node = new Node(value);
            node.next = temp.next;
            temp.next = node;
            break;
        }
        temp = temp.next;
    }

    return head;
}
```

---

#### Version 2 — Deep / Explained (Complete Code)

```javascript
// =======================
// Node structure
// =======================
class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

// =======================
// Insert at head helper
// =======================
function insertHead(head, value) {
    let node = new Node(value);
    node.next = head;
    return node;
}

// =======================
// Insert before given value
// =======================
function insertBeforeValue(head, value, target) {

    // Case 1: Empty list
    if (head === null) {
        return head;
    }

    // Case 2: Target at head
    if (head.data === target) {
        return insertHead(head, value);
    }

    let temp = head;

    // Traverse list
    while (temp.next !== null) {

        // Check next node (we stop one step before target)
        if (temp.next.data === target) {

            let node = new Node(value);

            // Correct pointer order
            node.next = temp.next;
            temp.next = node;

            break;
        }

        temp = temp.next;
    }

    return head;
}

// =======================
// Traversal helper
// =======================
function traverse(head) {
    let temp = head;
    let result = "";
    while (temp !== null) {
        result += temp.data + " ";
        temp = temp.next;
    }
    console.log(result.trim());
}

// Main execution
// Initial list: 1 → 2 → 3 → 4 → null
let head = new Node(1);
head.next = new Node(2);
head.next.next = new Node(3);
head.next.next.next = new Node(4);

// Insert 99 before 3
head = insertBeforeValue(head, 99, 3);

traverse(head);
```

---

### Dry Run (JavaScript)

Initial list:

```
1 → 2 → 3 → 4 → null
```

Insert `99` before `3`

* Stop at node `2`
* Insert `99` between `2` and `3`

Final list:

```
1 → 2 → 99 → 3 → 4 → null
```

---

### Time & Space Complexity (Deep Explanation)

#### Time Complexity — **O(n)**

**Why:**

* We may need to scan the entire list to find `target`
* In worst case, target is at the end or not present
* Each node is visited once

So traversal dominates → **O(n)**

---

#### Space Complexity — **O(1)**

**Why:**

* Only one new node is created (required output)
* Only one traversal pointer (`temp`)
* No recursion
* No extra data structures

Extra memory does **not depend on list size** → **O(1)**

---

### Interview Insight

> “Insert before value” is just **insert at K**, where K is **unknown**.
---

## Final Q&A Synthesis (Mindset Lock)

### Q1. Why deletion is harder than insertion?

Because deletion needs **memory + link control**.

---

### Q2. Why `prev` is mandatory?

Because singly linked list has **no backward traversal**.

---

### Q3. Why pointer order matters in insertion?

Wrong order = lost nodes forever.

---

### Q4. Why everything is O(n)?

Because linked list has **no random access**.

---

### Q5. What breaks most candidates?

* Losing head
* Breaking links early
* Ignoring edge cases
