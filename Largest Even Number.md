# PROBLEM (Original Statement)

You are given a string `s` consisting only of the characters `'1'` and `'2'`.

You may delete any number of characters from `s` **without changing the order** of the remaining characters.

Return the **largest possible resultant string** that represents an **even integer**.
If there is no such string, return the empty string `""`.

---

## BREAKDOWN PROBLEM

### What is being asked?

* From the given string `s`, we can **delete characters** (subsequence).
* The remaining string must:

  * Represent a **number**
  * Be **even**
  * Be **lexicographically / numerically largest possible**

### What is input?

* A string `s` containing only `'1'` and `'2'`

### What is output?

* A string (largest even number possible)
* Or `""` if no even number can be formed

---

## CONSTRAINT UNDERSTANDING

* Characters allowed: `'1'`, `'2'`
* Order **cannot change**
* We can delete **any number** of characters
* Length can be large (string-based logic required)

### Important observations from constraints

* Only **even digit available is `'2'`**
* An even number **must end with `'2'`**
* We want the **longest and lexicographically largest** valid subsequence

---

# BRUTE FORCE APPROACH

## First Thought Intuition

* Generate **all subsequences**
* Check which ones:

  * End with `'2'`
  * Are even
* Return the largest

---

## Thought Process (Step-wise)

1. Generate all subsequences of `s`
2. For each subsequence:

   * Check if last character is `'2'`
   * Compare and keep the largest

---

## Pseudocode

```
allSubsequences = generate all subsequences of s
answer = ""

for each subseq:
    if subseq ends with '2':
        answer = max(answer, subseq)

return answer
```

---

## Algorithm

* Try all combinations
* Compare valid ones

---

## CODE

❌ **Not writing code**

---

## Time and Space Complexity

* Time: `O(2^n)`
* Space: `O(2^n)`

---

## Does This Approach Fail?

### YES

* Exponential
* Impossible for large `s`

➡️ Move to next approach

---

# BETTER APPROACH

## First Thought Intuition

Let’s reason instead of brute force.

Key facts:

* Only `'2'` is even
* Final number **must end with `'2'`**
* To maximize number:

  * Take **as many characters as possible**
  * Especially `'2'` > `'1'`

---

## Thought Process (Step-wise)

1. If there is **no `'2'` in the string**, answer is `""`
2. The last character **must be `'2'`**
3. To make number largest:

   * Take **all characters before the last chosen `'2'`**
4. Deleting characters only reduces length → reduces value

---

## Key Insight (Very Important)

👉 **The largest possible even subsequence is simply the prefix ending at the last `'2'`**

Why?

* Longer length = larger number
* `'2'` is the only even digit
* Any deletion before last `'2'` only makes it smaller

---

## Pseudocode

```
find last index of '2' in s
if not found:
    return ""
return substring from 0 to lastIndex (inclusive)
```

---

## Algorithm

1. Traverse string to find the **last `'2'`**
2. If not found → return `""`
3. Return substring `[0 … lastIndex]`

---

## CODE (C++ and JavaScript)

---

### C++

#### V1 (Only Required Function)

```cpp
string largestEvenNumber(string s) {
    // Find the last occurrence of '2'
    int lastTwoIndex = -1;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '2') {
            lastTwoIndex = i;
        }
    }

    // If no '2' found, no even number possible
    if (lastTwoIndex == -1) {
        return "";
    }

    // Return prefix ending at last '2'
    return s.substr(0, lastTwoIndex + 1);
}
```

---

#### V2 (Complete Program)

```cpp
#include <bits/stdc++.h>
using namespace std;

string largestEvenNumber(string s) {
    int lastTwoIndex = -1;

    // Traverse entire string
    for (int i = 0; i < s.length(); i++) {
        // Track last position of '2'
        if (s[i] == '2') {
            lastTwoIndex = i;
        }
    }

    // If no '2' exists, no even number possible
    if (lastTwoIndex == -1) {
        return "";
    }

    // Take the largest possible prefix ending with '2'
    return s.substr(0, lastTwoIndex + 1);
}

int main() {
    string s = "12121";

    string result = largestEvenNumber(s);

    cout << "Largest Even Number = \"" << result << "\"" << endl;
    return 0;
}
```

---

### JavaScript

#### V1 (Only Required Function)

```js
var largestEvenNumber = function(s) {
    let lastTwoIndex = -1;

    // Find last occurrence of '2'
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '2') {
            lastTwoIndex = i;
        }
    }

    // If no '2', no even number possible
    if (lastTwoIndex === -1) {
        return "";
    }

    // Return prefix ending at last '2'
    return s.substring(0, lastTwoIndex + 1);
};
```

---

#### V2 (Complete Program)

```js
function largestEvenNumber(s) {
    let lastTwoIndex = -1;

    // Traverse string to find last '2'
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '2') {
            lastTwoIndex = i;
        }
    }

    // No even digit
    if (lastTwoIndex === -1) {
        return "";
    }

    // Return maximum prefix
    return s.substring(0, lastTwoIndex + 1);
}

// Test cases
console.log(largestEvenNumber("12121")); // "1212"
console.log(largestEvenNumber("1111"));  // ""
console.log(largestEvenNumber("222"));   // "222"
```

---

## Time and Space Complexity

### Time Complexity

```
O(n)
```

Single traversal of string.

### Space Complexity

```
O(1)
```

No extra space used (excluding output).

---

## Dry Run (All Cases)

### Normal Case

```
s = "12121"
last '2' index = 3
result = "1212"
```

### Best Case

```
s = "2"
result = "2"
```

### Worst Case

```
s = "111111"
no '2' → ""
```

---

## Edge Cases

* No `'2'` in string
* Single character
* All `'2'`
* `'2'` only at beginning or end

All handled.

---

## How This Approach Handles the Problem

* Uses **parity rule** (even → last digit even)
* Maximizes **length and value**
* Avoids unnecessary deletions
* Linear time, optimal

---

## Does This Approach Fail?

### NO

---

# WHY THIS IS OPTIMAL

* Any even number must end with `'2'`
* Longest prefix gives maximum value
* Cannot do better than `O(n)`
