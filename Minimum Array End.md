# PROBLEM (Original Statement)

You are given two integers `n` and `x`.

You have to construct an array of positive integers `nums` of size `n` such that:

* For every `0 ≤ i < n - 1`,
  `nums[i + 1] > nums[i]` (strictly increasing)
* The **bitwise AND** of all elements of `nums` is exactly `x`

Return the **minimum possible value of `nums[n - 1]`**.

---

## BREAKDOWN PROBLEM

### What is being asked?

* Build a strictly increasing array of size `n`
* Bitwise AND of **all elements** must be `x`
* Among all valid arrays, minimize the **last element**

### What is input?

* Integer `n`
* Integer `x`

### What is output?

* Minimum possible value of the last element (`nums[n-1]`)

---

## CONSTRAINT UNDERSTANDING

* `1 ≤ n ≤ 10^8`
* `1 ≤ x ≤ 10^8`

### Constraint impact

* We **cannot construct the full array**
* We must use **bitwise reasoning**
* Solution must be **O(log x)** or similar

---

# BRUTE FORCE APPROACH

## First Thought Intuition

* Start with `nums[0] = x`
* Keep increasing numbers one by one
* Ensure AND of all numbers stays `x`

---

## Thought Process (Step-wise)

1. Start from `x`
2. Keep adding `1`
3. Check AND of all numbers
4. Stop when size becomes `n`

---

## Pseudocode

```
nums[0] = x
for i = 1 to n-1:
    nums[i] = nums[i-1] + 1
check AND
```

---

## Algorithm

* Construct array directly

---

## Time and Space Complexity

* Time: `O(n)`
* Space: `O(n)`

---

## Does This Approach Fail?

### YES

* `n` can be `10^8`
* Impossible to simulate
* AND condition breaks easily

➡️ Move to next approach

---

# BETTER APPROACH (Bitwise Observation)

## First Thought Intuition

Important AND rule:

> If `A & B = x`, then **all bits set in `x` must be set in both `A` and `B`**

So:

* Every number in the array **must contain all 1-bits of `x`**
* Extra bits (0-bits of `x`) can vary

---

## Thought Process (Step-wise)

1. Fix `nums[0] = x`
2. To keep AND = `x`:

   * Never unset a `1` bit of `x`
3. We can only **add extra bits where `x` has 0**
4. Increasing numbers = adding combinations of these extra bits

---

## Key Insight (CRITICAL)

Let:

* Binary of `x` has some **0-bit positions**
* These positions can be treated like **free slots**
* We can map numbers from `0 → n-1` into these slots

👉 The last number will be:

```
x + (n - 1) placed into zero-bit positions of x
```

This is **bitwise embedding**, not normal addition.

---

## Pseudocode

```
result = x
k = n - 1
for each bit position i from 0 to 60:
    if bit i of x == 0:
        take lowest bit of k
        place it at position i in result
        shift k right
return result
```

---

## Algorithm

1. Start with `result = x`
2. Let `extra = n - 1`
3. Traverse bit positions from LSB to MSB
4. Wherever `x` has `0`, fill it with bits from `extra`
5. Return result

---

# OPTIMAL APPROACH

(This is the same as the better approach — already optimal)

---

## CODE (C++ and JavaScript)

---

### C++

#### V1 (Only Required Function)

```cpp
long long minEnd(int n, int x) {
    long long result = x;
    long long extra = n - 1; // we need (n-1) increments

    // Iterate through bit positions
    for (int bit = 0; extra > 0; bit++) {
        // If this bit is 0 in x, we can use it
        if ((x & (1LL << bit)) == 0) {
            // Take lowest bit of extra
            if (extra & 1) {
                result |= (1LL << bit);
            }
            // Move to next bit of extra
            extra >>= 1;
        }
    }

    return result;
}
```

---

#### V2 (Complete Program)

```cpp
#include <bits/stdc++.h>
using namespace std;

long long minEnd(int n, int x) {
    long long result = x;
    long long extra = n - 1;

    // We distribute bits of (n-1) into zero-bit positions of x
    for (int bit = 0; extra > 0; bit++) {
        // Check if bit is 0 in x
        if ((x & (1LL << bit)) == 0) {
            // If current lowest bit of extra is 1,
            // set this bit in result
            if (extra & 1) {
                result |= (1LL << bit);
            }
            // Shift extra to process next bit
            extra >>= 1;
        }
    }

    return result;
}

int main() {
    cout << minEnd(3, 4) << endl; // 6
    cout << minEnd(2, 7) << endl; // 15
    return 0;
}
```

---

### JavaScript

#### V1 (Only Required Function)

```js
var minEnd = function(n, x) {
    let result = BigInt(x);
    let extra = BigInt(n - 1);

    for (let bit = 0n; extra > 0n; bit++) {
        if ((result & (1n << bit)) === 0n) {
            if (extra & 1n) {
                result |= (1n << bit);
            }
            extra >>= 1n;
        }
    }

    return result;
};
```

---

#### V2 (Complete Program)

```js
function minEnd(n, x) {
    let result = BigInt(x);
    let extra = BigInt(n - 1);

    for (let bit = 0n; extra > 0n; bit++) {
        // If x does not have this bit set
        if ((result & (1n << bit)) === 0n) {
            // Place lowest bit of extra here
            if (extra & 1n) {
                result |= (1n << bit);
            }
            extra >>= 1n;
        }
    }

    return result;
}

// Tests
console.log(String(minEnd(3, 4))); // 6
console.log(String(minEnd(2, 7))); // 15
```

---

## Time and Space Complexity

### Time Complexity

```
O(log n + log x)
```

### Space Complexity

```
O(1)
```

---

## Dry Run (All Cases)

### Example 1

```
n = 3, x = 4
x = 100
n-1 = 2 = 10

Zero bit positions: 0,1,...

Place bits:
bit 0 ← 0
bit 1 ← 1

Result = 110 = 6
```

---

### Example 2

```
n = 2, x = 7
x = 111
n-1 = 1

Next zero bit = bit 3
Result = 1111 = 15
```

---

## Edge Cases

* `n = 1` → answer is `x`
* Large `n`
* All bits of `x` are `1`
* Sparse binary representation

All handled.

---

## How This Approach Handles the Problem

* Preserves all `1` bits of `x`
* Adds minimal extra bits
* Ensures strictly increasing
* AND remains exactly `x`

---

## Why This Is Optimal

* No array construction
* Uses pure bit manipulation
* Minimal possible last value
* Interview-grade solution

