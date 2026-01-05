
# LeetCode 840 — Magic Squares in Grid

## 1. Problem Definition

A **3 × 3 magic square** is a grid that satisfies:

1. Contains **only numbers from 1 to 9**
2. All numbers are **distinct**
3. Sum of:

   * Each row
   * Each column
   * Both diagonals
     is the **same**

You are given a 2D grid.
Task: **Count how many 3 × 3 subgrids are magic squares**.

---

## 2. Key Observations

### 2.1 Size Constraint

* Only **3 × 3** grids matter
* So for a grid of size `rows × cols`:

  * Top-left corner `(i, j)` of a 3×3 grid must satisfy:

    ```
    i ≤ rows - 3
    j ≤ cols - 3
    ```

---

### 2.2 Brute Force is Enough

* Total grids checked: `(rows - 2) × (cols - 2)`
* Each grid check is **constant time**
* Overall complexity: **O(m × n)**

---

## 3. High-Level Algorithm

1. Loop over all possible top-left positions `(i, j)`
2. For each `(i, j)`:

   * Check if the 3×3 grid starting there is a **magic square**
3. Count valid magic squares

---

## 4. Magic Square Validation Logic

Given a starting cell `(r, c)`:

### Step 1: Distinct & Range Check

* Use a set
* All values must be in `[1, 9]`
* No duplicates allowed

---

### Step 2: Row Sums

* All 3 rows must have the same sum

---

### Step 3: Column Sums

* All 3 columns must have the same sum

---

### Step 4: Diagonals

* Main diagonal sum must match
* Anti-diagonal sum must match

If **any check fails → not magic**

---

## 5. C++ Implementation (Clean + Commented)

```cpp
class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int r, int c) {
        unordered_set<int> seen;

        // Step 1: Range and uniqueness check
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int val = grid[r + i][c + j];
                if (val < 1 || val > 9 || seen.count(val))
                    return false;
                seen.insert(val);
            }
        }

        // Sum of first row
        int sum = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];

        // Step 2: Check all rows
        for (int i = 0; i < 3; i++) {
            int rowSum = grid[r + i][c] +
                         grid[r + i][c + 1] +
                         grid[r + i][c + 2];
            if (rowSum != sum)
                return false;
        }

        // Step 3: Check all columns
        for (int j = 0; j < 3; j++) {
            int colSum = grid[r][c + j] +
                         grid[r + 1][c + j] +
                         grid[r + 2][c + j];
            if (colSum != sum)
                return false;
        }

        // Step 4: Diagonals
        int diag1 = grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2];
        int diag2 = grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c];

        if (diag1 != sum || diag2 != sum)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                if (isMagic(grid, i, j))
                    count++;
            }
        }

        return count;
    }
};
```

---

## 6. JavaScript Implementation (Clean)

```js
var numMagicSquaresInside = function(grid) {
    const rows = grid.length;
    const cols = grid[0].length;
    let count = 0;

    function isMagic(r, c) {
        const seen = new Set();

        // Range & uniqueness
        for (let i = 0; i < 3; i++) {
            for (let j = 0; j < 3; j++) {
                const val = grid[r + i][c + j];
                if (val < 1 || val > 9 || seen.has(val)) return false;
                seen.add(val);
            }
        }

        const sum =
            grid[r][c] + grid[r][c + 1] + grid[r][c + 2];

        // Rows
        for (let i = 0; i < 3; i++) {
            const rowSum =
                grid[r + i][c] +
                grid[r + i][c + 1] +
                grid[r + i][c + 2];
            if (rowSum !== sum) return false;
        }

        // Columns
        for (let j = 0; j < 3; j++) {
            const colSum =
                grid[r][c + j] +
                grid[r + 1][c + j] +
                grid[r + 2][c + j];
            if (colSum !== sum) return false;
        }

        // Diagonals
        const diag1 =
            grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2];
        const diag2 =
            grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c];

        return diag1 === sum && diag2 === sum;
    }

    for (let i = 0; i <= rows - 3; i++) {
        for (let j = 0; j <= cols - 3; j++) {
            if (isMagic(i, j)) count++;
        }
    }

    return count;
};
```

---

## 7. Time & Space Complexity

### Time Complexity

```
O(m × n)
```

* Each 3×3 check is constant time

### Space Complexity

```
O(1)
```

* Set size ≤ 9 (constant)

---

## 8. Interview Notes

* Brute force works due to **fixed grid size**
* Must check **distinctness + range**
* Diagonals are commonly missed
* Clean boundary handling is key

---
* Primary Topic - Matrix / 2D Grid Traversal

---

# Dry Run — Magic Squares in Grid

We use this function logic:

```
numMagicSquaresInside(grid)
```

It checks **every possible 3×3 subgrid** and counts how many are magic.

---

## Case 1: Given Example (ONE valid magic square)

### Input

```
grid =
[
  [4, 3, 8, 4],
  [9, 5, 1, 9],
  [2, 7, 6, 2]
]
```

Rows = 3, Cols = 4

---

### Step 1: Loop boundaries

We can only start a 3×3 grid when:

```
i <= rows - 3 = 0
j <= cols - 3 = 1
```

So possible starting points:

```
(i, j) = (0,0) and (0,1)
```

---

### Subgrid 1 → start at (0,0)

```
4 3 8
9 5 1
2 7 6
```

#### ✔ Step A: Range + uniqueness check

* Elements = {1,2,3,4,5,6,7,8,9}
* All in range [1,9]
* All distinct → PASS

#### ✔ Step B: Row sums

```
Row1: 4+3+8 = 15
Row2: 9+5+1 = 15
Row3: 2+7+6 = 15
```

PASS

#### ✔ Step C: Column sums

```
Col1: 4+9+2 = 15
Col2: 3+5+7 = 15
Col3: 8+1+6 = 15
```

PASS

#### ✔ Step D: Diagonals

```
Main: 4+5+6 = 15
Anti: 8+5+2 = 15
```

PASS

✅ **Magic square found → count = 1**

---

### Subgrid 2 → start at (0,1)

```
3 8 4
5 1 9
7 6 2
```

#### ❌ Step A: Range + uniqueness

* Values include duplicates / invalid sum pattern
* Even if distinct, sums will fail

Check row sum:

```
3+8+4 = 15
5+1+9 = 15
7+6+2 = 15
```

Now diagonals:

```
3+1+2 = 6 ❌
```

❌ **Not magic**

---

### Final Answer

```
Output = 1
```

---

## Case 2: No Magic Square

### Input

```
grid =
[
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]
```

Only one 3×3 grid.

#### Range + uniqueness → PASS

#### Row sums:

```
1+2+3 = 6
4+5+6 = 15 ❌
```

❌ **Not magic**

### Output

```
0
```

---

## Case 3: Invalid number (>9)

### Input

```
grid =
[
  [10, 3, 5],
  [4,  9, 2],
  [1,  7, 6]
]
```

#### Range check:

```
10 > 9 ❌
```

❌ Immediately rejected

### Output

```
0
```

---

## Case 4: Duplicate numbers

### Input

```
grid =
[
  [2, 7, 6],
  [9, 5, 1],
  [4, 3, 2]   ← duplicate 2
]
```

#### Uniqueness check:

```
2 appears twice ❌
```

### Output

```
0
```

---

## Case 5: Small grid (<3×3)

### Input

```
grid =
[
  [1, 2],
  [3, 4]
]
```

Rows < 3 or Cols < 3
Loop never runs.

### Output

```
0
```

---

## Case 6: Multiple magic squares

### Input

```
grid =
[
  [8, 1, 6, 8, 1],
  [3, 5, 7, 3, 5],
  [4, 9, 2, 4, 9],
  [8, 1, 6, 8, 1]
]
```

Valid magic squares found at:

```
(0,0), (0,2), (1,0), (1,2)
```

### Output

```
4
```

---

## Summary of All Cases

| Case | Description                 | Result |
| ---- | --------------------------- | ------ |
| 1    | Valid single magic square   | 1      |
| 2    | Correct size but wrong sums | 0      |
| 3    | Number out of range         | 0      |
| 4    | Duplicate numbers           | 0      |
| 5    | Grid too small              | 0      |
| 6    | Multiple magic squares      | >1     |

---

## Interview One-Line Dry Run Explanation

> We slide a 3×3 window across the grid, and for each window we validate range, uniqueness, row sums, column sums, and diagonal sums. Each valid window increases the count.

---
