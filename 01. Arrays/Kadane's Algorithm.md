# PROBLEM (Original Statement)

Kadane's Algorithm

You are given an integer array `arr[]`.
Find the **maximum sum of a subarray** (contiguous part of the array) containing **at least one element**.

Problem Link - [GFG](https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1?page=1&category=Arrays&company=Google&sortBy=submissions)
---

## BREAKDOWN PROBLEM

We are given:

- An array (can contain positive, negative, zero)

We need:

- A **continuous subarray**
- With **maximum possible sum**

Return that maximum sum.

---

## CONSTRAINT UNDERSTANDING

- Array can be large
- Numbers can be **negative**
- Subarray must contain **at least one element**

This destroys many naive approaches.

---

# BRUTE FORCE APPROACH

## First Thought Intuition

Try all subarrays, calculate sum, keep maximum.

---

## Thought Process

For every `i`, for every `j ≥ i`, calculate:

```
arr[i] + arr[i+1] + ... + arr[j]
```

---

## Pseudocode

```
best = -infinity
for i = 0 to n-1
    sum = 0
    for j = i to n-1
        sum += arr[j]
        best = max(best, sum)
return best
```

---

## Time Complexity

O(n²) → too slow.

---

## Does this approach fail?

YES.
n up to 10⁵ or more.

We need O(n).

---

# YOUR WRONG THINKING (Very Important)

Most people think:

> “This is subarray sum. I can use sliding window.”

This is **WRONG**.

Why?

Sliding window only works when:

> Removing elements **always decreases** the sum
> Adding elements **always increases** the sum

That only happens when **all numbers are non-negative**.

Here we have **negative numbers**.

---

### Example that breaks sliding window

```
arr = [4, -10, 5]
```

Correct answer = 5

Sliding window would:

```
4 → -6 → -1
```

It never resets properly.

---

## Mental mistake

You were thinking:

> “Window bada ya chhota kar ke sum control kar sakta hoon.”

But with negatives:

- Removing a negative increases sum
- Adding a negative decreases sum

So window is **not monotonic**.

---

# CORRECT MENTAL MODEL (Kadane)

We do NOT track a window.
We track **best subarray ending at each index**.

At every element, we ask:

> Is it better to
> start fresh from here
> OR continue previous subarray?

---

## DP Definition

```
currentSum = best subarray sum ending here
maxSum = best seen anywhere
```

---

## Transition

At each index `i`:

```
currentSum = max(arr[i], currentSum + arr[i])
maxSum = max(maxSum, currentSum)
```

If previous sum is bad (negative), we drop it.

---

# Pseudocode

```
current = arr[0]
best = arr[0]

for i from 1 to n-1
    current = max(arr[i], current + arr[i])
    best = max(best, current)

return best
```

---

# CODE (C++)

```cpp
int maxSubarraySum(vector<int> &arr) {
    int currentSum = arr[0];
    int maxSum = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}
```

---

# DRY RUN

```
arr = [2, 3, -8, 7, -1, 2, 3]

i=0 → current=2, best=2
i=1 → max(3,2+3)=5 → best=5
i=2 → max(-8,5-8)=-3 → best=5
i=3 → max(7,-3+7)=7 → best=7
i=4 → max(-1,7-1)=6 → best=7
i=5 → max(2,6+2)=8 → best=8
i=6 → max(3,8+3)=11 → best=11
```

Answer = 11

---

# EDGE CASE

All negative:

```
[-2,-4]
```

Kadane returns `-2`
(chooses best single element)

---

# INTERVIEW TRUTH

> Sliding window works only for non-negative arrays.
> Kadane works because it **drops bad prefixes** dynamically.

---

# FINAL MENTAL MODEL

This is NOT a window problem.
This is **"best subarray ending here" DP problem.**

You are not moving pointers —
You are deciding whether to **continue or restart**.

---
