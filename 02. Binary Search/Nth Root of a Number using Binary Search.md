Below is the **clean, structured `.md` notes file** for
**Nth Root of a Number using Binary Search**, written **exactly in your established DSA + Binary Search style**
(intuition-first, why/how, dry run, edge cases, interview-ready).

You can directly save this as:
`Nth_Root_of_a_Number_Using_Binary_Search.md`

---

# Nth Root of a Number (Binary Search)

---

## 1. Problem Statement

**English**:
Given two integers `N` and `M`, find the **Nth root of M**.

The Nth root of M is a number `X` such that:

```
X^N = M
```

* If the Nth root is an **integer**, return it
* Otherwise, return **-1**

**Hinglish**:
Do numbers `N` aur `M` diye hain.
Aisa integer `X` dhoondo jiska:

```
X^N = M
```

Agar exact integer root exist karta hai → return `X`
Nahi karta → return `-1`

---

## 2. Examples (Must Know)

| N | M  | Output | Explanation     |
| - | -- | ------ | --------------- |
| 2 | 16 | 4      | `4² = 16`       |
| 3 | 27 | 3      | `3³ = 27`       |
| 3 | 28 | -1     | No integer root |
| 4 | 81 | 3      | `3⁴ = 81`       |
| 1 | 5  | 5      | `5¹ = 5`        |

---

## 3. Brute Force Approach (For Understanding)

### 3.1 Intuition

> Try every possible value `x` starting from `1` and check
> whether `x^N == M`.

As soon as `x^N > M`, we can stop because values will only increase.

---

### 3.2 Algorithm

```text
for x from 1 to M:
    compute x^N
    if x^N == M:
        return x
    if x^N > M:
        break
return -1
```

---

### 3.3 C++ Code (Brute Force)

```cpp
int nthRoot(int n, int m) {
    for (int i = 1; i <= m; i++) {

        long long power = pow(i, n);

        if (power == m)
            return i;

        if (power > m)
            break;
    }
    return -1;
}
```

---

### 3.4 Complexity

| Metric | Value |
| ------ | ----- |
| Time   | O(M)  |
| Space  | O(1)  |

❌ **Very slow for large M**
❌ Not acceptable in interviews

---

## 4. Core Intuition (Binary Search Thinking)

> This is a classic **Binary Search on Answer** problem.

---

### 4.1 Why Binary Search works here?

* Possible answers lie between **1 and M**
* This range is **sorted**
* If `mid^N < M` → all smaller values also fail
* If `mid^N > M` → all larger values fail

This **monotonic behavior** allows Binary Search.

---

### 4.2 What exactly are we finding?

> **An integer `X` such that `X^N == M`**

Not:

* floor root
* approximate root

👉 **Exact integer root only**

---

### 4.3 Direction Logic

| Condition    | Meaning    | Move       |
| ------------ | ---------- | ---------- |
| `mid^N == M` | exact root | return mid |
| `mid^N < M`  | too small  | RIGHT      |
| `mid^N > M`  | too big    | LEFT       |

---

### 4.4 Important Difference from sqrt

| Problem      | Output                         |
| ------------ | ------------------------------ |
| Square Root  | floor value allowed            |
| **Nth Root** | **only exact integer allowed** |

---

## 5. Algorithm (Binary Search – Optimal)

```text
low = 1, high = M

while(low <= high):
    mid = (low + high) / 2
    compute mid^N safely

    if mid^N == M:
        return mid
    else if mid^N < M:
        low = mid + 1
    else:
        high = mid - 1

return -1
```

---

## 6. Safe Power Calculation (Very Important)

> **Never use `pow(mid, N)` in interviews**

Reason:

* Uses floating point
* Causes precision errors
* Overflow risk

### Correct Way

```text
ans = 1
repeat N times:
    ans = ans * mid
    if ans > M:
        break
```

---

## 7. Dry Run

### Example: `N = 3, M = 27`

| low | high | mid | mid³ | Comparison | Move     |
| --- | ---- | --- | ---- | ---------- | -------- |
| 1   | 27   | 14  | >27  | too big    | left     |
| 1   | 13   | 7   | >27  | too big    | left     |
| 1   | 6    | 3   | 27   | equal      | return 3 |

---

## 8. Full Working Code

### C++ (Interview Preferred)

```cpp
class Solution {
public:
    int nthRoot(int n, int m) {

        int low = 1, high = m;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long val = 1;

            // Compute mid^n safely
            for (int i = 0; i < n; i++) {
                val *= mid;
                if (val > m)
                    break;
            }

            if (val == m)
                return mid;

            else if (val < m)
                low = mid + 1;

            else
                high = mid - 1;
        }
        return -1;
    }
};
```

---

### JavaScript

```js
function nthRoot(n, m) {

    let low = 1, high = m;

    while (low <= high) {

        let mid = low + Math.floor((high - low) / 2);
        let val = 1;

        // Compute mid^n safely
        for (let i = 0; i < n; i++) {
            val *= mid;
            if (val > m)
                break;
        }

        if (val === m)
            return mid;
        else if (val < m)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Test
console.log(nthRoot(3, 27)); // 3
console.log(nthRoot(3, 28)); // -1
```

---

## 9. Edge Cases Covered

| Case            | Output                     |
| --------------- | -------------------------- |
| `M = 0`         | 0                          |
| `N = 1`         | M                          |
| No integer root | -1                         |
| Large M         | safe due to overflow check |

---

## 10. Complexity Analysis

| Approach          | Time             | Space    |
| ----------------- | ---------------- | -------- |
| Brute Force       | O(M)             | O(1)     |
| **Binary Search** | **O(log M × N)** | **O(1)** |

---

## 11. Interview Connections (Very Important)

1. **Binary Search on Answer**

   * Square root
   * Nth root
   * Koko Eating Bananas
   * Min days / capacity problems

2. **Overflow handling is mandatory**

   * Always multiply step-by-step
   * Break early if exceeds M

3. **Why exact match only?**

   * Problem explicitly asks for integer root

---

## Final Notes (Yaad Rakhna)

1. This is **Binary Search on value range**
2. Goal → **exact integer root**
3. `mid^N` must be computed safely
4. On match → return immediately
5. Very common interview problem

---

⚠️ Common Mistakes (Very Important)

❌ Using pow(i, n) directly
→ floating point error

❌ Not stopping power calculation early
→ overflow

❌ Searching beyond m
→ unnecessary iterations