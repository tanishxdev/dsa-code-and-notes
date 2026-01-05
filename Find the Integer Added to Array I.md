# PROBLEM (Original Statement)

You are given two arrays of equal length, `nums1` and `nums2`.

Each element in `nums1` has been increased (or decreased in the case of negative) by an integer `x`.

As a result, `nums1` becomes equal to `nums2`.
Two arrays are considered equal when they contain the same integers with the same frequencies.

Return the integer `x`.

---

## BREAKDOWN PROBLEM

### What is being asked?

* There exists **one integer `x`**
* Adding `x` to **every element** of `nums1`
* Makes `nums1` and `nums2` equal as **multisets**

### What is input?

* Two integer arrays `nums1`, `nums2`
* Same length

### What is output?

* An integer `x`

---

## CONSTRAINT UNDERSTANDING

* `1 ≤ length ≤ 100`
* `0 ≤ nums[i] ≤ 1000`
* **Guaranteed that an answer exists**

### Constraint impact

* Small input size
* Multiple valid approaches possible
* Sorting / frequency / math all acceptable

---

# BRUTE FORCE APPROACH

## First Thought Intuition

* Try **all possible values of x**
* Check if adding `x` to nums1 makes it equal to nums2

---

## Thought Process (Step-wise)

1. Guess a value of `x`
2. Add it to every element of `nums1`
3. Check if it matches `nums2`

---

## Pseudocode

```
for x from -1000 to 1000:
    newArray = nums1 + x
    if newArray == nums2:
        return x
```

---

## Algorithm

* Try all x
* Validate

---

## Time and Space Complexity

* Time: O(2000 × n)
* Space: O(n)

---

## Does This Approach Fail?

### YES

* Unnecessary guessing
* Inefficient logic
* We can do much better

➡️ Move to next approach

---

# BETTER APPROACH (Sorting + Difference)

## First Thought Intuition

If:

```
nums1[i] + x = nums2[j]
```

Then:

```
x = nums2[j] - nums1[i]
```

But order doesn’t matter → **sort both arrays**

---

## Thought Process (Step-wise)

1. Sort `nums1`

   * Sorting puts elements in increasing order.
   * After sorting, relative positions become comparable.

2. Sort `nums2`

   * Same logic: sorted order removes any shuffle effect.

3. After sorting:

   * Problem guarantee: `nums2` is formed by adding the **same integer `x`** to every element of `nums1`.
   * So after sorting, **corresponding elements differ by the same value `x`**.

   Example intuition:

   ```
   nums1 = [2, 6, 4]
   nums2 = [9, 7, 5]

   After sorting:
   nums1 = [2, 4, 6]
   nums2 = [5, 7, 9]

   Differences:
   5 - 2 = 3
   7 - 4 = 3
   9 - 6 = 3
   ```

4. The difference between any pair gives `x`

   * Since all differences are equal, we can safely take the first pair.

---

## Pseudocode

```
sort(nums1)
sort(nums2)
return nums2[0] - nums1[0]
```

Why this works:

* Sorting aligns the smallest elements.
* Smallest element difference already equals `x`.
* No need to check all elements because the problem guarantees validity.

---

## Algorithm

* Sort both arrays
* Subtract first elements

Expanded reasoning:

* Sorting ensures correct alignment.
* Since every element was increased by the same `x`,
  `nums2[i] - nums1[i]` is constant for all `i`.
* Taking index `0` is enough.

---

## WHY SORTING?


### 1. Pehle problem ko bina sort samjho

Problem says:

> `nums2` = `nums1` ke **har element me SAME number add karke** bana hai

That means:

```
nums2[i] = nums1[i] + x   (for all i)
```

But **order change ho sakta hai**.

Example:

```
nums1 = [3, 1, 5]
x = 4

nums2 banega:
[7, 5, 9]   (but order random ho sakta hai)
```

Now arrays are:

```
nums1 = [3, 1, 5]
nums2 = [7, 5, 9]
```

👉 Ab dekh:

* nums1[0] = 3
* nums2[0] = 7
* 7 - 3 = 4  (looks correct)

But ye **luck** hai.

---

### 2. Problem jab order different ho

Example:

```
nums1 = [3, 1, 5]
nums2 = [9, 5, 7]   // shuffled
```

Ab try karo bina sort:

```
nums2[0] - nums1[0] = 9 - 3 = 6  ❌ galat
nums2[1] - nums1[1] = 5 - 1 = 4  ✅
nums2[2] - nums1[2] = 7 - 5 = 2  ❌
```

👉 Confusion:

* Alag-alag difference aa raha
* Pata hi nahi kaunsa sahi hai

**Yahi asli problem hai.**

---

### 3. Ab SORT karo (yeh magic nahi, alignment hai)

Sort ka kaam:

> **same size ke numbers ko same position pe lana**

#### After sorting:

```
nums1 = [1, 3, 5]
nums2 = [5, 7, 9]
```

Ab dekho:

```
nums2[0] - nums1[0] = 5 - 1 = 4
nums2[1] - nums1[1] = 7 - 3 = 4
nums2[2] - nums1[2] = 9 - 5 = 4
```

👉 Ab **har jagah SAME difference** aa raha

**Reason**:

* Smallest + x = smallest
* Second smallest + x = second smallest
* Largest + x = largest

Sorting ne **original pairing wapas bana di**.

---

### 4. Simple real-life analogy (yaad rakhne layak)

Socho:

```
Height list of students
```

nums1:

```
[150, 160, 170]
```

Sab students ne same shoes pehne (+5 cm):

nums2:

```
[155, 165, 175]
```

Agar list shuffle ho jaye:

```
[175, 155, 165]
```

Agar bina sort compare karoge:

* galat student compare ho jayega

Sort karoge:

* shortest ↔ shortest
* tallest ↔ tallest

**Bas yahi fayda hai sorting ka.**

---

### 5. Isliye sirf first element ka difference kaam karta hai

After sorting:

* nums1[0] = smallest original
* nums2[0] = smallest after adding x

So:

```
x = nums2[0] - nums1[0]
```

Baaki sab bhi same hi denge.

---

### 6. Ek line me final truth (interview level)

> Sorting ensures **correct alignment of corresponding elements**,
> so the constant difference `x` can be safely computed.

---

### 7. Agar ab bhi doubt ho, next step

---
## CODE (C++ and JavaScript)

### C++

#### V1 (Only Required Function)

```cpp
int addedInteger(vector<int>& nums1, vector<int>& nums2) {
    // Step 1: Sort nums1 to bring elements in order
    sort(nums1.begin(), nums1.end());

    // Step 2: Sort nums2 for the same reason
    sort(nums2.begin(), nums2.end());

    // Step 3: Since nums2[i] = nums1[i] + x,
    // x can be found by subtracting any corresponding pair
    // Using first element is sufficient
    return nums2[0] - nums1[0];
}
```

---

---

#### V2 (Complete Program)

```cpp
#include <bits/stdc++.h>
using namespace std;

int addedInteger(vector<int>& nums1, vector<int>& nums2) {
    // Sort both arrays to align corresponding elements
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    // The difference between any matching pair is x
    return nums2[0] - nums1[0];
}

int main() {
    vector<int> nums1 = {2, 6, 4};
    vector<int> nums2 = {9, 7, 5};

    cout << "x = " << addedInteger(nums1, nums2) << endl;
    return 0;
}
```

---

### JavaScript

#### V1 (Only Required Function)

```js
var addedInteger = function(nums1, nums2) {
    nums1.sort((a, b) => a - b);
    nums2.sort((a, b) => a - b);

    return nums2[0] - nums1[0];
};
```

---

#### V2 (Complete Program)

```js
function addedInteger(nums1, nums2) {
    // Sort both arrays
    nums1.sort((a, b) => a - b);
    nums2.sort((a, b) => a - b);

    // Difference gives x
    return nums2[0] - nums1[0];
}

// Test cases
console.log(addedInteger([2,6,4], [9,7,5])); // 3
console.log(addedInteger([10], [5]));        // -5
console.log(addedInteger([1,1,1], [1,1,1])); // 0
```

---

## Time and Space Complexity

### Time Complexity

```
O(n log n)
```

### Space Complexity

```
O(1) (ignoring sort internals)
```

---

## Dry Run (All Cases)

### Normal Case

```
nums1 = [2,6,4] → sort → [2,4,6]
nums2 = [9,7,5] → sort → [5,7,9]

x = 5 - 2 = 3
```

### Best Case

```
nums1 = [1]
nums2 = [1]

x = 0
```

### Worst Case

```
nums1 = [0,0,0]
nums2 = [1000,1000,1000]

x = 1000
```

---

## Edge Cases

* Single element arrays
* Negative x
* All values equal
* Repeated elements

Handled safely.

---

## How This Approach Handles the Problem

* Sorting aligns corresponding values
* Difference is constant
* Guaranteed correctness by problem statement

---

## Does This Approach Fail?

### NO

---

# OPTIMAL APPROACH (Math Insight)

## First Thought Intuition

If:

```
nums1[i] + x = nums2[j]
```

Then:

```
x = average(nums2) - average(nums1)
```

Because **same x is added everywhere**.

---

## Thought Process (Step-wise)

1. Compute sum of nums1
2. Compute sum of nums2
3. Difference of averages gives x

---

## Pseudocode

```
sum1 = sum(nums1)
sum2 = sum(nums2)
x = (sum2 - sum1) / n
return x
```

---

## Algorithm

* One pass sum
* Compute difference

---

## CODE (C++ and JavaScript)

### C++

#### V1 (Only Required Function)

```cpp
int addedInteger(vector<int>& nums1, vector<int>& nums2) {
    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < nums1.size(); i++) {
        sum1 += nums1[i];
        sum2 += nums2[i];
    }

    return (sum2 - sum1) / nums1.size();
}
```

---

#### V2 (Complete Program)

```cpp
#include <bits/stdc++.h>
using namespace std;

int addedInteger(vector<int>& nums1, vector<int>& nums2) {
    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < nums1.size(); i++) {
        sum1 += nums1[i];
        sum2 += nums2[i];
    }

    // Since same x added to all elements
    return (sum2 - sum1) / nums1.size();
}

int main() {
    vector<int> nums1 = {2,6,4};
    vector<int> nums2 = {9,7,5};

    cout << "x = " << addedInteger(nums1, nums2) << endl;
    return 0;
}
```

---

### JavaScript

#### V1 (Only Required Function)

```js
var addedInteger = function(nums1, nums2) {
    let sum1 = 0, sum2 = 0;

    for (let i = 0; i < nums1.length; i++) {
        sum1 += nums1[i];
        sum2 += nums2[i];
    }

    return (sum2 - sum1) / nums1.length;
};
```

---

#### V2 (Complete Program)

```js
function addedInteger(nums1, nums2) {
    let sum1 = 0, sum2 = 0;

    for (let i = 0; i < nums1.length; i++) {
        sum1 += nums1[i];
        sum2 += nums2[i];
    }

    return (sum2 - sum1) / nums1.length;
}

// Tests
console.log(addedInteger([2,6,4], [9,7,5])); // 3
console.log(addedInteger([10], [5]));        // -5
console.log(addedInteger([1,1], [1,1]));     // 0
```

---

## Time and Space Complexity

### Time

```
O(n)
```

### Space

```
O(1)
```

---

## Why This Is Optimal

* Single pass
* No sorting
* Uses math guarantee
* Cleanest interview solution
