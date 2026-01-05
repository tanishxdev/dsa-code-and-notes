# Number of Provinces (Connected Components in Graph)

**Reference**
[https://www.geeksforgeeks.org/problems/number-of-provinces/1](https://www.geeksforgeeks.org/problems/number-of-provinces/1)

---

## Section 1 — Understanding the Problem

### Problem Statement

You are given a graph of `V` nodes (cities).
The graph is represented as a **2D matrix** `isConnected[][]` where:

* `isConnected[i][j] = 1` → city `i` is directly connected to city `j`
* `isConnected[i][j] = 0` → no direct connection

Your task is to find the **number of provinces**.

---

### What Is a Province?

A **province** is a group of cities such that:

* Every city in the group is **directly or indirectly connected**
* No city outside the group is connected to any city inside

In graph terms:

> **Number of provinces = Number of connected components**

---

### Important Observations

* Graph is **undirected**
* Self connections exist (`isConnected[i][i] = 1`)
* Graph may be **disconnected**
* We must count how many separate connected groups exist

---

### Example

**Input**

```
isConnected =
[
  [1,1,0],
  [1,1,0],
  [0,0,1]
]
```

**Output**

```
2
```

Explanation:

* City `0` and `1` form one province
* City `2` alone forms another province

---

## Section 2 — Building the Solution

### Intuition

#### Core Idea

If we start from any unvisited city and explore **all cities reachable from it**, we will cover **exactly one province**.

So:

* Pick a city
* Traverse all connected cities (DFS or BFS)
* Mark them visited
* Increase province count by `1`
* Repeat for remaining unvisited cities

---

### Why Graph Traversal Works

* Each traversal covers **one full connected component**
* Counting how many times traversal starts gives total provinces

---

### One-Line Mental Model

> **Each DFS/BFS call starting from an unvisited node gives exactly one province.**

---

## Section 3 — Algorithms

We will implement **both DFS and BFS**, in **C++ and JavaScript**.

So total **4 files**:

1. C++ — DFS
2. C++ — BFS
3. JavaScript — DFS
4. JavaScript — BFS

---

# 1️⃣ C++ — Number of Provinces using DFS

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // =====================================================================
    // Function: dfs
    //
    // Purpose:
    // - Performs Depth First Search starting from a city (node)
    // - Marks all cities connected to this city as visited
    // - Effectively covers ONE complete province
    //
    // Parameters:
    // node        -> current city index
    // isConnected -> adjacency matrix where isConnected[i][j] = 1
    //                means city i is directly connected to city j
    // visited     -> array to mark cities that are already visited
    // V           -> total number of cities
    // =====================================================================
    void dfs(int node,
             vector<vector<int>>& isConnected,
             vector<bool>& visited,
             int V) {

        // Mark the current city as visited
        // This ensures we do not count it again
        visited[node] = true;

        // Check connections with all other cities
        for (int neighbor = 0; neighbor < V; neighbor++) {

            // Condition explanation:
            // isConnected[node][neighbor] == 1 → there is a road
            // !visited[neighbor]              → city not visited yet
            if (isConnected[node][neighbor] == 1 &&
                !visited[neighbor]) {

                // Visit the connected city
                dfs(neighbor, isConnected, visited, V);
            }
        }
    }

    // =====================================================================
    // Function: findCircleNum
    //
    // Purpose:
    // - Counts the number of provinces (connected components)
    //
    // Idea:
    // - Each DFS call from an unvisited city discovers ONE province
    //
    // Parameters:
    // isConnected -> adjacency matrix of the graph
    //
    // Returns:
    // Total number of provinces
    // =====================================================================
    int findCircleNum(vector<vector<int>>& isConnected) {

        // Number of cities
        int V = isConnected.size();

        // Visited array to track which cities are already part of a province
        vector<bool> visited(V, false);

        // Counter for provinces
        int provinces = 0;

        // Iterate through all cities
        for (int i = 0; i < V; i++) {

            // If city is not visited, it starts a new province
            if (!visited[i]) {

                // DFS will mark all cities in this province
                dfs(i, isConnected, visited, V);

                // One complete province is found
                provinces++;
            }
        }

        return provinces;
    }
};

int main() {
    // Adjacency matrix representing city connections
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    Solution sol;

    // Print number of provinces
    cout << "Number of Provinces: "
         << sol.findCircleNum(isConnected) << endl;

    return 0;
}
```
---

# 2️⃣ C++ — Number of Provinces using BFS

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // =====================================================================
    // Function: findCircleNum
    //
    // Purpose:
    // - Counts the number of provinces (connected components)
    // - Uses BFS traversal on an adjacency MATRIX
    //
    // A province means:
    // - A group of cities directly or indirectly connected
    //
    // Input:
    // - isConnected: adjacency matrix
    //   isConnected[i][j] == 1 → city i is connected to city j
    //
    // Output:
    // - Total number of provinces
    // =====================================================================
    int findCircleNum(vector<vector<int>>& isConnected) {

        // Total number of cities (nodes)
        int V = isConnected.size();

        // Visited array to track which cities are already counted
        vector<bool> visited(V, false);

        // Counter to store number of provinces
        int provinces = 0;

        // ---------------------------------------------------------------
        // STEP 1: Traverse all cities one by one
        // ---------------------------------------------------------------
        for (int i = 0; i < V; i++) {

            // -----------------------------------------------------------
            // If city i is NOT visited,
            // it means we have found a NEW province
            // -----------------------------------------------------------
            if (!visited[i]) {

                // One new province found
                provinces++;

                // Queue for BFS traversal
                queue<int> q;

                // Start BFS from city i
                q.push(i);

                // Mark city i as visited
                visited[i] = true;

                // -------------------------------------------------------
                // STEP 2: BFS to visit all cities in this province
                // -------------------------------------------------------
                while (!q.empty()) {

                    // Take the front city from queue
                    int node = q.front();
                    q.pop();

                    // ---------------------------------------------------
                    // Check connections with all other cities
                    // ---------------------------------------------------
                    for (int neighbor = 0; neighbor < V; neighbor++) {

                        // Condition explanation:
                        // isConnected[node][neighbor] == 1 → cities connected
                        // !visited[neighbor]              → city not yet visited
                        if (isConnected[node][neighbor] == 1 &&
                            !visited[neighbor]) {

                            // Mark neighbor city as visited
                            visited[neighbor] = true;

                            // Add neighbor city to queue
                            q.push(neighbor);
                        }
                    }
                }
                // BFS ends → entire province is visited
            }
        }

        // ---------------------------------------------------------------
        // STEP 3: Return total provinces found
        // ---------------------------------------------------------------
        return provinces;
    }
};

int main() {

    // Adjacency matrix representation of cities
    // Each city is isolated here
    vector<vector<int>> isConnected = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    Solution sol;

    // Print number of provinces
    cout << "Number of Provinces: "
         << sol.findCircleNum(isConnected) << endl;

    return 0;
}
```

---

# 3️⃣ JavaScript — Number of Provinces using DFS

```javascript
class Solution {
  // =====================================================================
  // Function: dfs
  //
  // Purpose:
  // - Marks all cities connected to current city
  // =====================================================================
  dfs(node, isConnected, visited) {
    visited[node] = true;

    for (let neighbor = 0; neighbor < isConnected.length; neighbor++) {
      if (isConnected[node][neighbor] === 1 && !visited[neighbor]) {
        this.dfs(neighbor, isConnected, visited);
      }
    }
  }

  // =====================================================================
  // Function: findCircleNum
  //
  // Purpose:
  // - Counts number of provinces
  // =====================================================================
  findCircleNum(isConnected) {
    const V = isConnected.length;
    const visited = new Array(V).fill(false);
    let provinces = 0;

    for (let i = 0; i < V; i++) {
      if (!visited[i]) {
        this.dfs(i, isConnected, visited);
        provinces++;
      }
    }

    return provinces;
  }
}

// Example
const isConnected = [
  [1,1,0],
  [1,1,0],
  [0,0,1]
];

const sol = new Solution();
console.log("Number of Provinces:", sol.findCircleNum(isConnected));
```

---

# 4️⃣ JavaScript — Number of Provinces using BFS

```javascript
class Solution {
  findCircleNum(isConnected) {
    const V = isConnected.length;
    const visited = new Array(V).fill(false);
    let provinces = 0;

    for (let i = 0; i < V; i++) {
      if (!visited[i]) {
        provinces++;
        const queue = [];
        queue.push(i);
        visited[i] = true;

        while (queue.length > 0) {
          const node = queue.shift();

          for (let neighbor = 0; neighbor < V; neighbor++) {
            if (isConnected[node][neighbor] === 1 && !visited[neighbor]) {
              visited[neighbor] = true;
              queue.push(neighbor);
            }
          }
        }
      }
    }

    return provinces;
  }
}

// Example
const isConnected = [
  [1,0,0],
  [0,1,0],
  [0,0,1]
];

const sol = new Solution();
console.log("Number of Provinces:", sol.findCircleNum(isConnected));
```

---

## Time Complexity

* **DFS / BFS Traversal**: `O(V²)`

  * Because adjacency matrix is scanned fully
* **Total**: `O(V²)`

---

## Space Complexity

* Visited array: `O(V)`
* DFS recursion stack / BFS queue: `O(V)`
* **Total**: `O(V)`

---

## Interview Key Points

* Provinces = Connected Components
* Use DFS or BFS
* Matrix → treat as graph
* Increment count when a new traversal starts
* Works for disconnected graphs

---

## Section 4 — Time & Space Complexity Analysis (DFS vs BFS)

### DFS (Depth First Search)

#### Time Complexity

* **O(V²)**

Why:

* The graph is given as an **adjacency matrix**
* For **each city**, we scan **all V possible neighbors**
* In the worst case, DFS is called once per city

So:

```
V DFS calls × V neighbor checks = O(V²)
```

---

#### Space Complexity

* **O(V)**

Breakdown:

* `visited` array → `O(V)`
* Recursive call stack (worst case) → `O(V)`

Total:

```
O(V)
```

---

### BFS (Breadth First Search)

#### Time Complexity

* **O(V²)**

Why:

* Each city is pushed into the queue **once**
* For every popped city, we scan **all V neighbors** from the matrix

So:

```
V queue operations × V neighbor checks = O(V²)
```

---

#### Space Complexity

* **O(V)**

Breakdown:

* `visited` array → `O(V)`
* Queue (worst case stores all cities) → `O(V)`

Total:

```
O(V)
```

---

### DFS vs BFS — Final Comparison

| Aspect             | DFS               | BFS         |
| ------------------ | ----------------- | ----------- |
| Traversal style    | Depth-first       | Level-order |
| Data structure     | Recursion (stack) | Queue       |
| Time Complexity    | O(V²)             | O(V²)       |
| Space Complexity   | O(V)              | O(V)        |
| Result (provinces) | Same              | Same        |

---

### Final One-Line Lock (Interview Ready)

> **DFS and BFS have the same time and space complexity for the Provinces problem because the graph is represented as an adjacency matrix.**
