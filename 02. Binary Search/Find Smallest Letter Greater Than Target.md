# 744. Find Smallest Letter Greater Than Target

[Problem Link](https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/?envType=daily-question&envId=2026-01-31)

---

## Problem Statement

You are given:

- A sorted array of characters `letters`
- A character `target`

Your task is to **find the smallest character in `letters` that is strictly greater than `target`**.

If no such character exists, **return the first character of the array** (wrap-around behavior).

---

## Key Observations

- The array `letters` is already **sorted**
- At least **two different characters** exist
- Wrap-around is allowed

---

## My First Thinking (Brute / Intuitive Approach)

### Thought Process

- Since the array is sorted, I can scan from left to right
- The **first character greater than target** will automatically be the smallest
- If I reach the end and find nothing, then wrap around and return `letters[0]`

This is the **most natural beginner approach**.

---

## Approach 1: Linear Scan (First Thinking)

### Algorithm

1. Loop through each character in `letters`
2. If `letters[i] > target`, return it immediately
3. If loop finishes without return, return `letters[0]`

---

### C++ Code (With Detailed Comments)

```cpp
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        // Step 1: Traverse the array from left to right
        for (int i = 0; i < letters.size(); i++) {

            // Step 2: Check if current letter is strictly greater than target
            if (letters[i] > target) {

                // Since array is sorted, this is the smallest valid answer
                return letters[i];
            }
        }

        // Step 3: If no character is greater than target
        // Wrap around and return the first character
        return letters[0];
    }
};
```

---

### Dry Run

```
letters = [c, f, j]
target = c

i = 0 → c > c ❌
i = 1 → f > c ✅ → return f
```

```
letters = [c, f, j]
target = j

No character > j
Return letters[0] → c
```

---

### Complexity

- Time Complexity: **O(n)**
- Space Complexity: **O(1)**

---

## Optimized Thinking (Using Sorted Property)

### Why Optimize?

- Array is sorted
- We are searching for **first element greater than target**
- This is a **classic Binary Search use case**

---

## Approach 2: Binary Search (Optimized)

### Algorithm

1. Apply binary search on `letters`
2. Try to find the **first character greater than target**
3. If found, store it and move left
4. If not found, return `letters[0]` (wrap-around)

---

### C++ Code (With Detailed Comments)

```cpp
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        int left = 0;
        int right = letters.size() - 1;

        // Default answer for wrap-around case
        char answer = letters[0];

        // Binary search loop
        while (left <= right) {

            int mid = left + (right - left) / 2;

            // If mid character is greater than target
            if (letters[mid] > target) {

                // This can be a valid answer
                answer = letters[mid];

                // Try to find a smaller valid character on the left
                right = mid - 1;
            } else {

                // letters[mid] <= target
                // Move right to search for greater characters
                left = mid + 1;
            }
        }

        return answer;
    }
};
```

---

### Dry Run

```
letters = [c, f, j]
target = c

left = 0, right = 2
mid = 1 → f > c → answer = f → right = 0
mid = 0 → c <= c → left = 1

return f
```

---

### Complexity

- Time Complexity: **O(log n)**
- Space Complexity: **O(1)**

---

## Comparison Summary

| Approach      | Time     | Space | Notes                    |
| ------------- | -------- | ----- | ------------------------ |
| Linear Scan   | O(n)     | O(1)  | Best for first intuition |
| Binary Search | O(log n) | O(1)  | Expected in interviews   |

---

## Final Notes (Mindset)

- Your **first thinking was correct**
- You understood:
  - Sorted array
  - Wrap-around case

- Binary search is just an **optimization**, not a different logic

This is how problems should be approached:

> First make it work → then make it fast

---
