# Depth First Search (DFS) of a Graph

![](https://miro.medium.com/v2/resize:fit:1400/1*VM84VPcCQe0gSy44l9S5yA.jpeg)
![](https://media.geeksforgeeks.org/wp-content/uploads/20240216084522/bfs-vs-dfs-(1).png)

---

## Section 1 — Understanding the Problem

### Problem Statement

Given an **undirected graph** with `V` vertices represented using an **adjacency list**, perform a **Depth First Search (DFS) traversal** starting from **vertex 0** and return the order of traversal.

* The graph may contain **cycles**
* The graph may be **connected or disconnected**
* If the graph is disconnected, DFS is performed **only from vertex 0** (as per standard GFG convention)

---

### What is DFS Traversal?

Depth First Search is a graph traversal technique where:

* We explore **one path completely** before trying other paths
* From a node, we go to **one neighbor**, then its neighbor, and so on
* We **backtrack** only when no unvisited neighbor is left
* Recursion (or an explicit stack) is used to manage depth

---

### Example

**Input (Adjacency List):**

```
V = 5
adj = [
  [2, 3, 1],
  [0],
  [0, 4],
  [0],
  [2]
]
```

**Output (DFS starting from 0):**

```
[0, 2, 4, 3, 1]
```

(The exact order depends on adjacency list order.)

---

### What Exactly Is Being Asked?

* Start traversal from node `0`
* Go **as deep as possible** along one path before backtracking
* Ensure **no node is visited more than once**
* Return the DFS traversal order

---

## Section 2 — Building the Solution

### Intuition

#### What DFS Is Trying to Do

DFS (Depth First Search) tries to **explore depth first**, not breadth.

That means:

* Pick one neighbor
* Go as deep as possible along that path
* Only when you cannot go further, come back and try another neighbor

Depth here means:

> How far you can go from the starting node by continuously following neighbors.

---

#### Mental Picture (Most Important)

Think of **exploring a maze**.

1. You choose one path and keep walking forward
2. You do not turn back unless the path is blocked
3. When blocked, you go back to the last junction
4. Then you try a different path

DFS works exactly like this.

* Go forward as much as possible
* Backtrack only when necessary

---

#### Step-by-Step DFS Thinking

When DFS starts from node `0`:

1. Visit node `0`
2. Choose the **first neighbor** (based on adjacency list order)
3. Visit that neighbor
4. From there, again choose its first unvisited neighbor
5. Continue until:

   * A node has **no unvisited neighbors**
6. Backtrack to the previous node
7. Try the next unvisited neighbor
8. Repeat until all reachable nodes are explored

---

#### Why DFS Is Called “Depth First”

Break the name:

* **Depth** → go as far as possible
* **First** → before trying other branches

Meaning:

> DFS finishes one entire path before starting another.

DFS does **not care about distance or levels**.
It only cares about **going deep**.

---

#### Why Recursion Is Natural for DFS

DFS behavior naturally matches recursion:

* Each recursive call goes **one level deeper**
* When a call finishes, execution automatically **returns back**
* This return represents **backtracking**

The function call stack works like an **implicit stack**.

---

#### Why Visited Array Is Required

Graphs can have:

* cycles
* multiple paths to the same node

Without a visited array:

* DFS can enter an infinite loop
* The same node can be processed repeatedly

---

#### What Visited Array Guarantees

The `visited` array ensures:

* Each node is processed **only once**
* DFS never revisits an already explored node
* Traversal finishes correctly

Rule to remember:

> Mark a node as visited **as soon as you enter it**.

---

#### Neighbor Visiting Order (Important)

DFS visits neighbors in the **exact order** given in the adjacency list.

Example:

```
adj[0] = {2, 3, 1}
```

DFS will try:

```
2 → then (from 2) → then back → 3 → then 1
```

This affects:

* Output order
* Dry runs
* Online judge expected answers

---

#### One-Line Mental Model (Must Remember)

> **DFS explores one complete path at a time using recursion, and backtracks when stuck.**

---

### Algorithm

1. Create a `visited` array of size `V`, initialized with `false`
2. Create a `result` array to store DFS traversal
3. Call a recursive DFS function starting from vertex `0`
4. In the DFS function:

   * Mark the current node as visited
   * Add the node to the result
   * For each neighbor:

     * If unvisited, call DFS on that neighbor
5. Return the result array

---

### Pseudocode

```
function dfsOfGraph(V, adj):
    visited = array of size V filled with false
    result = empty array
    dfs(0, adj, visited, result)
    return result

function dfs(node, adj, visited, result):
    visited[node] = true
    result.append(node)

    for each neighbor in adj[node]:
        if visited[neighbor] == false:
            dfs(neighbor, adj, visited, result)
```

---

### Code — C++ (Primary)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // =====================================================================
    // Helper Function: dfsTraversal
    //
    // Purpose:
    // - Performs the actual Depth First Search using recursion
    // - Visits the current node, then goes deep into its neighbors
    //
    // Parameters:
    // node    -> current node being visited
    // adj     -> adjacency list of the graph
    // visited -> keeps track of visited nodes to avoid cycles
    // result  -> stores DFS traversal order
    // =====================================================================
    void dfsTraversal(int node,
                      vector<vector<int>> &adj,
                      vector<bool> &visited,
                      vector<int> &result)
    {
        // Mark the current node as visited
        // This prevents revisiting the same node again
        visited[node] = true;

        // Add the current node to the DFS traversal result
        result.push_back(node);

        // Traverse all neighbors of the current node
        // Order depends on adjacency list
        for (int neighbor : adj[node])
        {
            // If the neighbor has not been visited yet
            if (!visited[neighbor])
            {
                // Recursively visit the neighbor
                dfsTraversal(neighbor, adj, visited, result);
            }
        }
    }

    // =====================================================================
    // Function: dfs
    //
    // Purpose:
    // - Initializes required data structures
    // - Starts DFS traversal from node 0
    //
    // Input:
    // adj -> adjacency list of the graph
    //
    // Output:
    // DFS traversal order starting from node 0
    // =====================================================================
    vector<int> dfs(vector<vector<int>> &adj)
    {
        // Total number of vertices in the graph
        int V = adj.size();

        // Visited array initialized to false for all nodes
        vector<bool> visited(V, false);

        // Vector to store DFS traversal result
        vector<int> result;

        // Start DFS traversal from node 0
        dfsTraversal(0, adj, visited, result);

        // Return the final DFS traversal
        return result;
    }
};

int main()
{
    // Number of vertices
    int V = 5;

    // Adjacency list representation of the graph
    vector<vector<int>> adj(V);

    // Defining the graph connections
    adj[0] = {2, 3, 1};
    adj[1] = {0};
    adj[2] = {0, 4};
    adj[3] = {0};
    adj[4] = {2};

    // Create Solution object
    Solution obj;

    // Perform DFS traversal
    vector<int> dfsResult = obj.dfs(adj);

    // Print DFS traversal result
    cout << "DFS Traversal: ";
    for (int node : dfsResult)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
```

---

### Code — JavaScript (Equivalent Logic)

```javascript
class Solution {
  dfs(adj) {
    const V = adj.length;
    const visited = new Array(V).fill(false);
    const result = [];

    function dfsTraversal(node) {
      visited[node] = true;      // Mark node as visited
      result.push(node);         // Add node to result

      // Explore neighbors
      for (const neighbor of adj[node]) {
        if (!visited[neighbor]) {
          dfsTraversal(neighbor);
        }
      }
    }

    // Start DFS from node 0
    dfsTraversal(0);

    return result;
  }
}

// Example usage
const adj = [
  [2, 3, 1],
  [0],
  [0, 4],
  [0],
  [2],
];

const sol = new Solution();
console.log("DFS Traversal:", sol.dfs(adj));
```

---

### Dry Run (Tabular Format)

**Input:**

```
adj = [[2,3,1], [0], [0,4], [0], [2]]
```

**Expected Output:**

```
[0, 2, 4, 3, 1]
```

| Step | Current Node | Visited         | Result          | Action                    |
| ---: | ------------ | --------------- | --------------- | ------------------------- |
|    1 | 0            | [T, F, F, F, F] | [0]             | Start DFS at 0            |
|    2 | 2            | [T, F, T, F, F] | [0, 2]          | Go to first neighbor of 0 |
|    3 | 4            | [T, F, T, F, T] | [0, 2, 4]       | Go deeper from 2          |
|    4 | -            | [T, F, T, F, T] | [0, 2, 4]       | Backtrack (no neighbors)  |
|    5 | 3            | [T, F, T, T, T] | [0, 2, 4, 3]    | Next neighbor of 0        |
|    6 | -            | [T, F, T, T, T] | [0, 2, 4, 3]    | Backtrack                 |
|    7 | 1            | [T, T, T, T, T] | [0, 2, 4, 3, 1] | Last neighbor             |
|    8 | -            | [T, T, T, T, T] | [0, 2, 4, 3, 1] | DFS complete              |

---

### Time Complexity

* **O(V + E)**

  * Each vertex is visited once
  * Each edge is explored once

Same for **C++ and JavaScript**

---

### Space Complexity

* Visited array: `O(V)`
* Result array: `O(V)`
* Recursion stack: `O(V)` in worst case (skewed graph)

Overall: **O(V)** (excluding input adjacency list)

---

## Section 3 — Important Follow-Up (Q & A)

**Q1. Why does DFS not guarantee shortest path?**
DFS goes deep without considering distance. It may reach a far node before a closer one.

**Q2. When should DFS be preferred over BFS?**

* Exploring all possible paths
* Cycle detection
* Topological sorting
* Backtracking-based problems

**Q3. Can DFS be implemented without recursion?**
Yes. Using an explicit stack, but logic remains the same.

**Q4. What happens if the graph is disconnected?**
Only nodes reachable from vertex `0` are visited. To cover all nodes, DFS must be started from every unvisited vertex.

**Q5. What is the biggest risk in DFS?**
Stack overflow due to deep recursion in very large or skewed graphs.

