## Problem: Linear Search (Array Search)
Problem Link https://www.geeksforgeeks.org/problems/search-an-element-in-an-array-1587115621/1

**Problem Statement**:

Given an array `arr[]` of `n` integers and an integer element `x`, find the index of the first occurrence of `x` in the array. If `x` is not present, return `-1`. The array may be unsorted and may contain duplicates.

**Breakdown**:

- **Input**: Array of integers `arr` and target integer `x`.
- **Output**: Index of the first occurrence of `x` in `arr`, or `1` if not found.
- **What We Need to Do**: Scan the array sequentially to find the first instance of `x`.
- **Why is This a Problem?** Requires simple, reliable searching in unsorted arrays, handling cases where the target may not exist.
- **Hinglish**: Array diya hai, `x` ko dhoondhna hai, pehli baar mila to index do, nahi mila to `1`.

**Constraints**:

- `1 ≤ arr.size() ≤ 10^6`
- `0 ≤ arr[i] ≤ 10^6`
- `0 ≤ x ≤ 10^5`

**Examples**:

- **Example 1**:
    - Input: `arr = [1,2,3,4], x = 3`
    - Output: `2`
    - Explanation: `3` is at index `2`.
- **Example 2**:
    - Input: `arr = [10,8,30,4,5], x = 5`
    - Output: `4`
    - Explanation: `5` is at index `4`.
- **Example 3**:
    - Input: `arr = [10,8,30], x = 6`
    - Output: `1`
    - Explanation: `6` is not in the array.

**Key Definitions**:

- **Linear Search**: Sequentially check each element until the target is found or the array ends.
- **First Occurrence**: Return the smallest index where `x` appears.
- **Hinglish**: Ek ek element check karo, `x` mile to index do, nahi to `1`.

**Prerequisites**:

- Basic understanding of array traversal.
- Familiarity with loops and conditionals.

**Problem Link**:

- [GeeksforGeeks: Array Search](https://www.geeksforgeeks.org/problems/search-an-element-in-an-array-1587115621/1)

---

### Approach: Linear Search (Sequential Search)

**Thought Process**:

- **Goal**: Find the first occurrence of `x` in an unsorted array.
- **How?** Iterate through the array from index `0` to `n-1`, check each element against `x`, return the index of the first match, or `1` if no match.
- **Benefit?** Simple, works on unsorted arrays, handles duplicates by returning the first occurrence.
- **Drawback?** Inefficient for large datasets or sorted arrays (where binary search would be better).
- **Hinglish**: Shuru se end tak ek ek element check karo, `x` mile to index return, nahi to `1`.

**Examples to Prove Idea**:

- `arr = [1,2,3,4], x = 3`:
    - Check `1`: No match.
    - Check `2`: No match.
    - Check `3`: Match at index `2`, return `2`.
- `arr = [10,8,30,4,5], x = 5`:
    - Check `10,8,30,4`: No match.
    - Check `5`: Match at index `4`, return `4`.
- `arr = [10,8,30], x = 6`:
    - Check all: No match, return `1`.

**Intuition**:
Like searching for a name in an unsorted list by checking each entry one by one until found or list ends.

**Dry Run**:

- Input: `arr = [10,8,30,4,5], x = 5`
- Step 1: `i = 0`, `arr[0] = 10 ≠ 5`: Continue.
- Step 2: `i = 1`, `arr[1] = 8 ≠ 5`: Continue.
- Step 3: `i = 2`, `arr[2] = 30 ≠ 5`: Continue.
- Step 4: `i = 3`, `arr[3] = 4 ≠ 5`: Continue.
- Step 5: `i = 4`, `arr[4] = 5 = 5`: Return `4`.
- Output: `4`
- **Hinglish**: Ek ek element check kiya, `5` index `4` pe mila, `4` return kiya.

**Algorithm**:

1. Iterate from `i = 0` to `n-1`.
2. If `arr[i] == x`, return `i`.
3. If loop ends, return `1`.

**Pseudocode**:

```cpp
function linearSearch(arr, x):
    for i from 0 to arr.size-1:
        if arr[i] == x:
            return i
    return -1

```

**Code**:

```cpp
class Solution {
public:
    int search(vector<int>& arr, int x) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == x) {
                return i; // Return first occurrence
            }
        }
        return -1; // Not found
    }
};

```

**Time Complexity (TC)**:

- **Best Case**: `O(1)` – Target found at index `0`.
- **Average/Worst Case**: `O(n)` – Must check all elements if target is at end or not present.
- **Why?** Linear traversal of array.

**Space Complexity (SC)**:

- `O(1)`: Only uses a loop variable.
- **Why?** No extra space proportional to input size.

**Notes/Observations**:

- **Why Simple?** Straightforward loop, no preprocessing needed.
- **Hinglish**: Bas ek loop chalao, `x` mile to index do, nahi to `1`.
- **Drawback**: Inefficient for large or sorted arrays.
- **When to Use**:
    - Small arrays.
    - Unsorted arrays.
    - Single or few searches.
- **When Not to Use**:
    - Sorted arrays (use binary search).
    - Large datasets requiring multiple searches.

---

### Final Consolidated Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int x) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == x) {
                return i; // Return first occurrence
            }
        }
        return -1; // Not found
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {10, 8, 30, 4, 5};
    int x1 = 5;
    vector<int> arr2 = {1, 2, 3, 4};
    int x2 = 3;
    vector<int> arr3 = {10, 8, 30};
    int x3 = 6;

    // Test Case 1
    cout << "Test Case 1: arr = [10,8,30,4,5], x = 5\\n";
    cout << "Output: " << sol.search(arr1, x1) << endl; // Expected: 4

    // Test Case 2
    cout << "Test Case 2: arr = [1,2,3,4], x = 3\\n";
    cout << "Output: " << sol.search(arr2, x2) << endl; // Expected: 2

    // Test Case 3
    cout << "Test Case 3: arr = [10,8,30], x = 6\\n";
    cout << "Output: " << sol.search(arr3, x3) << endl; // Expected: -1

    return 0;
}

```

---

### Key Points for Interview

- **Linear Search**: `O(n)` time, `O(1)` space – Simple, sequential check for target.
- **Hinglish**: Interview mein bolo: “Ek ek element check karta hoon, pehla match index return, nahi to -1.”
- **Edge Cases**:
    - Empty array: Return `1` (handled by loop not running).
    - Single element: `[1], x=1` → `0`; `[1], x=2` → `1`.
    - Duplicates: Returns first occurrence (e.g., `[1,3,3], x=3` → `1`).
    - Target not present: Return `1`.
- **Key Insight**: Works on unsorted arrays, guaranteed to find first occurrence or confirm absence.
- **When to Use**:
    - Small datasets.
    - Unsorted arrays.
    - Single search or rare searches.
- **When Not to Use**:
    - Sorted arrays (use binary search for `O(log n)`).
    - Large datasets with frequent searches (consider hashing or indexing).

---

### Addressing Doubts from Provided Context

1. **Single Approach for Linear Search**:
    - The provided context only describes one approach (sequential search). Since linear search is inherently simple, there’s no need for multiple approaches like brute force vs. optimal. I’ve focused on the standard linear search algorithm, ensuring clarity and alignment with the problem.
2. **Clarification on Use Cases**:
    - The context highlights linear search for unsorted arrays and small datasets. I reinforced this with explicit notes on when to use (unsorted, small data) and when not to use (sorted arrays, large data).
3. **Dry Run Consistency**:
    - The provided dry run for `[4,2,9,7,5], x=7` is clear and correct. I provided a detailed dry run for `[10,8,30,4,5], x=5` to align with the GeeksforGeeks examples, ensuring consistency.
4. **Handling Edge Cases**:
    - The context doesn’t explicitly mention edge cases, but I covered empty arrays, single elements, duplicates, and target absence to ensure robustness.
5. **No Binary Search**:
    - As requested (“only linear search”), I excluded binary search discussion, focusing solely on linear search’s simplicity and applicability.
6. **GeeksforGeeks Problem Alignment**:
    - The problem matches GeeksforGeeks’ “Array Search” with constraints and examples. I ensured the solution uses the same function signature (`int search(vector<int>& arr, int x)`) and addresses the first occurrence requirement.

---

### Additional Notes for Beginners

- **Why Linear Search?** Teaches basic array traversal and is the simplest search algorithm.
- **Hinglish**:
    - Bas ek loop chalao, `x` mile to index do, nahi to `1`.
- **Practice**:
    - `[10,8,30,4,5], x=5` → `4`
    - `[1,2,3,4], x=3` → `2`
    - `[10,8,30], x=6` → `1`
- **Related Problems**:
    - [GeeksforGeeks: Array Search](https://www.geeksforgeeks.org/problems/search-an-element-in-an-array-1587115621/1)
    - [LeetCode 704: Binary Search](https://leetcode.com/problems/binary-search/) (for comparison, not used here)
- **Interview Tip**: Explain linear search’s simplicity, emphasize it works on unsorted arrays, mention binary search for sorted arrays if asked to optimize.

---