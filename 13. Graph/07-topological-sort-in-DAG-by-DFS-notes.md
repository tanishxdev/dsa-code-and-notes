# Topological Sort using DFS (Directed Acyclic Graph)

Reference:
[https://www.geeksforgeeks.org/topological-sorting/](https://www.geeksforgeeks.org/topological-sorting/)

---

## Section 1 — Understanding the Problem

### Problem Statement

You are given a **directed graph** with `V` vertices (numbered `0` to `V-1`).
The graph is represented using an **adjacency list**.

Your task is to return a **topological ordering** of the vertices.

---

### What Is Topological Sort?

A **topological sort** is a **linear ordering of vertices** such that:

> For every directed edge `u → v`,
> vertex `u` appears **before** vertex `v` in the ordering.

---

### Important Conditions

* Topological sort is **only possible for Directed Acyclic Graphs (DAGs)**
* If a graph has a **cycle**, topological order **does not exist**

*Explain this in better way*

##### Topological Sort — Key Rule

> **Topological sort is possible only for Directed Acyclic Graphs (DAGs).**

Why?

Because topological order means:

> For every directed edge `u → v`,
> **`u` must appear before `v`** in the ordering.

---

###### Example 1 — DAG (Topological Order Exists)

```
0 → 1 → 2
```

Valid topological order:

```
0, 1, 2
```

Reason:

* `0` comes before `1`
* `1` comes before `2`
* No conflicts

---

###### Example 2 — Directed Graph with Cycle (No Topological Order)

```
0 → 1 → 2
↑         ↓
└─────────┘
```

Try to order:

* `0` before `1`
* `1` before `2`
* `2` before `0` ❌

Impossible.

Reason:

> Each node depends on another node in the cycle.

---

##### One-Line Interview Answer (Lock This)

> **Topological sort is only possible in DAGs because cycles create circular dependencies, making a valid ordering impossible.**

---

### Example

**Input**

```
V = 6
adj = [
  [2, 3],
  [3, 4],
  [],
  [5],
  [5],
  []
]
```

**Output (one valid order)**

```
[1, 4, 0, 3, 5, 2]
```

(There can be multiple valid answers.)

---

### What Exactly Is Being Asked?

* Arrange all vertices in a linear order
* Ensure **dependency direction is respected**
* Return the order as an array/list

---

## Section 2 — Building the Solution

### Intuition

#### Why DFS Works for Topological Sort

Topological sorting is about **dependencies**.

If there is an edge:

```
u → v
```

Then:

* `u` **must come before** `v`

DFS helps because:

* It goes **deep first**
* A node finishes **only after all its dependent nodes finish**

---

#### Key Insight (Very Important)

> A node should be added to the result **after all nodes reachable from it are already processed**.

This is exactly what DFS gives us.

---

#### Stack-Based Thinking

* Perform DFS
* When DFS finishes for a node:

  * Push that node into a stack
* After DFS of all nodes:

  * Pop stack elements to get topological order

Why stack?

Because:

* Nodes that depend on others are pushed **earlier**
* Nodes with no dependencies end up **on top**

---

#### Why Graph Must Be Acyclic

If a cycle exists:

```
A → B → C → A
```

Then:

* No node can come before the other
* Ordering becomes impossible

That is why **Topological Sort only works on DAGs**.

---

#### One-Line Mental Model

> **Push a node into the stack only when all nodes dependent on it are already placed below it.**

---

### Algorithm (DFS Based)

1. Create a `visited` array of size `V`, initialized to `false`
2. Create an empty stack
3. For every vertex `i` from `0` to `V-1`:

   * If `i` is not visited, run DFS from `i`
4. In DFS:

   * Mark current node as visited
   * For each neighbor:

     * If not visited, call DFS on neighbor
   * After all neighbors are processed:

     * Push current node into stack
5. Pop all elements from stack → this is the topological order

---

### Pseudocode

```
function topoSort(V, adj):
    visited = array[V] initialized to false
    stack = empty stack

    for i from 0 to V-1:
        if not visited[i]:
            dfs(i)

    result = empty list
    while stack not empty:
        result.append(stack.pop())

    return result


function dfs(node):
    visited[node] = true

    for neighbor in adj[node]:
        if not visited[neighbor]:
            dfs(neighbor)

    stack.push(node)
```

---

### Code — C++ (Primary, Exact Logic)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // =====================================================================
    // Helper Function: dfs
    //
    // Purpose:
    // - Performs DFS traversal
    // - Pushes a node to stack ONLY AFTER all its neighbors are processed
    //
    // Parameters:
    // node    -> current node being visited
    // adj     -> adjacency list of directed graph
    // visited -> keeps track of visited nodes
    // st      -> stack to store topological order
    // =====================================================================
    void dfs(int node,
             vector<vector<int>>& adj,
             vector<bool>& visited,
             stack<int>& st) {

        // Mark current node as visited
        visited[node] = true;

        // Explore all outgoing edges from current node
        for (int neighbor : adj[node]) {

            // If neighbor is not visited, continue DFS
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, st);
            }
        }

        // IMPORTANT:
        // Push current node into stack AFTER all its neighbors
        // This ensures correct topological ordering
        st.push(node);
    }

    // =====================================================================
    // Function: topoSort
    //
    // Purpose:
    // - Returns a valid topological ordering of a DAG
    // - Uses DFS + stack
    //
    // Parameters:
    // V   -> number of vertices
    // adj -> adjacency list of directed graph
    //
    // Returns:
    // Vector containing topological order
    // =====================================================================
    vector<int> topoSort(int V, vector<vector<int>>& adj) {

        // Visited array to track visited nodes
        vector<bool> visited(V, false);

        // Stack to store topological ordering
        stack<int> st;

        // Run DFS from every unvisited node
        // This handles disconnected graphs
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, st);
            }
        }

        // Pop stack to get topological order
        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};

int main() {
    int V = 6;

    // Directed graph adjacency list
    vector<vector<int>> adj = {
        {2, 3},   // 0 -> 2, 3
        {3, 4},   // 1 -> 3, 4
        {},       // 2
        {5},      // 3 -> 5
        {5},      // 4 -> 5
        {}        // 5
    };

    Solution sol;

    // Get topological order
    vector<int> topo = sol.topoSort(V, adj);

    // Print result
    cout << "Topological Order: ";
    for (int x : topo) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
```

---

### Code — JavaScript (Equivalent Logic)

```javascript
class Solution {
  dfs(node, adj, visited, stack) {
    visited[node] = true;

    for (const neighbor of adj[node]) {
      if (!visited[neighbor]) {
        this.dfs(neighbor, adj, visited, stack);
      }
    }

    // Push after exploring all neighbors
    stack.push(node);
  }

  topoSort(V, adj) {
    const visited = new Array(V).fill(false);
    const stack = [];

    for (let i = 0; i < V; i++) {
      if (!visited[i]) {
        this.dfs(i, adj, visited, stack);
      }
    }

    // Reverse stack for topological order
    return stack.reverse();
  }
}

// Example usage
const V = 6;
const adj = [
  [2, 3],
  [3, 4],
  [],
  [5],
  [5],
  []
];

const sol = new Solution();
console.log("Topological Order:", sol.topoSort(V, adj));
```

---

### Dry Run (Step-by-Step)

**Graph**

```
0 → 2, 3
1 → 3, 4
3 → 5
4 → 5
```

**DFS Flow**

* Start DFS at `0`

  * DFS(2) → push `2`
  * DFS(3)

    * DFS(5) → push `5`
    * push `3`
  * push `0`
* DFS at `1`

  * DFS(4)

    * neighbor `5` already visited
    * push `4`
  * push `1`

**Stack (bottom → top)**

```
[2, 5, 3, 0, 4, 1]
```

**Final Order (pop stack)**

```
[1, 4, 0, 3, 5, 2]
```

---

### Time Complexity

* **O(V + E)**

  * Each vertex visited once
  * Each edge explored once

Same for C++ and JavaScript.

---

### Space Complexity

* Visited array: `O(V)`
* Recursion stack: `O(V)`
* Stack for result: `O(V)`

Overall: **O(V)** (excluding adjacency list)

---

## Section 3 — Interview Q & A

**Q1. Why push node after DFS completes?**
Because all its dependent nodes must appear before it.

**Q2. Can this detect cycles?**
No. DFS-based topo sort assumes the graph is acyclic.

**Q3. What happens if graph has a cycle?**
The output will be invalid. Cycle detection must be done separately.

**Q4. When to use DFS topo vs BFS topo?**

* DFS: simple, recursive, ordering-based
* BFS (Kahn): cycle detection + topo order

**Q5. Is topological order unique?**
No. Multiple valid orders can exist.
