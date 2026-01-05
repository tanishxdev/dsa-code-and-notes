Below is the **clean, structured `.md` notes file** for
**Finding Square Root of a Number using Binary Search**, written **exactly in your established Binary Search notes style**
(intuition-first, why/how, dry run, edge cases, interview-ready).

You can directly save this as:
`Sqrt_of_Number_Using_Binary_Search.md`

---

# Square Root of a Number (Binary Search)

---

## 1. Problem Statement

**English**:
You are given a **positive integer `n`**.
Find and return the **floor value of `sqrt(n)`**.

* If `n` is a perfect square → return exact square root
* Otherwise → return **floor of square root**

**Hinglish**:
Ek number `n` diya hai → uska square root nikaalo.
Agar perfect square nahi hai → **floor value** return karo.

---

## 2. Examples (Must Know)

| Input    | Output | Explanation                   |
| -------- | ------ | ----------------------------- |
| `n = 36` | `6`    | `6 × 6 = 36`                  |
| `n = 28` | `5`    | `sqrt(28) ≈ 5.29` → floor = 5 |
| `n = 1`  | `1`    | base case                     |
| `n = 0`  | `0`    | base case                     |
| `n = 2`  | `1`    | `1² ≤ 2 < 2²`                 |

---

## 3. Brute Force Approach (For Understanding)

### 3.1 Intuition

> Square root of `n` will lie between **1 and n**.

We try all numbers from `1` to `n` and:

* keep updating answer while `i*i <= n`
* stop when `i*i > n`

---

### 3.2 Algorithm

```text
ans = 0
for i = 1 to n:
    if i*i <= n:
        ans = i
    else:
        break
return ans
```

---

### 3.3 C++ Code (Brute Force)

```cpp
int floorSqrt(int n) {
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if ((long long)i * i <= n)
            ans = i;
        else
            break;
    }
    return ans;
}
```

---

### 3.4 Complexity

| Metric | Value |
| ------ | ----- |
| Time   | O(N)  |
| Space  | O(1)  |

❌ **Too slow for large `n`**
❌ Not acceptable in interviews

---

## 4. Core Intuition (Binary Search Thinking)

> This is a **Binary Search on Answer** problem.

### Why Binary Search works here?

* Possible answers lie in range **[1 … n]**
* This range is **sorted**
* If `mid² <= n`, then **all values smaller than mid also work**
* If `mid² > n`, then **all larger values fail**

👉 This monotonic behavior allows Binary Search.

---

### What exactly are we finding?

> **Largest integer `x` such that `x² ≤ n`**

This is exactly the **FLOOR of sqrt(n)**.

---

### Direction Logic

| Condition        | Meaning      | Move         |
| ---------------- | ------------ | ------------ |
| `mid * mid <= n` | valid answer | go **RIGHT** |
| `mid * mid > n`  | too big      | go **LEFT**  |

---

## 5. Algorithm (Binary Search – Optimal)

```text
if n < 2: return n

low = 1, high = n
ans = 0

while(low <= high):
    mid = low + (high-low)/2

    if mid*mid <= n:
        ans = mid
        low = mid + 1     // try bigger value
    else:
        high = mid - 1

return ans
```

---

## 6. Dry Run

### Example: `n = 28`

| low | high | mid | mid² | ≤ 28? | ans | move  |
| --- | ---- | --- | ---- | ----- | --- | ----- |
| 1   | 14   | 7   | 49   | No    | 0   | left  |
| 1   | 6    | 3   | 9    | Yes   | 3   | right |
| 4   | 6    | 5   | 25   | Yes   | 5   | right |
| 6   | 6    | 6   | 36   | No    | 5   | left  |

➡ Loop ends → **answer = 5**

---

## 7. Full Working Code

### C++ (Interview Preferred)

```cpp
class Solution {
public:
    int mySqrt(int n) {

        // Handle base cases
        if (n < 2) return n;

        int low = 1, high = n / 2;
        int ans = 0;

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            if (mid * mid <= n) {
                ans = mid;        // possible answer
                low = mid + 1;    // try larger value
            } else {
                high = mid - 1;   // too large
            }
        }
        return ans;
    }
};
```

---

### JavaScript

```js
function floorSqrt(n) {

    if (n < 2) return n;

    let low = 1, high = Math.floor(n / 2);
    let ans = 0;

    while (low <= high) {

        let mid = low + Math.floor((high - low) / 2);

        if (mid * mid <= n) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

// Test
console.log(floorSqrt(28)); // 5
console.log(floorSqrt(36)); // 6
```

---

## 8. Edge Cases Covered

| Case               | Output                  |
| ------------------ | ----------------------- |
| `n = 0`            | 0                       |
| `n = 1`            | 1                       |
| Perfect square     | exact root              |
| Non-perfect square | floor value             |
| Large `n`          | safe due to `long long` |

---

## 9. Complexity Analysis

| Approach          | Time         | Space    |
| ----------------- | ------------ | -------- |
| Brute Force       | O(N)         | O(1)     |
| **Binary Search** | **O(log N)** | **O(1)** |

---

## 10. Interview Connections (Very Important)

1. **Binary Search on Answer pattern**

   * Painters partition
   * Allocate books
   * Koko eating bananas

2. **Why use `long long`?**

   * `mid * mid` can overflow `int`

3. **Why `high = n/2`?**

   * For `n > 1`, `sqrt(n)` ≤ `n/2`

---

## Final Notes (Yaad Rakhna)

1. This is **NOT array binary search**
2. This is **Binary Search on value range**
3. Goal → **largest x where `x² ≤ n`**
4. On valid → go **RIGHT**
5. Very common interview problem

---

### Next Perfect Topic (Flow Wise)

* **Nth Root of a Number**
* **Binary Search on Answer (general pattern)**
* **Koko Eating Bananas**

Tell me what you want next.
