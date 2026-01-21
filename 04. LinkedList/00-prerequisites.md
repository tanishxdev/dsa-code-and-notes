# LINKED LIST — ABSOLUTE FOUNDATIONS (FROM ZERO)

If these foundations are weak, **nothing in Linked Lists will feel stable** later.

---

## 1. What Is Memory? (Very Basic but Critical)

Computer memory is just a **huge collection of boxes**.

Each box has:

* an **address** (number)
* a **value** stored inside

Example memory:

```text
Address 100 → ?
Address 101 → ?
Address 102 → ?
```

When you write:

```cpp
int x = 5;
```

What really happens:

```text
Address 200 → 5
```

* `x` is just a **name**
* actual value `5` lives at **address 200**

Important rule:

> Every variable lives somewhere in memory.

---

## 2. What Is a Pointer? (MOST IMPORTANT CONCEPT)

### Definition (Plain English)

A **pointer** is a variable that stores the **address of another variable**.

---

### Example Code

```cpp
int x = 5;
int* p = &x;
```

Let’s break this line by line.

#### Step 1: `int x = 5;`

```text
Address 200 → 5
```

#### Step 2: `int* p = &x;`

* `&x` means: “give me the address of x”
* `p` stores that address

Memory now:

```text
x → address 200 → value 5
p → address 300 → value 200
```

Key understanding:

* `x` stores **value**
* `p` stores **address**
* `*p` means: “go to the address inside p and get the value”

```cpp
cout << *p;   // prints 5
```

Golden rule:

> Linked Lists are **impossible** without pointers.

---

## 3. Stack vs Heap (Why Linked Lists Need Heap)

---

### Stack Memory

```cpp
Node x(10);
```

* Created automatically
* Destroyed automatically when function ends

Example:

```cpp
void func() {
    Node x(10);
} // x is destroyed here
```

Problem:

> Node disappears → Linked List breaks

---

### Heap Memory

```cpp
Node* x = new Node(10);
```

* Memory stays alive
* Only destroyed when `delete` is called

Why Linked Lists use heap:

* Nodes must survive
* Nodes must stay connected
* Size is dynamic

Important rule:

> **All Linked List nodes are heap-allocated.**

---

## 4. Class and Object (Quick Reminder)

```cpp
class Node {
public:
    int data;
    Node* next;
};
```

### Object

```cpp
Node a;
```

* Stores data directly

### Pointer to Object

```cpp
Node* b;
```

* Stores address of a Node

Linked Lists **always use `Node*`**, not `Node`.

---

## 5. Meaning of NULL / nullptr

```cpp
nullptr
```

Means:

> “This pointer is not pointing to any valid memory”

In Linked List:

* Last node’s `next = nullptr`
* That is how traversal stops

---
