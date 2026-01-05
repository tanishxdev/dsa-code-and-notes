# Detecting Cycle in Undirected Graph using DFS

_Reference:_
[https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1](https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1)

---

## Section 1 — Understanding the Problem

### Problem Statement

You are given an **undirected graph** with `V` vertices.
The graph is provided in the form of an **edge list**.

Your task is to determine **whether the graph contains a cycle or not**.

Return:

- `true` → if a cycle exists
- `false` → if no cycle exists

Important points:

- The graph can be **connected or disconnected**
- The graph can contain **multiple components**
- Vertices are **0-based indexed**

---

### What is a Cycle in an Undirected Graph?

A **cycle** exists if:

- You can start from a node
- Traverse through edges
- And come back to the **same node**
- Without reusing an edge
- And the path length is **≥ 3**

In undirected graphs, **going back to the parent node is NOT a cycle**
(because edges are bidirectional).

---

### Examples

#### Example 1 — Graph with Cycle

Edges:

```
0 - 1
1 - 2
2 - 3
3 - 0
```

Output:

```
true
```

There is a loop: `0 → 1 → 2 → 3 → 0`

---

#### Example 2 — Graph without Cycle (Tree)

Edges:

```
0 - 1
1 - 2
```

Output:

```
false
```

This is a straight tree structure.

---

### What Exactly Is Being Asked?

- Traverse the entire graph
- Check **every connected component**
- Detect if **any cycle exists**
- Return the result

---

## Section 2 — Building the Solution

### Intuition

#### What Problem We Are Solving

In an **undirected graph**, every edge appears twice:

```
u → v
v → u
```

Because of this, when we traverse the graph:

- We will always see the **parent node again**
- That alone should **not** be considered a cycle

So the real challenge is:

> How do we differentiate between a **real cycle** and a **normal parent edge**?

---

#### Key Observation (Most Important)

While doing DFS:

- If we reach a node that is:

  - already visited
  - and **not the parent**

- Then a **cycle exists**

Why?

Because:

- The node was reached earlier via a different path
- That means there are **two different paths** to the same node
- This forms a loop

---

#### Why Parent Tracking Is Required

Consider this simple graph:

```
0 - 1
```

DFS steps:

- Start at `0`
- Go to `1`
- From `1`, you see neighbor `0`

If we do not track the parent:

- `0` is already visited
- We might incorrectly say “cycle detected”

But this is **wrong**.

Reason:

- `0` is just the parent of `1`
- This back-edge is expected in undirected graphs

So we must ignore:

```
neighbor == parent
```

---

#### DFS Thinking for Cycle Detection

For each node:

1. Mark the node as visited
2. Traverse all its neighbors
3. For each neighbor:

   - If unvisited → DFS on it
   - If visited AND not parent → cycle found

---

#### Disconnected Graphs (Very Important)

The graph may look like this:

```
Component 1: 0 - 1 - 2
Component 2: 3 - 4 - 5 - 3
```

Even if one component has a cycle, the answer is `true`.

So:

- We must run DFS from **every unvisited node**
- Not only from node `0`

---

#### One-Line Mental Model

> **In an undirected graph, a cycle exists if during DFS we find a visited node that is not the parent.**

---

### Algorithm

1. Convert the edge list into an adjacency list
2. Create a `visited` array of size `V`
3. For every vertex `i` from `0` to `V-1`:

   - If `i` is not visited:

     - Run DFS starting from `i` with parent `-1`

4. In DFS:

   - Mark current node as visited
   - For each neighbor:

     - If neighbor is unvisited → DFS(neighbor, current)
     - Else if neighbor is visited and not parent → cycle found

5. If any DFS finds a cycle → return `true`
6. Otherwise → return `false`

---

### Pseudocode

```
function detectCycle(V, adj):
    visited = array[V] initialized to false

    for i from 0 to V-1:
        if visited[i] == false:
            if dfs(i, -1, adj, visited) == true:
                return true

    return false


function dfs(node, parent, adj, visited):
    visited[node] = true

    for each neighbor in adj[node]:
        if visited[neighbor] == false:
            if dfs(neighbor, node, adj, visited) == true:
                return true
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
    // Helper Function: dfsCycle
    //
    // Purpose:
    // - Performs DFS to detect cycle in an undirected graph
    //
    // Parameters:
    // node    -> current node being visited
    // parent  -> node from which current node was called
    // adj     -> adjacency list of the graph
    // visited -> tracks visited nodes
    //
    // Returns:
    // true  -> cycle detected
    // false -> no cycle from this path
    // =====================================================================
    bool dfsCycle(int node, int parent,
                  vector<vector<int>>& adj,
                  vector<bool>& visited) {

        // Mark current node as visited
        visited[node] = true;

        // Traverse all neighbors of the current node
        for (int neighbor : adj[node]) {

            // Case 1: Neighbor not visited
            // Continue DFS deeper
            if (!visited[neighbor]) {
                if (dfsCycle(neighbor, node, adj, visited))
                    return true;   // Cycle found in deeper call
            }
            // Case 2: Neighbor already visited AND not parent
            // This indicates a back-edge -> cycle
            else if (neighbor != parent) {
                return true;
            }
        }

        // No cycle found starting from this node
        return false;
    }

    // =====================================================================
    // Function: isCycle
    //
    // Purpose:
    // - Builds the graph
    // - Checks for cycle in all connected components
    //
    // Parameters:
    // V     -> number of vertices
    // edges -> edge list representation
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

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            // Since graph is undirected, add both directions
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // ---------------------------------------------------------------
        // STEP 2: Visited array initialization
        // ---------------------------------------------------------------
        vector<bool> visited(V, false);

        // ---------------------------------------------------------------
        // STEP 3: Check each connected component
        // ---------------------------------------------------------------
        for (int i = 0; i < V; i++) {

            // If node is not visited, start DFS from it
            if (!visited[i]) {
                if (dfsCycle(i, -1, adj, visited))
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

    // Edge list of the graph
    vector<vector<int>> edges = {
        {0,1}, {0,2}, {1,2}, {2,3}
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

### Dry Run (Tabular Format)

#### Example — Graph with Cycle

Edges:

```
0-1, 1-2, 2-3, 3-0
```

| Step | Node | Parent | Visited                      | Action      |
| ---: | ---: | -----: | ---------------------------- | ----------- |
|    1 |    0 |     -1 | [T,F,F,F]                    | Start DFS   |
|    2 |    1 |      0 | [T,T,F,F]                    | Visit 1     |
|    3 |    2 |      1 | [T,T,T,F]                    | Visit 2     |
|    4 |    3 |      2 | [T,T,T,T]                    | Visit 3     |
|    5 |    0 |      3 | already visited & not parent | Cycle found |

---

### Time Complexity

- **O(V + E)**

  - Each vertex is visited once
  - Each edge is checked once

Same for **C++ and JavaScript**

---

### Space Complexity

- Adjacency list: `O(V + E)`
- Visited array: `O(V)`
- Recursion stack: `O(V)` (worst case)

Overall: **O(V + E)**

---

## Section 3 — Important Follow-Up (Q & A)

**Q1. Why is parent checking mandatory in undirected graphs?**
Because every edge appears twice, and going back to the parent is normal.

**Q2. Can this logic work for directed graphs?**
No. Directed graphs require a recursion stack or indegree-based methods.

**Q3. What happens if the graph is disconnected?**
DFS is run from every unvisited node, so all components are checked.

**Q4. Can a single node form a cycle?**
No. A cycle needs at least 3 nodes in an undirected graph.

**Q5. What is the most common interview mistake here?**
Forgetting to ignore the parent and reporting false cycles.

---
