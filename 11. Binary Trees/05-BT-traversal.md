# BINARY TREE TRAVERSALS — INORDER, PREORDER, POSTORDER, LEVEL ORDER

---

## What We Covered Here

1. Why traversal is needed in trees
2. Difference between DFS and BFS
3. Depth First Search (DFS) intuition
4. Breadth First Search (BFS) intuition
5. Inorder traversal (Left → Root → Right)
6. Preorder traversal (Root → Left → Right)
7. Postorder traversal (Left → Right → Root)
8. Recursive traversal mechanism
9. Level Order traversal (BFS using queue)
10. Pseudocode for all traversals
11. Dry run on a sample tree
12. C++ implementations (all traversals)
13. JavaScript implementations (all traversals)
14. Time & space complexity analysis
15. Interview-level Q&A synthesis

---

## 1. Why Traversal Is Needed (Mindset First)

A tree is **not linear**.

You cannot:

- Access elements by index
- Randomly jump to nodes

So the only way to:

- Read data
- Process nodes
- Apply logic

is to **visit nodes one by one** → this process is called **Traversal**.

_Tree traversal means visiting every node exactly once in a specific order._

---

## 2. Two Broad Categories of Tree Traversal

![](https://static.takeuforward.org/content/-2BrrXvQo)

### 2.1 Depth First Search (DFS)

> Go as **deep as possible** before coming back.

- Starts from root
- Goes down one branch fully
- Backtracks when no further child exists

DFS is implemented using:

- **Recursion** (implicit stack)
- OR **explicit stack**

---

### 2.2 Breadth First Search (BFS)

> Go **level by level**.

- Visit all nodes at level 0
- Then level 1
- Then level 2 …

BFS is implemented using:

- **Queue**

---

## 3. Sample Tree (We’ll Use This Everywhere)

```
        1
       / \
      2   3
         /
        5
```

Root = `1`

---

## 4. Depth First Search (DFS) Traversals

DFS depends on **WHEN you visit the root**.

There are **3 types**:

| Traversal | Order               |
| --------- | ------------------- |
| Inorder   | Left → Root → Right |
| Preorder  | Root → Left → Right |
| Postorder | Left → Right → Root |

## ![](https://static.takeuforward.org/content/-RXXPMuEv)

## 5. Inorder Traversal (L → R → R)

![](https://static.takeuforward.org/content/-Jg6Rjk7C)

### Definition

> Visit **Left subtree**, then **Root**, then **Right subtree**

Order:

```
Left → Root → Right
```

---

### Why It’s Important

- In a **Binary Search Tree (BST)**,
  inorder traversal gives **sorted order**.

---

### Pseudocode (Inorder)

```
INORDER(node):
    IF node is NULL:
        RETURN

    INORDER(node.left)
    VISIT node
    INORDER(node.right)
```

---

### Dry Run (Inorder)

Tree:

```
        1
       / \
      2   3
         /
        5
```

Traversal:

- Left of 1 → 2
- Visit 2
- Visit 1
- Left of 3 → 5
- Visit 5
- Visit 3

**Output:**

```
2 1 5 3
```

---

### C++ Code (Inorder)

```cpp
void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);          // left
    cout << root->data << " ";    // root
    inorder(root->right);         // right
}
```

---

### JavaScript Code (Inorder)

```javascript
function inorder(root) {
  if (root === null) return;

  inorder(root.left);
  console.log(root.data);
  inorder(root.right);
}
```

---

## 6. Preorder Traversal (R → L → R)

![](https://static.takeuforward.org/content/-SHy81zDa)

### Definition

> Visit **Root first**, then **Left**, then **Right**

Order:

```
Root → Left → Right
```

---

### Why It’s Used

- Used to **copy trees**
- Used in **serialization**
- Structure-first traversal

---

### Pseudocode (Preorder)

```
PREORDER(node):
    IF node is NULL:
        RETURN

    VISIT node
    PREORDER(node.left)
    PREORDER(node.right)
```

---

### Dry Run (Preorder)

Traversal:

- Visit 1
- Visit 2
- Visit 3
- Visit 5

**Output:**

```
1 2 3 5
```

---

### C++ Code (Preorder)

```cpp
void preorder(Node* root) {
    if (root == nullptr)
        return;

    cout << root->data << " ";    // root
    preorder(root->left);         // left
    preorder(root->right);        // right
}
```

---

### JavaScript Code (Preorder)

```javascript
function preorder(root) {
  if (root === null) return;

  console.log(root.data);
  preorder(root.left);
  preorder(root.right);
}
```

---

## 7. Postorder Traversal (L → R → R)

![](https://static.takeuforward.org/content/-2KdT_sT1)

### Definition

> Visit **Left**, then **Right**, then **Root**

Order:

```
Left → Right → Root
```

---

### Why It’s Important

- Used in **tree deletion**
- Used to evaluate **expression trees**
- Children-first logic

---

### Pseudocode (Postorder)

```
POSTORDER(node):
    IF node is NULL:
        RETURN

    POSTORDER(node.left)
    POSTORDER(node.right)
    VISIT node
```

---

### Dry Run (Postorder)

Traversal:

- Visit 2
- Visit 5
- Visit 3
- Visit 1

**Output:**

```
2 5 3 1
```

---

### C++ Code (Postorder)

```cpp
void postorder(Node* root) {
    if (root == nullptr)
        return;

    postorder(root->left);        // left
    postorder(root->right);       // right
    cout << root->data << " ";    // root
}
```

---

### JavaScript Code (Postorder)

```javascript
function postorder(root) {
  if (root === null) return;

  postorder(root.left);
  postorder(root.right);
  console.log(root.data);
}
```

---

## 8. Level Order Traversal (BFS)

![](https://static.takeuforward.org/content/-Yh5uQD-T)

### Definition

> Visit nodes **level by level**, left to right.

---

### Data Structure Used

- **Queue**

Why?

- FIFO order
- Nodes visited in same order they are discovered

---

### Pseudocode (Level Order)

```
LEVELORDER(root):
    IF root is NULL:
        RETURN

    CREATE queue
    PUSH root into queue

    WHILE queue not empty:
        node = POP front
        VISIT node

        IF node.left exists:
            PUSH node.left

        IF node.right exists:
            PUSH node.right
```

---

### Dry Run (Level Order)

Levels:

```
Level 0 → 1
Level 1 → 2 3
Level 2 → 5
```

**Output:**

```
1 2 3 5
```

---

### C++ Code (Level Order)

```cpp
#include <queue>

void levelOrder(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left)
            q.push(curr->left);

        if (curr->right)
            q.push(curr->right);
    }
}
```

---

### JavaScript Code (Level Order)

```javascript
function levelOrder(root) {
  if (root === null) return;

  let queue = [];
  queue.push(root);

  while (queue.length > 0) {
    let curr = queue.shift();
    console.log(curr.data);

    if (curr.left) queue.push(curr.left);
    if (curr.right) queue.push(curr.right);
  }
}
```

---

## 9. Time & Space Complexity

### DFS Traversals

- Time: **O(n)** (each node visited once)
- Space:
  - Recursive stack → **O(h)**
  - Worst case (skewed tree) → **O(n)**

---

### BFS Traversal

- Time: **O(n)**
- Space:
  - Queue can hold max nodes at a level
  - Worst case → **O(n)**

---

Good doubt.
Let’s slow it down and build the **exact mental model**.
No extra fluff.

---

## What problem are we solving here?

**Level Order Traversal** =
👉 Print nodes **level by level** (top to bottom, left to right)

Example tree:

```
        1
      /   \
     2     3
    / \     \
   4   5     6
```

Expected output:

```
1 2 3 4 5 6
```

---

### Core questions! I have doubts

> **why are we pushing nodes into the queue?**

Short answer:

> **Queue stores the "next nodes to be visited later" in correct order**

Now let’s explain **WHY** in depth.

---

#### Key Rule of Level Order Traversal

1. Visit a node
2. **Remember its children for later**
3. Visit remembered nodes **in the same order**

👉 This is exactly what a **queue (FIFO)** is good at.

---

#### Why queue, not stack?

| Data Structure | Order                        |
| -------------- | ---------------------------- |
| Stack          | LIFO (Last In First Out) ❌  |
| Queue          | FIFO (First In First Out) ✅ |

Level order **needs FIFO**, so queue is mandatory.

---

#### Line-by-line explanation (important)

```cpp
queue<Node*> q;
```

Creates a queue to **store nodes that are waiting to be processed**.

Think of it as:

```
"Who should be visited next?"
```

---

```cpp
q.push(root);
```

Why push root?

Because:

- Root is the **first node to process**
- Queue must start with **level 0**

Queue now:

```
[ 1 ]
```

---

```cpp
while (!q.empty()) {
```

Loop until **all levels are processed**.

---

```cpp
Node* curr = q.front();
q.pop();
```

- Take the **oldest inserted node**
- This ensures **left to right order**

Queue before pop:

```
[ 1 ]
```

After pop:

```
[ ]
```

---

```cpp
cout << curr->data << " ";
```

We **visit / print** the node.

---

#### MOST IMPORTANT PART (your doubt)

```cpp
if (curr->left)
    q.push(curr->left);

if (curr->right)
    q.push(curr->right);
```

#### WHY push children?

Because:

- We are done with `curr`
- But **its children must be visited later**
- So we **store them in queue**

This preserves **level order**.

---

#### Dry Run (must read)

#### Initial

```
Queue: [1]
Output:
```

---

#### Process 1

- Pop `1`
- Print `1`
- Push `2`, `3`

```
Queue: [2, 3]
Output: 1
```

---

#### Process 2

- Pop `2`
- Print `2`
- Push `4`, `5`

```
Queue: [3, 4, 5]
Output: 1 2
```

---

#### Process 3

- Pop `3`
- Print `3`
- Push `6`

```
Queue: [4, 5, 6]
Output: 1 2 3
```

---

#### Process 4,5,6

```
Output: 1 2 3 4 5 6
Queue: empty
```

Traversal ends.

---

#### One-line intuition (interview ready)

> **We push nodes into the queue so that their children are visited later in FIFO order, which guarantees level-by-level traversal.**

---

#### Common mistake to avoid

❌ Printing child immediately
❌ Using stack instead of queue
❌ Forgetting to push children

---

## 10. Interview-Level Q&A Synthesis

### Q1. Which traversal gives sorted order in BST?

**Inorder traversal**

---

### Q2. Which traversal is used to delete a tree?

**Postorder**

---

### Q3. Which traversal is best for copying a tree?

**Preorder**

---

### Q4. Why recursion works so well for DFS?

Because tree structure is **naturally recursive**.

---

### Q5. DFS vs BFS — when to use?

- DFS → depth-based problems
- BFS → level-based problems

---

## Key Takeaway (Lock This)

> Traversal = **how you walk the tree**
> DFS cares about **depth**
> BFS cares about **levels**
