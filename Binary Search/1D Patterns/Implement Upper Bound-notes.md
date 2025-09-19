## Upper Bound in a Sorted Array

Problem Link - [Upper Bound](https://www.geeksforgeeks.org/problems/implement-upper-bound/1)

**Problem Statement**:

Given a sorted array of integers `arr` (in ascending order, may contain duplicates) and a target value `x`, find the **smallest index** `i` such that `arr[i] > x` (strictly greater than `x`). If no such element exists, return the array length `n` (hypothetical index).

**Breakdown**:

- **Input**:
    - `arr`: Sorted array of integers (may have duplicates).
    - `x`: Target integer.
- **Output**: Integer representing the smallest index `i` where `arr[i] > x`, or `n` if no such element exists.
- **Objective**: Use Binary Search to efficiently find the smallest index by leveraging the sorted property of the array.
- **Why is This a Problem?**: Linear search takes `O(n)` time, which is slow for large arrays. Binary Search reduces this to `O(log n)` by halving the search space.
- *Hinglish*: Sorted array mein `x` se strictly bada wala pehla index dhoondhna hai. Linear search slow hai, Binary Search se jaldi milega.

**Constraints**:

- `1 <= arr.length <= 10^5`.
- `10^4 <= arr[i], x <= 10^4`.
- Array is sorted in ascending order, may contain duplicates.

**Examples**:

- **Example 1**: `arr = [1,2,8,10,10,12,19]`, `x = 8` → Output: `3` (`arr[3] = 10 > 8`).
- **Example 2**: `arr = [1,2,8,10,10,12,19]`, `x = 9` → Output: `3` (`arr[3] = 10 > 9`).
- **Example 3**: `arr = [1,2,8,10,10,12,19]`, `x = 19` → Output: `7` (no element `> 19`, return `n`).
- **Example 4**: `arr = [1,2,8,10,10,12,19]`, `x = 0` → Output: `0` (`arr[0] = 1 > 0`).

**Key Definitions**:

- **Upper Bound**: The smallest index `i` where `arr[i] > x` (strictly greater than `x`).
- **Hypothetical Index**: If no element satisfies `arr[i] > x`, return `n`, indicating `x` is larger than all elements.
- *Hinglish*: Upper bound matlab `x` se strictly bada wala sabse pehla index. Agar nahi milta to `n` return karo, matlab array ke baad insert hoga.

**Concepts** (from Lecture):

- **Binary Search for Upper Bound**: Similar to Lower Bound, Binary Search finds the target efficiently in a sorted array by halving the search space. For Upper Bound, we check if `arr[mid] > x` (strictly greater). If true, this is a candidate for the answer, but we search left to find a smaller index. If `arr[mid] <= x`, we search right since those elements can’t satisfy the condition.
- **Key Property**: The array must be sorted, allowing us to eliminate half the search space each step.
- **Answer Variable**: Use an `ans` variable to store the smallest valid index, initialized to `n` (hypothetical index if no element is found).
- **Overflow Handling**: Calculate `mid` as `low + (high - low) / 2` to avoid integer overflow when `low + high` is large.
- *Hinglish*: Binary Search mein `arr[mid] > x` check karo. Agar true hai to index save karo par left jao kyunki chhota index chahiye. `arr[mid] <= x` ho to right jao. `mid` nikalte waqt overflow se bachne ke liye `low + (high - low) / 2` use karo.
- **Time Complexity**: `O(log n)` because the search space halves each step.
- **Space Complexity**: `O(1)` for iterative approach, `O(log n)` for recursive due to call stack.
- **Why Important?**: Upper Bound complements Lower Bound and is used in standard libraries (e.g., C++ STL `upper_bound`) and many Binary Search problems.

---

### Approaches for Upper Bound

### 🔴 Approach 1: Linear Search

**Thought Process**:

- **Goal**: Find the smallest index `i` where `arr[i] > x`, or return `n` if none exists.
- **How to Model**: Iterate through the array from index `0` to `n-1`. Return the first index `i` where `arr[i] > x`. If no such index is found, return `n`.
- **Choices**: Linear search is simple but doesn’t leverage the sorted property, making it inefficient for large arrays.
- **Constraints**: `O(n)` time, `O(1)` space.
- *Hinglish*: Har element ko ek-ek karke check karo. Jahan pehla `arr[i] > x` mile, wahi index return karo. Simple hai par slow kyunki sorted ka fayda nahi liya.

**Examples to Prove Idea**:

- `arr = [1,2,8,10,10,12,19]`, `x = 8`:
    - Check: `1 < 8`, `2 < 8`, `8 == 8`, `10 > 8` → return `3`.
- `arr = [1,2,8,10,10,12,19]`, `x = 19`:
    - All elements `<= 19` → return `7` (array length).
- *Why It Works*: Sequentially checks each element, ensuring the first index satisfying `> x` is returned.

**Intuition**:
Loop through the array from start to end. As soon as `arr[i] > x` is found, return `i` since it’s the smallest index (due to sequential checking). If no element satisfies, return `n`. The approach is intuitive but slow because it ignores the sorted nature of the array.

**Dry Run**:

- Input: `arr = [1,2,8,10,10,12,19]`, `x = 8`, `n = 7`.
- Loop:
    - `i=0`: `arr[0] = 1 < 8`. **Reason**: `1` is less than `8`, doesn’t satisfy `> 8`, move to next index.
    - `i=1`: `arr[1] = 2 < 8`. **Reason**: `2` is less than `8`, continue.
    - `i=2`: `arr[2] = 8 == 8`. **Reason**: `8` equals `x`, not `> x`, continue.
    - `i=3`: `arr[3] = 10 > 8`. **Reason**: `10` satisfies `> 8`, and it’s the first such index, so return `3`.
- Return: `3`.
- *Hinglish*: Ek-ek karke check kiya: `1 < 8`, `2 < 8`, `8 == 8`, `10 > 8`. Index `3` pe condition mili, to `3` return karo.

**Algorithm**:

1. Iterate `i` from `0` to `arr.length - 1`:
    - If `arr[i] > x`, return `i`.
2. Return `arr.length`.

**Pseudocode**:

```cpp
function upperBoundLinear(arr, x):
    for i from 0 to arr.length - 1:
        if arr[i] > x:
            return i
    return arr.length

```

**Code**:

```cpp
#include <bits/stdc++.h>
using namespace std;

int upperBoundLinear(vector<int>& arr, int x) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > x) return i;
    }
    return arr.size();
}

```

**Java Equivalent**:

```java
class Solution {
    public int upperBoundLinear(int[] arr, int x) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > x) return i;
        }
        return arr.length;
    }
}

```

**Time Complexity (TC)**:

- `O(n)`: In the worst case (e.g., `x` larger than or equal to all elements), it checks every element.
- *Why?*: Linearly traverses the array without leveraging the sorted property.

**Space Complexity (SC)**:

- `O(1)`: Only uses a loop variable.
- *Why?*: No additional data structures are needed.

**Notes/Observations**:

- *Why this approach?*: Easy to implement and understand, good for small arrays or as a baseline for interviews.
- *Hinglish*: Yeh approach simple hai, bas har element check karo. Par bade array ke liye slow hai kyunki sorted ka fayda nahi liya.
- *Limitation*: Inefficient for large `n` (e.g., `10^5`), where Binary Search is better.

---

### 🟢 Approach 2: Binary Search (Optimized)

**Thought Process**:

- **Goal**: Find the smallest index `i` where `arr[i] > x`, or return `n`.
- **How to Model**: Use Binary Search with two pointers (`low` and `high`) to define the search space. Initialize `ans = arr.length` to handle cases where no element satisfies `> x`. Compute the middle index (`mid`). If `arr[mid] > x`, store `mid` in `ans` and search left to find a potentially smaller index. If `arr[mid] <= x`, search right since those elements can’t satisfy the condition.
- **Choices**: Iterative Binary Search is preferred for `O(1)` space over recursive, and the `ans` variable ensures we track the smallest valid index.
- **Constraints**: `O(log n)` time, `O(1)` space.
- *Hinglish*: Binary Search se search space aadha karo. `arr[mid] > x` ho to `ans` mein `mid` rakho aur chhota index dhoondhne left jao. Agar `arr[mid] <= x` ho to right jao kyunki wo elements kaam nahi karenge.

**Examples to Prove Idea**:

- `arr = [1,2,8,10,10,12,19]`, `x = 8`:
    - Start: `low=0`, `high=6`, `ans=7`. `mid=3`, `arr[3]=10 > 8` → set `ans=3`, search left (`high=2`).
    - `mid=1`, `arr[1]=2 < 8` → search right (`low=2`).
    - `mid=2`, `arr[2]=8 == 8` → search right (`low=3`). Stop, return `ans=3`.
- `arr = [1,2,8,10,10,12,19]`, `x = 19`:
    - All `arr[mid] <= 19`, keep searching right, `ans` stays `7` → return `7`.
- *Why It Works*: The sorted property allows us to eliminate half the search space, and `ans` tracks the smallest index satisfying `> x`.

**Intuition**:
Maintain a search space with `low` and `high`. Compute `mid` and check `arr[mid] > x`:

- If true, `mid` is a candidate, but search left (`high = mid-1`) for a smaller index.
- If false (`arr[mid] <= x`), search right (`low = mid+1`) since elements at or before `mid` are too small or equal.
- Use `ans` to store the smallest valid index, defaulting to `n`. Stop when `low > high`, return `ans`.
The sorted array ensures we can safely eliminate half the elements each step.

**Dry Run**:

- Input: `arr = [1,2,8,10,10,12,19]`, `x = 8`, `n = 7`.
- Initialize: `low = 0`, `high = 6`, `ans = 7`.
- **Step 1**:
    - Compute: `mid = (0 + 6) / 2 = 3`.
    - Check: `arr[3] = 10 > 8`. **Reason**: `10` satisfies `> 8`, so index `3` is a candidate for the smallest index. Store `ans = 3` and search left (`high = mid-1 = 2`) to find a potentially smaller index, since we want the smallest `i` where `arr[i] > x`.
- **Step 2**:
    - Compute: `mid = (0 + 2) / 2 = 1`.
    - Check: `arr[1] = 2 < 8`. **Reason**: `2` is less than `8`, so no index at or before `mid=1` can satisfy `> 8` (since array is sorted, `arr[0]=1` is even smaller). Search right (`low = mid+1 = 2`) to find larger elements.
- **Step 3**:
    - Compute: `mid = (2 + 2) / 2 = 2`.
    - Check: `arr[2] = 8 == 8`. **Reason**: `8` equals `x`, not `> x`, so index `2` doesn’t satisfy. Search right (`low = mid+1 = 3`) to check larger elements.
- **Step 4**:
    - Check: `low = 3 > high = 2`. **Reason**: Search space is exhausted (`low > high`). The last stored `ans = 3` is the smallest index where `arr[3] = 10 > 8`.
- Return: `3`.
- *Hinglish*: Shuru mein `low=0`, `high=6`, `ans=7`. `mid=3` pe `10 > 8`, to `ans=3` aur left jao (`high=2`) kyunki chhota index chahiye. Phir `mid=1` pe `2 < 8`, to right jao (`low=2`). Phir `mid=2` pe `8 == 8`, to right jao (`low=3`) kyunki `> 8` chahiye. Ab `low > high`, to `ans=3` return karo.

**Dry Run (Edge Case)**:

- Input: `arr = [1,2,8,10,10,12,19]`, `x = 19`, `n = 7`.
- Initialize: `low = 0`, `high = 6`, `ans = 7`.
- **Step 1**:
    - Compute: `mid = (0 + 6) / 2 = 3`.
    - Check: `arr[3] = 10 < 19`. **Reason**: `10` is less than `19`, so indices `0` to `3` won’t satisfy `> 19`. Search right (`low = mid+1 = 4`).
- **Step 2**:
    - Compute: `mid = (4 + 6) / 2 = 5`.
    - Check: `arr[5] = 12 < 19`. **Reason**: `12` is less than `19`, so indices `4` and below won’t work. Search right (`low = mid+1 = 6`).
- **Step 3**:
    - Compute: `mid = (6 + 6) / 2 = 6`.
    - Check: `arr[6] = 19 == 19`. **Reason**: `19` equals `x`, not `> x`, so index `6` doesn’t satisfy. Search right (`low = mid+1 = 7`).
- **Step 4**:
    - Check: `low = 7 > high = 6`. **Reason**: No element `> 19` found, so `ans` remains `7` (hypothetical index).
- Return: `7`.
- *Hinglish*: Sab elements `<= 19` hain. Har baar right gaye kyunki `arr[mid] <= 19`. Ant mein `low > high`, to `ans=7` return karo.

**Algorithm**:

1. Initialize `low = 0`, `high = arr.length - 1`, `ans = arr.length`.
2. While `low <= high`:
    - Compute `mid = low + (high - low) / 2`.
    - If `arr[mid] > x`, set `ans = mid` and search left (`high = mid - 1`).
    - Else (`arr[mid] <= x`), search right (`low = mid + 1`).
3. Return `ans`.

**Pseudocode**:

```cpp
function upperBound(arr, x):
    low = 0
    high = arr.length - 1
    ans = arr.length
    while low <= high:
        mid = low + (high - low) / 2
        if arr[mid] > x:
            ans = mid
            high = mid - 1
        else:
            low = mid + 1
    return ans

```

**Code**:

```cpp
#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1, ans = arr.size();
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

```

**Java Equivalent**:

```java
class Solution {
    public int upperBound(int[] arr, int x) {
        int low = 0, high = arr.length - 1, ans = arr.length;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
}

```

**Time Complexity (TC)**:

- `O(log n)`: Each iteration halves the search space (e.g., `n=32` takes ~5 steps since `32=2^5`).
- *Why?*: The sorted property allows eliminating half the elements each step, and each comparison is `O(1)`.

**Space Complexity (SC)**:

- `O(1)`: Only uses `low`, `high`, `mid`, and `ans` variables.
- *Why?*: No additional data structures are needed.

**Notes/Observations**:

- *Why this approach?*: Efficient, leverages sorted property, and is standard in interviews (e.g., C++ STL `upper_bound`).
- *Hinglish*: Yeh approach fast hai kyunki search space aadha hota hai har step mein. `ans` variable se smallest index track karo.
- *Limitation*: Requires sorted array. Use `low + (high - low) / 2` to avoid overflow.
- *Edge Cases*:
    - Single element: Check `arr[0] > x`, return `0` or `1`.
    - `x` larger than or equal to all elements: Returns `n`.
    - `x` smaller than all elements: Returns `0` (if `arr[0] > x`).
    - Duplicates: Returns first index where `arr[i] > x`.

---

### Key Points for Interview

- **Linear Approach**: Simple but `O(n)`, useful as a baseline to explain why Binary Search is better.
- **Binary Search**: `O(log n)` time, `O(1)` space, preferred for efficiency.
- *Hinglish*: Interview mein pehle linear approach briefly bolo, phir Binary Search ka logic clear karo. `ans` variable aur left/right move ka reason samjhao.
- **Key Insight**: Use `ans` to track the smallest index, search left when `arr[mid] > x` to minimize it.
- **C++ STL**: `upper_bound(arr.begin(), arr.end(), x) - arr.begin()` gives the same result.
- **Difference from Lower Bound**: Checks `> x` instead of `>= x`, so skips elements equal to `x`.

### Additional Notes for Beginners

- *Why this approach?*: Binary Search is efficient and teaches how to leverage sorted data. Linear search is easier but impractical for large `n`.
- *Hinglish*: Linear mein har element check karo, samajh aata hai par slow. Binary Search mein aadha space hatao, fast hai.
- *Practice*:
    - `arr=[1,2,8,10,10,12,19]`, `x=8` → `3`.
    - `arr=[1,2,8,10,10,12,19]`, `x=19` → `7`.
    - `arr=[1]`, `x=0` → `0`.
- *Edge Cases*:
    - Single element array: Check `arr[0]` against `x`.
    - Empty array: Not applicable per constraints (`n >= 1`).
    - Large `n`: Use overflow-safe `mid` calculation.
