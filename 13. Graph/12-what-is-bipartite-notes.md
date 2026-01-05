# Bipartite Graph (Using DFS Coloring)

---

## Section 1 — Understanding the Problem

### What is a Bipartite Graph?

An **undirected graph** is called **bipartite** if:

* We can divide all nodes into **two different groups**
* Such that:

  * **No edge connects nodes within the same group**
  * Every edge connects nodes of **different groups**

In simple words:

> Every edge must go **from Group A to Group B**, never A → A or B → B.

---

### Another Equivalent Definition (Very Important)

A graph is bipartite **if and only if**:

> The graph **does NOT contain an odd-length cycle**

This observation is extremely important for intuition and interviews.

---

### Small Examples

#### Example 1 — Bipartite

```
0 --- 1
|     |
2 --- 3
```

Possible grouping:

* Group A: {0, 3}
* Group B: {1, 2}

All edges go across groups.

---

#### Example 2 — NOT Bipartite (Odd Cycle)

```
0 --- 1
 \   /
   2
```

This is a **cycle of length 3 (odd)** → NOT bipartite.

---

### What Exactly Is Being Asked?

Given a graph:

* Decide **whether it is bipartite or not**
* Graph can be:

  * disconnected
  * cyclic
* Nodes are **0-based indexed**

Return:

* `true` → if bipartite
* `false` → otherwise

---

## Section 2 — Core Intuition (Most Important Part)

### How to *Think* About Bipartite Graphs

Do **not** think in terms of cycles first.

Think like this:

> “Can I color the graph using **only two colors**, such that no adjacent nodes have the same color?”

If yes → bipartite
If no → not bipartite

---

### Why Coloring Works

Two groups = two colors.

Let:

* Color `0` = Red
* Color `1` = Blue

Rules:

* Pick any node → color it Red
* All its neighbors must be Blue
* All neighbors of Blue must be Red
* Continue this alternation

If at any point:

* A node is **forced to take a color it already has**
* And that color **matches its neighbor**

→ conflict → NOT bipartite

---

### Mental Model (Very Important)

Think of **enemy teams**:

* Every node hates its neighbors
* Enemies cannot be in the same team
* Only two teams are allowed

If conflict arises → impossible.

---

### Why DFS / BFS Is Used

Coloring needs:

* graph traversal
* neighbor-to-neighbor propagation

DFS or BFS both work.

Here we’ll use **DFS** because:

* simple
* recursive
* matches your learning flow

---

## Section 3 — Key Observations

### Observation 1 — Odd Cycle

* Odd-length cycle **forces** a color conflict
* You start with Red
* After odd steps, you return to Red again → conflict

So:

* Odd cycle → NOT bipartite
* Even cycle → bipartite possible

---

### Observation 2 — Disconnected Graph

Graph may look like:

```
Component 1: bipartite
Component 2: bipartite
Component 3: NOT bipartite
```

Overall answer = **false**

So:

* We must check **every component**
* Not only node `0`

---

## Section 4 — Algorithm (DFS Coloring)

### High-Level Steps

1. Create a `color` array of size `V`

   * Initialize all values as `-1` (uncolored)
2. Traverse all nodes:

   * If node is uncolored:

     * Start DFS from it
     * Assign initial color
3. During DFS:

   * For each neighbor:

     * If uncolored → assign opposite color
     * If already colored:

       * If same color → conflict → return false
4. If no conflict anywhere → bipartite

---

### Why `-1` Is Used

* `-1` → unvisited / uncolored
* `0` → color A
* `1` → color B

This avoids a separate `visited` array.

---

## Section 5 — DFS Logic (Core)

### DFS Function Responsibility

For a given node:

* Assign color
* Check all neighbors
* Ensure coloring rules are respected

---

### Conflict Condition (Most Important Line)

```
if (color[neighbor] == color[node])
    return false;
```

This single check defines bipartiteness.

---

## Section 6 — Pseudocode

```
function isBipartite(V, adj):
    color[V] = {-1}

    for each node i:
        if color[i] == -1:
            if dfs(i, 0) == false:
                return false

    return true


function dfs(node, currColor):
    color[node] = currColor

    for each neighbor:
        if color[neighbor] == -1:
            if dfs(neighbor, 1 - currColor) == false:
                return false
        else if color[neighbor] == currColor:
            return false

    return true
```

---

## Section 7 — Code (C++ — Primary, Exact Style)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // =====================================================================
    // Helper Function: dfsCheck
    //
    // Purpose:
    // - Perform DFS to color the graph
    // - Detect conflict if same color appears on adjacent nodes
    //
    // Parameters:
    // node  -> current node
    // color -> current color to assign
    // adj   -> adjacency list
    // col   -> color array (-1 uncolored, 0/1 colored)
    //
    // Returns:
    // true  -> no conflict in this DFS path
    // false -> conflict found (not bipartite)
    // =====================================================================
    bool dfsCheck(int node, int color,
                  vector<vector<int>>& adj,
                  vector<int>& col) {

        // Assign color to current node
        col[node] = color;

        // Traverse all neighbors
        for (int neighbor : adj[node]) {

            // Case 1: Neighbor not colored yet
            if (col[neighbor] == -1) {

                // Assign opposite color
                if (!dfsCheck(neighbor, 1 - color, adj, col))
                    return false;
            }
            // Case 2: Neighbor already colored
            else if (col[neighbor] == color) {

                // Same color on adjacent nodes → conflict
                return false;
            }
        }

        // No conflict from this node
        return true;
    }

    // =====================================================================
    // Function: isBipartite
    //
    // Purpose:
    // - Checks whether the graph is bipartite
    // - Handles disconnected components
    //
    // =====================================================================
    bool isBipartite(int V, vector<vector<int>>& adj) {

        // Color array initialized to -1 (uncolored)
        vector<int> col(V, -1);

        // Check each connected component
        for (int i = 0; i < V; i++) {

            // If node is uncolored, start DFS
            if (col[i] == -1) {

                if (!dfsCheck(i, 0, adj, col))
                    return false;
            }
        }

        return true;
    }
};
```

---

## Section 8 — Code (JavaScript — Same Logic)

```javascript
class Solution {
  dfsCheck(node, color, adj, col) {
    col[node] = color;

    for (const neighbor of adj[node]) {
      if (col[neighbor] === -1) {
        if (!this.dfsCheck(neighbor, 1 - color, adj, col)) {
          return false;
        }
      } else if (col[neighbor] === color) {
        return false;
      }
    }

    return true;
  }

  isBipartite(V, adj) {
    const col = new Array(V).fill(-1);

    for (let i = 0; i < V; i++) {
      if (col[i] === -1) {
        if (!this.dfsCheck(i, 0, adj, col)) {
          return false;
        }
      }
    }

    return true;
  }
}
```

---

## Section 9 — Edge Cases & Traps

1. **Disconnected graph**

   * Must start DFS from every uncolored node
2. **Single node**

   * Always bipartite
3. **Self-loop**

   * Immediate false
4. **Odd cycle**

   * Always false
5. **Even cycle**

   * Always true

---

## Section 10 — Time & Space Complexity

* **Time:** `O(V + E)`
* **Space:**

  * Color array: `O(V)`
  * Recursion stack: `O(V)` worst case

---

## Section 11 — Interview Perspective

### Common Questions

* Why odd cycle breaks bipartite?
* DFS vs BFS for bipartite?
* Can directed graph be bipartite? (rare, tricky)
* How to modify for BFS?

### One-Line Answer to Remember

> **A graph is bipartite if we can color it using two colors without conflict.**
