# Koko Eating Bananas(Binary Search on Answer)

---

## 1. Problem Statement

**English**:
You are given an array `piles[]` where each element represents the number of bananas in a pile.
You are also given an integer `H` representing the number of hours.

Koko can eat **K bananas per hour**.
In one hour, she can choose **only one pile** and eat up to `K` bananas from it.

Your task is to find the **minimum integer K** such that Koko can eat **all bananas within `H` hours**.

**Hinglish**:
Bananas ke piles diye hain aur total `H` hours diye gaye hain.
Koko har hour mein **sirf ek pile** se **K bananas** kha sakti hai.

Batana hai:

> **minimum K** kya hoga jisse saare bananas `H` hours ke andar khatam ho jaayein.

---

## 2. Examples (Must Know)

### Example 1

```
piles = [3,6,7,11], H = 8
Output = 4
```

**Explanation**:

* K = 4 bananas/hour
* Hours needed:

  * 3 → 1 hour
  * 6 → 2 hours
  * 7 → 2 hours
  * 11 → 3 hours
* Total = 8 hours (valid)

---

### Example 2

```
piles = [30,11,23,4,20], H = 5
Output = 30
```

---

## 3. Brute Force Approach (For Understanding)

### Intuition

> Try every possible eating speed `K` starting from 1
> Check if Koko can finish all bananas within `H` hours.

---

### Algorithm

```text
for K from 1 to max(piles):
    calculate total hours needed
    if hours <= H:
        return K
```

```cpp
// ⭐ Helper function
// Calculates total hours needed if Koko eats at speed k
long long calculateHours(vector<int>& piles, int k)
{
    long long hours = 0;

    for (int bananas : piles)
    {
        // ceil(bananas / k)
        hours += (bananas + k - 1) / k;
    }

    return hours;
}

int minEatingSpeed_Brute(vector<int>& piles, int H)
{
    int maxPile = *max_element(piles.begin(), piles.end());

    for (int k = 1; k <= maxPile; k++)
    {
        long long hours = calculateHours(piles, k);

        if (hours <= H)
            return k;
    }

    return -1;
```
---

### Dry Run (Brute Force)

**Input**

```
piles = [3, 6, 7, 11]
H = 8
```

**Try K = 1**

```
hours = ceil(3/1) + ceil(6/1) + ceil(7/1) + ceil(11/1)
       = 3 + 6 + 7 + 11
       = 27

27 > 8 → not possible
```

**Try K = 2**

```
hours = ceil(3/2) + ceil(6/2) + ceil(7/2) + ceil(11/2)
       = 2 + 3 + 4 + 6
       = 15

15 > 8 → not possible
```

**Try K = 3**

```
hours = ceil(3/3) + ceil(6/3) + ceil(7/3) + ceil(11/3)
       = 1 + 2 + 3 + 4
       = 10

10 > 8 → not possible
```

**Try K = 4**

```
hours = ceil(3/4) + ceil(6/4) + ceil(7/4) + ceil(11/4)
       = 1 + 2 + 2 + 3
       = 8

8 <= 8 → valid
Return K = 4
```

---

### Time Complexity

| Metric | Value            |
| ------ | ---------------- |
| Time   | O(N × max(pile)) |
| Space  | O(1)             |

❌ Too slow
❌ Not acceptable in interviews

---

## 4. Core Intuition (Binary Search Thinking)

> This is a **Binary Search on Answer** problem.

---

### 4.1 What is the search space?

* Minimum speed = `1`
* Maximum speed = `max(piles)`

```
K ∈ [1 ... max(piles)]
```

This range is **sorted**.

---

### 4.2 Key Observation (Very Important)

If Koko can finish all bananas at speed `K`:

* She can also finish at **any speed > K**

This means:

```
false false false true true true
```

👉 **Monotonic behavior** → Binary Search applicable.

---

### 4.3 What are we minimizing?

> **Minimum K** such that total hours ≤ H

---

## 5. How to Calculate Hours for a Given K

For each pile:

```
hours = ceil(pile / K)
```

To avoid floating point:

```text
hours += pile / K
if pile % K != 0:
    hours += 1
```

---

## 6. Binary Search Algorithm

```text
low = 1
high = max(piles)
ans = high

while low <= high:
    mid = low + (high-low)/2

    if canFinish(mid):
        ans = mid
        high = mid - 1    // try smaller K
    else:
        low = mid + 1     // need bigger K

return ans
```

---

## 7. Dry Run

### Input

```
piles = [3,6,7,11], H = 8
```

| K | Hours Needed | Valid? | Move  |
| - | ------------ | ------ | ----- |
| 6 | 6            | Yes    | left  |
| 3 | 10           | No     | right |
| 4 | 8            | Yes    | left  |
| 3 | 10           | No     | stop  |

✅ **Answer = 4**

### Detailed - Dry Run (Binary Search)

**Input**

```
piles = [3, 6, 7, 11]
H = 8
```

**Initial Search Space**

```
low = 1
high = 11   (max pile)
```

**Iteration 1**

```
mid = (1 + 11) / 2 = 6

hours = ceil(3/6) + ceil(6/6) + ceil(7/6) + ceil(11/6)
       = 1 + 1 + 2 + 2
       = 6

6 <= 8  → valid speed
ans = 6
high = 5
```

**Iteration 2**

```
mid = (1 + 5) / 2 = 3

hours = ceil(3/3) + ceil(6/3) + ceil(7/3) + ceil(11/3)
       = 1 + 2 + 3 + 4
       = 10

10 > 8 → too slow
low = 4
```

**Iteration 3**

```
mid = (4 + 5) / 2 = 4

hours = ceil(3/4) + ceil(6/4) + ceil(7/4) + ceil(11/4)
       = 1 + 2 + 2 + 3
       = 8

8 <= 8 → valid speed
ans = 4
high = 3
```

**Loop Ends**

```
low > high
Final Answer = 4
```

---

## 8. Full Working Code

### C++ (Interview Preferred)

```cpp
class Solution
{
public:
    bool canEatAll(vector<int> &piles, int H, int K)
    {
        long long hours = 0;

        for (int bananas : piles)
        {
            hours += bananas / K;
            if (bananas % K != 0)
                hours += 1;
        }
        return hours <= H;
    }

    int minEatingSpeed(vector<int> &piles, int H)
    {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (canEatAll(piles, H, mid))
            {
                ans = mid;
                high = mid - 1; // minimize K
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
```

---

### JavaScript

```js
        function
        canEatAll(piles, H, K)
{
    let hours = 0;

    for (let bananas of piles)
    {
        hours += Math.floor(bananas / K);
        if (bananas % K != = 0)
            hours += 1;
    }
    return hours <= H;
}

function minEatingSpeed(piles, H)
{
    let low = 1;
    let high = Math.max(... piles);
    let ans = high;

    while (low <= high)
    {
        let mid = low + Math.floor((high - low) / 2);

        if (canEatAll(piles, H, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

// Test
console.log(minEatingSpeed([ 3, 6, 7, 11 ], 8)); // 4
```

---

## 9. Edge Cases Covered

| Case                | Result       |
| ------------------- | ------------ |
| One pile            | works        |
| H = number of piles | K = max pile |
| Very large piles    | safe         |
| Minimum K needed    | found        |

---

## 10. Complexity Analysis

| Metric | Value               |
| ------ | ------------------- |
| Time   | O(N × log(maxPile)) |
| Space  | O(1)                |

---

## 11. Interview Pattern Recognition

This problem is a **template** for:

* Minimum speed / capacity
* Minimum days / time
* Binary Search on Answer

Related problems:

* Koko Eating Bananas
* Min days to make bouquets
* Capacity to ship packages
* Allocate books

---

## Final Notes (Yaad Rakhna)

1. This is **not array binary search**
2. Search space is **answer range**
3. Valid mid → go **LEFT**
4. Invalid mid → go **RIGHT**
5. Always minimize the answer

---