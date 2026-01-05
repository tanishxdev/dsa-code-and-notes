# Course Schedule (Cycle Detection in Directed Graph)

**Reference:**
[https://www.geeksforgeeks.org/problems/course-schedule/1](https://www.geeksforgeeks.org/problems/course-schedule/1)
(Equivalent to LeetCode 207 – Course Schedule)

---

## Section 1 — Understanding the Problem

### Problem Statement

You are given:

- An integer `numCourses` representing total courses labeled from `0` to `numCourses - 1`
- A list `prerequisites`, where each pair `[a, b]` means:

  - To take course `a`, you **must first complete** course `b`

Your task is to determine whether **it is possible to finish all courses**.

Return:

- `true` → if all courses can be completed
- `false` → if it is **not possible** (cycle exists)

---

### How to Model This Problem

This is a **directed graph problem**:

- **Node** → Course
- **Directed edge** `b → a` → `b` is a prerequisite of `a`

---

### Key Observation

- If the directed graph contains a **cycle**, then courses in that cycle depend on each other
- Cyclic dependency means **no valid order exists**
- Therefore:

  - **Cycle present → cannot finish courses**
  - **No cycle → possible to finish**

---

### Example

#### Example 1

```
numCourses = 2
prerequisites = [[1,0]]
```

Graph:

```
0 → 1
```

Result:

```
true
```

---

#### Example 2

```
numCourses = 2
prerequisites = [[1,0], [0,1]]
```

Graph:

```
0 → 1
↑   ↓
└───┘
```

Result:

```
false (cycle)
```

---

## Section 2 — Building the Solution

This problem is solved in **two standard ways**:

1. **BFS (Kahn’s Algorithm / Topological Sort)**
2. **DFS (Recursion Stack / Back-edge detection)**

Both are important and commonly asked in interviews.

---

## Approach 1 — BFS (Kahn’s Algorithm)

### Intuition

- If all courses can be arranged in **topological order**, then no cycle exists
- Kahn’s Algorithm removes nodes with **in-degree = 0**
- If we are able to process all nodes → no cycle
- If some nodes remain unprocessed → cycle exists

---

### Algorithm (BFS)

1. Build adjacency list from prerequisites
2. Compute in-degree of each course
3. Push all courses with in-degree `0` into a queue
4. Process queue:

   - Pop a course
   - Reduce in-degree of its neighbors
   - Push neighbors whose in-degree becomes `0`

5. Count processed courses
6. If processed count == `numCourses` → return `true`
7. Else → return `false`

---

### Code — C++ (BFS / Kahn’s Algorithm)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // =====================================================================
    // Function: canFinish
    //
    // Purpose:
    // - Checks whether it is possible to finish all courses
    // - Uses BFS-based topological sorting (Kahn’s Algorithm)
    //
    // Idea:
    // - If a cycle exists in the prerequisite graph, courses cannot be finished
    // - If all courses are processed in topo order, no cycle exists
    //
    // Parameters:
    // numCourses    -> total number of courses
    // prerequisites -> pairs [course, prerequisite]
    //
    // Returns:
    // true  -> all courses can be completed
    // false -> cycle exists
    // =====================================================================
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // ---------------------------------------------------------------
        // STEP 1: Build adjacency list and indegree array
        // ---------------------------------------------------------------
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Each pair [a, b] means b -> a
        for (auto &p : prerequisites) {
            int course = p[0];
            int prereq = p[1];

            adj[prereq].push_back(course);
            indegree[course]++;
        }

        // ---------------------------------------------------------------
        // STEP 2: Push all courses with indegree 0 into queue
        // ---------------------------------------------------------------
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // ---------------------------------------------------------------
        // STEP 3: BFS processing (Topological Sort)
        // ---------------------------------------------------------------
        int completed = 0;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            // One course completed
            completed++;

            // Reduce indegree of dependent courses
            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // ---------------------------------------------------------------
        // STEP 4: Final check
        // ---------------------------------------------------------------
        // If all courses are completed, no cycle exists
        return completed == numCourses;
    }
};

int main() {
    Solution sol;

    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}};

    cout << (sol.canFinish(numCourses, prerequisites) ? "true" : "false");
    return 0;
}
```

---

### Code — JavaScript (BFS / Kahn’s Algorithm)

```javascript
class Solution {
  canFinish(numCourses, prerequisites) {
    // Step 1: Build adjacency list and indegree array
    const adj = Array.from({ length: numCourses }, () => []);
    const indegree = new Array(numCourses).fill(0);

    for (const [course, prereq] of prerequisites) {
      adj[prereq].push(course);
      indegree[course]++;
    }

    // Step 2: Initialize queue with indegree 0 nodes
    const queue = [];
    for (let i = 0; i < numCourses; i++) {
      if (indegree[i] === 0) queue.push(i);
    }

    // Step 3: BFS processing
    let completed = 0;

    while (queue.length > 0) {
      const node = queue.shift();
      completed++;

      for (const neighbor of adj[node]) {
        indegree[neighbor]--;
        if (indegree[neighbor] === 0) {
          queue.push(neighbor);
        }
      }
    }

    return completed === numCourses;
  }
}

// Example
const sol = new Solution();
console.log(sol.canFinish(2, [[1, 0]])); // true
```

---

## Approach 2 — DFS (Recursion Stack Method)

### Intuition

- In a directed graph, a cycle exists if during DFS:

  - We reach a node that is **already in the current recursion path**

- We track:

  - `visited[]` → node already processed
  - `recStack[]` → node currently in DFS path

---

### Algorithm (DFS)

1. Build adjacency list
2. Maintain `visited` and `recStack`
3. For each unvisited node:

   - Run DFS
   - If a node is found already in `recStack` → cycle

4. If no cycle found → return `true`

---

### Code — C++ (DFS Cycle Detection)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // =====================================================================
    // Function: dfs
    //
    // Purpose:
    // - Performs DFS to detect cycle in a directed graph
    // - Uses recursion stack to detect back edges
    //
    // Parameters:
    // node     -> current course
    // adj      -> adjacency list (prerequisite graph)
    // visited  -> marks nodes already visited
    // recStack -> marks nodes in current DFS path
    //
    // Returns:
    // true  -> cycle detected
    // false -> no cycle from this path
    // =====================================================================
    bool dfs(int node,
             vector<vector<int>>& adj,
             vector<bool>& visited,
             vector<bool>& recStack) {

        // Mark current node as visited
        visited[node] = true;

        // Mark current node in recursion stack
        recStack[node] = true;

        // Explore all dependent courses
        for (int neighbor : adj[node]) {

            // Case 1: Neighbor not visited
            if (!visited[neighbor]) {
                if (dfs(neighbor, adj, visited, recStack))
                    return true;
            }
            // Case 2: Neighbor already in recursion stack
            // This indicates a cycle
            else if (recStack[neighbor]) {
                return true;
            }
        }

        // Backtrack: remove node from recursion stack
        recStack[node] = false;

        return false;
    }

    // =====================================================================
    // Function: canFinish
    //
    // Purpose:
    // - Determines if all courses can be finished
    // - Uses DFS-based cycle detection in directed graph
    //
    // Parameters:
    // numCourses    -> total number of courses
    // prerequisites -> list of prerequisite pairs
    //
    // Returns:
    // true  -> no cycle, all courses can be completed
    // false -> cycle exists
    // =====================================================================
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // Build adjacency list
        vector<vector<int>> adj(numCourses);
        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]); // prereq -> course
        }

        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);

        // Run DFS from every unvisited node
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, recStack))
                    return false; // cycle detected
            }
        }

        return true; // no cycle found
    }
};

int main() {
    Solution sol;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}};
    cout << (sol.canFinish(numCourses, prerequisites) ? "true" : "false");
}
```

---

### Code — JavaScript (DFS Cycle Detection)

```javascript
class Solution {
  canFinish(numCourses, prerequisites) {
    const adj = Array.from({ length: numCourses }, () => []);
    for (const [a, b] of prerequisites) {
      adj[b].push(a);
    }

    const visited = new Array(numCourses).fill(false);
    const recStack = new Array(numCourses).fill(false);

    const dfs = (node) => {
      visited[node] = true;
      recStack[node] = true;

      for (const neighbor of adj[node]) {
        if (!visited[neighbor]) {
          if (dfs(neighbor)) return true;
        } else if (recStack[neighbor]) {
          return true;
        }
      }

      recStack[node] = false;
      return false;
    };

    for (let i = 0; i < numCourses; i++) {
      if (!visited[i]) {
        if (dfs(i)) return false;
      }
    }

    return true;
  }
}

// Example
const sol = new Solution();
console.log(sol.canFinish(2, [[1, 0]])); // true
```

---

## Time Complexity

- **BFS:** `O(V + E)`
- **DFS:** `O(V + E)`

---

## Space Complexity

- Adjacency list: `O(V + E)`
- Auxiliary arrays: `O(V)`
- Recursion stack (DFS): `O(V)`

---

## Interview Notes

- Course Schedule is **cycle detection in directed graph**
- BFS → preferred when you also want topological order
- DFS → preferred for conceptual clarity and recursion-based cycle detection
- If cycle exists → **cannot complete all courses**
