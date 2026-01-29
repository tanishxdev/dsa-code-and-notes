# PROBLEM (Original Statement)

Given an input string containing upper-case letters, lower-case letters, digits, and spaces (`' '`).

A **word** is defined as a sequence of **non-space characters**.
The words in the string are separated by **at least one space**.

Return a string with the **words in reverse order**, concatenated by a **single space**.

---

## BREAKDOWN PROBLEM

### What is being asked?

- Words ka **order reverse** karna hai
- Characters ke order ko **change nahi** karna
- Output me:
  - Sirf **single space** between words
  - No leading or trailing spaces

### What is input?

- Ek string `s`
- Example:
  `"  hello   world 123  "`

### What is output?

- Words reversed, clean spacing
- Output:
  `"123 world hello"`

---

## CONSTRAINT UNDERSTANDING

- String length can be large
- Multiple spaces ho sakte hain
- Leading / trailing spaces ho sakti hain
- Words ke andar digits + letters allowed

### Constraint impact:

- Space handling important
- Direct reverse string ❌ (characters break ho jaate)
- Word-level processing chahiye

---

# BRUTE FORCE APPROACH

> ⚠️ **Abhi sirf BRUTE FORCE.
> Next approach tab aayega jab ye fully clear ho.**

---

## First Thought Intuition (VERY IMPORTANT)

Sabse natural thought:

> “Pehle saare words nikal leta hoon,
> phir unko ulta order me jod deta hoon.”

Human bhi aise hi karta hai:

1. Words pehchano
2. Order reverse karo
3. Proper spacing ke saath join karo

Isliye ye brute force bilkul **logical first step** hai.

---

## Thought Process (Step-wise) — NO CODE

1. Ek empty list / array lo → `words`
2. String ko left se right scan karo
3. Jab bhi word mile:
   - Us word ko `words` me daal do

4. Scan ke baad:
   - `words` ko **reverse order** me traverse karo

5. Har word ke beech **single space** daal ke result banao

Key baat:

- Extra space ko ignore karna hoga
- Empty words ko skip karna hoga

---

## Behind the Intuition (WHY this works)

- Problem **word-level** hai, character-level nahi
- Jab words alag ho jaate hain:
  - Reverse karna trivial ho jaata hai

- Extra memory use hoti hai, par:
  - Logic simple
  - Bugs kam
  - Interview me explain karna easy

---

## Pseudocode

```
words = empty list
currentWord = ""

for each character ch in string:
    if ch is not space:
        add ch to currentWord
    else:
        if currentWord is not empty:
            add currentWord to words
            clear currentWord

if currentWord is not empty:
    add currentWord to words

result = ""
for i from words.size-1 to 0:
    add words[i] to result
    if i != 0:
        add space

return result
```

---

## Algorithm (Plain Steps)

1. Initialize empty list `words`
2. Traverse string character by character
3. Build words manually
4. Push completed words into list
5. Traverse list from back
6. Join words using single space
7. Return final string

---

## CODE

### C++

#### V1 (Only Required Function)

```cpp
string reverseWords(string s) {
    vector<string> words;
    string curr = "";

    for (char ch : s) {
        if (ch != ' ') {
            curr += ch;
        } else {
            if (!curr.empty()) {
                words.push_back(curr);
                curr = "";
            }
        }
    }

    if (!curr.empty()) {
        words.push_back(curr);
    }

    string result = "";
    for (int i = words.size() - 1; i >= 0; i--) {
        result += words[i];
        if (i != 0) result += " ";
    }

    return result;
}
```

---

#### V2 (Complete Program)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "  hello   world 123  ";

    vector<string> words;
    string curr = "";

    // Step 1: Extract words
    for (char ch : s) {
        if (ch != ' ') {
            curr += ch;
        } else {
            if (!curr.empty()) {
                words.push_back(curr);
                curr = "";
            }
        }
    }

    if (!curr.empty()) {
        words.push_back(curr);
    }

    // Step 2: Reverse words
    string result = "";
    for (int i = words.size() - 1; i >= 0; i--) {
        result += words[i];
        if (i != 0) result += " ";
    }

    cout << result << endl;
    return 0;
}
```

---

### JavaScript

#### V1 (Only Required Function)

```js
var reverseWords = function (s) {
  let words = [];
  let curr = "";

  for (let ch of s) {
    if (ch !== " ") {
      curr += ch;
    } else {
      if (curr.length > 0) {
        words.push(curr);
        curr = "";
      }
    }
  }

  if (curr.length > 0) {
    words.push(curr);
  }

  let result = "";
  for (let i = words.length - 1; i >= 0; i--) {
    result += words[i];
    if (i !== 0) result += " ";
  }

  return result;
};
```

---

## Time and Space Complexity

### Time Complexity

- Traversing string → O(n)
- Traversing words list → O(n)
- Total → **O(n)**

### Space Complexity

- Extra array for words → **O(n)**

---

## Dry Run (All Cases)

### Normal Case

Input: `"hello world"`
Output: `"world hello"`

### Multiple Spaces

Input: `"  a   b  c "`
Words: `["a","b","c"]`
Output: `"c b a"`

### Single Word

Input: `"hello"`
Output: `"hello"`

---

## Edge Cases

- Only spaces → return empty string
- Single word → unchanged
- Multiple spaces between words → ignored correctly

---

## How This Approach Handles the Problem

- Words extracted cleanly
- Extra spaces ignored
- Order reversed safely

---

## Does This Approach Fail?

YES ❌

### Where it fails (from optimization POV)

- Uses extra memory (vector / array)
- Interviewer may ask:
  **“Can you do it without extra list?”**

### Which constraint breaks it?

- Large input → memory overhead

👉 **That’s why we need a BETTER / OPTIMAL approach**

---

# BETTER APPROACH

### (Reverse whole string + fix words)

---

## First Thought Intuition (WHY this idea comes)

Brute force me problem kya thi?

- Extra array `words` use ho rahi thi → memory heavy

So next natural thought aata hai:

> “Agar main **poori string ko reverse** kar doon,
> toh words ka order automatically reverse ho jaayega.”

Example soch:

```
Original: "hello world"
Reverse : "dlrow olleh"
```

Order sahi ho gaya,
bas **har word ulta ho gaya**.

Toh next idea:

> “Order sahi ho gaya hai,
> ab bas **har word ko dubara reverse** kar dete hain.”

Ye thinking **step-by-step improvement** hai.

---

## Behind the Intuition (DEPTH / WHY IT WORKS)

Problem ko tod ke dekho:

### Hume kya chahiye?

- Words ka order reverse
- Words ke andar characters same order me

### Is approach me kya hota hai?

1. **Full string reverse**
   - Words ka order reverse ✔
   - Characters ulte ❌

2. **Har word ko reverse**
   - Characters wapas sahi ✔

So:

- 2 wrong → 1 right solution

Ye pattern bahut common hai:

> **Global reverse → local reverse**

Interviewers is logic ko pasand karte hain
kyunki ye **in-place thinking** dikhata hai.

---

## Thought Process (Step-wise)

1. String ko reverse karo (character-wise)
2. Ab string me:
   - Extra spaces ho sakti hain

3. String ko left se right traverse karo
4. Jab ek word mile:
   - Us word ko reverse karo

5. Extra spaces ko clean karo
6. Final string banao

---

## Important Note (LIMITATION upfront)

⚠️ Ye approach:

- **Mutable string** maangta hai
- C++ me easy
- JavaScript me string immutable hoti hai
  (array me convert karna padta hai)

Isliye ye **BETTER** hai,
par abhi **OPTIMAL + clean** nahi.

---

## Pseudocode

```
reverse entire string

i = 0
result = ""

while i < length:
    skip spaces
    start = i

    while i < length and char != space:
        i++

    end = i - 1
    reverse substring(start, end)

    add word to result with single space

return result
```

---

## Algorithm (Plain Steps)

1. Reverse whole string
2. Traverse string to find words
3. Reverse each word individually
4. Build result with single spaces
5. Remove leading/trailing spaces

---

## CODE

### C++

#### V1 (Only Required Function)

```cpp
string reverseWords(string s) {
    reverse(s.begin(), s.end());

    int n = s.size();
    int i = 0;
    string result = "";

    while (i < n) {
        // skip spaces
        while (i < n && s[i] == ' ') i++;
        if (i >= n) break;

        int start = i;

        // move till word end
        while (i < n && s[i] != ' ') i++;
        int end = i - 1;

        // reverse the word
        reverse(s.begin() + start, s.begin() + end + 1);

        // add to result
        if (!result.empty()) result += " ";
        result += s.substr(start, end - start + 1);
    }

    return result;
}
```

---

#### V2 (Complete Program)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "  hello   world 123  ";

    reverse(s.begin(), s.end());

    int n = s.size();
    int i = 0;
    string result = "";

    while (i < n) {
        while (i < n && s[i] == ' ') i++;
        if (i >= n) break;

        int start = i;
        while (i < n && s[i] != ' ') i++;
        int end = i - 1;

        reverse(s.begin() + start, s.begin() + end + 1);

        if (!result.empty()) result += " ";
        result += s.substr(start, end - start + 1);
    }

    cout << result << endl;
    return 0;
}
```

---

### JavaScript

> JS me string immutable hoti hai
> isliye array use karna padta hai

#### V1 (Only Required Function)

```js
var reverseWords = function (s) {
  let arr = s.split("").reverse();
  let n = arr.length;
  let i = 0;
  let result = [];

  while (i < n) {
    while (i < n && arr[i] === " ") i++;
    if (i >= n) break;

    let start = i;
    while (i < n && arr[i] !== " ") i++;
    let end = i - 1;

    // reverse word
    while (start < end) {
      [arr[start], arr[end]] = [arr[end], arr[start]];
      start++;
      end--;
    }

    result.push(arr.slice(start - (end - start + 1), i).join(""));
  }

  return result.join(" ");
};
```

---

## Time and Space Complexity

### Time Complexity

- Reverse string → O(n)
- Reverse each word → O(n)
- Total → **O(n)**

### Space Complexity

- C++: O(1) extra (output excluded)
- JS: O(n) (due to array)

---

## Dry Run (Normal Case)

Input:

```
"hello world"
```

Step 1:

```
"dlrow olleh"
```

Step 2 (reverse words):

```
"world hello"
```

---

## Edge Cases

- Multiple spaces → handled
- Single word → unchanged
- Leading/trailing spaces → removed

---

## How This Approach Handles the Problem

- Order reversed by full reverse
- Character order fixed by word reverse
- Clean spacing ensured

---

## Does This Approach Fail?

YES (Conceptually) ❌

### Why?

- Logic thoda complex
- JavaScript me awkward
- Interviewer may ask:
  **“Can you do it in ONE pass?”**

👉 That leads us to **OPTIMAL APPROACH**

---

# OPTIMAL APPROACH

### (One Pass • Two Pointers • No extra word list)

---

## First Thought Intuition (WHY this approach even exists)

Brute force problem:

- Extra array `words` ❌

Better approach problem:

- Reverse whole string → logic heavy ❌
- JS awkward ❌

So interviewer ka next push hota hai:

> “Can you do this in **ONE PASS**,
> without reversing whole string,
> without storing all words?”

So we ask ourselves:

### ❓ Observation

Words already **exist in correct character order**.
Bas **order galat** hai.

So instead of:

- storing words
- reversing string

👉 **Right se left chalo**
👉 Word milte hi answer me add kar do

This avoids:

- extra array
- double reverse
- unnecessary operations

---

## Behind the Intuition (DEPTH / WHY IT WORKS)

Human sentence bolte waqt:

- Last word pehle bol sakte ho
- Fir second last
- Fir third last

String bhi waise hi hai.

### Key idea:

- Words ka **natural boundary = spaces**
- Right side se scan karne par:
  - Pehla word jo milega = last word
  - Next = second last

So:

- Right → Left scan
- Word build karo
- Direct result me add karo

---

## Thought Process (Step-wise)

1. Pointer `i` ko string ke **end** pe rakho
2. Jab tak space ho → skip
3. Jab non-space mile:
   - Ye word ka **end** hai

4. Left chalte jao jab tak space na mile
5. Is word ko result me add karo
6. Repeat till start

Important:

- Result me words ke beech **single space**
- No leading / trailing spaces

---

## Pseudocode

```
i = length - 1
result = ""

while i >= 0:
    skip spaces

    end = i

    while i >= 0 and s[i] != space:
        i--

    start = i + 1

    if result not empty:
        add space
    add substring(start, end)

return result
```

---

## Algorithm (Plain Steps)

1. Start from end of string
2. Ignore spaces
3. Identify word boundaries
4. Append word to result
5. Continue till beginning

---

## CODE

### C++

#### V1 (Only Required Function)

```cpp
string reverseWords(string s) {
    int i = s.size() - 1;
    string result = "";

    while (i >= 0) {
        // skip spaces
        while (i >= 0 && s[i] == ' ') i--;
        if (i < 0) break;

        int end = i;

        // move to word start
        while (i >= 0 && s[i] != ' ') i--;
        int start = i + 1;

        if (!result.empty()) result += " ";
        result += s.substr(start, end - start + 1);
    }

    return result;
}
```

---

#### V2 (Complete Program)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "  hello   world 123  ";

    int i = s.size() - 1;
    string result = "";

    while (i >= 0) {
        while (i >= 0 && s[i] == ' ') i--;
        if (i < 0) break;

        int end = i;
        while (i >= 0 && s[i] != ' ') i--;
        int start = i + 1;

        if (!result.empty()) result += " ";
        result += s.substr(start, end - start + 1);
    }

    cout << result << endl;
    return 0;
}
```

---

### JavaScript

#### V1 (Only Required Function)

```js
var reverseWords = function (s) {
  let i = s.length - 1;
  let result = "";

  while (i >= 0) {
    while (i >= 0 && s[i] === " ") i--;
    if (i < 0) break;

    let end = i;
    while (i >= 0 && s[i] !== " ") i--;
    let start = i + 1;

    if (result.length > 0) result += " ";
    result += s.substring(start, end + 1);
  }

  return result;
};
```

---

#### V2 (Complete Program)

```js
let s = "  hello   world 123  ";
console.log(reverseWords(s));
```

---

## Time and Space Complexity

### Time Complexity

- Single traversal from right to left
- **O(n)**

### Space Complexity

- Output string only
- **O(1)** extra space (excluding output)

---

## Dry Run (All Cases)

### Normal Case

Input: `"hello world"`
Output: `"world hello"`

### Multiple Spaces

Input: `"  a   b  c "`
Right scan finds:

- c
- b
- a
  Output: `"c b a"`

### Single Word

Input: `"hello"`
Output: `"hello"`

---

## Edge Cases

- Only spaces → `""`
- Leading / trailing spaces → skipped
- Multiple spaces between words → cleaned

---

## How This Approach Handles the Problem

- Words never reversed internally
- Order reversed naturally
- Space cleanup automatic
- One pass, simple logic

---

## Why This Is Optimal

- Constraints allow linear scan
- No extra memory
- No double reverse
- Clean and readable
- Works equally well in C++ & JS

---

### 🔥 FINAL INTERVIEW ONE-LINER

> **Right se left scan karo,
> word milte hi answer me daalte jao.
> No reverse, no extra array.**

---
