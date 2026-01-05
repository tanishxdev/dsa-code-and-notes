# Detect Cycle in Undirected Graph using BFS

*Reference:*
[https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1](https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1)

---

## Section 1 — Understanding the Problem

### Problem Statement

You are given an **undirected graph** with `V` vertices.
The graph is provided as an **edge list**.

Your task is to determine **whether the graph contains a cycle or not** using **BFS**.

Return:

* `true` → if a cycle exists
* `false` → if no cycle exists

Important details:

* Vertices are numbered from `0` to `V-1`
* The graph can be **connected or disconnected**
* Edges are **bidirectional**

---

### What Is a Cycle in an Undirected Graph?

A **cycle** exists if:

* You start from a node
* Traverse through edges
* And reach an **already visited node**
* **that is not the parent**

In undirected graphs:

* Returning to the **parent node is normal**
* That alone does **not** form a cycle

---

### Examples

#### Example 1 — Cycle Exists

```
Edges:
0 - 1
1 - 2
2 - 3
3 - 1
```

Output:

```
true
```

Explanation:
Path `1 → 2 → 3 → 1` forms a cycle.

---

#### Example 2 — No Cycle (Tree)

```
Edges:
0 - 1
1 - 2
```

Output:

```
false
```

Explanation:
This is a tree structure with no loops.

---

### What Exactly Is Being Asked?

* Traverse the entire graph
* Check **all connected components**
* Detect if **any cycle exists**
* Use **BFS traversal**
* Return a boolean result

---

## Section 2 — Building the Solution

### Intuition

#### Core Idea

In an **undirected graph**, every edge works in **both directions**.

So during traversal:

* From node `u`, you go to `v`
* From `v`, you will naturally see `u` again

This backward edge is **not a cycle**.

So the real question becomes:

> How do we detect a *real* cycle and ignore the normal parent edge?

---

#### Key Observation (Most Important)

While performing BFS:

* If we encounter a **visited neighbor**
* And that neighbor is **not the parent**
* Then a **cycle exists**

Why?

Because:

* The node was reached earlier via a different path
* This means there are **two distinct paths**
* Which forms a loop

---

#### Why Parent Tracking Is Required

Consider this simple graph:

```
0 - 1
```

BFS steps:

* Start at `0`
* Visit `1`
* From `1`, neighbor `0` appears again

If we do not track parent:

* `0` is already visited
* We might incorrectly detect a cycle

But this is **wrong**.

That edge exists only because the graph is undirected.

So we must **ignore the parent node** during cycle checking.

---

#### Why BFS Works Here

BFS:

* Explores nodes **level by level**
* Uses a **queue**
* Allows us to track:

  * current node
  * parent node

By storing `(node, parent)` pairs in the queue,
we can correctly identify real cycles.

---

#### Disconnected Graphs (Critical Detail)

The graph may have multiple components.

Example:

```
Component 1: 0 - 1 - 2
Component 2: 3 - 4 - 5 - 3
```

Even if one component has a cycle, the answer is `true`.

So:

* BFS must be started from **every unvisited node**

---

#### One-Line Mental Model

> **In an undirected graph, BFS detects a cycle when it finds a visited neighbor that is not the parent.**

---

### Algorithm

1. Build an adjacency list from the edge list
2. Create a `visited` array of size `V`
3. For every vertex `i` from `0` to `V-1`:

   * If `i` is not visited:

     * Run BFS from `i`
4. In BFS:

   * Store `(node, parent)` in the queue
   * For each neighbor:

     * If unvisited → mark visited, push `(neighbor, node)`
     * If visited and neighbor ≠ parent → cycle found
5. If any BFS detects a cycle → return `true`
6. Otherwise → return `false`

---

### Pseudocode

```
function isCyclic(V, adj):
    visited = array[V] initialized to false

    for i from 0 to V-1:
        if visited[i] == false:
            if bfsCycle(i, adj, visited):
                return true

    return false


function bfsCycle(start, adj, visited):
    queue = empty queue of (node, parent)
    visited[start] = true
    queue.push((start, -1))

    while queue not empty:
        (node, parent) = queue.pop()

        for each neighbor in adj[node]:
            if visited[neighbor] == false:
                visited[neighbor] = true
                queue.push((neighbor, node))
            else if neighbor != parent:
                return true

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
    // Helper Function: bfsCycle
    //
    // Purpose:
    // - Detects a cycle in ONE connected component using BFS
    //
    // Idea:
    // - BFS traversal using a queue
    // - Each queue entry stores {current_node, parent_node}
    //
    // Parameters:
    // start   -> starting node of the BFS
    // adj     -> adjacency list of the graph
    // visited -> tracks visited nodes
    //
    // Returns:
    // true  -> cycle detected in this component
    // false -> no cycle in this component
    // =====================================================================
    bool bfsCycle(int start,
                  vector<vector<int>>& adj,
                  vector<bool>& visited) {

        // Queue stores pair of:
        // {current_node, parent_node}
        queue<pair<int, int>> q;

        // Mark starting node as visited
        visited[start] = true;

        // Push starting node with parent = -1 (no parent)
        q.push({start, -1});

        // ===============================================================
        // BFS traversal
        // ===============================================================
        while (!q.empty()) {

            // Extract front element from queue
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            // Traverse all neighbors of the current node
            for (int neighbor : adj[node]) {

                // Case 1: Neighbor not visited
                if (!visited[neighbor]) {

                    // Mark neighbor as visited
                    visited[neighbor] = true;

                    // Push neighbor into queue with current node as parent
                    q.push({neighbor, node});
                }
                // Case 2: Neighbor already visited AND not parent
                // This indicates a cycle in an undirected graph
                else if (neighbor != parent) {
                    return true;
                }
            }
        }

        // No cycle found in this component
        return false;
    }

    // =====================================================================
    // Function: isCycle
    //
    // Purpose:
    // - Builds the graph
    // - Checks for cycle in ALL connected components
    //
    // Parameters:
    // V     -> number of vertices
    // edges -> edge list representation of the graph
    //
    // Returns:
    // true  -> cycle exists
    // false -> no cycle
    // =====================================================================
    bool isCycle(int V, vector<vector<int>>& edges) {

        // ---------------------------------------------------------------
        // STEP 1: Build adjacency list from edge list
        // ---------------------------------------------------------------
        vector<vector<int>> adj(V);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // Since graph is undirected, add both directions
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // ---------------------------------------------------------------
        // STEP 2: Initialize visited array
        // ---------------------------------------------------------------
        vector<bool> visited(V, false);

        // ---------------------------------------------------------------
        // STEP 3: Check each connected component
        // ---------------------------------------------------------------
        for (int i = 0; i < V; i++) {

            // If node is not visited, start BFS from it
            if (!visited[i]) {
                if (bfsCycle(i, adj, visited))
                    return true;   // Cycle detected
            }
        }

        // No cycle found in any component
        return false;
    }
};

int main() {
    Solution sol;

    int V = 4;

    // Edge list representation of the graph
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {2, 3}
    };

    // Check if cycle exists
    if (sol.isCycle(V, edges))
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
  bfsCycle(start, adj, visited) {
    const queue = [];
    visited[start] = true;
    queue.push([start, -1]);

    while (queue.length > 0) {
      const [node, parent] = queue.shift();

      for (const neighbor of adj[node]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          queue.push([neighbor, node]);
        } else if (neighbor !== parent) {
          return true;
        }
      }
    }

    return false;
  }

  isCycle(V, edges) {
    const adj = Array.from({ length: V }, () => []);

    for (const [u, v] of edges) {
      adj[u].push(v);
      adj[v].push(u);
    }

    const visited = new Array(V).fill(false);

    for (let i = 0; i < V; i++) {
      if (!visited[i]) {
        if (this.bfsCycle(i, adj, visited)) {
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
const edges = [[0,1],[0,2],[1,2],[2,3]];

console.log(sol.isCycle(V, edges)); // true
```

---

### Dry Run (Tabular Format)

#### Graph with Cycle

```
0: [1,2]
1: [0,3]
2: [0,3]
3: [1,2]
```

| Step | Queue (node,parent) | Visited   | Action                               |
| ---: | ------------------- | --------- | ------------------------------------ |
|    1 | (0,-1)              | [T,F,F,F] | Start BFS                            |
|    2 | (1,0),(2,0)         | [T,T,T,F] | Visit neighbors                      |
|    3 | (2,0),(3,1)         | [T,T,T,T] | Visit 3                              |
|    4 | —                   | —         | Encounter visited non-parent → cycle |

---

### Time Complexity

* **O(V + E)**

  * Each vertex visited once
  * Each edge processed once

Same for **C++ and JavaScript**

---

### Space Complexity

* Visited array: `O(V)`
* Queue: `O(V)` (worst case)

Overall: **O(V)** (excluding adjacency list)

---

## Section 3 — Important Follow-Up (Q & A)

**Q1. Why is parent tracking required in BFS?**
Because undirected edges naturally point back to the parent.

**Q2. Can BFS be replaced with DFS here?**
Yes. DFS with parent tracking also works.

**Q3. What happens if the graph is disconnected?**
Each component is checked separately using a loop.

**Q4. What is the most common mistake in interviews?**
Forgetting the parent check, leading to false cycle detection.

**Q5. When should BFS be preferred over DFS for cycle detection?**
When level-wise traversal or iterative logic is preferred.

