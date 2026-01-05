# Capacity to Ship Packages Within D Days

(Binary Search on Answer)

---

## 1. Problem Statement

You are given:

* An array `weights[]` where `weights[i]` is the weight of the `i-th` package
* An integer `d` representing the number of days

Rules:

* Packages must be shipped **in the given order**
* A package **cannot be split**
* Each day, the total weight shipped must not exceed the ship’s capacity

### Task

Find the **minimum ship capacity** such that **all packages can be shipped within `d` days**.

---

## 2. Examples

### Example 1

```
weights = [5,4,5,2,3,4,5,6]
d = 5
```

**Output**

```
9
```

**Explanation**
With capacity `9`, packages can be shipped in 5 days.

---

### Example 2

```
weights = [1,2,3,4,5]
d = 2
```

**Output**

```
9
```

**Explanation**

```
Day 1 → [1,2,3,4]
Day 2 → [5]
```

---

## 3. Key Observations

1. Capacity **cannot be less than the heaviest package**
2. Capacity **need not exceed sum of all packages**
3. As capacity increases → required days **decrease**
4. The relationship is **monotonic**

```
capacity ↑  →  days needed ↓
```

👉 This monotonic behavior enables **Binary Search on Answer**

---

## 4. Why Binary Search on Answer?

We are **not searching in the array**
We are searching for the **minimum valid ship capacity**

### Search Space

```
minimum capacity = max(weights)
maximum capacity = sum(weights)
```

---

### Decision Logic

| Condition | Meaning            | Move                    |
| --------- | ------------------ | ----------------------- |
| days ≤ d  | capacity works     | move LEFT (try smaller) |
| days > d  | capacity too small | move RIGHT (increase)   |

---

## 5. Brute Force Approach (For Understanding)

### Idea

Try every possible capacity from `max(weights)` to `sum(weights)`
For each capacity, simulate shipping and count days.

### Complexity

```
Time  → O((sum - max) × N)
Space → O(1)
```

❌ Too slow
❌ Not interview-friendly

---

## 6. Core Intuition (Binary Search Thinking)

> We want the **minimum capacity** that can ship all packages in `d` days.

* If a capacity works → **larger capacities will also work**
* If a capacity fails → **smaller capacities will fail**

```
false false false true true true
```

Classic **minimum valid value** pattern.

---

## 7. Helper Function – Days Needed

Given a capacity, calculate how many days are required.

### Logic

* Start with day = 1
* Keep adding package weights
* If capacity exceeded → start a new day

---

## 8. Binary Search Algorithm

```text
low = max(weights)
high = sum(weights)

while low < high:
    mid = (low + high) / 2

    if daysNeeded(mid) <= d:
        high = mid        // try smaller capacity
    else:
        low = mid + 1     // capacity too small

return low
```

---

## 9. Full Working Code (C++ – Interview Preferred)

```cpp
class Solution {
public:
    // Helper function to calculate required days for a given capacity
    int daysNeeded(vector<int>& weights, int capacity) {
        int days = 1;          // start with first day
        int currentLoad = 0;   // current load for the day

        for (int w : weights) {
            if (currentLoad + w > capacity) {
                days++;        // new day required
                currentLoad = w;
            } else {
                currentLoad += w;
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int d) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (daysNeeded(weights, mid) <= d) {
                high = mid;      // try smaller capacity
            } else {
                low = mid + 1;   // need larger capacity
            }
        }
        return low;
    }
};
```

---

## 10. Dry Run (Quick)

```
weights = [1,2,3,4,5], d = 2

low = 5, high = 15
mid = 10 → days = 2 → valid → high = 10
mid = 7  → days = 3 → invalid → low = 8
mid = 9  → days = 2 → valid → high = 9
mid = 8  → days = 3 → invalid → low = 9

Answer = 9
```

---

## 11. Edge Cases

| Case                   | Result       |
| ---------------------- | ------------ |
| d = number of packages | max(weights) |
| d = 1                  | sum(weights) |
| single package         | its weight   |
| large inputs           | handled      |

---

## 12. Complexity Analysis

| Metric | Value                 |
| ------ | --------------------- |
| Time   | `O(N log(sum - max))` |
| Space  | `O(1)`                |

---

## 13. Pattern Recognition (Very Important)

This problem belongs to **Binary Search on Answer – Minimum Valid Value**.

Same family:

* Koko Eating Bananas
* Smallest Divisor Given Threshold
* Minimum Days to Make Bouquets
* Minimum Time to Complete Trips

---

## Final Interview Notes

1. Answer space is **capacity**
2. Use monotonic property
3. Always simulate with greedy loading
4. Return `low` after binary search
5. Clean, optimal, interview-ready

