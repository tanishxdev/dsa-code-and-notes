

## 2️⃣ Correct Mental Model (THIS IS THE KEY)

This problem is **NOT grid DP cell-by-cell**.

It is:

> **Row-by-row DP with fixed width (3 columns)**

Because:

* Width = 3 (constant)
* Height = n (up to 5000)

So we classify **row color patterns**, not individual cells.

---

## 3️⃣ The Only Two Valid Row Types

For a row of 3 cells with 3 colors:

### Type A — All 3 colors different

Example: `R Y G`

* Count = **6** (3! permutations)

### Type B — First and third same, middle different

Example: `R Y R`

* Count = **6**

No other patterns are valid (adjacent cannot be same).

---

## 4️⃣ DP State Definition (Interview Gold)

Let:

```
dpA[i] = number of ways where row i is Type A
dpB[i] = number of ways where row i is Type B
```

### Base Case (n = 1)

```
dpA = 6
dpB = 6
```

---

## 5️⃣ DP Transitions (MOST IMPORTANT PART)

From previous row to current row:

```
new_dpA = dpA * 2 + dpB * 2
new_dpB = dpA * 2 + dpB * 3
```

Why?

* Carefully count how many colorings are allowed vertically
* This is the crux interviewers test

---

## 6️⃣ Final Answer

```
answer = (dpA + dpB) % MOD
```

---

## 7️⃣ Clean C++ Code (Platform-Ready)

### ✅ V1 — Required Function Only

```cpp
class Solution
{
public:
    int numOfWays(int n)
    {
        const int MOD = 1e9 + 7;

        long long dpA = 6; // all three different
        long long dpB = 6; // first and third same

        for (int i = 2; i <= n; i++)
        {
            long long newA = (dpA * 2 + dpB * 2) % MOD;
            long long newB = (dpA * 2 + dpB * 3) % MOD;
            dpA = newA;
            dpB = newB;
        }

        return (dpA + dpB) % MOD;
    }
};
```

---

## 8️⃣ What NOT to Do (Common Mistakes)

* ❌ Trying 3D DP on grid → unnecessary
* ❌ Backtracking → TLE
* ❌ Thinking in terms of cells → wrong abstraction

This is a **pattern-counting DP**, not grid traversal.

---

## 9️⃣ Final Google Sheet Row Example

| Problem             | Topic               | Pattern                            | Status |
| ------------------- | ------------------- | ---------------------------------- | ------ |
| 1411 Paint N×3 Grid | Dynamic Programming | DP with State Compression (Row DP) | SOLVED |

---

## 🔑 One-Line Recall Rule (For Revision)

> “Only 2 row types → DP on rows, not cells.”

If this line instantly clicks, you’re good.

