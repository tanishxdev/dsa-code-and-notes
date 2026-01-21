# PROBLEM (Original Statement)

Indexes of Subarray Sum

Given an array `arr[]` containing only **non-negative integers**, find a **continuous subarray** (contiguous sequence) whose sum equals a given value `target`.
Return the **1-based indices** of the leftmost and rightmost elements of this subarray.
Return the **first such subarray**.
If no such subarray exists, return `[-1]`.

Problem Link - [GFG](https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1?page=1&category=Arrays&company=Google&sortBy=submissions)

---

## BREAKDOWN PROBLEM

We are given:

- An array `arr`
- A number `target`

We need:

- A **contiguous subarray**
- Whose **sum = target**
- Return its **starting index and ending index (1-based)**
- If many answers exist, return the **first one**

---

## CONSTRAINT UNDERSTANDING

```
1 <= arr.size() <= 10^6
0 <= arr[i] <= 10^3
0 <= target <= 10^9
```

Key observation:

> All elements are **NON-NEGATIVE**

This single line completely decides the algorithm.

---

# BRUTE FORCE APPROACH

## First Thought Intuition

The first idea is:

> Try every subarray and check its sum.

---

## Thought Process

For each starting index `i`:

- Keep adding elements `j = i … n`
- Compute sum
- If sum == target → answer

---

## Pseudocode

```
for i from 0 to n-1
    sum = 0
    for j from i to n-1
        sum += arr[j]
        if sum == target
            return i+1, j+1
return -1
```

---

## Time and Space Complexity

Time: O(n²)
Space: O(1)

---

## Does This Approach Fail?

YES.

Why?

`n` can be `10^6`.
`n²` = `10^12` → impossible.

So we need something much faster.

---

# YOUR WRONG THINKING (Very Important)

You were thinking:

> “This looks like Two Sum. I can use two pointers with
> `while(low < high)`.”

This is **the wrong mental model**.

Why?

Because:

### Two Sum means:

Pick **two numbers** from anywhere.

### This problem means:

Pick a **continuous block** of numbers.

Two completely different structures.

---

### You were trying:

```
while(low < high) {
   if(sum < target) low++
   else high--
}
```

This logic works only when:

- We are selecting **exactly two elements**
- Array is sorted
- We move both ends

But here:

```
sum = arr[low] + arr[low+1] + ... + arr[high]
```

Removing `high` removes **a whole chunk**, not just one value.
So `sum` changes in unpredictable ways.

Therefore:

> `while(low < high)` is logically invalid for subarrays.

---

## INTERVIEW TRUTH (Mandatory)

> while(low < high) two-pointer is for **pair problems**.
> Subarray sum needs **sliding window**, where only **one side shrinks at a time**.

---

# BETTER / OPTIMAL APPROACH — SLIDING WINDOW

This works **only because all numbers are non-negative**.

That gives us:

- Expanding window → sum increases
- Shrinking window → sum decreases

This makes the window **monotonic**.

---

## First Thought Intuition

We grow a window from left to right, and whenever sum becomes too big, we shrink it from the left.

---

## Thought Process

We maintain:

- `left`
- `right`
- `sum` of elements from `left` to `right`

Steps:

1. Expand `right`, add to sum
2. If sum > target → move `left` forward
3. If sum == target → answer found

---

## Pseudocode

```
left = 0
sum = 0

for right from 0 to n-1
    sum += arr[right]

    while sum > target
        sum -= arr[left]
        left++

    if sum == target
        return left+1, right+1

return -1
```

---

## Algorithm

1. Start with empty window
2. Expand window by moving `right`
3. Shrink window from left when sum becomes too big
4. The moment sum equals target, return indices

---

## CODE (C++)

### V1 (Only Required Function)

```cpp
vector<int> subarraySum(vector<int> arr, int n, long long target) {
    long long sum = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        sum += arr[right];

        while (sum > target && left <= right) {
            sum -= arr[left];
            left++;
        }

        if (sum == target) {
            return {left + 1, right + 1};
        }
    }

    return {-1};
}
```

---

## Time and Space Complexity

Time: **O(n)**
Space: **O(1)**

---

## Dry Run

Example:

```
arr = [1,2,3,7,5], target = 12
```

Window moves:

```
1 → 3 → 6 → 13 (too big) → remove 1 → 12
Found from index 2 to 4
```

---

## Edge Cases

- target = 0
- array contains zeros
- no valid subarray
- single element equals target

Sliding window handles all.

---

## Why This Is Optimal

Constraints:

- n up to 10^6
- Values non-negative

Sliding window:

- Each element enters window once
- Leaves once

Total operations: O(n)
This is the fastest possible.

---

## Final Mental Model

This problem is **not Two Sum**.

This is:

> “Grow a window, shrink it when too big.”

That is **Sliding Window Two Pointers**, not **pair-based two pointers**.

---
