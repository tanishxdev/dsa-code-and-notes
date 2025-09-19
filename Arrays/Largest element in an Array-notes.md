## Problem 1: Largest Element in an Array

Problem Link https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1


**Problem Statement**:

Given an array of integers, return the largest element.

**Breakdown**:

- **Input**: Array `arr` of size `n` with integers.
- **Output**: The largest integer in the array.
- **What We Need to Do**: Find the maximum value in the array.
- **Why is This a Problem?**: Simple but tests basic array traversal and comparison logic.
- **Key Point**: Array may contain duplicates or negative numbers.

**Constraints**:

- `1 <= n <= 10^6`
- `10^9 <= arr[i] <= 10^9`

**Examples**:

- Input: `arr = [2, 3, 1, 4, 7, 6]`
Output: `7`
- Input: `arr = [1, 1, 1]`
Output: `1`
- Input: `arr = [-1, -2, -3]`
Output: `1`

**Key Definitions**:

- **Largest Element**: The maximum value in the array.
- **Hinglish**: Array mein sabse bada number dhoondhna hai.

**Prerequisite**:

- Basic array traversal and comparison.

**Key Observation**:

- Sorting puts the largest element at the end but is overkill.
- A single pass comparing elements is more efficient.

### 🔴 Approach 1: Brute Force (Sorting)

**Thought Process**:

- *What’s the goal?* Find the largest element.
- *How to model?* Sort the array in ascending order; the last element is the largest.
- *Choices?* Use any sorting algorithm (e.g., quicksort, mergesort).
- *Hinglish*: Array ko sort karo, last wala element largest hoga.

**Examples to Prove Idea**:

- `arr = [2, 3, 1, 4, 7, 6]`, sorted = `[1, 2, 3, 4, 6, 7]`:
    - Last element: `7` (largest).
- *Why it works*: Sorting arranges elements in ascending order, so `arr[n-1]` is the maximum.

**Intuition**:

Sort the array using a standard sorting algorithm. The largest element will be at index `n-1`.

**Dry Run**:

- Input: `arr = [2, 3, 1, 4, 7, 6]`.
- Sort: `[1, 2, 3, 4, 6, 7]`.
- Return: `arr[5] = 7`.
- *Hinglish*: Sort kiya, last element 7 mila.

**Algorithm**:

1. Sort `arr` in ascending order.
2. Return `arr[n-1]`.

**Pseudocode**:

```cpp
function findLargestBrute(arr, n):
    sort(arr)
    return arr[n-1]

```

**Code**:

```cpp
int findLargestBrute(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    return arr[n-1];
}

```

**Time Complexity (TC)**:

- Sorting: `O(n log n)` (using quicksort/mergesort).
- Total: `O(n log n)`.
- Why? Sorting dominates.

**Space Complexity (SC)**:

- `O(1)` (in-place sorting like quicksort, ignoring recursive stack).
- Why? No extra space used.

**Notes/Observations**:

- *Why brute?* Simple but inefficient due to sorting.
- *Hinglish*: Sort karna easy hai, par time zyada lagta hai.
- *Limitation*: `O(n log n)` is unnecessary for a simple maximum.

### 🟢 Approach 2: Optimal (Single Pass)

**Thought Process**:

- *Can we improve?* Avoid sorting by tracking the maximum during a single traversal.
- *How?* Initialize `largest` as `arr[0]`, compare with each element, update if larger.
- *Hinglish*: Ek baar array mein ghumo, har element ko check karo, jo bada mile, largest mein daal do.

**Examples to Prove Idea**:

- `arr = [2, 3, 1, 4, 7, 6]`:
    - Start: `largest = 2`.
    - Compare: `3 > 2` → `largest = 3`, `1 > 3` (no), `4 > 3` → `largest = 4`, `7 > 4` → `largest = 7`, `6 > 7` (no).
    - Return: `7`.
- *Why it works*: Single pass ensures we find the maximum by comparing each element.

**Intuition**:

Initialize `largest` with the first element. Iterate through the array, updating `largest` whenever a larger element is found.

**Dry Run**:

- Input: `arr = [2, 3, 1, 4, 7, 6]`.
- Initialize: `largest = 2`.
- Steps:
    - `i=1`: `3 > 2`, `largest = 3`.
    - `i=2`: `1 > 3`, no update.
    - `i=3`: `4 > 3`, `largest = 4`.
    - `i=4`: `7 > 4`, `largest = 7`.
    - `i=5`: `6 > 7`, no update.
- Return: `7`.
- *Hinglish*: Ek ek karke check kiya, 7 sabse bada mila.

**Algorithm**:

1. Initialize `largest = arr[0]`.
2. For `i` from `0` to `n-1`:
    - If `arr[i] > largest`, update `largest = arr[i]`.
3. Return `largest`.

**Pseudocode**:

```cpp
function findLargestOptimal(arr, n):
    largest = arr[0]
    for i from 0 to n-1:
        if arr[i] > largest:
            largest = arr[i]
    return largest

```

**Code**:

```cpp
int findLargestOptimal(vector<int>& arr) {
    int n = arr.size();
    int largest = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

```

**Time Complexity (TC)**:

- Single loop: `O(n)`.
- Total: `O(n)`.
- Why? One pass through the array.

**Space Complexity (SC)**:

- `O(1)` (only `largest` variable).
- Why? No extra space used.

**Notes/Observations**:

- *Why optimal?* Achieves `O(n)` time with `O(1)` space, better than sorting.
- *Hinglish*: Ek baar ghumke largest dhoondh liya, time aur space bacha.
- *Edge Cases*:
    - Single element: Return `arr[0]`.
    - All same elements: Return that element.
    - Negative numbers: Works the same.