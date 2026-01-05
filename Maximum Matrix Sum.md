# LeetCode 1975 — Maximum Matrix Sum

---

## 1. Problem Statement

You are given an `n x n` integer matrix.

You can perform the following operation **any number of times**:

* Choose **any two adjacent elements** (sharing a border)
* Multiply **both elements by -1**

Your goal is to **maximize the sum of all elements in the matrix** after applying any number of such operations.

Return the **maximum possible sum**.

---

## 2. Key Doubts (Natural Questions)

These are the exact doubts that arise when reading the problem:

1. Do we need to simulate operations?
2. Does adjacency actually matter in the final answer?
3. Can we choose which elements become positive or negative?
4. What if negatives are odd in count?
5. Is sorting required?

We will resolve **all of them logically**, without brute force simulation.

---

## 3. Important Observation (Invariant Thinking)

### What happens in one operation?

* Exactly **two elements** change sign
* Either:

  * Two positives → two negatives
  * Two negatives → two positives
  * One positive & one negative → unchanged count

### Core Invariant

> **The parity (odd/even) of the number of negative elements NEVER changes.**

This is the most important realization.

---

## 4. Why Adjacency Does NOT Matter

Although the operation requires adjacency:

* The matrix is a **connected grid**
* Any element can influence any other through a sequence of adjacent flips

So:

> Adjacency restricts operations, **not the final achievable sign configuration**.

We do **NOT** need BFS / DFS / simulation.

---

## 5. Two Final Cases

### Case 1: Negative Count is EVEN

* All negative elements can be paired
* Every element can be made positive

➡️ Final matrix: **all positive**

### Case 2: Negative Count is ODD

* One negative element **must remain**
* Choice is ours: which one?

➡️ To minimize loss, keep the element with **minimum absolute value** negative

---

## 6. Final Strategy (Mental Model)

1. Take **absolute value of every element**
2. Add all absolute values → `totalSum`
3. Count number of negative elements
4. Track **minimum absolute value**
5. If negative count is odd:

   * Subtract `2 × minAbsValue` from `totalSum`

---

## 7. Pseudocode (Language Independent)

```
initialize totalSum = 0
initialize negativeCount = 0
initialize minAbsValue = infinity

for each element in matrix:
    if element < 0:
        negativeCount++

    absValue = absolute(element)
    totalSum += absValue
    minAbsValue = min(minAbsValue, absValue)

if negativeCount is odd:
    totalSum -= 2 * minAbsValue

return totalSum
```

---

## 8. Dry Run Example

### Example 1

```
Matrix:
[  1  -1
  -1   1 ]
```

* Absolute sum = 1 + 1 + 1 + 1 = 4
* Negative count = 2 (even)
* No subtraction

✅ Answer = **4**

---

### Example 2

```
Matrix:
[ 1  2  3
 -1 -2 -3
  1  2  3 ]
```

* Absolute sum = 18
* Negative count = 3 (odd)
* Minimum absolute value = 1

Final Sum:

```
18 - 2×1 = 16
```

---

## 9. Final C++ Code

```cpp
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int negativeCount = 0;
        int minAbsValue = INT_MAX;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                int val = matrix[i][j];

                if (val < 0) {
                    negativeCount++;
                }

                int absVal = abs(val);
                totalSum += absVal;
                minAbsValue = min(minAbsValue, absVal);
            }
        }

        if (negativeCount % 2 == 1) {
            totalSum -= 2LL * minAbsValue;
        }

        return totalSum;
    }
};
```

---

## 10. JavaScript Code

```js
var maxMatrixSum = function(matrix) {
    let totalSum = 0;
    let negativeCount = 0;
    let minAbsValue = Infinity;

    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[0].length; j++) {
            let val = matrix[i][j];

            if (val < 0) negativeCount++;

            let absVal = Math.abs(val);
            totalSum += absVal;
            minAbsValue = Math.min(minAbsValue, absVal);
        }
    }

    if (negativeCount % 2 === 1) {
        totalSum -= 2 * minAbsValue;
    }

    return totalSum;
};
```

---

## 11. Time & Space Complexity

### Time Complexity

```
O(n²)
```

One full traversal of the matrix.

### Space Complexity

```
O(1)
```

Only constant extra variables used.

---

## 12. Why This Approach is Optimal

* Every element must be read at least once
* No extra memory needed
* No simulation or recursion

This is **provably optimal**.

---

## 13. Key Takeaway (Very Important)

> This was **never an adjacency problem**.
> It is an **invariant + parity problem**.

Once you identify the invariant, the problem collapses into a simple formula.

---

## 14. Pattern Recognition

This problem belongs to:

* Invariant-based problems
* Parity optimization
* Sign manipulation

Same thinking appears in many advanced DSA problems.

---

## 15. Final One-Line Interview Summary

> We maximize the sum by converting all elements to their absolute values, and if the count of negative numbers is odd, we subtract twice the smallest absolute value to maintain parity.
