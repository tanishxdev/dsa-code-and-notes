![](https://labuladong.online/algo/images/algo4/1-en.jpg)

# Check if a Graph is Bipartite (DFS Coloring Method)

**Problem Link (GFG):**
[https://www.geeksforgeeks.org/problems/bipartite-graph/1](https://www.geeksforgeeks.org/problems/bipartite-graph/1)

---

## Section 1 — Understanding the Problem

### Problem Statement

You are given a **graph** (usually undirected) represented using an **adjacency list**.

Your task is to determine whether the graph is **bipartite** or not.

Return:

* `true` → if the graph is bipartite
* `false` → otherwise

Important points:

* The graph can be **connected or disconnected**
* Nodes are **0-based indexed**
* Graph may contain **cycles**

---

### What is a Bipartite Graph?

A graph is called **bipartite** if:

* We can divide all vertices into **two different groups**
* Every edge connects a node from **group A** to **group B**
* **No edge** connects two nodes of the **same group**

Another equivalent definition (very important):

> **A graph is bipartite if and only if it has NO odd-length cycle.**

---

### Simple Visual Intuition

Think in terms of **colors**:

* Group 1 → Color `0` (say Red)
* Group 2 → Color `1` (say Blue)

Rules:

* Adjacent nodes must have **different colors**
* If at any point two adjacent nodes get the **same color**, graph is **NOT bipartite**

---

## Section 2 — Building the Solution

### Intuition (How to Think)

What we want to do:

* Try to split graph nodes into **two groups**
* While traversing:

  * Assign one color to current node
  * Assign **opposite color** to all its neighbors

If during traversal:

* A neighbor is already colored
* And its color is **same as current node**

→ Conflict → **Not bipartite**

---

### Why This Algorithm Is Needed

Graphs may have:

* Multiple paths
* Cycles
* Disconnected components

Manual checking is impossible.

So we use:

* **DFS (or BFS)**
* **Coloring technique**
* **Visited / color array**

This ensures:

* Every edge is checked
* Every component is validated

---

### Core Concept / Theory

Key facts:

1. Bipartite graph = **2-colorable graph**
2. DFS naturally propagates color constraints
3. Parent-child coloring works unless:

   * An **odd-length cycle** exists

Odd cycle example:

```
0 - 1
|   |
3 - 2
```

This forces same color at some point → conflict.

---

### Graph Representation Used

We use **Adjacency List**:

```cpp
vector<vector<int>> adj;
```

Color array:

```cpp
vector<int> color(V, -1);
```

Meaning:

* `-1` → uncolored
* `0` → color A
* `1` → color B

---

## Section 3 — Algorithm

### High-Level Steps

1. Create a color array initialized with `-1`
2. For every node from `0` to `V-1`:

   * If node is uncolored:

     * Start DFS from it
     * Assign initial color `0`
3. During DFS:

   * For each neighbor:

     * If uncolored → color with opposite color
     * If colored with same color → return false
4. If all nodes processed without conflict → bipartite

---

### Pseudocode

```
function isBipartite(V, adj):
    color = array of size V filled with -1

    for i from 0 to V-1:
        if color[i] == -1:
            if dfs(i, 0) == false:
                return false

    return true


function dfs(node, currColor):
    color[node] = currColor

    for each neighbor in adj[node]:
        if color[neighbor] == -1:
            if dfs(neighbor, 1 - currColor) == false:
                return false
        else if color[neighbor] == currColor:
            return false

    return true
```

---

## Section 4 — Code (Exact Style)

### Code — C++ (Primary)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ================================================================
    // Helper Function: dfs
    //
    // Purpose:
    // - Try to color the graph using 2 colors
    // - Detect conflict during DFS traversal
    //
    // Parameters:
    // node       -> current node
    // currColor  -> color assigned to current node
    // adj        -> adjacency list
    // color      -> color array (-1 = uncolored)
    //
    // Returns:
    // true  -> no conflict in this DFS path
    // false -> conflict found (not bipartite)
    // ================================================================
    bool dfs(int node, int currColor,
             vector<vector<int>>& adj,
             vector<int>& color) {

        // Assign color to current node
        color[node] = currColor;

        // Traverse all neighbors
        for (int neighbor : adj[node]) {

            // If neighbor is not colored, color it with opposite color
            if (color[neighbor] == -1) {
                if (!dfs(neighbor, 1 - currColor, adj, color))
                    return false;
            }
            // If neighbor already has same color -> conflict
            else if (color[neighbor] == currColor) {
                return false;
            }
        }

        return true;
    }

    // ================================================================
    // Function: isBipartite
    //
    // Purpose:
    // - Checks bipartiteness for all components
    //
    // ================================================================
    bool isBipartite(vector<vector<int>>& adj) {

        int V = adj.size();

        // Color array initialized with -1 (uncolored)
        vector<int> color(V, -1);

        // Handle disconnected graph
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, adj, color))
                    return false;
            }
        }

        return true;
    }
};
```

---

### Code — JavaScript (Equivalent Logic)

```javascript
class Solution {
  // Helper DFS function
  dfs(node, currColor, adj, color) {
    color[node] = currColor;

    for (const neighbor of adj[node]) {
      if (color[neighbor] === -1) {
        if (!this.dfs(neighbor, 1 - currColor, adj, color)) {
          return false;
        }
      } else if (color[neighbor] === currColor) {
        return false;
      }
    }
    return true;
  }

  isBipartite(adj) {
    const V = adj.length;
    const color = new Array(V).fill(-1);

    for (let i = 0; i < V; i++) {
      if (color[i] === -1) {
        if (!this.dfs(i, 0, adj, color)) {
          return false;
        }
      }
    }
    return true;
  }
}
```

---

## Section 5 — Dry Run (Step-by-Step)

### Example 1 — Bipartite Graph

```
0 -- 1
|    |
3 -- 2
```

Adjacency List:

```
adj = [
  [1,3],
  [0,2],
  [1,3],
  [0,2]
]
```

| Step | Node | Assigned Color | Neighbor | Action              |
| ---: | ---: | -------------: | -------: | ------------------- |
|    1 |    0 |              0 |        1 | color[1] = 1        |
|    2 |    1 |              1 |        2 | color[2] = 0        |
|    3 |    2 |              0 |        3 | color[3] = 1        |
|    4 |    3 |              1 |        0 | OK (opposite color) |

Result: **No conflict → Bipartite**

---

### Example 2 — Not Bipartite (Odd Cycle)

```
0 - 1
 \ /
  2
```

Adjacency List:

```
adj = [
  [1,2],
  [0,2],
  [0,1]
]
```

| Step | Node | Assigned Color | Neighbor | Result                |
| ---: | ---: | -------------: | -------: | --------------------- |
|    1 |    0 |              0 |        1 | color[1] = 1          |
|    2 |    1 |              1 |        2 | color[2] = 0          |
|    3 |    2 |              0 |        0 | Conflict (same color) |

Result: **Conflict → Not Bipartite**

---

## Section 6 — Edge Cases & Common Mistakes

1. **Disconnected graph**

   * Must start DFS from every uncolored node
2. **Odd-length cycle**

   * Always fails bipartite test
3. **Self-loop**

   * Immediately not bipartite
4. **Forgetting opposite color**

   * Must use `1 - currColor`
5. **Using visited instead of color**

   * Color array already implies visited

---

## Section 7 — Time & Space Complexity

### Time Complexity

* **O(V + E)**

  * Each vertex visited once
  * Each edge checked once

### Space Complexity

* Color array: `O(V)`
* Recursion stack: `O(V)` (worst case)

---

## Section 8 — Interview Perspective

* Bipartite graph = **2-coloring problem**
* DFS or BFS both acceptable
* Key interviewer check:

  * Do you handle **disconnected graphs**
  * Do you detect **odd cycles**
* Common follow-up:

  * “How would you do this using BFS?” (same logic)

---

### One-Line Mental Model (Must Remember)

> **Try to color the graph with two colors using DFS; any conflict means the graph is not bipartite.**

---

When you want, next we can:

* Convert this to **BFS version**
* Compare **DFS vs BFS bipartite**
* Practice **LeetCode Bipartite problems**
* Build a **pattern summary for graphs**

Just say: **organize and teach me next topic**
