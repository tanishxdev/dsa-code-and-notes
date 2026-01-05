# BIPARTITE GRAPH — COMPLETE MASTER NOTE (ENHANCED WITH CODE)

---

## CORE IDEA (COMMON FOR ALL METHODS)

A graph is **bipartite** if:

* Nodes can be divided into **two groups**
* Every edge connects nodes from **different groups**
* Equivalent rule:

> **Graph must NOT contain an odd-length cycle**

### Why odd cycle fails?

* Even cycle → colors alternate perfectly
* Odd cycle → at some point, **same color touches same color**

---

# 1️⃣ DFS COLORING METHOD

---

## Algorithm Intuition

* We try to **paint the graph**
* Only **2 colors** allowed: `0` and `1`
* Rule:

  > If a node is color `X`, all its neighbors must be `1 - X`

DFS helps because:

* Goes deep
* Propagates color constraints
* Detects conflict immediately

Disconnected graph?

* Start DFS from **every unvisited node**

---

## DFS Algorithm Steps

1. Create `color[]` initialized with `-1`
2. Loop over all nodes:

   * If node is uncolored → start DFS with color `0`
3. In DFS:

   * Color current node
   * For each neighbor:

     * If uncolored → DFS with opposite color
     * If same color → conflict

---

## DFS — FULL C++ CODE (COMPLETE & COMMENTED)

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
    DFS function to check bipartiteness
    node      -> current node
    currColor -> color assigned to this node (0 or 1)
    adj       -> adjacency list
    color     -> color array
*/
bool dfs(int node, int currColor,
         vector<vector<int>>& adj,
         vector<int>& color) {

    // Assign color to current node
    color[node] = currColor;

    // Traverse all adjacent nodes
    for (int neighbor : adj[node]) {

        // Case 1: Neighbor is not colored yet
        if (color[neighbor] == -1) {

            // Assign opposite color and continue DFS
            if (!dfs(neighbor, 1 - currColor, adj, color)) {
                return false;  // conflict found deeper
            }
        }

        // Case 2: Neighbor already colored
        else if (color[neighbor] == currColor) {

            // Same color on both ends of edge → conflict
            return false;
        }
    }

    // No conflicts in this path
    return true;
}

/*
    Main function to check bipartite graph using DFS
*/
bool isBipartiteDFS(int V, vector<vector<int>>& adj) {

    // Initialize all nodes as uncolored
    vector<int> color(V, -1);

    // Handle disconnected graph
    for (int i = 0; i < V; i++) {

        // If node is unvisited, start DFS
        if (color[i] == -1) {

            if (!dfs(i, 0, adj, color)) {
                return false;
            }
        }
    }

    return true;
}
```

---

## DFS Edge Cases

1. **Disconnected graph**
   → DFS from every uncolored node

2. **Self-loop (u → u)**
   → Immediate failure

3. **Single node / no edges**
   → Always bipartite

---

## DFS Complexity

### Time

```
O(V + E)
```

### Space

```
O(V)   // color array + recursion stack
```

---

# 2️⃣ BFS COLORING METHOD

---

## Algorithm Intuition

Same coloring logic, but:

* Uses **queue**
* Colors spread **level by level**
* No recursion → no stack overflow

---

## BFS Algorithm Steps

1. Initialize `color[] = -1`
2. For each node:

   * If uncolored:

     * Assign color `0`
     * Push into queue
3. While queue not empty:

   * Pop node
   * For each neighbor:

     * If uncolored → assign opposite color + push
     * If same color → conflict

---

## BFS — FULL C++ CODE (COMPLETE & COMMENTED)

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
    Function to check bipartite graph using BFS
*/
bool isBipartiteBFS(int V, vector<vector<int>>& adj) {

    // Color array: -1 means uncolored
    vector<int> color(V, -1);

    // Traverse all components
    for (int i = 0; i < V; i++) {

        // If node not colored, start BFS
        if (color[i] == -1) {

            queue<int> q;
            q.push(i);
            color[i] = 0;   // initial color

            while (!q.empty()) {

                int node = q.front();
                q.pop();

                // Check all neighbors
                for (int neighbor : adj[node]) {

                    // If neighbor uncolored
                    if (color[neighbor] == -1) {

                        // Assign opposite color
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    }

                    // If neighbor has same color → conflict
                    else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}
```

---

## BFS Complexity

### Time

```
O(V + E)
```

### Space

```
O(V)   // color array + queue
```

---

## BFS vs DFS (Interview)

| Aspect | DFS            | BFS         |
| ------ | -------------- | ----------- |
| Stack  | Recursive      | Iterative   |
| Risk   | Stack overflow | Safe        |
| Usage  | Simple graphs  | Large depth |

---

# 3️⃣ UNION-FIND (DSU) METHOD

---

## Algorithm Intuition (IMPORTANT)

We **do NOT color nodes**.

Instead:

* For node `u`
* **All neighbors of `u` must belong to same group**
* But **never the same group as `u`**

If at any point:

```
find(u) == find(v)
```

→ conflict

---

## DSU Algorithm Steps

1. Initialize DSU for `V` nodes
2. For each node `u`:

   * For all neighbors `v`:

     * If `u` and `v` in same set → fail
     * Union first neighbor with other neighbors

---

## DSU — FULL C++ CODE (COMPLETE & COMMENTED)

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
    Disjoint Set Union (Union-Find) structure
*/
class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union by rank
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

/*
    Bipartite check using DSU
*/
bool isBipartiteDSU(int V, vector<vector<int>>& adj) {

    DSU dsu(V);

    // Traverse each node
    for (int u = 0; u < V; u++) {

        // Traverse neighbors
        for (int v : adj[u]) {

            // If u and v are in same set → conflict
            if (dsu.find(u) == dsu.find(v)) {
                return false;
            }

            // Union all neighbors of u together
            if (!adj[u].empty()) {
                dsu.unite(adj[u][0], v);
            }
        }
    }

    return true;
}
```

---

## DSU Complexity

### Time

```
O((V + E) * α(V)) ≈ O(V + E)
```

### Space

```
O(V)
```

---

# FINAL COMPARISON SUMMARY

| Method | Uses Traversal | Stack Risk | Difficulty |
| ------ | -------------- | ---------- | ---------- |
| DFS    | Yes            | Yes        | Easy       |
| BFS    | Yes            | No         | Easy       |
| DSU    | No             | No         | Advanced   |

---

## FINAL MENTAL MODEL (LOCK THIS)

> **Bipartite graph = 2-colorable graph**
> **Odd cycle = impossible coloring**
> **DFS/BFS → color propagation**
> **DSU → grouping constraints**
