**Problem Statement**:

Given an array of distinct non-negative integers with at least two elements, return the second largest and second smallest elements.

**Breakdown**:

- **Input**: Array `arr` of size `n >= 2` with distinct non-negative integers.
- **Output**: Array `[second_largest, second_smallest]`.
- **What We Need to Do**: Find the second largest and second smallest elements without sorting.
- **Why is This a Problem?**: Tests ability to track multiple extremes in one pass.
- **Key Point**: No duplicates, so second largest/smallest always exist for `n >= 2`.

**Constraints**:

- `2 <= n <= 10^6`
- `0 <= arr[i] <= 10^9`

**Examples**:

- Input: `arr = [1, 2, 4, 7, 7, 5]`
Output: `[5, 2]`
Explanation: Largest = `7`, second largest = `5`, smallest = `1`, second smallest = `2`.
- Input: `arr = [1, 2]`
Output: `[1, 2]`
- Input: `arr = [3, 3, 3]` (not possible due to distinct constraint)

**Key Definitions**:

- **Second Largest**: Second highest value (strictly less than largest).
- **Second Smallest**: Second lowest value (strictly greater than smallest).
- **Hinglish**: Dusra sabse bada aur dusra sabse chhota number dhoondhna hai.

**Prerequisite**:

- Array traversal, comparison logic.

**Key Observation**:

- Sorting and checking backwards is slow.
- A single pass can track both largest/second largest and smallest/second smallest.

### 🔴 Approach 1: Brute Force (Sorting)

**Thought Process**:

- *What’s the goal?* Find second largest and second smallest.
- *How to model?* Sort the array, largest at `n-1`, check backwards for second largest (not equal to largest), smallest at `0`, check forwards for second smallest.
- *Hinglish*: Array sort karo, last se second largest aur start se second smallest dhoondh lo.

**Examples to Prove Idea**:

- `arr = [1, 2, 4, 7, 7, 5]`, sorted = `[1, 2, 4, 5, 7, 7]`:
    - Largest: `arr[n-1] = 7`.
    - Second largest: Check `n-2` backwards, `arr[4] = 7` (skip), `arr[3] = 5`.
    - Smallest: `arr[0] = 1`.
    - Second smallest: Check `1` forwards, `arr[1] = 2`.
    - Output: `[5, 2]`.
- *Why it works*: Sorting places extremes at ends, but we skip duplicates.

**Intuition**:

Sort the array. Largest is at `n-1`. Traverse backwards from `n-2` to find the first element not equal to largest (second largest). Smallest is at `0`. Traverse forwards from `1` to find second smallest.

**Dry Run**:

- Input: `arr = [1, 2, 4, 7, 7, 5]`.
- Sort: `[1, 2, 4, 5, 7, 7]`.
- Largest: `arr[5] = 7`.
- Second largest: `i=4`: `arr[4] = 7` (skip), `i=3`: `arr[3] = 5` (done).
- Smallest: `arr[0] = 1`.
- Second smallest: `i=1`: `arr[1] = 2` (done).
- Output: `[5, 2]`.
- *Hinglish*: Sort kiya, last se second largest 5 mila, start se second smallest 2 mila.

**Algorithm**:

1. Sort `arr`.
2. Initialize `largest = arr[n-1]`.
3. For `i` from `n-2` to `0`:
    - If `arr[i] != largest`, set `second_largest = arr[i]`, break.
4. Initialize `smallest = arr[0]`.
5. For `i` from `1` to `n-1`:
    - If `arr[i] != smallest`, set `second_smallest = arr[i]`, break.
6. Return `[second_largest, second_smallest]`.

**Pseudocode**:

```cpp
function secondLargestSmallestBrute(arr, n):
    sort(arr)
    largest = arr[n-1]
    second_largest = -1
    for i from n-2 to 0:
        if arr[i] != largest:
            second_largest = arr[i]
            break
    smallest = arr[0]
    second_smallest = INT_MAX
    for i from 1 to n-1:
        if arr[i] != smallest:
            second_smallest = arr[i]
            break
    return [second_largest, second_smallest]

```

**Code**:

```cpp
vector<int> secondLargestSmallestBrute(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int largest = arr[n-1];
    int second_largest = -1;
    for (int i = n-2; i >= 0; i--) {
        if (arr[i] != largest) {
            second_largest = arr[i];
            break;
        }
    }
    int smallest = arr[0];
    int second_smallest = INT_MAX;
    for (int i = 1; i < n; i++) {
        if (arr[i] != smallest) {
            second_smallest = arr[i];
            break;
        }
    }
    return {second_largest, second_smallest};
}

```

**Time Complexity (TC)**:

- Sorting: `O(n log n)`.
- Backward/forward traversal: `O(n)` worst case.
- Total: `O(n log n)`.
- Why? Sorting dominates.

**Space Complexity (SC)**:

- `O(1)` (in-place sorting).
- Why? No extra space used.

**Notes/Observations**:

- *Why brute?* Sorting is simple but slow.
- *Hinglish*: Sort karke second largest aur smallest dhoondha, par time zyada laga.
- *Limitation*: `O(n log n)` is inefficient.

### 🟡 Approach 2: Better (Two Passes)

**Thought Process**:

- *Can we improve?* Avoid sorting by finding largest/smallest in first pass, then second largest/smallest in second pass.
- *How?* Track `largest` and `smallest` in one pass, then track `second_largest` and `second_smallest` in another pass, ensuring they differ from `largest` and `smallest`.
- *Hinglish*: Do baar array ghumo, pehle largest/smallest, phir second largest/smallest dhoondh lo.

**Examples to Prove Idea**:

- `arr = [1, 2, 4, 7, 7, 5]`:
    - First pass: `largest = 7`, `smallest = 1`.
    - Second pass: Check for `second_largest < 7`, get `5`; check for `second_smallest > 1`, get `2`.
    - Output: `[5, 2]`.
- *Why it works*: Two passes ensure we find second extremes without sorting.

**Intuition**:

First pass: Find `largest` and `smallest` by comparing each element. Second pass: Find `second_largest` (less than `largest`, greater than current `second_largest`) and `second_smallest` (greater than `smallest`, less than current `second_smallest`).

**Dry Run**:

- Input: `arr = [1, 2, 4, 7, 7, 5]`.
- First pass:
    - `largest = 1`, `smallest = 1`.
    - `i=1`: `2 > 1` → `largest = 2`, `2 < 1` (no).
    - `i=2`: `4 > 2` → `largest = 4`, `4 < 1` (no).
    - `i=3`: `7 > 4` → `largest = 7`, `7 < 1` (no).
    - `i=4`: `7 > 7` (no), `7 < 1` (no).
    - `i=5`: `5 > 7` (no), `5 < 1` (no).
    - Result: `largest = 7`, `smallest = 1`.
- Second pass:
    - `second_largest = -1`, `second_smallest = INT_MAX`.
    - `i=0`: `1 < 7` and `1 > -1` → `second_largest = 1`, `1 > 1` (no).
    - `i=1`: `2 < 7` and `2 > 1` → `second_largest = 2`, `2 > 1` and `2 < INT_MAX` → `second_smallest = 2`.
    - `i=2`: `4 < 7` and `4 > 2` → `second_largest = 4`, `4 > 1` and `4 < 2` (no).
    - `i=3`: `7 == 7` (skip), `7 > 1` and `7 < 2` (no).
    - `i=4`: `7 == 7` (skip), `7 > 1` and `7 < 2` (no).
    - `i=5`: `5 < 7` and `5 > 4` → `second_largest = 5`, `5 > 1` and `5 < 2` (no).
- Output: `[5, 2]`.
- *Hinglish*: Pehle largest 7 aur smallest 1 mila, doosre pass mein second largest 5 aur second smallest 2 mila.

**Algorithm**:

1. Initialize `largest = arr[0]`, `smallest = arr[0]`.
2. For `i` from `0` to `n-1`:
    - If `arr[i] > largest`, `largest = arr[i]`.
    - If `arr[i] < smallest`, `smallest = arr[i]`.
3. Initialize `second_largest = -1`, `second_smallest = INT_MAX`.
4. For `i` from `0` to `n-1`:
    - If `arr[i] < largest` and `arr[i] > second_largest`, `second_largest = arr[i]`.
    - If `arr[i] > smallest` and `arr[i] < second_smallest`, `second_smallest = arr[i]`.
5. Return `[second_largest, second_smallest]`.

**Pseudocode**:

```cpp
function secondLargestSmallestBetter(arr, n):
    largest = arr[0], smallest = arr[0]
    for i from 0 to n-1:
        if arr[i] > largest:
            largest = arr[i]
        if arr[i] < smallest:
            smallest = arr[i]
    second_largest = -1, second_smallest = INT_MAX
    for i from 0 to n-1:
        if arr[i] < largest and arr[i] > second_largest:
            second_largest = arr[i]
        if arr[i] > smallest and arr[i] < second_smallest:
            second_smallest = arr[i]
    return [second_largest, second_smallest]

```

**Code**:

```cpp
vector<int> secondLargestSmallestBetter(vector<int>& arr) {
    int n = arr.size();
    int largest = arr[0], smallest = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) largest = arr[i];
        if (arr[i] < smallest) smallest = arr[i];
    }
    int second_largest = -1, second_smallest = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (arr[i] < largest && arr[i] > second_largest) second_largest = arr[i];
        if (arr[i] > smallest && arr[i] < second_smallest) second_smallest = arr[i];
    }
    return {second_largest, second_smallest};
}

```

**Time Complexity (TC)**:

- First pass: `O(n)`.
- Second pass: `O(n)`.
- Total: `O(2n) = O(n)`.
- Why? Two linear passes.

**Space Complexity (SC)**:

- `O(1)` (only variables).
- Why? No extra space.

**Notes/Observations**:

- *Why better?* Avoids sorting, uses two passes.
- *Hinglish*: Do pass mein largest/smallest aur second largest/smallest dhoondha, time bacha.
- *Limitation*: Two passes can be optimized to one.

### 🟢 Approach 3: Optimal (Single Pass)

**Thought Process**:

- *Can we do better?* Track largest, second largest, smallest, and second smallest in one pass.
- *How?* Update `largest` and `second_largest` when a larger element is found (previous `largest` becomes `second_largest`). Similarly for `smallest` and `second_smallest`.
- *Hinglish*: Ek hi pass mein sab dhoondh lo, largest update hua to second largest ban jata hai.

**Examples to Prove Idea**:

- `arr = [1, 2, 4, 7, 7, 5]`:
    - Initialize: `largest = 1`, `second_largest = -1`, `smallest = 1`, `second_smallest = INT_MAX`.
    - `i=1`: `2 > 1` → `second_largest = 1`, `largest = 2`; `2 < 1` (no).
    - `i=2`: `4 > 2` → `second_largest = 2`, `largest = 4`; `4 < 1` (no).
    - `i=3`: `7 > 4` → `second_largest = 4`, `largest = 7`; `7 < 1` (no).
    - `i=4`: `7 == 7` (skip); `7 < 1` (no).
    - `i=5`: `5 < 7` and `5 > 4` → `second_largest = 5`; `5 > 1` and `5 < INT_MAX` → `second_smallest = 5`.
    - Output: `[5, 2]`.
- *Why it works*: Single pass updates all four values efficiently.

**Intuition**:

Initialize `largest` and `smallest` with `arr[0]`, `second_largest` with `-1`, `second_smallest` with `INT_MAX`. For each element, update `largest` (moving previous `largest` to `second_largest`) or `second_largest` if less than `largest`. Similarly, update `smallest` (moving previous `smallest` to `second_smallest`) or `second_smallest` if greater than `smallest`.

**Dry Run**:

- Input: `arr = [1, 2, 4, 7, 7, 5]`.
- Initialize: `largest = 1`, `second_largest = -1`, `smallest = 1`, `second_smallest = INT_MAX`.
- Steps:
    - `i=1`: `2 > 1` → `second_largest = 1`, `largest = 2`; `2 < 1` (no).
    - `i=2`: `4 > 2` → `second_largest = 2`, `largest = 4`; `4 < 1` (no).
    - `i=3`: `7 > 4` → `second_largest = 4`, `largest = 7`; `7 < 1` (no).
    - `i=4`: `7 == 7` (skip); `7 < 1` (no).
    - `i=5`: `5 < 7` and `5 > 4` → `second_largest = 5`; `5 > 1` and `5 < INT_MAX` → `second_smallest = 5`.
- Output: `[5, 2]`.
- *Hinglish*: Ek pass mein largest 7, second largest 5, smallest 1, second smallest 2 mila.

**Algorithm**:

1. Initialize `largest = arr[0]`, `second_largest = -1`, `smallest = arr[0]`, `second_smallest = INT_MAX`.
2. For `i` from `1` to `n-1`:
    - If `arr[i] > largest`: `second_largest = largest`, `largest = arr[i]`.
    - Else if `arr[i] < largest` and `arr[i] > second_largest`: `second_largest = arr[i]`.
    - If `arr[i] < smallest`: `second_smallest = smallest`, `smallest = arr[i]`.
    - Else if `arr[i] > smallest` and `arr[i] < second_smallest`: `second_smallest = arr[i]`.
3. Return `[second_largest, second_smallest]`.

**Pseudocode**:

```cpp
function secondLargestSmallestOptimal(arr, n):
    largest = arr[0], second_largest = -1
    smallest = arr[0], second_smallest = INT_MAX
    for i from 1 to n-1:
        if arr[i] > largest:
            second_largest = largest
            largest = arr[i]
        else if arr[i] < largest and arr[i] > second_largest:
            second_largest = arr[i]
        if arr[i] < smallest:
            second_smallest = smallest
            smallest = arr[i]
        else if arr[i] > smallest and arr[i] < second_smallest:
            second_smallest = arr[i]
    return [second_largest, second_smallest]

```

**Code**:

```cpp
vector<int> secondLargestSmallestOptimal(vector<int>& arr) {
    int n = arr.size();
    int largest = arr[0], second_largest = -1;
    int smallest = arr[0], second_smallest = INT_MAX;
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } else if (arr[i] < largest && arr[i] > second_largest) {
            second_largest = arr[i];
        }
        if (arr[i] < smallest) {
            second_smallest = smallest;
            smallest = arr[i];
        } else if (arr[i] > smallest && arr[i] < second_smallest) {
            second_smallest = arr[i];
        }
    }
    return {second_largest, second_smallest};
}

```

**Time Complexity (TC)**:

- Single pass: `O(n)`.
- Total: `O(n)`.
- Why? One linear pass.

**Space Complexity (SC)**:

- `O(1)` (only variables).
- Why? No extra space.

**Notes/Observations**:

- *Why optimal?* Achieves `O(n)` time with `O(1)` space in one pass.
- *Hinglish*: Ek hi pass mein sab dhoondh liya, time aur space bacha.
- *Edge Cases*:
    - `n=2`: Second largest = smaller element, second smallest = larger element.
    - Non-negative distinct integers ensure second largest/smallest exist.