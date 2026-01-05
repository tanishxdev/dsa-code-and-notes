# Course Schedule II (Topological Order using BFS – Kahn’s Algorithm)

Reference:
[https://leetcode.com/problems/course-schedule-ii/](https://leetcode.com/problems/course-schedule-ii/)

---

## Section 1 — Understanding the Problem

### Problem Statement

You are given:

- `numCourses` → total number of courses labeled `0` to `numCourses - 1`
- `prerequisites` → list of pairs `[a, b]` meaning
  **to take course `a`, you must first complete course `b`**

Your task is to:

- Return **one valid order** in which all courses can be completed
- If it is **not possible** (because of a cycle), return an **empty array**

---

### Key Observations

- This is a **directed graph**

  - Course = node
  - Prerequisite = directed edge `b → a`

- If the graph has a **cycle**, course completion is **impossible**
- If the graph is **acyclic**, a **topological order** gives the answer

---

### Why This Is a Graph Problem

- Courses depend on other courses → **dependencies**
- Dependencies naturally form a **directed graph**
- Ordering with dependency constraints = **Topological Sort**

---

## Section 2 — Building the Solution

### Intuition

#### Core Idea

- A course with **no prerequisites** can be taken immediately
- Such a course has **in-degree = 0**

Kahn’s Algorithm works by:

1. Finding all courses with `in-degree = 0`
2. Taking them first
3. Removing their dependency effect on other courses
4. Repeating until no courses are left

---

#### What Indicates a Cycle

- If some courses **never reach in-degree 0**
- Queue becomes empty **before** all courses are processed
- That means a **cycle exists**

---

#### One-Line Mental Model

> **If we can take all courses by always picking prerequisite-free courses, the schedule is possible.**

---

### Algorithm (Course Schedule II)

1. Build adjacency list from prerequisites
2. Compute in-degree for each course
3. Push all courses with in-degree `0` into queue
4. While queue is not empty:

   - Pop course
   - Add it to result
   - Reduce in-degree of dependent courses
   - Push any course whose in-degree becomes `0`

5. If result size == `numCourses` → return result
   Else → return empty array

---

### Pseudocode

```
function findOrder(numCourses, prerequisites):
    adj = adjacency list
    indegree = array[numCourses] = 0

    for each (a, b) in prerequisites:
        adj[b].push(a)
        indegree[a]++

    queue = all nodes with indegree 0
    result = empty list

    while queue not empty:
        course = queue.pop()
        result.append(course)

        for nextCourse in adj[course]:
            indegree[nextCourse]--
            if indegree[nextCourse] == 0:
                queue.push(nextCourse)

    if result.size == numCourses:
        return result
    else:
        return empty list
```

---

## Code — C++ (Primary, Exact Style & Depth)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // =====================================================================
    // Function: findOrder
    //
    // Purpose:
    // - Returns a valid order to complete all courses
    // - Uses BFS-based Topological Sort (Kahn’s Algorithm)
    //
    // Parameters:
    // numCourses    -> total number of courses
    // prerequisites -> list of [course, prerequisite]
    //
    // Returns:
    // - Vector of course order if possible
    // - Empty vector if cycle exists
    // =====================================================================
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // ---------------------------------------------------------------
        // STEP 1: Build adjacency list
        //
        // Edge direction:
        // prereq -> course
        // Means: prereq must be completed before course
        // ---------------------------------------------------------------
        vector<vector<int>> adj(numCourses);

        // ---------------------------------------------------------------
        // STEP 2: Initialize indegree array
        //
        // indegree[i] = number of prerequisites for course i
        // ---------------------------------------------------------------
        vector<int> indegree(numCourses, 0);

        for (auto &p : prerequisites) {
            int course = p[0];
            int prereq = p[1];

            adj[prereq].push_back(course);
            indegree[course]++;
        }

        // ---------------------------------------------------------------
        // STEP 3: Push all courses with indegree 0 into queue
        //
        // These courses have no prerequisites and can be taken first
        // ---------------------------------------------------------------
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // ---------------------------------------------------------------
        // STEP 4: BFS Topological Traversal
        // ---------------------------------------------------------------
        vector<int> result;

        while (!q.empty()) {

            // Course with all prerequisites satisfied
            int course = q.front();
            q.pop();

            // Add course to ordering
            result.push_back(course);

            // Reduce indegree of dependent courses
            for (int nextCourse : adj[course]) {
                indegree[nextCourse]--;

                // If no prerequisites remain, push to queue
                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        // ---------------------------------------------------------------
        // STEP 5: Final validation
        //
        // If all courses are included, valid order exists
        // Otherwise, a cycle is present
        // ---------------------------------------------------------------
        if (result.size() == numCourses) {
            return result;
        }

        return {};
    }
};
```

---

## Code — JavaScript (Equivalent Logic, Same Depth)

```javascript
class Solution {
  // ===============================================================
  // Function: findOrder
  //
  // Purpose:
  // - Returns a valid course completion order
  // - Uses BFS-based Kahn’s Algorithm
  //
  // Parameters:
  // numCourses    -> total number of courses
  // prerequisites -> array of [course, prerequisite]
  //
  // Returns:
  // - Array of course order
  // - Empty array if cycle exists
  // ===============================================================
  findOrder(numCourses, prerequisites) {
    // -------------------------------------------------------------
    // STEP 1: Build adjacency list
    // -------------------------------------------------------------
    const adj = Array.from({ length: numCourses }, () => []);

    // -------------------------------------------------------------
    // STEP 2: Build indegree array
    // -------------------------------------------------------------
    const indegree = new Array(numCourses).fill(0);

    for (const [course, prereq] of prerequisites) {
      adj[prereq].push(course);
      indegree[course]++;
    }

    // -------------------------------------------------------------
    // STEP 3: Initialize queue with indegree 0 courses
    // -------------------------------------------------------------
    const queue = [];
    for (let i = 0; i < numCourses; i++) {
      if (indegree[i] === 0) {
        queue.push(i);
      }
    }

    // -------------------------------------------------------------
    // STEP 4: BFS Topological Processing
    // -------------------------------------------------------------
    const result = [];

    while (queue.length > 0) {
      const course = queue.shift();
      result.push(course);

      for (const nextCourse of adj[course]) {
        indegree[nextCourse]--;

        if (indegree[nextCourse] === 0) {
          queue.push(nextCourse);
        }
      }
    }

    // -------------------------------------------------------------
    // STEP 5: Validate result
    // -------------------------------------------------------------
    if (result.length === numCourses) {
      return result;
    }

    return [];
  }
}
```

---

## Dry Run (Quick)

**Input**

```
numCourses = 4
prerequisites = [[1,0],[2,0],[3,1],[3,2]]
```

**Edges**

```
0 → 1
0 → 2
1 → 3
2 → 3
```

**In-degree**

```
[0,1,1,2]
```

**Queue Start**

```
[0]
```

**Processing Order**

```
0 → 1 → 2 → 3
```

**Output**

```
[0,1,2,3]
```

---

## Time Complexity

- Graph build: `O(E)`
- BFS traversal: `O(V + E)`
- **Total:** `O(V + E)`

---

## Space Complexity

- Adjacency list: `O(V + E)`
- In-degree array: `O(V)`
- Queue + result: `O(V)`

---

## Interview Key Points

- Course Schedule II = **Topological Sort + Cycle Detection**
- BFS preferred when:

  - Order is required
  - Cycle detection needed

- If result size < numCourses → **cycle exists**
