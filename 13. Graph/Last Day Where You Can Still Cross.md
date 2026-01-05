# PROBLEM (Original Statement)

There is a **1-based binary matrix** where:

* `0` represents **land**
* `1` represents **water**

You are given integers `row` and `col` representing the grid size.

Initially (day 0), the entire matrix is land.

Each day, **one new cell becomes flooded with water**, given by `cells[i] = [ri, ci]` (1-based index), meaning on **day i**, cell `(ri, ci)` becomes water.

You want to find the **last day** such that it is still possible to **walk from the top row to the bottom row** by moving only through land cells.

Rules:

* You can start from **any cell in the top row**
* You can end at **any cell in the bottom row**
* You can move only in **4 directions** (up, down, left, right)

Return the **last day** when crossing is possible.

---

## BREAKDOWN PROBLEM

What is being asked?

* Find the **maximum day `d`** such that after flooding cells `0..d`, there is **still a path of land** from top to bottom.

Input:

* `row`, `col` → grid size
* `cells[]` → flooding order (day-wise)

Output:

* An integer → last valid day to cross

---

## CONSTRAINT UNDERSTANDING

* `2 <= row, col <= 2 * 10^4`
* `row * col <= 2 * 10^4`
* `cells.length = row * col`

### Key implications

* Grid can be **large**
* We **cannot simulate day-by-day DFS/BFS naively** (TLE)
* We need an **optimized strategy**
* Answer is **monotonic**:

  * If crossing is possible on day `d`
  * Then it is also possible on **any day < d**

This monotonic property is crucial.

---

# BRUTE FORCE APPROACH

## First Thought Intuition

Simulate day by day:

* Flood the grid
* Check if there is a path from top to bottom using BFS/DFS

---

## Thought Process (Step-wise)

1. For day `d`, mark first `d` cells as water
2. Run BFS from all land cells in top row
3. If we reach bottom row → crossing possible
4. Repeat for all days

---

## Pseudocode

```
for day = 0 to n:
    mark flooded cells
    if canReachBottom():
        answer = day
```

---

## Algorithm

* Simulate grid for each day
* BFS check connectivity

---

## CODE (C++ and JavaScript)

❌ **Not written intentionally**

---

## Time and Space Complexity

* Time: `O(N * (R*C))` → too large
* Space: `O(R*C)`

---

## Dry Run (All Cases)

Fails for large input.

---

## Edge Cases

Handled, but too slow.

---

## How This Approach Handles the Problem

Correct but inefficient.

---

## Does This Approach Fail?

**YES**

* Time limit exceeded
* Constraint `row * col = 2e4` breaks it

➡️ Move to next approach.

---

# BETTER APPROACH

## First Thought Intuition

Use **Binary Search on Days**.

Why?

* The answer is monotonic:

  * Crossing possible → then impossible forever after some day

---

## Thought Process (Step-wise)

1. Binary search on day `d`
2. For a mid day:

   * Build grid with flooded cells
   * Check if crossing is possible using BFS
3. If possible → try later days
4. Else → try earlier days

---

## Pseudocode

```
low = 0, high = total_days
while low <= high:
    mid = (low + high) / 2
    if canCross(mid):
        answer = mid
        low = mid + 1
    else:
        high = mid - 1
```

---

## Algorithm

* Binary search + BFS validation

---

## CODE (C++ and JavaScript)

---

### C++

#### V1 (Only Required Function)

```cpp
bool canCross(int day, int row, int col, vector<vector<int>>& cells) {
    vector<vector<int>> grid(row, vector<int>(col, 0));

    for (int i = 0; i < day; i++) {
        grid[cells[i][0]-1][cells[i][1]-1] = 1;
    }

    queue<pair<int,int>> q;
    vector<vector<bool>> vis(row, vector<bool>(col, false));

    for (int c = 0; c < col; c++) {
        if (grid[0][c] == 0) {
            q.push({0, c});
            vis[0][c] = true;
        }
    }

    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        if (r == row - 1) return true;

        for (auto& d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
                !vis[nr][nc] && grid[nr][nc] == 0) {
                vis[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

    return false;
}

int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
    int low = 0, high = cells.size(), ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (canCross(mid, row, col, cells)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
```

---

### JavaScript

#### V1 (Only Required Function)

```js
var latestDayToCross = function(row, col, cells) {
    const dirs = [[1,0],[-1,0],[0,1],[0,-1]];

    function canCross(day) {
        const grid = Array.from({length: row}, () => Array(col).fill(0));
        for (let i = 0; i < day; i++) {
            const [r, c] = cells[i];
            grid[r-1][c-1] = 1;
        }

        const queue = [];
        const vis = Array.from({length: row}, () => Array(col).fill(false));

        for (let c = 0; c < col; c++) {
            if (grid[0][c] === 0) {
                queue.push([0, c]);
                vis[0][c] = true;
            }
        }

        while (queue.length) {
            const [r, c] = queue.shift();
            if (r === row - 1) return true;

            for (const [dr, dc] of dirs) {
                const nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
                    !vis[nr][nc] && grid[nr][nc] === 0) {
                    vis[nr][nc] = true;
                    queue.push([nr, nc]);
                }
            }
        }
        return false;
    }

    let low = 0, high = cells.length, ans = 0;
    while (low <= high) {
        const mid = Math.floor((low + high) / 2);
        if (canCross(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
};
```

---

## Time and Space Complexity

* Time: `O(logN * R * C)`
* Space: `O(R * C)`

---

## Dry Run (All Cases)

Works but still **heavy**.

---

## Edge Cases

Handled.

---

## How This Approach Handles the Problem

Uses monotonicity + BFS.

---

## Does This Approach Fail?

**YES (borderline TLE in worst cases)**

Because BFS is repeated `logN` times.

➡️ Move to optimal.

---

# OPTIMAL APPROACH

## First Thought Intuition

Reverse the process.

Instead of **flooding day by day**,
**unflood from last day to first**.

Use **Union Find (DSU)** to track connectivity.

---

## Thought Process (Step-wise)

1. Start with **all cells flooded**
2. Unflood one cell per day (reverse order)
3. Union adjacent land cells
4. Track:

   * Any land cell in top row connected to bottom row?
5. The moment it becomes true → that day is the answer

---

## Pseudocode

```
mark all as water
for day from last to first:
    make cell land
    union with neighbors
    if top connected to bottom:
        return day
```

---

## Algorithm

* DSU with path compression
* Two virtual nodes:

  * Top
  * Bottom

---

## CODE (C++ and JavaScript)

---

### C++

#### V1 (Only Required Function)

```cpp
int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
    int n = row * col;
    vector<int> parent(n + 2);
    iota(parent.begin(), parent.end(), 0);

    auto find = [&](int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    };

    auto unite = [&](int a, int b) {
        a = find(a); b = find(b);
        if (a != b) parent[a] = b;
    };

    vector<vector<bool>> land(row, vector<bool>(col, false));
    int top = n, bottom = n + 1;

    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    for (int d = n - 1; d >= 0; d--) {
        int r = cells[d][0] - 1;
        int c = cells[d][1] - 1;
        land[r][c] = true;
        int idx = r * col + c;

        if (r == 0) unite(idx, top);
        if (r == row - 1) unite(idx, bottom);

        for (auto& dir : dirs) {
            int nr = r + dir[0], nc = c + dir[1];
            if (nr >= 0 && nr < row && nc >= 0 && nc < col && land[nr][nc]) {
                unite(idx, nr * col + nc);
            }
        }

        if (find(top) == find(bottom)) return d;
    }
    return 0;
}
```

---

### JavaScript

#### V1 (Only Required Function)

```js
var latestDayToCross = function(row, col, cells) {
    const n = row * col;
    const parent = Array(n + 2).fill(0).map((_, i) => i);

    function find(x) {
        if (parent[x] !== x) parent[x] = find(parent[x]);
        return parent[x];
    }

    function union(a, b) {
        a = find(a);
        b = find(b);
        if (a !== b) parent[a] = b;
    }

    const land = Array.from({length: row}, () => Array(col).fill(false));
    const top = n, bottom = n + 1;
    const dirs = [[1,0],[-1,0],[0,1],[0,-1]];

    for (let d = n - 1; d >= 0; d--) {
        const [r, c] = cells[d];
        const rr = r - 1, cc = c - 1;
        land[rr][cc] = true;
        const idx = rr * col + cc;

        if (rr === 0) union(idx, top);
        if (rr === row - 1) union(idx, bottom);

        for (const [dr, dc] of dirs) {
            const nr = rr + dr, nc = cc + dc;
            if (nr >= 0 && nr < row && nc >= 0 && nc < col && land[nr][nc]) {
                union(idx, nr * col + nc);
            }
        }

        if (find(top) === find(bottom)) return d;
    }
    return 0;
};
```

---

## Time and Space Complexity

* **Time:** `O(R * C * α(N))` ≈ linear
* **Space:** `O(R * C)`

---

## Dry Run (All Cases)

Works efficiently even at max constraints.

---

## Edge Cases

* Single column
* Immediate disconnect
* Late reconnection

All handled.

---

## How This Approach Handles the Problem

* Avoids repeated BFS
* Uses connectivity logic
* Reverses time to make problem easy

---

## Why This Is Optimal

* Each cell processed once
* DSU operations are nearly constant
* Matches constraint limits perfectly

---