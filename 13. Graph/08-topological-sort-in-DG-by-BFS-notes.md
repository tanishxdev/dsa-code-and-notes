# Topological Sort using BFS (Kahn’s Algorithm)

Reference:
[https://www.geeksforgeeks.org/topological-sorting/](https://www.geeksforgeeks.org/topological-sorting/)

---

## Section 1 — Understanding the Problem

### Problem Statement

You are given a **directed graph** with `V` vertices numbered from `0` to `V-1`.
The graph is represented using an **adjacency list**.

Your task is to return a **topological ordering** of the vertices using **BFS (Kahn’s Algorithm)**.

---

### What Is Topological Sort?

A **topological sort** is a linear ordering of vertices such that:

> For every directed edge `u → v`,
> vertex `u` appears **before** vertex `v` in the ordering.

---

### Important Conditions

* Topological sort is possible **only for Directed Acyclic Graphs (DAGs)**
* If the graph contains a **cycle**, topological ordering is **not possible**
* BFS-based topological sort also helps in **cycle detection**

---

### Example

**Input**

```
V = 6
adj = [
  [],
  [],
  [3],
  [1],
  [0,1],
  [0,2]
]
```

**One valid Output**

```
[4, 5, 2, 3, 1, 0]
```

(Multiple valid orders may exist.)

---

### What Exactly Is Being Asked?

* Arrange vertices in an order that respects **dependency direction**
* Use **BFS + in-degree concept**
* Return the ordering as an array

---

## Section 2 — Building the Solution

### Intuition

#### Core Idea

In a directed graph:

* A node with **in-degree = 0** has **no dependencies**
* Such a node can be placed **first** in topological order

Kahn’s Algorithm works by:

* Repeatedly removing nodes with in-degree `0`
* Reducing the in-degree of their neighbors
* Continuing this process until no nodes are left

---

#### Why BFS Is Used

* Nodes with in-degree `0` are processed **level by level**
* This naturally fits **queue-based (BFS) traversal**
* Dependencies are resolved gradually

---

#### What Happens in Case of a Cycle

If a cycle exists:

* Nodes inside the cycle will **never reach in-degree 0**
* Queue becomes empty before all nodes are processed
* Topological ordering fails

---

#### One-Line Mental Model

> **Keep removing nodes with no incoming edges; if all nodes are removed, topological sort exists.**

---

### Algorithm (Kahn’s Algorithm)

1. Compute the **in-degree** of each vertex
2. Push all vertices with in-degree `0` into a queue
3. Initialize an empty `result` array
4. While the queue is not empty:

   * Pop a node
   * Add it to `result`
   * Reduce in-degree of its neighbors
   * If any neighbor’s in-degree becomes `0`, push it into the queue
5. `result` will contain the topological order

---

### Pseudocode

```
function topoSort(V, adj):
    indegree = array[V] initialized to 0

    for u from 0 to V-1:
        for v in adj[u]:
            indegree[v]++

    queue = empty queue
    for i from 0 to V-1:
        if indegree[i] == 0:
            queue.push(i)

    result = empty list

    while queue not empty:
        node = queue.pop()
        result.append(node)

        for neighbor in adj[node]:
            indegree[neighbor]--
            if indegree[neighbor] == 0:
                queue.push(neighbor)

    return result
```

---

## Code — C++ (Primary, Exact Logic)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // =====================================================================
    // Function: topoSort
    //
    // Purpose:
    // - Returns a valid topological ordering of a DAG
    // - Uses BFS-based Kahn’s Algorithm
    //
    // Parameters:
    // V   -> number of vertices (0 to V-1)
    // adj -> adjacency list of directed graph
    //
    // Returns:
    // Vector containing topological order
    // =====================================================================
    vector<int> topoSort(int V, vector<vector<int>>& adj) {

        // ---------------------------------------------------------------
        // STEP 1: Calculate indegree of each vertex
        //
        // indegree[i] = number of incoming edges to node i
        // ---------------------------------------------------------------
        vector<int> indegree(V, 0);

        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }

        // ---------------------------------------------------------------
        // STEP 2: Push all vertices with indegree 0 into queue
        //
        // These nodes have no dependencies
        // ---------------------------------------------------------------
        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // ---------------------------------------------------------------
        // STEP 3: BFS traversal (Topological processing)
        // ---------------------------------------------------------------
        vector<int> result;

        while (!q.empty()) {

            // Take node with indegree 0
            int node = q.front();
            q.pop();

            // Add node to topological order
            result.push_back(node);

            // Reduce indegree of all neighbors
            for (int neighbor : adj[node]) {

                indegree[neighbor]--;

                // If neighbor has no remaining dependencies
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // ---------------------------------------------------------------
        // NOTE:
        // - If result.size() < V, graph contains a cycle
        // - Here, problem assumes DAG
        // ---------------------------------------------------------------
        return result;
    }
};

int main() {
    int V = 6;

    // Directed graph adjacency list
    vector<vector<int>> adj = {
        {},        // 0
        {},        // 1
        {3},       // 2 -> 3
        {1},       // 3 -> 1
        {0, 1},    // 4 -> 0, 1
        {0, 2}     // 5 -> 0, 2
    };

    Solution sol;

    // Get topological order
    vector<int> topo = sol.topoSort(V, adj);

    // Print result
    cout << "Topological Order: ";
    for (int x : topo) cout << x << " ";
    cout << endl;

    return 0;
}
```

---

## Code — JavaScript (Equivalent Logic)

```javascript
class Solution {
  topoSort(V, adj) {
    const indegree = new Array(V).fill(0);

    // Step 1: Calculate indegree
    for (let u = 0; u < V; u++) {
      for (const v of adj[u]) {
        indegree[v]++;
      }
    }

    // Step 2: Initialize queue with indegree 0 nodes
    const queue = [];
    for (let i = 0; i < V; i++) {
      if (indegree[i] === 0) {
        queue.push(i);
      }
    }

    // Step 3: BFS traversal
    const result = [];
    while (queue.length > 0) {
      const node = queue.shift();
      result.push(node);

      for (const neighbor of adj[node]) {
        indegree[neighbor]--;
        if (indegree[neighbor] === 0) {
          queue.push(neighbor);
        }
      }
    }

    return result;
  }
}

// Example usage
const V = 6;
const adj = [
  [],
  [],
  [3],
  [1],
  [0,1],
  [0,2]
];

const sol = new Solution();
console.log("Topological Order:", sol.topoSort(V, adj));
```

---

## Dry Run (Step-by-Step)

**Graph**

```
5 → 0
5 → 2
4 → 0
4 → 1
2 → 3
3 → 1
```

**Initial In-degree**

```
[2, 2, 1, 1, 0, 0]
```

**Queue Initialization**

```
Queue = [4, 5]
```

| Step | Queue | In-degree     | Result        |
| ---- | ----- | ------------- | ------------- |
| 1    | [5]   | [1,1,1,1,0,0] | [4]           |
| 2    | [2]   | [0,1,0,1,0,0] | [4,5]         |
| 3    | [3]   | [0,1,0,0,0,0] | [4,5,2]       |
| 4    | [1]   | [0,0,0,0,0,0] | [4,5,2,3]     |
| 5    | [0]   | [0,0,0,0,0,0] | [4,5,2,3,1]   |
| 6    | []    | [0,0,0,0,0,0] | [4,5,2,3,1,0] |

---

## Time Complexity

* In-degree calculation: `O(V + E)`
* BFS traversal: `O(V + E)`
* **Total:** `O(V + E)`

Same for C++ and JavaScript.

---

## Space Complexity

* In-degree array: `O(V)`
* Queue: `O(V)`
* Result array: `O(V)`

Overall: **O(V)** (excluding adjacency list)

---

## Section 3 — Interview Q & A

**Q1. Why BFS is used for topological sort?**
Because nodes with in-degree 0 can be processed level by level.

**Q2. How does this help in cycle detection?**
If all nodes are not processed, a cycle exists.

**Q3. Difference between DFS and BFS topo sort?**
DFS uses post-order + stack, BFS uses in-degree + queue.

**Q4. Is topological order unique?**
No, multiple valid orders can exist.

**Q5. When to prefer Kahn’s Algorithm?**
When you also want **cycle detection** along with topological order.

---
