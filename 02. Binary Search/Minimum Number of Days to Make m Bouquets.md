Below is a **clean, structured `.md` file** for
**Minimum Number of Days to Make `m` Bouquets**
written exactly in your **Binary Search on Answer + intuition-first style**.

You can directly save this as:

```
Minimum_Days_to_Make_Bouquets.md
```

---

# Minimum Number of Days to Make `m` Bouquets

(Binary Search on Answer)

---

## 1. Problem Statement

**English**
You are given an array `bloomDay[]` where `bloomDay[i]` tells the day on which the `i-th` flower blooms.

You are also given two integers:

- `m` → number of bouquets to make
- `k` → number of **adjacent flowers** required to make **one bouquet**

Rules:

- A flower can be used **only once**
- Flowers in a bouquet must be **adjacent**
- You must find the **minimum number of days** needed to make **at least `m` bouquets**
- If it is impossible → return `-1`

---

## 2. Key Observations (Very Important)

1. If you wait for **more days**, **more flowers bloom**
2. If you can make `m` bouquets on day `D`,
   then you can also make them on **any day > D**
3. We are asked for the **minimum day**

👉 This creates a **monotonic (true/false) pattern**

```
false false false true true true
```

➡️ **Perfect candidate for Binary Search on Answer**

---

## 3. Brute Force Idea (Why It’s Bad)

### Thought Process

- Try day `1`, day `2`, day `3`, …
- For each day, check if we can make `m` bouquets

### Time Complexity

```
O(maxDay × N)
```

❌ Too slow
❌ Not interview-acceptable

---

## 4. Core Intuition (Binary Search on Days)

> We are **not searching inside the array**
> We are searching on the **answer space (days)**

### Search Space

```
minimum day = 1
maximum day = max(bloomDay[])
```

---

### Binary Search Meaning

| Condition              | Meaning        | Move               |
| ---------------------- | -------------- | ------------------ |
| Can make m bouquets    | Day is valid   | Go LEFT (minimize) |
| Cannot make m bouquets | Day is invalid | Go RIGHT           |

---

## 5. How to Check If a Day Is Valid

### Question:

> If I wait till `day = X`, can I make at least `m` bouquets?

### Logic:

- Traverse `bloomDay[]`
- Count **consecutive bloomed flowers**
- Every time count reaches `k`, make one bouquet
- Reset count after bouquet is made

---

### Example

```
bloomDay = [1, 10, 3, 10, 2]
day = 3, k = 1
```

Flowers bloomed by day 3:

```
[✓, ✗, ✓, ✗, ✓]
```

Bouquets possible = 3 → valid

---

## 6. Binary Search Algorithm

```text
low = 1
high = max(bloomDay)
ans = -1

while(low <= high):
    mid = (low + high) / 2

    if canMakeBouquets(mid):
        ans = mid
        high = mid - 1   // try smaller day
    else:
        low = mid + 1    // need more days

return ans
```

---

## 7. Bouquet Feasibility Check (Core Logic)

```text
bouquets = 0
count = 0

for each flower:
    if bloomDay[i] <= mid:
        count++
        if count == k:
            bouquets++
            count = 0
    else:
        count = 0

return bouquets >= m
```

---

## 8. Full Working Code (C++ – Interview Preferred)

```cpp
class Solution {
public:
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0;
        int count = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if (n < (long long)m * k) return -1;

        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMakeBouquets(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
```

---

## 9. Dry Run (Key Example)

```
bloomDay = [1, 10, 3, 10, 2]
m = 3, k = 1
```

| Day | Possible Bouquets | Valid |
| --- | ----------------- | ----- |
| 2   | 2                 | ❌    |
| 3   | 3                 | ✅    |
| 4   | 3                 | ✅    |

➡️ **Minimum = 3**

---

## 10. Edge Cases

| Case                   | Result       |
| ---------------------- | ------------ |
| m × k > n              | return -1    |
| All flowers bloom late | handled      |
| k = 1                  | simple count |
| Large values           | safe         |

---

## 11. Complexity Analysis

| Metric | Value              |
| ------ | ------------------ |
| Time   | `O(N log(maxDay))` |
| Space  | `O(1)`             |

---

## 12. Pattern Recognition (Very Important)

This problem belongs to:

> **Binary Search on Answer (Minimum Valid Value)**

Same family as:

- Koko Eating Bananas
- Ship Packages in D Days
- Minimum Time to Complete Trips
- Aggressive Cows
- Allocate Books

---

## Final Notes (Interview Gold)

1. Search space = **days**
2. Valid → go left
3. Invalid → go right
4. Adjacent count reset is critical
5. Always check `m * k > n` early

---

If you want, next we can do:

- **Ship Packages Within D Days**
- **Minimum Time to Complete Trips**
- **Binary Search on Answer – Master Template**

Just say the name.
