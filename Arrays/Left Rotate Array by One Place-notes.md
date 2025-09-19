## Problem: Rotate Array by One Position (Left Rotation)

Problem Link https://www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1

**Problem Statement**:

Given an array of `n` integers, rotate the array by **one position to the left** (counter-clockwise). The first element moves to the end, and all other elements shift one position left. The operation should be performed in-place where possible. The array may contain duplicates.

**Breakdown**:

- **Input**: Array of integers `arr`.
- **Output**: Array rotated in-place by one position to the left.
- **What We Need to Do**: Shift each element one position left, move the first element to the end.
- **Why is This a Problem?** Requires efficient in-place manipulation while handling edge cases like empty arrays or single elements.
- **Hinglish**: Array diya hai, ek position left rotate karna hai, pehla element end mein jata hai, baaki ek step left shift.

**Constraints**:

- `1 ≤ arr.size() ≤ 10^5`
- `10^9 ≤ arr[i] ≤ 10^9`

**Examples**:

- **Example 1**:
    - Input: `arr = [10,20,30,40,50]`
    - Output: `[20,30,40,50,10]`
    - Explanation: First element `10` moves to end, others shift left.
- **Example 2**:
    - Input: `arr = [1]`
    - Output: `[1]`
    - Explanation: Single element, no change.
- **Example 3**:
    - Input: `arr = [1,2]`
    - Output: `[2,1]`
    - Explanation: `1` moves to end, `2` to start.

**Key Definitions**:

- **Left Rotation by One**: Each element moves one position left, first element wraps to end.
- **In-Place**: Modify array without using extra space proportional to input size.
- **Hinglish**: Left rotation: Har element ek step left, pehla element last mein. In-place: Bina extra array ke kaam karo.

**Prerequisites**:

- Understanding of array indexing and shifting.
- Familiarity with STL functions like `rotate` and `reverse` for optimal solutions.

**Problem Links**:

- [GeeksforGeeks: Cyclically Rotate an Array by One](https://www.geeksforgeeks.org/cyclically-rotate-an-array-by-one/)
- Related: [LeetCode 189: Rotate Array](https://leetcode.com/problems/rotate-array/) (generalized for `k` rotations)

---

### Approaches for Rotate Array by One Position (Left Rotation)

### 🔴 Approach 1: Brute Force (Shift with Temp Variable)

**Thought Process**:

- **Goal**: Rotate array left by one position in-place.
- **How?** Save the first element in a variable, shift all other elements left by one, then place the saved element at the end.
- **Benefit?** Simple, intuitive, and in-place with minimal extra space (just one variable).
- **Drawback?** Requires shifting each element individually.
- **Hinglish**: Pehla element save karo, baaki ko ek step left shift, saved element end mein daal do.

**Examples to Prove Idea**:

- `arr = [10,20,30,40,50]`:
    - Save `10`, shift `[20,30,40,50]` to `[20,30,40,50,*]`, place `10` at end → `[20,30,40,50,10]`.
- `arr = [1,2]`:
    - Save `1`, shift `[2]` to `[2,*]`, place `1` at end → `[2,1]`.

**Intuition**:
Like sliding elements one step left, with the first element jumping to the end.

**Dry Run**:

- Input: `arr = [10,20,30,40,50]`
- Step 1: Save `first = 10`
- Step 2: Shift left:
    - `arr[0] = arr[1] = 20`
    - `arr[1] = arr[2] = 30`
    - `arr[2] = arr[3] = 40`
    - `arr[3] = arr[4] = 50`
    - `arr = [20,30,40,50,50]`
- Step 3: Place `first` at `n-1`: `arr[4] = 10`
- Output: `[20,30,40,50,10]`
- **Hinglish**: `10` save kiya, baaki left shift, `10` last mein daala.

**Algorithm**:

1. If array is empty, return.
2. Save `arr[0]` in `first`.
3. For `i` from `0` to `n-2`, set `arr[i] = arr[i+1]`.
4. Set `arr[n-1] = first`.

**Pseudocode**:

```cpp
function leftRotateByOne(arr):
    if arr.empty(): return
    n = arr.size
    first = arr[0]
    for i from 0 to n-2:
        arr[i] = arr[i+1]
    arr[n-1] = first

```

**Code**:

```cpp
void leftRotateByOne(vector<int>& arr) {
    if (arr.empty()) return; // Edge case
    int n = arr.size();
    int first = arr[0]; // Save first element
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1]; // Shift left
    }
    arr[n - 1] = first; // Place first at end
}

```

**Time Complexity (TC)**:

- `O(n)`: Shift `n-1` elements, one assignment for last.
- **Why?** Linear traversal for shifting.

**Space Complexity (SC)**:

- `O(1)`: Only one variable (`first`).
- **Why?** In-place, minimal extra space.

**Notes/Observations**:

- **Why Simple?** Easy to understand, minimal code.
- **Hinglish**: Bas pehla save, shift karo, end mein daal do.
- **Drawback**: Not extensible for `k` rotations without repetition.

---

### 🟡 Approach 2: STL rotate()

**Thought Process**:

- **Goal**: Use a built-in function for clean, efficient code.
- **How?** Use `std::rotate` from `<algorithm>`, which shifts elements left by one position in-place.
- **Benefit?** Concise, reliable, optimized by STL.
- **Drawback?** Interviewer may ask for manual implementation.
- **Hinglish**: STL ka `rotate` use karo, ek line mein kaam ho jayega.

**Examples to Prove Idea**:

- `arr = [10,20,30,40,50]`:
    - `rotate(arr.begin(), arr.begin()+1, arr.end())` → `[20,30,40,50,10]`.
- `arr = [1,2]`:
    - `rotate` → `[2,1]`.

**Intuition**:
STL `rotate` performs the exact left shift we need, handling all edge cases internally.

**Dry Run**:

- Input: `arr = [10,20,30,40,50]`
- Step 1: Call `rotate(arr.begin(), arr.begin()+1, arr.end())`
- Internally: Shifts `[20,30,40,50]` to start, moves `10` to end.
- Output: `[20,30,40,50,10]`
- **Hinglish**: STL ne ek line mein shift kar diya, `10` end mein chala gaya.

**Algorithm**:

1. If array is empty, return.
2. Call `rotate(arr.begin(), arr.begin()+1, arr.end())`.

**Pseudocode**:

```cpp
function leftRotateByOne(arr):
    if arr.empty(): return
    rotate(arr.begin(), arr.begin()+1, arr.end())

```

**Code**:

```cpp
#include <algorithm>
void leftRotateByOne(vector<int>& arr) {
    if (arr.empty()) return; // Edge case
    rotate(arr.begin(), arr.begin() + 1, arr.end()); // STL rotate
}

```

**Time Complexity (TC)**:

- `O(n)`: STL `rotate` performs linear shifting.
- **Why?** Internally shifts elements like brute force.

**Space Complexity (SC)**:

- `O(1)`: In-place operation.
- **Why?** No extra space used.

**Notes/Observations**:

- **Why Use?** Clean, production-ready code.
- **Hinglish**: STL ka shortcut, ek line mein done.
- **Drawback**: May need to explain internal logic if asked.

---

### 🔵 Approach 3: Temporary Array

**Thought Process**:

- **Goal**: Rotate using a new array for simplicity.
- **How?** Create a new array, place `arr[i]` at `rotated[i-1]` for `i=1` to `n-1`, and `arr[0]` at `rotated[n-1]`, then copy back.
- **Benefit?** Easy to implement, clear logic.
- **Drawback?** Not in-place, uses O(n) space.
- **Hinglish**: Naya array banao, elements shift karke daal do, wapas copy karo.

**Examples to Prove Idea**:

- `arr = [10,20,30,40,50]`:
    - New array: `rotated[0] = arr[1] = 20`, ..., `rotated[3] = arr[4] = 50`, `rotated[4] = arr[0] = 10`.
    - Result: `[20,30,40,50,10]`.
- `arr = [1,2]`:
    - `rotated[0] = arr[1] = 2`, `rotated[1] = arr[0] = 1` → `[2,1]`.

**Intuition**:
Create a new array with shifted positions, then overwrite original array.

**Dry Run**:

- Input: `arr = [10,20,30,40,50]`
- Step 1: `rotated = [0,0,0,0,0]`
- Step 2: For `i=1` to `4`: `rotated[i-1] = arr[i]`
    - `rotated[0] = arr[1] = 20`
    - `rotated[1] = arr[2] = 30`
    - `rotated[2] = arr[3] = 40`
    - `rotated[3] = arr[4] = 50`
- Step 3: `rotated[4] = arr[0] = 10`
- Step 4: Copy `rotated` to `arr`: `arr = [20,30,40,50,10]`
- Output: `[20,30,40,50,10]`
- **Hinglish**: Naya array mein shift karke daala, `10` last mein, fir copy kiya.

**Algorithm**:

1. If array is empty, return.
2. Create `rotated` array of size `n`.
3. For `i=1` to `n-1`, set `rotated[i-1] = arr[i]`.
4. Set `rotated[n-1] = arr[0]`.
5. Copy `rotated` to `arr`.

**Pseudocode**:

```cpp
function leftRotateByOne(arr):
    if arr.empty(): return
    n = arr.size
    rotated = vector<int>(n)
    for i from 1 to n-1:
        rotated[i-1] = arr[i]
    rotated[n-1] = arr[0]
    arr = rotated

```

**Code**:

```cpp
void leftRotateByOne(vector<int>& arr) {
    if (arr.empty()) return; // Edge case
    int n = arr.size();
    vector<int> rotated(n);
    for (int i = 1; i < n; i++) {
        rotated[i - 1] = arr[i]; // Shift elements
    }
    rotated[n - 1] = arr[0]; // Place first at end
    arr = rotated; // Copy back
}

```

**Time Complexity (TC)**:

- `O(n)`: Fill `rotated` (O(n)), copy back (O(n)).
- **Why?** Linear operations for shifting and copying.

**Space Complexity (SC)**:

- `O(n)`: Temporary array of size `n`.
- **Why?** Full array duplicated.

**Notes/Observations**:

- **Why Use?** Simple but space-heavy.
- **Hinglish**: Naya array banaya, shift karke daala, copy kiya.
- **Drawback**: Not in-place, high space usage.

---

### 🟢 Bonus Approach: Reversal Algorithm (For k Rotations)

**Thought Process**:

- **Goal**: Handle the interviewer’s twist for rotating by `k` positions left.
- **How?** Use reversal trick: reverse first `k`, reverse remaining `n-k`, reverse entire array.
- **Benefit?** In-place, extensible to any `k`, elegant.
- **Hinglish**: `k` positions ke liye pehle `k` reverse, baaki reverse, pura reverse.

**Examples to Prove Idea**:

- `arr = [10,20,30,40,50], k = 1`:
    - Reverse `[10]`: `[10,20,30,40,50]`
    - Reverse `[20,30,40,50]`: `[10,50,40,30,20]`
    - Reverse all: `[20,30,40,50,10]`
- `arr = [10,20,30,40,50], k = 3`:
    - Reverse `[10,20,30]`: `[30,20,10,40,50]`
    - Reverse `[40,50]`: `[30,20,10,50,40]`
    - Reverse all: `[40,50,10,20,30]`

**Intuition**:
Reversing parts swaps blocks, final reversal aligns them for left rotation.

**Dry Run (k = 1)**:

- Input: `arr = [10,20,30,40,50], k = 1`
- Step 1: `k = 1 % 5 = 1`, reverse `[0,0]`: `[10,20,30,40,50]`
- Step 2: Reverse `[1,4]`: `[10,50,40,30,20]`
- Step 3: Reverse `[0,4]`: `[20,30,40,50,10]`
- Output: `[20,30,40,50,10]`
- **Hinglish**: Pehla reverse, baaki reverse, pura reverse kiya.

**Algorithm**:

1. Compute `k = k % n`.
2. If `k == 0`, return.
3. Reverse indices `0` to `k-1`.
4. Reverse indices `k` to `n-1`.
5. Reverse indices `0` to `n-1`.

**Pseudocode**:

```cpp
function leftRotateByK(arr, k):
    n = arr.size
    k = k % n
    if k == 0: return
    reverse(arr, 0, k-1)
    reverse(arr, k, n-1)
    reverse(arr, 0, n-1)

```

**Code**:

```cpp
#include <algorithm>
void leftRotateByK(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n; // Handle k > n
    if (k == 0) return;
    reverse(arr.begin(), arr.begin() + k); // Reverse first k
    reverse(arr.begin() + k, arr.end()); // Reverse remaining
    reverse(arr.begin(), arr.end()); // Reverse all
}

```

**Time Complexity (TC)**:

- `O(n)`: Three reversals: O(k) + O(n-k) + O(n) ≈ O(n).
- **Why?** Total elements reversed is `n`.

**Space Complexity (SC)**:

- `O(1)`: In-place reversals.
- **Why?** No extra space used.

**Notes/Observations**:

- **Why Optimal?** In-place, works for any `k`, elegant.
- **Hinglish**: Reverse trick se `k` rotation bhi ho gaya, space nahi laga.
- **Key Insight**: Reversals rearrange blocks naturally.

---

### Final Consolidated Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 🔴 Approach 1: Brute Force (Shift with Temp Variable)
    void leftRotateByOneBrute(vector<int>& arr) {
        if (arr.empty()) return;
        int n = arr.size();
        int first = arr[0];
        for (int i = 0; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[n - 1] = first;
    }

    // 🟡 Approach 2: STL rotate()
    void leftRotateByOneSTL(vector<int>& arr) {
        if (arr.empty()) return;
        rotate(arr.begin(), arr.begin() + 1, arr.end());
    }

    // 🔵 Approach 3: Temporary Array
    void leftRotateByOneTemp(vector<int>& arr) {
        if (arr.empty()) return;
        int n = arr.size();
        vector<int> rotated(n);
        for (int i = 1; i < n; i++) {
            rotated[i - 1] = arr[i];
        }
        rotated[n - 1] = arr[0];
        arr = rotated;
    }

    // 🟢 Bonus: Reversal Algorithm (for k rotations)
    void leftRotateByK(vector<int>& arr, int k) {
        int n = arr.size();
        k = k % n;
        if (k == 0) return;
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.end());
        reverse(arr.begin(), arr.end());
    }
};

int main() {
    vector<int> arr1 = {10, 20, 30, 40, 50};
    vector<int> arr2 = {10, 20, 30, 40, 50};
    vector<int> arr3 = {10, 20, 30, 40, 50};
    vector<int> arr4 = {10, 20, 30, 40, 50};
    int k = 1; // For k rotations
    Solution sol;

    // Test Approach 1: Brute Force
    cout << "Brute Force (Shift):\\n";
    sol.leftRotateByOneBrute(arr1);
    for (int x : arr1) cout << x << " "; // Expected: 20 30 40 50 10
    cout << endl;

    // Test Approach 2: STL rotate
    cout << "STL rotate():\\n";
    sol.leftRotateByOneSTL(arr2);
    for (int x : arr2) cout << x << " "; // Expected: 20 30 40 50 10
    cout << endl;

    // Test Approach 3: Temporary Array
    cout << "Temporary Array:\\n";
    sol.leftRotateByOneTemp(arr3);
    for (int x : arr3) cout << x << " "; // Expected: 20 30 40 50 10
    cout << endl;

    // Test Bonus: Reversal for k=1
    cout << "Reversal (k=1):\\n";
    sol.leftRotateByK(arr4, k);
    for (int x : arr4) cout << x << " "; // Expected: 20 30 40 50 10
    cout << endl;

    return 0;
}

```

---

### Key Points for Interview

- **Brute Force**: `O(n)`, `O(1)` – Simple shift, in-place, intuitive.
- **STL rotate**: `O(n)`, `O(1)` – Clean, production-ready, but may need explanation.
- **Temporary Array**: `O(n)`, `O(n)` – Easy but space-heavy, not in-place.
- **Reversal (k rotations)**: `O(n)`, `O(1)` – Optimal for any `k`, impresses with elegance.
- **Hinglish**: Interview mein brute se shuru karo, STL ka shortcut batao, reversal se impress karo, `k` rotation ke liye ready raho.
- **Edge Cases**:
    - Empty array: Return.
    - Single element: `[1]` → `[1]`.
    - Duplicates: Handled naturally.
- **Key Insight**: Reversal is versatile for any `k`, in-place, and elegant.

---

### Addressing Doubts from Provided Context

1. **Misinterpretation of Rotation Direction**:
    - The provided context mentions "clockwise" rotation as moving the last element to the first position, which is typically **right rotation** (e.g., `[1,2,3,4,5]` → `[5,1,2,3,4]`). However, the interview tone and code examples focus on **left rotation by one** (`[1,2,3,4,5]` → `[2,3,4,5,1]`). To resolve this, I’ve clarified that the problem statement in the interview tone specifies **left rotation by one**, and I’ve provided solutions for left rotation. If right rotation is needed, the reversal algorithm can be adapted (reverse all, then reverse `0` to `n-2`).
2. **Reversal Algorithm for One Position**:
    - The provided context includes a reversal approach for right rotation by one (`reverse all, reverse 1 to n-1`). For left rotation by one, the reversal approach is less intuitive but can be used as shown in the bonus section for `k=1`. I included it as a bonus to address the `k` rotation twist.
3. **Why Include STL rotate()?**:
    - The provided context doesn’t use STL `rotate`, but it’s a practical approach for interviews to show knowledge of standard libraries. I included it as a clean, optimized option.
4. **Temporary Array vs. In-Place**:
    - The provided context notes the temporary array approach uses O(n) space and isn’t in-place. I clarified this drawback and contrasted it with the in-place brute force and reversal methods.
5. **Handling k Rotations**:
    - The bonus section addresses the interviewer’s twist for `k` rotations, using the reversal algorithm, which is optimal and extensible.
6. **Edge Cases**:
    - Addressed empty array, single element, and duplicates explicitly in all approaches.

---

### Additional Notes for Beginners

- **Why Rotation by One?** Teaches basic array manipulation and in-place techniques.
- **Hinglish**:
    - Brute: Pehla element save, baaki left shift, end mein daal do.
    - STL: Ek line mein STL ne shift kar diya.
    - Temp Array: Naya array mein shift karke copy kiya.
    - Reversal: `k` ke liye reverse trick se blocks swap.
- **Practice**:
    - `[10,20,30,40,50]` → `[20,30,40,50,10]`
    - `[1,2]` → `[2,1]`
- **Related Problems**:
    - [LeetCode 189: Rotate Array](https://leetcode.com/problems/rotate-array/)
    - [GeeksforGeeks: Cyclically Rotate an Array by One](https://www.geeksforgeeks.org/cyclically-rotate-an-array-by-one/)