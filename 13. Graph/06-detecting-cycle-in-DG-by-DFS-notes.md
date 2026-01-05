# Detect Cycle in Directed Graph using DFS

_Reference:_
[https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1](https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1)

---

## Section 1 — Understanding the Problem

### Problem Statement

You are given a **directed graph** with `V` vertices.
The graph is represented using an **edge list** (or adjacency list internally).

Your task is to determine **whether the graph contains a cycle or not**.

Return:

- `true` → if a cycle exists
- `false` → if no cycle exists

Important details:

- Vertices are numbered from `0` to `V-1`
- Edges are **directed** (one-way)
- The graph can be **disconnected**

---

### What Is a Cycle in a Directed Graph?

A **cycle** exists if:

- You start from a node
- Follow directed edges
- And come back to the **same node**
- While respecting edge directions

Example:

```
0 → 1 → 2 → 0
```

This is a valid directed cycle.

---

### Examples

#### Example 1 — Cycle Exists

```
V = 4
adj = [
  [1],
  [2],
  [0, 3],
  []
]
```

Output:

```
true
```

Explanation:
`0 → 1 → 2 → 0` forms a cycle.

---

#### Example 2 — No Cycle

```
V = 3
adj = [
  [1],
  [2],
  []
]
```

Output:

```
false
```

Explanation:
This is a straight path `0 → 1 → 2`.

---

### What Exactly Is Being Asked?

- Traverse the directed graph
- Detect if **any path loops back to a node already in the same path**
- Return a boolean result

---

## Section 2 — Building the Solution

### Intuition

#### Why Directed Cycle Detection Is Different

In **undirected graphs**:

- We ignore the parent node

In **directed graphs**:

- Parent logic **does not work**
- Because edges are one-way
- A cycle depends on the **current DFS path**, not just visited nodes

So we need something more than just a `visited` array.

---

#### Key Idea (Most Important)

We use **two arrays**:

1. `visited[]`

   - Marks nodes that have been fully explored

2. `recStack[]` (recursion stack)

   - Marks nodes that are **currently in the DFS path**

---

#### Why `recStack` Is Necessary

Consider this graph:

```
0 → 1 → 2 → 0
```

DFS steps:

- Start DFS at `0`
- Go to `1`
- Go to `2`
- From `2`, neighbor is `0`

Now:

- `0` is already visited
- More importantly: `0` is **still in the current DFS path**

That means:

> We reached a node again **before finishing its DFS**

This confirms a **cycle**.

---

#### Difference Between `visited` and `recStack`

| Array            | Meaning                                  |
| ---------------- | ---------------------------------------- |
| `visited[node]`  | Node has been visited at least once      |
| `recStack[node]` | Node is part of the **current DFS path** |

Cycle condition:

```
If a neighbor is already in recStack → cycle exists
```

---

#### Handling Disconnected Graphs

The graph may have multiple components.

So:

- DFS must be started from **every unvisited node**
- If any DFS detects a cycle → answer is `true`

---

#### One-Line Mental Model

> **In a directed graph, a cycle exists if DFS reaches a node that is already in the current recursion stack.**

---

### Algorithm

1. Build the adjacency list from the edge list
2. Create:

   - `visited[V]` initialized to `false`
   - `recStack[V]` initialized to `false`

3. For every vertex `i` from `0` to `V-1`:

   - If `i` is not visited:

     - Run DFS from `i`

4. In DFS:

   - Mark node as visited
   - Mark node in `recStack`
   - For each neighbor:

     - If unvisited → DFS(neighbor)
     - Else if neighbor is in `recStack` → cycle found

   - Remove node from `recStack` before returning

5. If any DFS finds a cycle → return `true`
6. Otherwise → return `false`

---

### Pseudocode

```
function isCyclic(V, adj):
    visited = array[V] initialized to false
    recStack = array[V] initialized to false

    for i from 0 to V-1:
        if visited[i] == false:
            if dfs(i, adj, visited, recStack):
                return true

    return false


function dfs(node, adj, visited, recStack):
    visited[node] = true
    recStack[node] = true

    for each neighbor in adj[node]:
        if visited[neighbor] == false:
            if dfs(neighbor, adj, visited, recStack):
                return true
        else if recStack[neighbor] == true:
            return true

    recStack[node] = false
    return false
```

---

### Code — C++ (Primary, Exact Logic)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // =====================================================================
    // Helper Function: dfsCycle
    //
    // Purpose:
    // - Detects cycle in a directed graph using DFS
    // - Uses recursion stack to track current DFS path
    //
    // Parameters:
    // node     -> current node being visited
    // adj      -> adjacency list (directed graph)
    // visited  -> tracks nodes that are fully visited
    // recStack -> tracks nodes in current DFS recursion path
    //
    // Returns:
    // true  -> cycle detected
    // false -> no cycle in this DFS path
    // =====================================================================
    bool dfsCycle(int node,
                  vector<vector<int>>& adj,
                  vector<bool>& visited,
                  vector<bool>& recStack) {

        // Mark current node as visited
        visited[node] = true;

        // Mark current node as part of the current DFS path
        recStack[node] = true;

        // ---------------------------------------------------------------
        // Explore all outgoing edges from current node
        // ---------------------------------------------------------------
        for (int neighbor : adj[node]) {

            // Case 1: Neighbor not visited yet
            if (!visited[neighbor]) {
                if (dfsCycle(neighbor, adj, visited, recStack))
                    return true;   // Cycle found in deeper call
            }
            // Case 2: Neighbor already in recursion stack
            // This means we found a back-edge -> cycle
            else if (recStack[neighbor]) {
                return true;
            }
        }

        // ---------------------------------------------------------------
        // Backtracking step
        // Remove current node from recursion stack
        // ---------------------------------------------------------------
        recStack[node] = false;

        // No cycle found from this node
        return false;
    }

    // =====================================================================
    // Function: isCyclic
    //
    // Purpose:
    // - Builds the directed graph
    // - Checks for cycle in all connected components
    //
    // Parameters:
    // V     -> number of vertices
    // edges -> list of directed edges (u -> v)
    //
    // Returns:
    // true  -> cycle exists
    // false -> no cycle
    // =====================================================================
    bool isCyclic(int V, vector<vector<int>>& edges) {

        // ---------------------------------------------------------------
        // STEP 1: Build adjacency list
        // ---------------------------------------------------------------
        vector<vector<int>> adj(V);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            // Directed edge u -> v
            adj[u].push_back(v);
        }

        // ---------------------------------------------------------------
        // STEP 2: Initialize visited and recursion stack arrays
        // ---------------------------------------------------------------
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        // ---------------------------------------------------------------
        // STEP 3: Run DFS for each node (handles disconnected graph)
        // ---------------------------------------------------------------
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfsCycle(i, adj, visited, recStack))
                    return true;   // Cycle detected
            }
        }

        // No cycle found in entire graph
        return false;
    }
};

int main() {
    int V = 4;

    // Directed edges
    vector<vector<int>> edges = {
        {0,1}, {1,2}, {2,0}, {2,3}
    };

    Solution sol;

    if (sol.isCyclic(V, edges))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}
```

---

### Code — JavaScript (Equivalent Logic)

```javascript
class Solution {
  dfsCycle(node, adj, visited, recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (const neighbor of adj[node]) {
      if (!visited[neighbor]) {
        if (this.dfsCycle(neighbor, adj, visited, recStack)) {
          return true;
        }
      } else if (recStack[neighbor]) {
        return true;
      }
    }

    recStack[node] = false;
    return false;
  }

  isCyclic(V, edges) {
    const adj = Array.from({ length: V }, () => []);

    for (const [u, v] of edges) {
      adj[u].push(v);
    }

    const visited = new Array(V).fill(false);
    const recStack = new Array(V).fill(false);

    for (let i = 0; i < V; i++) {
      if (!visited[i]) {
        if (this.dfsCycle(i, adj, visited, recStack)) {
          return true;
        }
      }
    }

    return false;
  }
}

// Example usage
const sol = new Solution();
const V = 4;
const edges = [
  [0, 1],
  [1, 2],
  [2, 0],
  [2, 3],
];

console.log(sol.isCyclic(V, edges)); // true
```

---

### Dry Run (Tabular Format)

#### Example — Graph with Cycle

```
0 → 1 → 2 → 0
2 → 3
```

| Step | Node | Visited   | RecStack         | Action         |
| ---: | ---: | --------- | ---------------- | -------------- |
|    1 |    0 | [T,F,F,F] | [T,F,F,F]        | Start DFS      |
|    2 |    1 | [T,T,F,F] | [T,T,F,F]        | DFS to 1       |
|    3 |    2 | [T,T,T,F] | [T,T,T,F]        | DFS to 2       |
|    4 |    0 | —         | recStack[0]=true | Cycle detected |

---

### Time Complexity

- **O(V + E)**

  - Each vertex visited once
  - Each edge processed once

Same for **C++ and JavaScript**

---

### Space Complexity

- Visited array: `O(V)`
- Recursion stack array: `O(V)`
- DFS call stack: `O(V)` in worst case

Overall: **O(V)** (excluding adjacency list)

---

## Section 3 — Important Follow-Up (Q & A)

**Q1. Why doesn’t parent logic work in directed graphs?**
Because edges are one-way, so parent-child symmetry does not exist.

**Q2. Why do we need both visited and recStack?**
Visited tracks explored nodes, recStack tracks the current DFS path.

**Q3. What is a back edge?**
An edge pointing to a node already in the recursion stack.

**Q4. Can BFS be used for directed cycle detection?**
Yes, using Kahn’s Algorithm (indegree-based).

**Q5. What is the most common interview mistake?**
Using undirected graph logic (parent check) for directed graphs.
