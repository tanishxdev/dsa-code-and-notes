# Detect Cycle in Directed Graph using BFS (Kahn’s Algorithm)

Reference:
[https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1](https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1)

---

## Section 1 — Understanding the Problem

### Problem Statement

You are given a **directed graph** with `V` vertices numbered from `0` to `V-1`.
The graph is represented using a **list of directed edges** or an **adjacency list**.

Your task is to determine **whether the graph contains a cycle**.

A **cycle** in a directed graph means:

* You start from a vertex
* Follow directed edges
* And come back to the same vertex

---

### Input and Output

**Input**

* `V`: Number of vertices
* `edges`: A list of directed edges `[u, v]` meaning an edge from `u` to `v`

**Output**

* `true` → if the graph contains a cycle
* `false` → if the graph does not contain a cycle

---

### Examples

**Example 1**

```
V = 4
edges = [[0,1], [0,2], [1,2], [2,0], [2,3], [3,3]]
```

Output:

```
true
```

Explanation:

* `0 → 1 → 2 → 0` is a cycle
* `3 → 3` is a self-loop (also a cycle)

---

**Example 2**

```
V = 4
edges = [[0,1], [0,2], [1,2], [2,3]]
```

Output:

```
false
```

Explanation:

* This is a Directed Acyclic Graph (DAG)

---

### What Exactly Is Being Asked?

* Try to perform a **topological ordering** of the directed graph
* If topological ordering **fails**, the graph must contain a cycle

---

## Section 2 — Building the Solution

### Intuition

#### Core Idea Behind Kahn’s Algorithm

Kahn’s Algorithm is a **BFS-based topological sorting algorithm**.

Key observation:

> A directed graph has a valid topological order **if and only if** it has **no cycle**.

So:

* If we **can process all nodes**, there is **no cycle**
* If **some nodes are never processed**, a **cycle exists**

---

#### Role of In-Degree

The **in-degree** of a node is:

* The number of edges coming **into** that node

Important facts:

* Nodes with **in-degree = 0** have **no dependencies**
* Such nodes can be safely processed first

---

#### Why Cycles Block the Process

In a cycle:

```
A → B → C → A
```

* Every node has at least one incoming edge
* No node ever gets in-degree `0`
* BFS queue becomes empty early
* Some nodes remain unprocessed

This is how we detect a cycle.

---

#### One-Line Mental Model

> **If topological sorting using BFS does not include all vertices, the directed graph contains a cycle.**

---

### Algorithm (Kahn’s Algorithm)

1. Build an adjacency list from the given edges
2. Compute the in-degree of each vertex
3. Push all vertices with in-degree `0` into a queue
4. Initialize a counter `count = 0`
5. While the queue is not empty:

   * Pop a node
   * Increment `count`
   * Reduce the in-degree of its neighbors
   * If any neighbor’s in-degree becomes `0`, push it into the queue
6. After BFS:

   * If `count == V` → no cycle
   * Else → cycle exists

---

### Pseudocode

```
function isCyclic(V, adj):
    indegree = array of size V initialized to 0

    for each u in [0..V-1]:
        for each v in adj[u]:
            indegree[v]++

    queue = empty queue
    for i in [0..V-1]:
        if indegree[i] == 0:
            queue.push(i)

    count = 0

    while queue not empty:
        node = queue.pop()
        count++

        for each neighbor in adj[node]:
            indegree[neighbor]--
            if indegree[neighbor] == 0:
                queue.push(neighbor)

    if count == V:
        return false
    else:
        return true
```

---

### Code — C++ (Primary, Exact Logic)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // =====================================================================
    // Function: isCyclic
    //
    // Purpose:
    // - Detects cycle in a DIRECTED graph using BFS (Kahn’s Algorithm)
    //
    // Key Idea:
    // - Perform topological sorting
    // - If all nodes are processed -> no cycle
    // - If some nodes remain -> cycle exists
    //
    // Parameters:
    // V     -> number of vertices (0 to V-1)
    // edges -> list of directed edges (u -> v)
    //
    // Returns:
    // true  -> cycle exists
    // false -> no cycle (graph is DAG)
    // =====================================================================
    bool isCyclic(int V, vector<vector<int>> &edges) {

        // ---------------------------------------------------------------
        // STEP 1: Build adjacency list and indegree array
        // ---------------------------------------------------------------

        // adj[u] contains all nodes v such that u -> v
        vector<vector<int>> adj(V);

        // indegree[i] = number of incoming edges to node i
        vector<int> indegree(V, 0);

        // Convert edge list to adjacency list
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // Directed edge u -> v
            adj[u].push_back(v);

            // Increase indegree of v
            indegree[v]++;
        }

        // ---------------------------------------------------------------
        // STEP 2: Push all nodes with indegree 0 into queue
        // ---------------------------------------------------------------

        queue<int> q;

        for (int i = 0; i < V; i++) {
            // Nodes with no dependencies
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // ---------------------------------------------------------------
        // STEP 3: BFS (Topological Processing)
        // ---------------------------------------------------------------

        // Count of nodes successfully processed
        int count = 0;

        while (!q.empty()) {

            // Take a node with indegree 0
            int node = q.front();
            q.pop();

            // Node is processed
            count++;

            // Reduce indegree of all neighbors
            for (int neighbor : adj[node]) {

                indegree[neighbor]--;

                // If indegree becomes 0, push into queue
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // ---------------------------------------------------------------
        // STEP 4: Final Cycle Check
        // ---------------------------------------------------------------

        // If all nodes are processed -> no cycle
        // Otherwise -> cycle exists
        return count != V;
    }
};

int main() {
    Solution sol;

    int V = 4;

    // Directed edges
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 2},
        {2, 0}, {2, 3}, {3, 3}
    };

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
  isCyclic(V, edges) {
    const adj = Array.from({ length: V }, () => []);
    const indegree = new Array(V).fill(0);

    // Build adjacency list and indegree array
    for (const [u, v] of edges) {
      adj[u].push(v);
      indegree[v]++;
    }

    // Initialize queue with indegree 0 nodes
    const queue = [];
    for (let i = 0; i < V; i++) {
      if (indegree[i] === 0) {
        queue.push(i);
      }
    }

    let count = 0;

    // BFS
    while (queue.length > 0) {
      const node = queue.shift();
      count++;

      for (const neighbor of adj[node]) {
        indegree[neighbor]--;
        if (indegree[neighbor] === 0) {
          queue.push(neighbor);
        }
      }
    }

    return count !== V;
  }
}

// Example usage
const sol = new Solution();
const V = 4;
const edges = [[0,1],[0,2],[1,2],[2,0],[2,3],[3,3]];
console.log(sol.isCyclic(V, edges)); // true
```

---

### Dry Run (Cycle Case)

**Input**

```
V = 4
edges = [[0,1], [0,2], [1,2], [2,0], [2,3], [3,3]]
```

**In-degree after construction**

```
[0, 1, 2, 2]
```

No node has in-degree `0`.

* Queue is empty
* `count = 0`
* `count != V`

Result: **Cycle exists**

---

### Dry Run (No-Cycle Case)

**Input**

```
V = 4
edges = [[0,1], [0,2], [1,2], [2,3]]
```

| Step  | Queue | In-degree | Count |
| ----- | ----- | --------- | ----- |
| Init  | [0]   | [0,1,1,1] | 0     |
| Pop 0 | [1,2] | [0,0,0,1] | 1     |
| Pop 1 | [2]   | [0,0,0,1] | 2     |
| Pop 2 | [3]   | [0,0,0,0] | 3     |
| Pop 3 | []    | [0,0,0,0] | 4     |

`count == V` → No cycle

---

### Time Complexity

* Building graph: `O(E)`
* BFS traversal: `O(V + E)`
* **Total:** `O(V + E)`

Same for C++ and JavaScript.

---

### Space Complexity

* Adjacency list: `O(E)`
* In-degree array: `O(V)`
* Queue: `O(V)`
* **Total:** `O(V + E)`

---

## Section 3 — Interview Notes (Q & A)

**Q1. Why does Kahn’s Algorithm detect cycles?**
If a cycle exists, some nodes never get in-degree `0`, so BFS cannot process all nodes.

**Q2. Can this work for undirected graphs?**
No. Kahn’s Algorithm is for directed graphs only.

**Q3. What does `count != V` indicate?**
Some vertices were never processed → cycle exists.

**Q4. Self-loop handling?**
A self-loop increases in-degree and prevents processing → correctly detected as a cycle.

**Q5. When to prefer BFS over DFS?**
When you want:

* Topological sorting
* Explicit cycle detection using in-degree
* Iterative solution (no recursion stack)

---