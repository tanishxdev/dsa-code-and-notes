Good.
Now we are **continuing naturally from basic DSU** and moving to **Optimized DSU**, exactly in the way you think and write.

No reference to notes.
Mentor-style.
Same structure.
Same depth.
Same coding discipline.

---

# Disjoint Set Union (DSU) — Optimized

### Path Compression + Union by Rank

---

## Section 1 — Why Optimization Is Needed

### The Problem With Basic DSU

In the basic DSU:

* `find()` can take **O(n)** time in worst case
* This happens when unions create a **long chain**

Example (bad case):

```
0 <- 1 <- 2 <- 3 <- 4 <- 5
```

If you call:

```
find(5)
```

You traverse **all nodes** up to root.

Now imagine:

* Thousands of `find()` operations
* Graph problems like Kruskal, dynamic connectivity

This becomes **too slow**.

---

## Section 2 — Core Optimization Idea

DSU is optimized using **two independent ideas**:

1. **Path Compression**
   (Optimize `find`)
2. **Union by Rank**
   (Optimize tree structure during `union`)

Together, they make DSU **almost constant time**.

---

## Section 3 — Path Compression (Find Optimization)

### What Path Compression Does

Whenever we call `find(x)`:

* We **directly connect x to the ultimate parent**
* We also compress the path for **all nodes visited**

So next time:

* `find()` becomes faster

---

### Mental Picture

Before path compression:

```
5 → 4 → 3 → 2 → 1
```

After one `find(5)`:

```
5 → 1
4 → 1
3 → 1
2 → 1
```

Tree becomes **flat**.

---

### Key Rule

> While returning from recursion, update parent directly to root.

---

### Path Compression Logic

```
parent[x] = find(parent[x])
```

This one line does the magic.

---

## Section 4 — Union by Rank (Union Optimization)

### What Rank Means

* `rank[x]` ≈ height of tree rooted at `x`
* Smaller rank → smaller tree
* Larger rank → deeper tree

---

### Why Rank Matters

If we always attach:

* **small tree under big tree**

Then:

* Tree height stays small
* `find()` becomes faster

---

### Union by Rank Rules

Let:

* `px` = leader of `x`
* `py` = leader of `y`

Cases:

1. `rank[px] < rank[py]`
   → attach `px` under `py`

2. `rank[px] > rank[py]`
   → attach `py` under `px`

3. `rank[px] == rank[py]`
   → attach any one
   → increase rank of new root by `1`

---

### Important Interview Line

> Rank increases **only when both ranks are equal**.

---

## Section 5 — Full Algorithm (Optimized DSU)

### Data Structures Used

* `parent[]`
* `rank[]`

---

### Step-by-Step

1. Initialize:

   * `parent[i] = i`
   * `rank[i] = 0`
2. `find()` uses **path compression**
3. `union()` uses **rank comparison**
4. Repeat operations efficiently

---

## Section 6 — Pseudocode

```
find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]


union(x, y):
    px = find(x)
    py = find(y)

    if px == py:
        return

    if rank[px] < rank[py]:
        parent[px] = py
    else if rank[px] > rank[py]:
        parent[py] = px
    else:
        parent[py] = px
        rank[px]++
```

---

## Section 7 — Code (C++ — Primary, Exact Style)

```cpp
#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    // ================================================================
    // Constructor
    //
    // Purpose:
    // - Initialize parent and rank arrays
    // ================================================================
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;   // each node is its own parent
        }
    }

    // ================================================================
    // Function: find
    //
    // Purpose:
    // - Find ultimate parent using path compression
    //
    // Logic:
    // - Recursively find root
    // - Compress path while returning
    // ================================================================
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // path compression
        }
        return parent[x];
    }

    // ================================================================
    // Function: unionSet
    //
    // Purpose:
    // - Merge two sets using union by rank
    // ================================================================
    void unionSet(int x, int y) {

        int px = find(x);
        int py = find(y);

        // If already in same set, nothing to do
        if (px == py)
            return;

        // Attach smaller rank tree under larger rank tree
        if (rank[px] < rank[py]) {
            parent[px] = py;
        }
        else if (rank[px] > rank[py]) {
            parent[py] = px;
        }
        else {
            parent[py] = px;
            rank[px]++;   // increase rank only when equal
        }
    }
};
```

---

## Section 8 — Code (JavaScript — Same Logic)

```javascript
class DSU {
  constructor(n) {
    this.parent = new Array(n);
    this.rank = new Array(n).fill(0);

    for (let i = 0; i < n; i++) {
      this.parent[i] = i;
    }
  }

  find(x) {
    if (this.parent[x] !== x) {
      this.parent[x] = this.find(this.parent[x]); // path compression
    }
    return this.parent[x];
  }

  unionSet(x, y) {
    const px = this.find(x);
    const py = this.find(y);

    if (px === py) return;

    if (this.rank[px] < this.rank[py]) {
      this.parent[px] = py;
    } else if (this.rank[px] > this.rank[py]) {
      this.parent[py] = px;
    } else {
      this.parent[py] = px;
      this.rank[px]++;
    }
  }
}
```

---

## Section 9 — Dry Run (Small)

### Operations

```
union(1,2)
union(2,3)
union(4,5)
union(3,5)
```

### Parent (final)

All nodes end up pointing to **one root**, with minimal depth.

---

## Section 10 — Time & Space Complexity (Important)

### Time Complexity

* `find()` → **O(α(n))**
* `union()` → **O(α(n))**
* `α(n)` = Inverse Ackermann function
  → grows **extremely slowly**
  → treated as **constant** in practice

---

### Space Complexity

* Parent array → `O(n)`
* Rank array → `O(n)`

---

## Section 11 — Edge Cases

1. Repeated union on same nodes → safe
2. Find on isolated node → returns itself
3. Large graph → still efficient
4. Chain-like unions → fixed by compression

---

## Section 12 — Interview Perspective

### Must-Know Lines

* “DSU with path compression and union by rank runs in almost constant time.”
* “Rank increases only when both trees have same rank.”
* “Path compression flattens the tree during find.”

---

## Section 13 — Where This Is Used (Very Important)

* Cycle detection (undirected graph)
* Kruskal’s MST
* Dynamic connectivity
* Number of connected components

---

### FINAL COMPARISON (LOCK THIS)

| Feature          | Basic DSU  | Optimized DSU |
| ---------------- | ---------- | ------------- |
| Path Compression | ❌          | ✅             |
| Rank             | ❌          | ✅             |
| Time Complexity  | O(N) worst | ~O(1)         |
| Leader Value     | Unstable   | More stable   |
| Correctness      | ✅          | ✅             |
| Interview Use    | Learning   | Real problems |
