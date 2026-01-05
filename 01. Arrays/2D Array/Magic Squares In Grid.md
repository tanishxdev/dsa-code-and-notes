
# 840. Magic Squares In Grid — Complete Thinking + Solution Notes

---

## 1. Problem ko dimaag se samjho (pehle hi filter)

* Humein **sirf 3×3 subgrids** consider karni hain
* Grid ka max size **10×10** hai → brute force allowed
* Har possible **top-left (i, j)** se ek 3×3 window uthayi ja sakti hai

### Core idea:

> “Har 3×3 window ko uthao → check karo magic square hai ya nahi”

---

## 2. Magic square ka HARD truth (non-negotiable rule)

### Rule:

**1–9 ke numbers se bana 3×3 magic square ka sum hamesha 15 hota hai**

### Why?

* 1 to 9 ka total sum = 45
* 3 rows ⇒ har row ka sum = 45 / 3 = **15**

### Conclusion:

* Row sum = 15
* Column sum = 15
* Diagonal sum = 15

Isliye:

> “same sum” compare karne ke bajaye **direct 15 se compare** karo

---

## 3. Step 1: Range + Distinct check (gatekeeper logic)

### Condition:

* Har number **1 se 9 ke beech** hona chahiye
* Har number **distinct** hona chahiye

### Why pehle?

* Agar ek bhi number rule todta hai → magic square **impossible**
* Sum calculate karna bekaar ka kaam ho jaata hai

### Mental model:

> “Magic square ka membership card: sirf 1–9 allowed”

---

## 4. Step 2: Center element ka secret (INTERVIEW GOLD)

### Rule:

**3×3 magic square ka center hamesha 5 hota hai**

```cpp
if (grid[i+1][j+1] != 5) → reject
```

---

### Step 2 — In depth explanation

#### Facts:

* Numbers: 1 to 9
* Sab distinct
* Har row / column / diagonal ka sum = 15

#### Center ka role:

Center element:

* Row 2 ka part
* Column 2 ka part
* Main diagonal ka part
* Anti-diagonal ka part

> Center **4 different sums** ka common element hota hai

#### Pair logic:

```
a  b  c
d  X  e
f  g  h
```

Diagonal equations:

```
a + X + h = 15
c + X + f = 15
```

Subtract:

```
a + h = c + f
```

Same balancing rows & columns me bhi hota hai.

#### Result:

Center ko **exact middle value** hona chahiye.

#### 1–9 ka middle:

```
1 2 3 4 5 6 7 8 9
```

Middle = **5**

### Final conclusion:

> Har valid 3×3 magic square (1–9) ka center **5** hota hi hota hai.

---

### Interview one-liner:

> “The center of a 3×3 magic square using numbers 1 to 9 must be 5 because it participates in all rows, columns, and diagonals and balances the sum to 15.”

---

## 5. Step 3: Tumhari original intuition (correct but refine)

Tumhari thinking:

> “Agar row1 ka sum ≠ row2, to aage check karna useless”

### Corrected professional version:

* Row1 == 15
* Row2 == 15
* Row3 == 15
* Same for columns & diagonals

### Key improvement:

> **Compare sab ko 15 se karo**, aapas me nahi

---

## 6. Step 4: Order of checks (thinking like a pro)

Correct elimination order:

1. 3×3 window exist karta hai?
2. Center == 5 ?
3. All numbers ∈ [1,9] ?
4. All numbers distinct ?
5. Rows / Columns / Diagonals sum == 15 ?

Jo fail ho → turant reject
Jo pass ho → count++

---

## 7. Matrix basics clarification (rows & cols)

```cpp
int rows = grid.size();
int cols = grid[0].size();
```

### Why `grid[0]`?

* `grid` = vector of rows
* `grid[i]` = ek poori row
* Columns = ek row ke andar elements

So:

* rows = kitni rows
* cols = first row ki length

Problem guarantee karta hai grid empty nahi hoga.

---

## 8. PSEUDOCODE (thinking → structure)

```text
function numMagicSquaresInside(grid):
    rows = grid rows
    cols = grid columns
    count = 0

    for i = 0 to rows - 3:
        for j = 0 to cols - 3:

            if center != 5:
                continue

            if any number not in 1..9 OR duplicate:
                continue

            if any row sum != 15:
                continue

            if any column sum != 15:
                continue

            if diagonal sums != 15:
                continue

            count++

    return count
```

---

## 9. C++ Code (clean + deeply commented)

```cpp
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {

                // Step 1: Center must be 5
                if (grid[i + 1][j + 1] != 5) continue;

                bool used[10] = {false}; // index 1..9
                bool valid = true;

                // Step 2: Range + distinct check
                for (int r = i; r < i + 3 && valid; r++) {
                    for (int c = j; c < j + 3; c++) {
                        int val = grid[r][c];

                        if (val < 1 || val > 9 || used[val]) {
                            valid = false;
                            break;
                        }
                        used[val] = true;
                    }
                }
                if (!valid) continue;

                // Step 3: Row sums
                for (int r = i; r < i + 3; r++) {
                    int sum = 0;
                    for (int c = j; c < j + 3; c++) sum += grid[r][c];
                    if (sum != 15) { valid = false; break; }
                }
                if (!valid) continue;

                // Step 4: Column sums
                for (int c = j; c < j + 3; c++) {
                    int sum = 0;
                    for (int r = i; r < i + 3; r++) sum += grid[r][c];
                    if (sum != 15) { valid = false; break; }
                }
                if (!valid) continue;

                // Step 5: Diagonals
                int d1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
                int d2 = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];

                if (d1 == 15 && d2 == 15) {
                    count++;
                }
            }
        }
        return count;
    }
};
```

---

## 10. Time & Space Complexity (in-depth)

### Time Complexity:

* Max windows = (rows-2) × (cols-2) ≤ 8×8 = 64
* Har window me constant checks (9 cells)

**TC = O(R × C)**
(R, C ≤ 10)

### Space Complexity:

* `used[10]` array

**SC = O(1)**

---

## 11. Final Mental Model (most important)

> Magic square ek dynamic problem nahi hai
> Ye **fixed rules ka pattern matching** problem hai

Isliye:

* Early rejection
* Strong invariants
* Minimal computation

---

### Tumne jo seekha (real gain)

* Mathematical invariant ka use
* Brute force ko intelligent banana
* Interview-level optimization thinking
* Code likhne se pehle **problem ko todna**

---