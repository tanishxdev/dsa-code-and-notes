# Breadth First Search (BFS) of a Graph

![](https://miro.medium.com/v2/resize:fit:1400/1*VM84VPcCQe0gSy44l9S5yA.jpeg)
![](https://media.geeksforgeeks.org/wp-content/uploads/20240216084522/bfs-vs-dfs-(1).png)

---

## Section 1 — Understanding the Problem

### Problem Statement

Given an **undirected graph** with `V` vertices represented using an **adjacency list**, perform a **Breadth First Search (BFS) traversal** starting from **vertex 0** and return the order of traversal.

* The graph may contain **cycles**
* The graph may be **connected or disconnected**
* If the graph is disconnected, BFS is performed **only from vertex 0** (as per standard GFG convention)

---

### What is BFS Traversal?

Breadth First Search is a graph traversal technique where:

* We explore nodes **level by level**
* All **direct neighbors** of a node are visited **before** moving deeper
* A **queue** is used to maintain the correct visiting order

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

**Output:**

```
[0, 2, 3, 1, 4]
```

---

### What Exactly Is Being Asked?

* Start traversal from node `0`
* Visit nodes in **breadth-first (level-wise)** order
* Ensure **no node is visited more than once**
* Return the traversal order as a list/array

---

## Section 2 — Building the Solution

### Intuition

#### What BFS Is Trying to Do

BFS (Breadth First Search) tries to **visit nodes in increasing distance** from the starting node.

That means:

* Nodes **closest** to the start are visited first
* Nodes **farther away** are visited later

Distance here means:

> Number of edges from the starting node

---

#### Mental Picture (Most Important)

Think of **water waves**.

When you drop a stone in water:

1. First, the exact place where the stone falls is affected
2. Then, water **just around it** moves
3. Then, water **a little farther away** moves
4. This continues **layer by layer**

BFS works in **exactly the same way**.

Each “wave” is one **level** of the graph.

---

#### Step-by-Step BFS Thinking

When BFS starts from a node (say node `0`):

1. Visit node `0`
   → distance = 0

2. Visit all nodes **directly connected** to `0`
   → distance = 1

3. Visit all nodes connected to those nodes
   → distance = 2

4. Continue until no new nodes are left

At every step:

* **Closer nodes are always processed first**
* **Farther nodes wait their turn**

---

#### Why BFS Is Called “Breadth First”

Break the name:

* **Breadth** → width, neighbors, same level
* **First** → before going deeper

Meaning:

> BFS finishes **all nodes at the same level** before moving to the next level.

So BFS does **not go deep immediately**.
It spreads **sideways first**, then outward.

---

#### Why Queue Is Mandatory in BFS

BFS needs to **remember the order** in which nodes are discovered.

A **queue** gives exactly what BFS needs.

---

#### Queue Rule (Very Important)

Queue works on **FIFO**:

```
First In → First Out
```

Meaning:

* The node discovered first
* Is processed first

---

#### How Queue Creates Level-by-Level Traversal

1. Start node is pushed first
2. Its neighbors are pushed next
3. Neighbors of neighbors are pushed later

Because of FIFO:

* Nodes of level 1 are processed before level 2
* Nodes of level 2 are processed before level 3

Without a queue:

* BFS **cannot maintain levels**
* BFS logic breaks

---

#### Why Visited Array Is Required

Graphs can have:

* cycles
* multiple paths to the same node

Without `visited[]`:

* Same node can be pushed many times
* Queue keeps growing
* Algorithm may never stop

---

#### What Visited Array Guarantees

The `visited` array ensures:

* Each node is added to the queue **only once**
* Each node is processed **only once**
* BFS finishes safely and efficiently

Important rule:

> Mark a node as visited **when pushing into the queue**, not when popping.

This avoids duplicate pushes.

---

#### Neighbor Visiting Order (Important Detail)

BFS visits neighbors in the **same order** as they appear in the adjacency list.

Example:

```
adj[0] = {2, 3, 1}
```

BFS will visit:

```
2 → then 3 → then 1
```

This affects:

* Output order
* Dry runs
* Some GFG problems

---

#### One-Line Mental Model (Must Remember)

> **BFS explores the graph level by level using a queue, and never visits a node twice.**

---

If you want, next we can **lock this topic fully** by doing one of these (your choice):

* BFS code in **your exact C++ template** with step-wise comments
* BFS dry run on **your own example**
* BFS on **disconnected graph**
* BFS vs DFS intuition (clean comparison)
---

### Algorithm

1. Create a `visited` array of size `V`, initialized with `false`
2. Create an empty queue
3. Create a result array to store BFS traversal
4. Push vertex `0` into the queue and mark it as visited
5. While the queue is not empty:

   * Pop the front node
   * Add it to the result
   * Traverse all its neighbors
   * If a neighbor is not visited:

     * Mark it visited
     * Push it into the queue
6. Return the result array

---

### Pseudocode

```
function bfsOfGraph(V, adj):
    visited = array of size V filled with false
    queue = empty queue
    result = empty array

    queue.push(0)
    visited[0] = true

    while queue is not empty:
        node = queue.pop()
        result.append(node)

        for each neighbor in adj[node]:
            if visited[neighbor] == false:
                visited[neighbor] = true
                queue.push(neighbor)

    return result
```

---

### Code — C++ (Primary)

```cpp
#include <bits/stdc++.h>
// Includes all standard C++ libraries (vector, queue, iostream, etc.)
using namespace std;

// Solution class as expected in interview / GFG style
class Solution
{
public:
    // =====================================================================
    // Function: bfs
    // Purpose : Perform Breadth First Search (BFS) traversal
    // Start   : Always starts from vertex 0 (as per problem statement)
    // Input   : adj -> adjacency list representation of the graph
    // Output  : vector<int> containing BFS traversal order
    // =====================================================================
    vector<int> bfs(vector<vector<int>> &adj)
    {

        // Number of vertices in the graph
        // adj.size() gives total nodes (0 to V-1)
        int V = adj.size();

        // Visited array to keep track of visited nodes
        // visited[i] = true means node i is already visited
        vector<bool> visited(V, false);

        // Queue is mandatory for BFS
        // It helps process nodes level by level (FIFO order)
        queue<int> q;

        // Result vector to store BFS traversal order
        vector<int> result;

        // ===============================================================
        // STEP 1: START BFS FROM NODE 0
        // ===============================================================

        // Push starting node (0) into the queue
        q.push(0);

        // Mark node 0 as visited
        // Important: mark visited when pushing, not when popping
        visited[0] = true;

        // ===============================================================
        // STEP 2: PROCESS QUEUE UNTIL EMPTY
        // ===============================================================
        while (!q.empty())
        {

            // Take the front element of the queue
            int node = q.front();

            // Remove it from the queue
            q.pop();

            // Add the current node to BFS result
            result.push_back(node);

            // ===========================================================
            // STEP 3: VISIT ALL NEIGHBORS OF CURRENT NODE
            // ===========================================================

            // Traverse adjacency list of the current node
            for (int neighbor : adj[node])
            {

                // If the neighbor has not been visited yet
                if (!visited[neighbor])
                {

                    // Mark neighbor as visited
                    visited[neighbor] = true;

                    // Push neighbor into the queue
                    // It will be processed later (FIFO order)
                    q.push(neighbor);
                }
            }
        }

        // Return the BFS traversal order
        return result;
    }
};

int main()
{

    // Number of vertices
    int V = 5;

    // Adjacency list for graph with V nodes (0 to V-1)
    vector<vector<int>> adj(V);

    // Defining graph connections
    // This is an undirected graph
    adj[0] = {2, 3, 1}; // Node 0 is connected to 2, 3, 1
    adj[1] = {0};       // Node 1 is connected to 0
    adj[2] = {0, 4};    // Node 2 is connected to 0 and 4
    adj[3] = {0};       // Node 3 is connected to 0
    adj[4] = {2};       // Node 4 is connected to 2

    // Create Solution object
    Solution obj;

    // Call BFS function
    vector<int> bfsResult = obj.bfs(adj);

    // Print BFS traversal result
    cout << "BFS Traversal: ";
    for (int node : bfsResult)
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
  bfs(adj) {
    const V = adj.length;                   // Total number of vertices
    const visited = new Array(V).fill(false);
    const queue = [];
    const result = [];

    // Start BFS from node 0
    queue.push(0);
    visited[0] = true;

    // Process nodes until queue is empty
    while (queue.length > 0) {
      const node = queue.shift();            // Dequeue front element
      result.push(node);                     // Add node to result

      // Visit all adjacent neighbors
      for (const neighbor of adj[node]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          queue.push(neighbor);
        }
      }
    }

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
console.log("BFS Traversal:", sol.bfs(adj));
```

---

### Dry Run (Tabular Format)

**Input:**

```
adj = [[2,3,1], [0], [0,4], [0], [2]]
```

| Step | Queue   | Visited         | Result      | Action       |
| ---: | ------- | --------------- | ----------- | ------------ |
|    1 | [0]     | [T, F, F, F, F] | []          | Start from 0 |
|    2 | [2,3,1] | [T, F, T, T, F] | [0]         | Process 0    |
|    3 | [3,1,4] | [T, F, T, T, T] | [0,2]       | Process 2    |
|    4 | [1,4]   | [T, F, T, T, T] | [0,2,3]     | Process 3    |
|    5 | [4]     | [T, T, T, T, T] | [0,2,3,1]   | Process 1    |
|    6 | []      | [T, T, T, T, T] | [0,2,3,1,4] | Process 4    |

---

### Time Complexity

* **O(V + E)**

  * Each vertex is visited once
  * Each edge is checked once (adjacency list)

Same for **C++ and JavaScript**

---

### Space Complexity

* Visited array: `O(V)`
* Queue: `O(V)` in worst case
* Result array: `O(V)`

Overall: **O(V)** (excluding input graph)

---

## Section 3 — Important Follow-Up (Q & A)

**Q1. Why do we mark nodes visited before pushing into the queue?**
To prevent the same node from being pushed multiple times due to cycles or multiple parents.

**Q2. Why is BFS called level-order traversal?**
Because it completes all nodes at distance `d` before visiting nodes at distance `d + 1`.

**Q3. What happens if the graph is disconnected?**
Only nodes reachable from vertex `0` will be visited. For full traversal, BFS must be started from every unvisited node.

**Q4. Can BFS be done using recursion?**
No. BFS inherently depends on a queue, which makes it iterative.

**Q5. When should BFS be preferred over DFS?**

* Shortest path in unweighted graphs
* Level-wise traversal
* Minimum number of edges problems

