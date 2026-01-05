Below is a **clean, structured `.md` file** for the problem you are explaining in the transcript:

👉 **“Kth Missing Positive Number”**
(Linear + Binary Search approach, interview-ready, clear intuition)

You can directly save this as:

```
Kth_Missing_Positive_Number.md
```

---

# Kth Missing Positive Number

(Binary Search on Index)

---

## 1. Problem Statement

You are given a **strictly increasing array** `arr` of positive integers
and an integer `k`.

### Task

Find the **k-th missing positive number** from the sequence of positive integers.

---

## 2. Examples

### Example 1

```
arr = [2,3,4,7,11]
k = 5
```

**Missing numbers**

```
1, 5, 6, 8, 9, 10, ...
```

**Answer**

```
9
```

---

### Example 2

```
arr = [1,2,3,4]
k = 2
```

**Missing numbers**

```
5, 6, ...
```

**Answer**

```
6
```

---

## 3. Key Observation

If **no numbers were missing**, then:

```
arr[i] should be = i + 1
```

But when numbers are missing:

```
missing_count_at_index_i = arr[i] - (i + 1)
```

This formula tells us:

> **How many positive numbers are missing before index `i`**

---

## 4. Core Intuition

We want the **first index** where:

```
missing_count >= k
```

Because:

* Before this index → fewer than `k` numbers missing
* At / after this index → at least `k` numbers missing

This is a **monotonic condition**, so we can apply **Binary Search**.

---

## 5. Missing Count Formula (Most Important)

For index `i` (0-based):

```
missing = arr[i] - (i + 1)
```

### Example

```
arr = [2,3,4,7,11]

index = 3
arr[3] = 7

missing = 7 - (3+1) = 3
```

Missing numbers before index 3:

```
1, 5, 6
```

---

## 6. Binary Search Logic

### Search Space

```
low = 0
high = n - 1
```

### Decision Rule

| Condition   | Meaning                     | Move           |
| ----------- | --------------------------- | -------------- |
| missing < k | kth missing is to the RIGHT | low = mid + 1  |
| missing ≥ k | possible answer             | high = mid - 1 |

---

## 7. Final Answer Formula

After binary search finishes:

```
answer = low + k
```

Why?

* `low` numbers are present
* `k` numbers are missing
* So the k-th missing number is shifted by `low`

---

## 8. Dry Run

```
arr = [2,3,4,7,11]
k = 5
```

| index | arr[i] | missing = arr[i] - (i+1) |
| ----- | ------ | ------------------------ |
| 0     | 2      | 1                        |
| 1     | 3      | 1                        |
| 2     | 4      | 1                        |
| 3     | 7      | 3                        |
| 4     | 11     | 6                        |

First index where missing ≥ 5 → index = 4

```
answer = low + k = 4 + 5 = 9
```

---

## 9. Full Working Code (C++ – Interview Preferred)

```cpp
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // missing numbers before arr[mid]
            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // kth missing number
        return low + k;
    }
};
```

---

## 10. Linear Scan (For Understanding Only)

```cpp
int findKthPositive(vector<int>& arr, int k) {
    int current = 1;
    int i = 0;

    while (k > 0) {
        if (i < arr.size() && arr[i] == current) {
            i++;
        } else {
            k--;
            if (k == 0) return current;
        }
        current++;
    }
    return -1;
}
```

⛔ Not optimal for large inputs

---

## 11. Complexity Analysis

| Approach          | Time         | Space    |
| ----------------- | ------------ | -------- |
| Linear            | O(n + k)     | O(1)     |
| **Binary Search** | **O(log n)** | **O(1)** |

---

## 12. Pattern Recognition (Very Important)

This problem belongs to:

### **Binary Search on Index with Missing Count**

Same pattern appears in:

* Kth missing number
* First missing positive (variants)
* Missing ranges problems

---

## Final Notes (Interview Mindset)

1. Use formula: `arr[i] - (i+1)`
2. Binary search for first index where missing ≥ k
3. Answer = `low + k`
4. Clean, mathematical, optimal
5. Very common Google / Microsoft problem

---

If you want, next I can create a **single master file** covering:

* Kth missing
* Lower bound
* Upper bound
* Floor / Ceil
  all under **one Binary Search framework**.

Just say the word.
