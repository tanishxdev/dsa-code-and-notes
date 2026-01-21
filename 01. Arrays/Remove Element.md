# PROBLEM (Original Statement)

[Problem](https://leetcode.com/problems/remove-element/description/)
Given an integer array `nums` and an integer `val`, remove all occurrences of `val` in `nums` **in-place**.
The order of elements may change.
Return the number of elements in `nums` which are not equal to `val`.

After removing, the **first k elements** of `nums` must be the remaining elements.
What is after index `k-1` does not matter.

---

## BREAKDOWN PROBLEM

**What is being asked?**

We are given:

* An array `nums`
* A number `val`

We must:

* Remove all `val` from the array
* Do it **inside the same array** (no new array allowed)
* Return `k` = how many elements are NOT equal to `val`

The judge will only check:

* `k`
* First `k` elements of `nums` (after sorting them)

---

## CONSTRAINT UNDERSTANDING

```
0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100
```

This tells us:

* Array is small (100)
* We can do even O(n²), but interviewers expect O(n)
* In-place is compulsory → no new array

---

# BRUTE FORCE APPROACH

## First Thought Intuition

Desi brain says:

> “Jo value val hai, usko hatao, baaki ko naya array me daal do.”

So first idea:

* Loop through array
* If element ≠ val → push to new array

---

## Thought Process (Step-wise)

1. Create an empty array `temp`
2. Loop through `nums`
3. If `nums[i] != val` → push into `temp`
4. Copy `temp` back into `nums`
5. Return `temp.length`

---

## Pseudocode

```
temp = empty array
for each element x in nums:
    if x != val:
        temp.push(x)

for i from 0 to temp.length-1:
    nums[i] = temp[i]

return temp.length
```

---

## Algorithm

We filter all unwanted values into a new array, then overwrite original.

---

## CODE

### C++

#### V1 (Only Required Function)

```cpp
int removeElement(vector<int>& nums, int val) {
    vector<int> temp;                 // new array to store valid elements

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {          // if not equal to val, keep it
            temp.push_back(nums[i]);
        }
    }

    // copy back into nums
    for (int i = 0; i < temp.size(); i++) {
        nums[i] = temp[i];
    }

    return temp.size();                // k = number of valid elements
}
```

---

#### V2 (Complete Program)

```cpp
#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    vector<int> temp;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            temp.push_back(nums[i]);
        }
    }

    for (int i = 0; i < temp.size(); i++) {
        nums[i] = temp[i];
    }

    return temp.size();
}

int main() {
    vector<int> nums = {3,2,2,3};
    int val = 3;

    int k = removeElement(nums, val);

    cout << "k = " << k << endl;
    cout << "Array after removal: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
}
```

---

### JavaScript

#### V1

```js
function removeElement(nums, val) {
    let temp = [];

    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== val) {
            temp.push(nums[i]);
        }
    }

    for (let i = 0; i < temp.length; i++) {
        nums[i] = temp[i];
    }

    return temp.length;
}
```

---

#### V2

```js
function removeElement(nums, val) {
    let temp = [];

    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== val) {
            temp.push(nums[i]);
        }
    }

    for (let i = 0; i < temp.length; i++) {
        nums[i] = temp[i];
    }

    return temp.length;
}

let nums = [0,1,2,2,3,0,4,2];
let val = 2;

let k = removeElement(nums, val);
console.log("k =", k);
console.log(nums.slice(0, k));
```

---

## Time and Space Complexity

* Time = O(n)
* Space = O(n) ❌ (extra array)

---

## Does This Approach Fail?

YES.

Why?
Problem clearly says **in-place**.
We used extra array → space not allowed.

So we move to **better approach**.

---

# BETTER APPROACH (Two Pointers)

This is where **two pointer ka asli role** aata hai.

## First Thought Intuition (Desi Style)

Soch:

> Mujhe saare non-val elements ko front me jama karna hai.

Idea:

* Ek pointer read kare
* Ek pointer write kare

Like:

* `i` → jo dekh raha hai
* `k` → jaha next valid element dalna hai

---

## Thought Process

1. `i` goes from 0 to n-1
2. If `nums[i] != val`

   * Put it at `nums[k]`
   * Increase `k`
3. At end, `k` is number of valid elements

This keeps all good elements at front.

---

## Pseudocode

```
k = 0
for i = 0 to n-1:
    if nums[i] != val:
        nums[k] = nums[i]
        k++

return k
```

---

## Algorithm

We overwrite the array from the front with only valid values.

---

## CODE

### C++

#### V1

```cpp
int removeElement(vector<int>& nums, int val) {
    int k = 0;                          // position to store next valid element

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {           // if current is valid
            nums[k] = nums[i];          // place it at front
            k++;                        // move to next free position
        }
    }

    return k;
}
```

---

#### V2

```cpp
#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int k = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

int main() {
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;

    int k = removeElement(nums, val);

    cout << "k = " << k << endl;
    cout << "Array: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
}
```

---

### JavaScript

#### V1

```js
function removeElement(nums, val) {
    let k = 0;

    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== val) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}
```

---

#### V2

```js
function removeElement(nums, val) {
    let k = 0;

    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== val) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

let nums = [3,2,2,3];
let val = 3;

let k = removeElement(nums, val);
console.log("k =", k);
console.log(nums.slice(0, k));
```

---

## Time and Space

Time = O(n)
Space = O(1)

---

## Dry Run (nums = [3,2,2,3], val = 3)

```
i=0, nums[i]=3 → skip
i=1, nums[i]=2 → nums[0]=2, k=1
i=2, nums[i]=2 → nums[1]=2, k=2
i=3, nums[i]=3 → skip

Answer = k = 2
nums = [2,2,?,?]
```

---

## Why this works

We never break order of valid elements
We only push good elements forward
Bad elements get overwritten

---

## Why two pointer works here

This is **not** sliding window.
This is **filtering**.

One pointer reads, one writes.

---
