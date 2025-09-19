## Lower Bound in a Sorted Array

Problem Link: [Lower Bound](https://www.geeksforgeeks.org/problems/implement-lower-bound/1)

**Problem Statement**:

Given a sorted array of integers `arr` (in ascending order, may contain duplicates) and a target value `x`, find the **smallest index** `i` such that `arr[i] >= x`. If no such element exists, return the array length `n` (hypothetical index).

**Breakdown**:

- **Input**:
    - `arr`: Sorted array of integers (may have duplicates).
    - `x`: Target integer.
- **Output**: Integer representing the smallest index `i` where `arr[i] >= x`, or `n` if no such element exists.
- **Objective**: Use Binary Search to efficiently find the smallest index by leveraging the sorted property of the array.
- **Why is This a Problem?**: Linear search takes `O(n)` time, which is slow for large arrays. Binary Search reduces this to `O(log n)` by halving the search space.
- *Hinglish*: Sorted array mein `x` se bada ya barabar wala pehla index dhoondhna hai. Linear search slow hai, Binary Search se jaldi milega.

**Constraints**:

- `1 <= arr.length <= 10^5`.
- `10^4 <= arr[i], x <= 10^4`.
- Array is sorted in ascending order, may contain duplicates.

**Examples**:

- **Example 1**: `arr = [1,2,8,10,10,12,19]`, `x = 8` → Output: `2` (`arr[2] = 8 >= 8`).
- **Example 2**: `arr = [1,2,8,10,10,12,19]`, `x = 9` → Output: `3` (`arr[3] = 10 >= 9`).
- **Example 3**: `arr = [1,2,8,10,10,12,19]`, `x = 20` → Output: `7` (no element `>= 20`, return `n`).
- **Example 4**: `arr = [1,2,8,10,10,12,19]`, `x = 1` → Output: `0` (`arr[0] = 1 >= 1`).

**Key Definitions**:

- **Lower Bound**: The smallest index `i` where `arr[i] >= x`.
- **Hypothetical Index**: If no element satisfies `arr[i] >= x`, return `n` (array length), indicating `x` would be inserted at the end.
- *Hinglish*: Lower bound matlab `x` se bada ya barabar wala sabse pehla index. Agar nahi milta to `n` return karo, matlab array ke baad insert hoga.

**Concepts** (from Lecture):

- **Binary Search for Lower Bound**: Binary Search finds the target efficiently in a sorted array by halving the search space. For Lower Bound, we check if `arr[mid] >= x`. If true, this is a candidate for the answer, but we search left to find a smaller index. If `arr[mid] < x`, we search right since smaller elements can’t satisfy the condition.
- **Key Property**: The array must be sorted to apply Binary Search, allowing us to eliminate half the search space each step.
- **Answer Variable**: Use an `ans` variable to store the smallest valid index, initialized to `n` (hypothetical index if no element is found).
- **Overflow Handling**: Calculate `mid` as `low + (high - low) / 2` to avoid integer overflow when `low + high` is large.
- *Hinglish*: Binary Search mein array sorted hona chahiye. `arr[mid] >= x` ho to index save karo par left jao kyunki chhota index chahiye. `mid` nikalte waqt overflow se bachne ke liye `low + (high - low) / 2` use karo.
- **Time Complexity**: `O(log n)` because the search space halves each step.
- **Space Complexity**: `O(1)` for iterative approach, `O(log n)` for recursive due to call stack.
- **Why Important?**: Lower Bound is a foundational concept for many Binary Search problems and is used in standard libraries (e.g., C++ STL `lower_bound`).

---

### Approaches for Lower Bound

### 🔴 Approach 1: Linear Search

**Thought Process**:

- **Goal**: Find the smallest index `i` where `arr[i] >= x`, or return `n` if none exists.
- **How to Model**: Iterate through the array from index `0` to `n-1`. Return the first index `i` where `arr[i] >= x`. If no such index is found, return `n`.
- **Choices**: Linear search is straightforward but doesn’t use the sorted property, making it inefficient for large arrays.
- **Constraints**: `O(n)` time, `O(1)` space.
- *Hinglish*: Har element ko ek-ek karke check karo. Jahan pehla `arr[i] >= x` mile, wahi index return karo. Simple hai par slow hai kyunki sorted ka fayda nahi liya.

**Examples to Prove Idea**:

- `arr = [1,2,8,10,10,12,19]`, `x = 9`:
    - Check: `1 < 9`, `2 < 9`, `8 < 9`, `10 >= 9` → return `3`.
- `arr = [1,2,8,10,10,12,19]`, `x = 20`:
    - All elements `< 20` → return `7` (array length).
- *Why It Works*: Sequentially checks each element, ensuring the first valid index is returned.

**Intuition**:
Loop through the array from start to end. As soon as `arr[i] >= x` is found, return `i` since it’s the smallest index (due to sequential checking). If no element satisfies, return `n`. The approach is intuitive but slow because it doesn’t leverage the sorted nature of the array.

**Dry Run**:

- Input: `arr = [1,2,8,10,10,12,19]`, `x = 9`, `n = 7`.
- Loop:
    - `i=0`: `arr[0] = 1 < 9`. **Reason**: `1` is too small, move to next index.
    - `i=1`: `arr[1] = 2 < 9`. **Reason**: `2` is less than `9`, continue.
    - `i=2`: `arr[2] = 8 < 9`. **Reason**: `8` is still less than `9`, keep going.
    - `i=3`: `arr[3] = 10 >= 9`. **Reason**: `10` satisfies `>= 9`, and it’s the first such index, so return `3`.
- Return: `3`.
- *Hinglish*: Ek-ek karke check kiya: `1 < 9`, `2 < 9`, `8 < 9`, `10 >= 9`. Index `3` pe condition mili, to `3` return karo.

**Algorithm**:

1. Iterate `i` from `0` to `arr.length - 1`:
    - If `arr[i] >= x`, return `i`.
2. Return `arr.length`.

**Pseudocode**:

```cpp
function lowerBoundLinear(arr, x):
    for i from 0 to arr.length - 1:
        if arr[i] >= x:
            return i
    return arr.length

```

**Code**:

```cpp
#include <bits/stdc++.h>
using namespace std;

int lowerBoundLinear(vector<int>& arr, int x) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] >= x) return i;
    }
    return arr.size();
}

```

**Java Equivalent**:

```java
class Solution {
    public int lowerBoundLinear(int[] arr, int x) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] >= x) return i;
        }
        return arr.length;
    }
}

```

**Time Complexity (TC)**:

- `O(n)`: In the worst case (e.g., `x` larger than all elements), it checks every element.
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

- **Goal**: Find the smallest index `i` where `arr[i] >= x`, or return `n`.
- **How to Model**: Use Binary Search with two pointers (`low` and `high`) to define the search space. Initialize `ans = arr.length` to handle cases where no element satisfies `>= x`. Compute the middle index (`mid`). If `arr[mid] >= x`, store `mid` in `ans` and search left to find a potentially smaller index. If `arr[mid] < x`, search right since smaller elements can’t satisfy the condition.
- **Choices**: Iterative Binary Search is preferred for `O(1)` space over recursive, and the `ans` variable ensures we track the smallest valid index.
- **Constraints**: `O(log n)` time, `O(1)` space.
- *Hinglish*: Binary Search se search space aadha karo. `arr[mid] >= x` ho to `ans` mein `mid` rakho aur chhota index dhoondhne left jao. Agar `arr[mid] < x` ho to right jao kyunki chhote elements kaam nahi karenge.

**Examples to Prove Idea**:

- `arr = [1,2,8,10,10,12,19]`, `x = 9`:
    - Start: `low=0`, `high=6`, `ans=7`. `mid=3`, `arr[3]=10 >= 9` → set `ans=3`, search left (`high=2`).
    - `mid=1`, `arr[1]=2 < 9` → search right (`low=2`).
    - `mid=2`, `arr[2]=8 < 9` → search right (`low=3`). Stop, return `ans=3`.
- `arr = [1,2,8,10,10,12,19]`, `x = 20`:
    - All `arr[mid] < 20`, keep searching right, `ans` stays `7` → return `7`.
- *Why It Works*: The sorted property allows us to eliminate half the search space, and `ans` tracks the smallest index satisfying `>= x`.

**Intuition**:
Maintain a search space with `low` and `high`. Compute `mid` and check `arr[mid] >= x`:

- If true, `mid` is a candidate, but search left (`high = mid-1`) for a smaller index.
- If false, search right (`low = mid+1`) since elements at or before `mid` are too small.
- Use `ans` to store the smallest valid index, defaulting to `n`. Stop when `low > high`, return `ans`.
The sorted array ensures we can safely eliminate half the elements each step.

**Dry Run**:

- Input: `arr = [1,2,8,10,10,12,19]`, `x = 9`, `n = 7`.
- Initialize: `low = 0`, `high = 6`, `ans = 7`.
- **Step 1**:
    - Compute: `mid = (0 + 6) / 2 = 3`.
    - Check: `arr[3] = 10 >= 9`. **Reason**: `10` satisfies `>= 9`, so index `3` is a candidate for the smallest index. Store `ans = 3` and search left (`high = mid-1 = 2`) to find a potentially smaller index, since we want the smallest `i` where `arr[i] >= x`.
- **Step 2**:
    - Compute: `mid = (0 + 2) / 2 = 1`.
    - Check: `arr[1] = 2 < 9`. **Reason**: `2` is less than `9`, so no index at or before `mid=1` can satisfy `>= 9` (since array is sorted, `arr[0]=1` is even smaller). Search right (`low = mid+1 = 2`) to find larger elements.
- **Step 3**:
    - Compute: `mid = (2 + 2) / 2 = 2`.
    - Check: `arr[2] = 8 < 9`. **Reason**: `8` is still less than `9`, so index `2` or lower won’t work. Search right (`low = mid+1 = 3`) to check larger elements.
- **Step 4**:
    - Check: `low = 3 > high = 2`. **Reason**: Search space is exhausted (`low > high`). The last stored `ans = 3` is the smallest index where `arr[3] = 10 >= 9`.
- Return: `3`.
- *Hinglish*: Shuru mein `low=0`, `high=6`, `ans=7`. `mid=3` pe `10 >= 9`, to `ans=3` aur left jao (`high=2`) kyunki chhota index chahiye. Phir `mid=1` pe `2 < 9`, to right jao (`low=2`). Phir `mid=2` pe `8 < 9`, to right jao (`low=3`). Ab `low > high`, to `ans=3` return karo.

**Dry Run (Edge Case)**:

- Input: `arr = [1,2,8,10,10,12,19]`, `x = 20`, `n = 7`.
- Initialize: `low = 0`, `high = 6`, `ans = 7`.
- **Step 1**:
    - Compute: `mid = (0 + 6) / 2 = 3`.
    - Check: `arr[3] = 10 < 20`. **Reason**: `10` is less than `20`, so indices `0` to `3` won’t have `>= 20` (sorted array). Search right (`low = mid+1 = 4`).
- **Step 2**:
    - Compute: `mid = (4 + 6) / 2 = 5`.
    - Check: `arr[5] = 12 < 20`. **Reason**: `12` is less than `20`, so indices `4` and below are out. Search right (`low = mid+1 = 6`).
- **Step 3**:
    - Compute: `mid = (6 + 6) / 2 = 6`.
    - Check: `arr[6] = 19 < 20`. **Reason**: `19` is less than `20`, so index `6` or lower won’t work. Search right (`low = mid+1 = 7`).
- **Step 4**:
    - Check: `low = 7 > high = 6`. **Reason**: No element `>= 20` found, so `ans` remains `7` (hypothetical index).
- Return: `7`.
- *Hinglish*: Sab elements `20` se chhote hain. Har baar right gaye kyunki `arr[mid] < 20`. Ant mein `low > high`, to `ans=7` return karo.

**Algorithm**:

1. Initialize `low = 0`, `high = arr.length - 1`, `ans = arr.length`.
2. While `low <= high`:
    - Compute `mid = low + (high - low) / 2`.
    - If `arr[mid] >= x`, set `ans = mid` and search left (`high = mid - 1`).
    - Else (`arr[mid] < x`), search right (`low = mid + 1`).
3. Return `ans`.

**Pseudocode**:

```cpp
function lowerBound(arr, x):
    low = 0
    high = arr.length - 1
    ans = arr.length
    while low <= high:
        mid = low + (high - low) / 2
        if arr[mid] >= x:
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

int lowerBound(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1, ans = arr.size();
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
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
    public int lowerBound(int[] arr, int x) {
        int low = 0, high = arr.length - 1, ans = arr.length;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= x) {
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

- *Why this approach?*: Efficient, leverages sorted property, and is standard in interviews (e.g., C++ STL `lower_bound`).
- *Hinglish*: Yeh approach fast hai kyunki search space aadha hota hai har step mein. `ans` variable se smallest index track karo.
- *Limitation*: Requires sorted array. Use `low + (high - low) / 2` to avoid overflow.
- *Edge Cases*:
    - Single element: Check `arr[0] >= x`, return `0` or `1`.
    - `x` larger than all elements: Returns `n`.
    - `x` smaller than all elements: Returns `0` (if `arr[0] >= x`).
    - Duplicates: Returns first occurrence of `>= x`.

---

### Key Points for Interview

- **Linear Approach**: Simple but `O(n)`, useful as a baseline to explain why Binary Search is better.
- **Binary Search**: `O(log n)` time, `O(1)` space, preferred for efficiency.
- *Hinglish*: Interview mein pehle linear approach briefly bolo, phir Binary Search ka logic clear karo. `ans` variable aur left/right move ka reason samjhao.
- **Key Insight**: Use `ans` to track the smallest index, search left when `arr[mid] >= x` to minimize it.
- **C++ STL**: `lower_bound(arr.begin(), arr.end(), x) - arr.begin()` gives the same result.

### Additional Notes for Beginners

- *Why this approach?*: Binary Search is efficient and teaches how to leverage sorted data. Linear search is easier but impractical for large `n`.
- *Hinglish*: Linear mein har element check karo, samajh aata hai par slow. Binary Search mein aadha space hatao, fast hai.
- *Practice*:
    - `arr=[1,2,8,10,10,12,19]`, `x=9` → `3`.
    - `arr=[1,2,8,10,10,12,19]`, `x=20` → `7`.
    - `arr=[1]`, `x=1` → `0`.
- *Edge Cases*:
    - Single element array: Check `arr[0]` against `x`.
    - Empty array: Not applicable per constraints (`n >= 1`).
    - Large `n`: Use overflow-safe `mid` calculation.

### Citation

This solution aligns with the "Corey v Mike" YouTube transcript, emphasizing Binary Search for Lower Bound. For further reading:

- GeeksforGeeks: Lower and Upper Bound.
- LeetCode: Related problems like Search Insert Position (Problem 35).

---

## 

---

## 

---

Understood! Thank you for confirming. As per your request, I’ll now present the **Floor in a Sorted Array** problem as a separate question, following the same structured format as the "Count Good Triplets" and Binary Search samples. The explanation will include **Concepts**, **Thought Process**, **Examples to Prove Idea**, **Intuition**, **Dry Run**, **Algorithm**, **Pseudocode**, **Code**, **Time Complexity**, **Space Complexity**, **Notes/Observations**, and **Java Equivalent**, using simple words, Hinglish for relatability, and a professional, interview-ready tone. I’ll incorporate points from the YouTube transcript, focus on Binary Search solutions, and provide in-depth dry runs with reasoning. After this, I’ll wait for your response before proceeding to the next problem (Ceiling).

---

## Problem 4: Floor in a Sorted Array

**Problem Statement**:

Given a sorted array of integers `arr` (in ascending order, may contain duplicates) and a target value `x`, find the **largest number** in the array that is less than or equal to `x` (i.e., `arr[i] <= x`). If no such element exists, return `-1`.

**Breakdown**:

- **Input**:
    - `arr`: Sorted array of integers (may have duplicates).
    - `x`: Target integer.
- **Output**: Integer representing the largest number in the array where `arr[i] <= x`, or `1` if no such element exists.
- **Objective**: Use Binary Search to efficiently find the largest number by leveraging the sorted property of the array.
- **Why is This a Problem?**: Linear search takes `O(n)` time, which is slow for large arrays. Binary Search reduces this to `O(log n)` by halving the search space.
- *Hinglish*: Sorted array mein `x` se chhota ya barabar wala sabse bada number dhoondhna hai. Agar nahi hai to `1` return karo. Linear search slow hai, Binary Search se jaldi milega.

**Constraints**:

- `1 <= arr.length <= 10^5`.
- `10^4 <= arr[i], x <= 10^4`.
- Array is sorted in ascending order, may contain duplicates.

**Examples**:

- **Example 1**: `arr = [10,20,25,30,40]`, `x = 26` → Output: `25` (largest number `<= 26`).
- **Example 2**: `arr = [10,20,25,30,40]`, `x = 10` → Output: `10` (largest number `<= 10`).
- **Example 3**: `arr = [10,20,25,30,40]`, `x = 5` → Output: `1` (no element `<= 5`).
- **Example 4**: `arr = [1,2,8,10,10,12,19]`, `x = 11` → Output: `10` (largest number `<= 11`).

**Key Definitions**:

- **Floor**: The largest number in the array that is less than or equal to `x` (`arr[i] <= x`).
- **No Valid Element**: If no element satisfies `arr[i] <= x`, return `1` (e.g., `x` is smaller than all elements).
- *Hinglish*: Floor matlab `x` se chhota ya barabar wala sabse bada number. Agar nahi milta to `1` return karo.

**Concepts** (from Lecture):

- **Binary Search for Floor**: Binary Search finds the target efficiently in a sorted array by halving the search space. For Floor, we check if `arr[mid] <= x`. If true, this is a candidate for the largest number `<= x`, but we search right to find a potentially larger number. If `arr[mid] > x`, we search left since larger elements can’t satisfy the condition.
- **Key Property**: The array must be sorted, allowing us to eliminate half the search space each step.
- **Answer Variable**: Use an `ans` variable to store the largest valid number, initialized to `1` (default if no element is found).
- **Overflow Handling**: Calculate `mid` as `low + (high - low) / 2` to avoid integer overflow when `low + high` is large.
- *Hinglish*: Binary Search mein `arr[mid] <= x` ho to number save karo par right jao kyunki bada number chahiye. `arr[mid] > x` ho to left jao kyunki bade elements kaam nahi karenge. `mid` nikalte waqt overflow se bachne ke liye `low + (high - low) / 2` use karo.
- **Time Complexity**: `O(log n)` because the search space halves each step.
- **Space Complexity**: `O(1)` for iterative approach, `O(log n)` for recursive due to call stack.
- **Why Important?**: Floor is a key concept in Binary Search problems, often used in applications like finding the largest valid value or handling duplicates. It complements Ceiling and is common in interviews.

---

### Approaches for Floor

### 🔴 Approach 1: Linear Search

**Thought Process**:

- **Goal**: Find the largest number in the array where `arr[i] <= x`, or return `1` if none exists.
- **How to Model**: Iterate through the array from index `n-1` to `0` (backward) to find the first element where `arr[i] <= x`, as this will be the largest such number due to the sorted order. If no such element is found, return `1`.
- **Choices**: Linear search is simple but doesn’t leverage the sorted property, making it inefficient for large arrays.
- **Constraints**: `O(n)` time, `O(1)` space.
- *Hinglish*: Piche se array check karo kyunki largest number chahiye jo `<= x` ho. Pehla `arr[i] <= x` mile to return karo, nahi to `1`. Simple hai par slow.

**Examples to Prove Idea**:

- `arr = [10,20,25,30,40]`, `x = 26`:
    - Check backward: `40 > 26`, `30 > 26`, `25 <= 26` → return `25`.
- `arr = [10,20,25,30,40]`, `x = 5`:
    - All elements `> 5` → return `1`.
- *Why It Works*: Scanning backward ensures the first element `<= x` is the largest due to the sorted order (descending indices).

**Intuition**:
Loop through the array from end to start. Return the first element `arr[i] <= x`, as it’s the largest possible value satisfying the condition (since we encounter larger elements first). If no element satisfies, return `-1`. The approach is intuitive but slow because it ignores the sorted nature of the array.

**Dry Run**:

- Input: `arr = [10,20,25,30,40]`, `x = 26`, `n = 5`.
- Loop (backward):
    - `i=4`: `arr[4] = 40 > 26`. **Reason**: `40` is greater than `26`, doesn’t satisfy `<= 26`, move to next index.
    - `i=3`: `arr[3] = 30 > 26`. **Reason**: `30` is greater than `26`, continue.
    - `i=2`: `arr[2] = 25 <= 26`. **Reason**: `25` satisfies `<= 26`, and it’s the first such element when scanning backward, so it’s the largest. Return `25`.
- Return: `25`.
- *Hinglish*: Piche se check kiya: `40 > 26`, `30 > 26`, `25 <= 26`. Index `2` pe condition mili, to `25` return karo kyunki yeh largest hai jo `<= 26`.

**Algorithm**:

1. Iterate `i` from `arr.length - 1` to `0`:
    - If `arr[i] <= x`, return `arr[i]`.
2. Return `1`.

**Pseudocode**:

```cpp
function floorLinear(arr, x):
    for i from arr.length - 1 to 0:
        if arr[i] <= x:
            return arr[i]
    return -1

```

**Code**:

```cpp
#include <bits/stdc++.h>
using namespace std;

int floorLinear(vector<int>& arr, int x) {
    for (int i = arr.size() - 1; i >= 0; i--) {
        if (arr[i] <= x) return arr[i];
    }
    return -1;
}

```

**Java Equivalent**:

```java
class Solution {
    public int floorLinear(int[] arr, int x) {
        for (int i = arr.length - 1; i >= 0; i--) {
            if (arr[i] <= x) return arr[i];
        }
        return -1;
    }
}

```

**Time Complexity (TC)**:

- `O(n)`: In the worst case (e.g., `x` smaller than all elements), it checks every element.
- *Why?*: Linearly traverses the array without leveraging the sorted property.

**Space Complexity (SC)**:

- `O(1)`: Only uses a loop variable.
- *Why?*: No additional data structures are needed.

**Notes/Observations**:

- *Why this approach?*: Easy to implement and understand, good for small arrays or as a baseline for interviews. Scanning backward ensures the largest valid number is found first.
- *Hinglish*: Yeh approach simple hai, piche se check karo to largest `<= x` pehle milega. Par bade array ke liye slow hai.
- *Limitation*: Inefficient for large `n` (e.g., `10^5`), where Binary Search is better.

---

### 🟢 Approach 2: Binary Search (Optimized)

**Thought Process**:

- **Goal**: Find the largest number in the array where `arr[i] <= x`, or return `1`.
- **How to Model**: Use Binary Search with two pointers (`low` and `high`) to define the search space. Initialize `ans = -1` to handle cases where no element satisfies `<= x`. Compute the middle index (`mid`). If `arr[mid] <= x`, store `arr[mid]` in `ans` and search right to find a potentially larger number (since we want the largest `<= x`). If `arr[mid] > x`, search left since larger elements can’t satisfy the condition.
- **Choices**: Iterative Binary Search is preferred for `O(1)` space over recursive, and the `ans` variable ensures we track the largest valid number.
- **Constraints**: `O(log n)` time, `O(1)` space.
- *Hinglish*: Binary Search se search space aadha karo. `arr[mid] <= x` ho to `ans` mein `arr[mid]` rakho aur right jao kyunki bada number chahiye. Agar `arr[mid] > x` ho to left jao kyunki bade elements kaam nahi karenge.

**Examples to Prove Idea**:

- `arr = [10,20,25,30,40]`, `x = 26`:
    - Start: `low=0`, `high=4`, `ans=-1`. `mid=2`, `arr[2]=25 <= 26` → set `ans=25`, search right (`low=3`).
    - `mid=3`, `arr[3]=30 > 26` → search left (`high=2`). Stop, return `ans=25`.
- `arr = [10,20,25,30,40]`, `x = 5`:
    - All `arr[mid] > 5`, keep searching left, `ans` stays `1` → return `1`.
- *Why It Works*: The sorted property allows us to eliminate half the search space, and `ans` tracks the largest number satisfying `<= x`.

**Intuition**:
Maintain a search space with `low` and `high`. Compute `mid` and check `arr[mid] <= x`:

- If true, `mid` is a candidate for the largest number `<= x`, so store `arr[mid]` in `ans` and search right (`low = mid+1`) for a potentially larger number.
- If false (`arr[mid] > x`), search left (`high = mid-1`) since elements at or after `mid` are too large.
- Use `ans` to store the largest valid number, defaulting to `1`. Stop when `low > high`, return `ans`.
The sorted array ensures we can safely eliminate half the elements each step.

**Dry Run**:

- Input: `arr = [10,20,25,30,40]`, `x = 26`, `n = 5`.
- Initialize: `low = 0`, `high = 4`, `ans = -1`.
- **Step 1**:
    - Compute: `mid = (0 + 4) / 2 = 2`.
    - Check: `arr[2] = 25 <= 26`. **Reason**: `25` satisfies `<= 26`, so it’s a candidate for the largest number. Store `ans = 25` and search right (`low = mid+1 = 3`) to find a potentially larger number `<= 26`.
- **Step 2**:
    - Compute: `mid = (3 + 4) / 2 = 3`.
    - Check: `arr[3] = 30 > 26`. **Reason**: `30` is greater than `26`, so it and all elements to its right (e.g., `arr[4]=40`) can’t satisfy `<= 26`. Search left (`high = mid-1 = 2`) to check smaller elements.
- **Step 3**:
    - Check: `low = 3 > high = 2`. **Reason**: Search space is exhausted (`low > high`). The last stored `ans = 25` is the largest number where `arr[i] <= 26`.
- Return: `25`.
- *Hinglish*: Shuru mein `low=0`, `high=4`, `ans=-1`. `mid=2` pe `25 <= 26`, to `ans=25` aur right jao (`low=3`) kyunki bada number dhoondhna hai. Phir `mid=3` pe `30 > 26`, to left jao (`high=2`). Ab `low > high`, to `ans=25` return karo.

**Dry Run (Edge Case)**:

- Input: `arr = [10,20,25,30,40]`, `x = 5`, `n = 5`.
- Initialize: `low = 0`, `high = 4`, `ans = -1`.
- **Step 1**:
    - Compute: `mid = (0 + 4) / 2 = 2`.
    - Check: `arr[2] = 25 > 5`. **Reason**: `25` is greater than `5`, so it and all elements to its right can’t satisfy `<= 5`. Search left (`high = mid-1 = 1`).
- **Step 2**:
    - Compute: `mid = (0 + 1) / 2 = 0`.
    - Check: `arr[0] = 10 > 5`. **Reason**: `10` is greater than `5`, so no elements at or after `mid=0` satisfy. Search left (`high = mid-1 = -1`).
- **Step 3**:
    - Check: `low = 0 > high = -1`. **Reason**: No element `<= 5` found, so `ans` remains `1`.
- Return: `1`.
- *Hinglish*: Sab elements `5` se bade hain. Har baar left gaye kyunki `arr[mid] > 5`. Ant mein `low > high`, to `ans=-1` return karo.

**Algorithm**:

1. Initialize `low = 0`, `high = arr.length - 1`, `ans = -1`.
2. While `low <= high`:
    - Compute `mid = low + (high - low) / 2`.
    - If `arr[mid] <= x`, set `ans = arr[mid]` and search right (`low = mid + 1`).
    - Else (`arr[mid] > x`), search left (`high = mid - 1`).
3. Return `ans`.

**Pseudocode**:

```cpp
function floor(arr, x):
    low = 0
    high = arr.length - 1
    ans = -1
    while low <= high:
        mid = low + (high - low) / 2
        if arr[mid] <= x:
            ans = arr[mid]
            low = mid + 1
        else:
            high = mid - 1
    return ans

```

**Code**:

```cpp
#include <bits/stdc++.h>
using namespace std;

int floor(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= x) {
            ans = arr[mid];
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

```

**Java Equivalent**:

```java
class Solution {
    public int floor(int[] arr, int x) {
        int low = 0, high = arr.length - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= x) {
                ans = arr[mid];
                low = mid + 1;
            } else {
                high = mid - 1;
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

- *Why this approach?*: Efficient, leverages sorted property, and is standard in interviews for finding the largest valid number.
- *Hinglish*: Yeh approach fast hai kyunki search space aadha hota hai. `ans` variable se largest `<= x` track karo, right jao bada number dhoondhne.
- *Limitation*: Requires sorted array. Use `low + (high - low) / 2` to avoid overflow.
- *Edge Cases*:
    - Single element: Check `arr[0] <= x`, return `arr[0]` or `1`.
    - `x` larger than all elements: Returns largest element.
    - `x` smaller than all elements: Returns `1`.
    - Duplicates: Returns the largest valid number (rightmost if duplicates exist).

---

### Key Points for Interview

- **Linear Approach**: Simple but `O(n)`, useful as a baseline to explain why Binary Search is better. Scanning backward ensures the largest number is found first.
- **Binary Search**: `O(log n)` time, `O(1)` space, preferred for efficiency.
- *Hinglish*: Interview mein pehle linear approach briefly bolo, phir Binary Search ka logic clear karo. `ans` variable aur right/left move ka reason samjhao.
- **Key Insight**: Search right when `arr[mid] <= x` to maximize `ans`, as we want the largest number `<= x`.
- **Difference from Lower Bound**: Lower Bound finds the index of `>= x`, Floor finds the value of `<= x`, searching right to maximize it.

### Additional Notes for Beginners

- *Why this approach?*: Binary Search is efficient and teaches how to adapt Binary Search for value-based problems. Linear search is easier but impractical for large `n`.
- *Hinglish*: Linear mein piche se check karo, samajh aata hai par slow. Binary Search mein aadha space hatao, fast hai.
- *Practice*:
    - `arr=[10,20,25,30,40]`, `x=26` → `25`.
    - `arr=[10,20,25,30,40]`, `x=5` → `1`.
    - `arr=[1,2,8,10,10,12,19]`, `x=11` → `10`.
- *Edge Cases*:
    - Single element array: Check `arr[0]` against `x`.
    - Empty array: Not applicable per constraints (`n >= 1`).
    - Large `n`: Use overflow-safe `mid` calculation.

### Citation

This solution aligns with the "Corey v Mike" YouTube transcript, emphasizing Binary Search for Floor. For further reading:

- GeeksforGeeks: Floor and Ceiling in a Sorted Array.
- LeetCode: Related problems like Search Insert Position (Problem 35).

---

Understood! Thank you for confirming. As per your request, I’ll now present the **Ceiling in a Sorted Array** problem as a separate question, following the same structured format as the "Count Good Triplets" and Binary Search samples. The explanation will include **Concepts**, **Thought Process**, **Examples to Prove Idea**, **Intuition**, **Dry Run**, **Algorithm**, **Pseudocode**, **Code**, **Time Complexity**, **Space Complexity**, **Notes/Observations**, and **Java Equivalent**, using simple words, Hinglish for relatability, and a professional, interview-ready tone. I’ll incorporate points from the YouTube transcript, focus on Binary Search solutions, and provide in-depth dry runs with reasoning. This is the final problem in the sequence you requested (Lower Bound, Upper Bound, Search Insert Position, Floor, Ceiling). After this, I’ll await your further instructions.

---

## Problem 5: Ceiling in a Sorted Array

**Problem Statement**:

Given a sorted array of integers `arr` (in ascending order, may contain duplicates) and a target value `x`, find the **smallest number** in the array that is greater than or equal to `x` (i.e., `arr[i] >= x`). If no such element exists, return `-1`.

**Breakdown**:

- **Input**:
    - `arr`: Sorted array of integers (may have duplicates).
    - `x`: Target integer.
- **Output**: Integer representing the smallest number in the array where `arr[i] >= x`, or `1` if no such element exists.
- **Objective**: Use Binary Search to efficiently find the smallest number by leveraging the sorted property of the array.
- **Why is This a Problem?**: Linear search takes `O(n)` time, which is slow for large arrays. Binary Search reduces this to `O(log n)` by halving the search space. This problem is equivalent to finding the Lower Bound (smallest index `i` where `arr[i] >= x`) and returning the value at that index.
- *Hinglish*: Sorted array mein `x` se bada ya barabar wala sabse chhota number dhoondhna hai. Agar nahi hai to `1` return karo. Linear search slow hai, Binary Search se jaldi milega.

**Constraints**:

- `1 <= arr.length <= 10^5`.
- `10^4 <= arr[i], x <= 10^4`.
- Array is sorted in ascending order, may contain duplicates.

**Examples**:

- **Example 1**: `arr = [1,2,8,10,10,12,19]`, `x = 8` → Output: `8` (smallest number `>= 8`).
- **Example 2**: `arr = [1,2,8,10,10,12,19]`, `x = 9` → Output: `10` (smallest number `>= 9`).
- **Example 3**: `arr = [1,2,8,10,10,12,19]`, `x = 20` → Output: `1` (no element `>= 20`).
- **Example 4**: `arr = [1,2,8,10,10,12,19]`, `x = 1` → Output: `1` (smallest number `>= 1`).

**Key Definitions**:

- **Ceiling**: The smallest number in the array that is greater than or equal to `x` (`arr[i] >= x`).
- **No Valid Element**: If no element satisfies `arr[i] >= x`, return `1` (e.g., `x` is larger than all elements).
- *Hinglish*: Ceiling matlab `x` se bada ya barabar wala sabse chhota number. Agar nahi milta to `1` return karo.

**Concepts** (from Lecture):

- **Binary Search for Ceiling**: This is identical to the Lower Bound problem (smallest index `i` where `arr[i] >= x`). Binary Search finds the target efficiently in a sorted array by halving the search space. We check if `arr[mid] >= x`. If true, this is a candidate for the smallest number, but we search left to find a smaller index (potentially a smaller or equal value). If `arr[mid] < x`, we search right since smaller elements can’t satisfy the condition.
- **Key Property**: The array must be sorted, allowing us to eliminate half the search space each step.
- **Answer Variable**: Use an `ans` variable to store the index of the smallest valid number, initialized to `arr.length` (to check if no valid element exists). Return `arr[ans]` or `1` if `ans == arr.length`.
- **Overflow Handling**: Calculate `mid` as `low + (high - low) / 2` to avoid integer overflow when `low + high` is large.
- *Hinglish*: Binary Search mein `arr[mid] >= x` ho to index save karo par left jao kyunki chhota index (aur number) chahiye. `arr[mid] < x` ho to right jao. `mid` nikalte waqt overflow se bachne ke liye `low + (high - low) / 2` use karo.
- **Time Complexity**: `O(log n)` because the search space halves each step.
- **Space Complexity**: `O(1)` for iterative approach, `O(log n)` for recursive due to call stack.
- **Why Important?**: Ceiling complements Floor and is common in interviews, often used to find the smallest valid value or handle duplicates. It’s equivalent to Lower Bound in terms of index-finding logic.

---

### Approaches for Ceiling

### 🔴 Approach 1: Linear Search

**Thought Process**:

- **Goal**: Find the smallest number in the array where `arr[i] >= x`, or return `1` if none exists.
- **How to Model**: Iterate through the array from index `0` to `n-1` (forward) to find the first element where `arr[i] >= x`, as this will be the smallest such number due to the sorted order. If no such element is found, return `1`.
- **Choices**: Linear search is simple but doesn’t leverage the sorted property, making it inefficient for large arrays.
- **Constraints**: `O(n)` time, `O(1)` space.
- *Hinglish*: Aage se array check karo kyunki smallest number chahiye jo `>= x` ho. Pehla `arr[i] >= x` mile to return karo, nahi to `1`. Simple hai par slow.

**Examples to Prove Idea**:

- `arr = [1,2,8,10,10,12,19]`, `x = 9`:
    - Check forward: `1 < 9`, `2 < 9`, `8 < 9`, `10 >= 9` → return `10`.
- `arr = [1,2,8,10,10,12,19]`, `x = 20`:
    - All elements `< 20` → return `1`.
- *Why It Works*: Scanning forward ensures the first element `>= x` is the smallest due to the sorted order (ascending indices).

**Intuition**:
Loop through the array from start to end. Return the first element `arr[i] >= x`, as it’s the smallest possible value satisfying the condition (since we encounter smaller elements first). If no element satisfies, return `-1`. The approach is intuitive but slow because it ignores the sorted nature of the array.

**Dry Run**:

- Input: `arr = [1,2,8,10,10,12,19]`, `x = 9`, `n = 7`.
- Loop (forward):
    - `i=0`: `arr[0] = 1 < 9`. **Reason**: `1` is less than `9`, doesn’t satisfy `>= 9`, move to next index.
    - `i=1`: `arr[1] = 2 < 9`. **Reason**: `2` is less than `9`, continue.
    - `i=2`: `arr[2] = 8 < 9`. **Reason**: `8` is less than `9`, continue.
    - `i=3`: `arr[3] = 10 >= 9`. **Reason**: `10` satisfies `>= 9`, and it’s the first such element when scanning forward, so it’s the smallest. Return `10`.
- Return: `10`.
- *Hinglish*: Aage se check kiya: `1 < 9`, `2 < 9`, `8 < 9`, `10 >= 9`. Index `3` pe condition mili, to `10` return karo kyunki yeh smallest hai jo `>= 9`.

**Algorithm**:

1. Iterate `i` from `0` to `arr.length - 1`:
    - If `arr[i] >= x`, return `arr[i]`.
2. Return `1`.

**Pseudocode**:

```cpp
function ceilingLinear(arr, x):
    for i from 0 to arr.length - 1:
        if arr[i] >= x:
            return arr[i]
    return -1

```

**Code**:

```cpp
#include <bits/stdc++.h>
using namespace std;

int ceilingLinear(vector<int>& arr, int x) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] >= x) return arr[i];
    }
    return -1;
}

```

**Java Equivalent**:

```java
class Solution {
    public int ceilingLinear(int[] arr, int x) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] >= x) return arr[i];
        }
        return -1;
    }
}

```

**Time Complexity (TC)**:

- `O(n)`: In the worst case (e.g., `x` larger than all elements), it checks every element.
- *Why?*: Linearly traverses the array without leveraging the sorted property.

**Space Complexity (SC)**:

- `O(1)`: Only uses a loop variable.
- *Why?*: No additional data structures are needed.

**Notes/Observations**:

- *Why this approach?*: Easy to implement and understand, good for small arrays or as a baseline for interviews. Scanning forward ensures the smallest valid number is found first.
- *Hinglish*: Yeh approach simple hai, aage se check karo to smallest `>= x` pehle milega. Par bade array ke liye slow hai.
- *Limitation*: Inefficient for large `n` (e.g., `10^5`), where Binary Search is better.

---

### 🟢 Approach 2: Binary Search (Optimized)

**Thought Process**:

- **Goal**: Find the smallest number in the array where `arr[i] >= x`, or return `1`.
- **How to Model**: This is identical to the Lower Bound problem (smallest index `i` where `arr[i] >= x`). Use Binary Search with two pointers (`low` and `high`) to define the search space. Initialize `ans = arr.length` to handle cases where no element satisfies `>= x`. Compute the middle index (`mid`). If `arr[mid] >= x`, store `mid` in `ans` and search left to find a potentially smaller index (for a smaller or equal value). If `arr[mid] < x`, search right since smaller elements can’t satisfy the condition. Finally, return `arr[ans]` if `ans < arr.length`, else `1`.
- **Choices**: Iterative Binary Search is preferred for `O(1)` space over recursive, and storing the index in `ans` allows us to retrieve the value easily.
- **Constraints**: `O(log n)` time, `O(1)` space.
- *Hinglish*: Yeh lower bound jaisa hi hai. Binary Search se search space aadha karo. `arr[mid] >= x` ho to `ans` mein `mid` rakho aur left jao kyunki chhota index (aur number) chahiye. Agar `arr[mid] < x` ho to right jao kyunki chhote elements kaam nahi karenge.

**Examples to Prove Idea**:

- `arr = [1,2,8,10,10,12,19]`, `x = 9`:
    - Start: `low=0`, `high=6`, `ans=7`. `mid=3`, `arr[3]=10 >= 9` → set `ans=3`, search left (`high=2`).
    - `mid=1`, `arr[1]=2 < 9` → search right (`low=2`).
    - `mid=2`, `arr[2]=8 < 9` → search right (`low=3`). Stop, return `arr[3]=10`.
- `arr = [1,2,8,10,10,12,19]`, `x = 20`:
    - All `arr[mid] < 20`, keep searching right, `ans` stays `7` → return `1`.
- *Why It Works*: The sorted property allows us to find the smallest index where `arr[i] >= x`, and the value at that index is the ceiling.

**Intuition**:
Maintain a search space with `low` and `high`. Compute `mid` and check `arr[mid] >= x`:

- If true, `mid` is a candidate for the smallest number `>= x`, so store `mid` in `ans` and search left (`high = mid-1`) for a potentially smaller index.
- If false (`arr[mid] < x`), search right (`low = mid+1`) since elements at or before `mid` are too small.
- Use `ans` to store the smallest valid index, defaulting to `arr.length`. After the loop, return `arr[ans]` if `ans < arr.length`, else `1`.
The sorted array ensures we can safely eliminate half the elements each step.

**Dry Run**:

- Input: `arr = [1,2,8,10,10,12,19]`, `x = 9`, `n = 7`.
- Initialize: `low = 0`, `high = 6`, `ans = 7`.
- **Step 1**:
    - Compute: `mid = (0 + 6) / 2 = 3`.
    - Check: `arr[3] = 10 >= 9`. **Reason**: `10` satisfies `>= 9`, so index `3` is a candidate for the smallest number. Store `ans = 3` and search left (`high = mid-1 = 2`) to find a potentially smaller index (smaller or equal value).
- **Step 2**:
    - Compute: `mid = (0 + 2) / 2 = 1`.
    - Check: `arr[1] = 2 < 9`. **Reason**: `2` is less than `9`, so no index at or before `mid=1` can satisfy `>= 9`. Search right (`low = mid+1 = 2`) to check larger elements.
- **Step 3**:
    - Compute: `mid = (2 + 2) / 2 = 2`.
    - Check: `arr[2] = 8 < 9`. **Reason**: `8` is less than `9`, so index `2` doesn’t satisfy. Search right (`low = mid+1 = 3`).
- **Step 4**:
    - Check: `low = 3 > high = 2`. **Reason**: Search space is exhausted (`low > high`). Since `ans = 3 < 7`, return `arr[3] = 10`, the smallest number `>= 9`.
- Return: `10`.
- *Hinglish*: Shuru mein `low=0`, `high=6`, `ans=7`. `mid=3` pe `10 >= 9`, to `ans=3` aur left jao (`high=2`) kyunki chhota index dhoondhna hai. Phir `mid=1` pe `2 < 9`, to right jao (`low=2`). Phir `mid=2` pe `8 < 9`, to right jao (`low=3`). Ab `low > high`, to `ans=3` se `arr[3]=10` return karo.

**Dry Run (Edge Case)**:

- Input: `arr = [1,2,8,10,10,12,19]`, `x = 20`, `n = 7`.
- Initialize: `low = 0`, `high = 6`, `ans = 7`.
- **Step 1**:
    - Compute: `mid = (0 + 6) / 2 = 3`.
    - Check: `arr[3] = 10 < 20`. **Reason**: `10` is less than `20`, so indices `0` to `3` can’t satisfy `>= 20`. Search right (`low = mid+1 = 4`).
- **Step 2**:
    - Compute: `mid = (4 + 6) / 2 = 5`.
    - Check: `arr[5] = 12 < 20`. **Reason**: `12` is less than `20`, so indices `4` and below won’t work. Search right (`low = mid+1 = 6`).
- **Step 3**:
    - Compute: `mid = (6 + 6) / 2 = 6`.
    - Check: `arr[6] = 19 < 20`. **Reason**: `19` is less than `20`, so index `6` doesn’t satisfy. Search right (`low = mid+1 = 7`).
- **Step 4**:
    - Check: `low = 7 > high = 6`. **Reason**: No element `>= 20` found, so `ans = 7 == arr.length`. Return `1`.
- Return: `1`.
- *Hinglish*: Sab elements `20` se chhote hain. Har baar right gaye kyunki `arr[mid] < 20`. Ant mein `low > high`, to `ans=7` se `1` return karo.

**Algorithm**:

1. Initialize `low = 0`, `high = arr.length - 1`, `ans = arr.length`.
2. While `low <= high`:
    - Compute `mid = low + (high - low) / 2`.
    - If `arr[mid] >= x`, set `ans = mid` and search left (`high = mid - 1`).
    - Else (`arr[mid] < x`), search right (`low = mid + 1`).
3. If `ans == arr.length`, return `1`. Else, return `arr[ans]`.

**Pseudocode**:

```cpp
function ceiling(arr, x):
    low = 0
    high = arr.length - 1
    ans = arr.length
    while low <= high:
        mid = low + (high - low) / 2
        if arr[mid] >= x:
            ans = mid
            high = mid - 1
        else:
            low = mid + 1
    if ans == arr.length:
        return -1
    return arr[ans]

```

**Code**:

```cpp
#include <bits/stdc++.h>
using namespace std;

int ceiling(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1, ans = arr.size();
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (ans == arr.size()) return -1;
    return arr[ans];
}

```

**Java Equivalent**:

```java
class Solution {
    public int ceiling(int[] arr, int x) {
        int low = 0, high = arr.length - 1, ans = arr.length;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (ans == arr.length) return -1;
        return arr[ans];
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

- *Why this approach?*: Efficient, leverages sorted property, and is identical to Lower Bound. It’s a standard interview problem for value-based Binary Search.
- *Hinglish*: Yeh lower bound ka code hi hai, bas value return karo index ke bajaye. `>= x` wala smallest number dhoondho.
- *Limitation*: Requires sorted array. Use `low + (high - low) / 2` to avoid overflow.
- *Edge Cases*:
    - Single element: Check `arr[0] >= x`, return `arr[0]` or `1`.
    - `x` larger than all elements: Returns `1`.
    - `x` smaller than all elements: Returns smallest element (e.g., `arr[0]`).
    - Duplicates: Returns the smallest valid number (leftmost if duplicates exist).

---

### Key Points for Interview

- **Linear Approach**: Simple but `O(n)`, useful as a baseline to explain why Binary Search is better. Scanning forward ensures the smallest number is found first.
- **Binary Search**: `O(log n)` time, `O(1)` space, preferred for efficiency.
- *Hinglish*: Interview mein pehle linear approach briefly bolo, phir Binary Search ka logic clear karo. `ans` variable aur left/right move ka reason samjhao.
- **Key Insight**: Identical to Lower Bound, finding the smallest index where `arr[i] >= x` and returning the value.
- **C++ STL**: `lower_bound(arr.begin(), arr.end(), x)` gives the iterator to the ceiling; check if it’s `arr.end()` to return `1`.
- **Connection to Lower Bound**: The logic is identical, but we return the value `arr[ans]` instead of the index.

### Additional Notes for Beginners

- *Why this approach?*: Binary Search is efficient and teaches how to adapt Lower Bound logic for value-based problems. Linear search is easier but impractical for large `n`.
- *Hinglish*: Linear mein aage se check karo, samajh aata hai par slow. Binary Search mein aadha space hatao, fast hai.
- *Practice*:
    - `arr=[1,2,8,10,10,12,19]`, `x=9` → `10`.
    - `arr=[1,2,8,10,10,12,19]`, `x=20` → `1`.
    - `arr=[1]`, `x=1` → `1`.
- *Edge Cases*:
    - Single element array: Check `arr[0]` against `x`.
    - Empty array: Not applicable per constraints (`n >= 1`).
    - Large `n`: Use overflow-safe `mid` calculation.
