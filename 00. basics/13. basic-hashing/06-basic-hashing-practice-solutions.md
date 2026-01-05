# **Complete Hashing Practice Solutions with Detailed Analysis**

## **COMMON MENTAL MODEL FOR ALL HASHING PROBLEMS**

**Always Ask These Questions:**

1. **Can I pre-store data?** → Yes → Use hashing
2. **What's the key-value relationship?** → Key = element, Value = frequency/position
3. **What's the range?** → Fixed small → Array, Unknown → unordered_map
4. **Do I need order?** → Yes → Scan original, No → Direct access

---

## **QUESTION 1: Frequency Query**

### **Why This Algorithm?**

- Multiple queries expected → O(n) per query is inefficient
- Pre-compute frequencies once → O(1) per query
- unordered_map provides average O(1) lookup

```cpp
#include <bits/stdc++.h>
using namespace std;

// Time: O(n) for building, O(1) per query
// Space: O(n) for frequency map
int frequencyQuery(const vector<int> &arr, int q) {
    unordered_map<int, int> freq;

    // Pre-store frequencies
    for (int x : arr) {
        freq[x]++;
    }

    return freq[q]; // Returns 0 if not found
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int q;
    cin >> q;

    cout << frequencyQuery(arr, q);
    return 0;
}
```

### **DRY RUN:**

```
Input:
n = 6
arr = [1, 2, 3, 2, 1, 2]
q = 2

Building freq:
1 → freq[1]++ = 1
2 → freq[2]++ = 1
3 → freq[3]++ = 1
2 → freq[2]++ = 2
1 → freq[1]++ = 2
2 → freq[2]++ = 3

Final freq map:
1 → 2
2 → 3
3 → 1

Query: freq[2] = 3
Output: 3
```

### **COMPLEXITY ANALYSIS:**

- **Time:** O(n) for building map, O(1) per query
- **Space:** O(n) for storing frequencies
- **Key Insight:** Trade space for time - optimal for multiple queries

---

## **QUESTION 2: Count Distinct Elements**

### **Why This Algorithm?**

- Set automatically eliminates duplicates
- Size of set = number of unique elements
- Better than sorting (O(n log n)) or nested loops (O(n²))

```cpp
#include <bits/stdc++.h>
using namespace std;

// Time: O(n) average, O(n²) worst-case (collisions)
// Space: O(n) worst case (all unique)
int countDistinctElement(const vector<int> &arr) {
    unordered_set<int> s;

    for (int x : arr) {
        s.insert(x);
    }

    return s.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << countDistinctElement(arr);
    return 0;
}
```

### **DRY RUN:**

```
Input:
n = 4
arr = [1, 2, 2, 3]

Set operations:
insert(1) → {1}
insert(2) → {1, 2}
insert(2) → {1, 2} (duplicate ignored)
insert(3) → {1, 2, 3}

Set size = 3
Output: 3
```

### **COMPLEXITY ANALYSIS:**

- **Time:** O(n) average (unordered_set operations are O(1) average)
- **Space:** O(k) where k = number of distinct elements
- **Alternative:** Could use unordered_map but set is more semantically correct

---

## **QUESTION 3: Check Element Presence**

### **Why This Algorithm?**

- Set provides O(1) average lookup
- Better than linear search O(n)
- Simple and readable

```cpp
#include <bits/stdc++.h>
using namespace std;

// Time: O(n) to build set, O(1) to check
// Space: O(n) for the set
bool checkElementPresence(const vector<int> &arr, int target) {
    unordered_set<int> s;

    for (int x : arr) {
        s.insert(x);
    }

    return s.find(target) != s.end();
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    if (checkElementPresence(arr, x))
        cout << "Exists";
    else
        cout << "Does not exist";

    return 0;
}
```

### **DRY RUN:**

```
Input:
arr = [1, 2, 2, 3]
target = 2

Set: {1, 2, 3}
find(2) returns iterator (found)
Output: "Exists"
```

### **COMPLEXITY ANALYSIS:**

- **Time:** O(n) for building, O(1) for lookup
- **Space:** O(n) for the set
- **Optimization:** Could break early when inserting if target found, but negligible gain

---

## **QUESTION 4: Character Frequency (Lowercase)**

### **Why This Algorithm?**

- Fixed range (a-z) → Perfect for array hashing
- O(1) space for array of size 26
- Preserving order requires scanning input twice

```cpp
#include <bits/stdc++.h>
using namespace std;

// Time: O(n)
// Space: O(1) - fixed 26 size array
void frequencyOfLowercase(const string &s) {
    int hash[26] = {0};

    // Count frequencies
    for (char c : s) {
        hash[c - 'a']++;
    }

    // Print in input order
    for (char c : s) {
        if (hash[c - 'a'] > 0) {
            cout << c << " -> " << hash[c - 'a'] << endl;
            hash[c - 'a'] = 0; // Mark as printed
        }
    }
}

int main() {
    string s;
    cin >> s;
    frequencyOfLowercase(s);
    return 0;
}
```

### **DRY RUN:**

```
Input: "abac"

First pass (counting):
a: hash[0]++ → 1
b: hash[1]++ → 1
a: hash[0]++ → 2
c: hash[2]++ → 1

Second pass (printing):
a: hash[0] = 2 > 0 → print "a -> 2", set hash[0] = 0
b: hash[1] = 1 > 0 → print "b -> 1", set hash[1] = 0
a: hash[0] = 0 → skip
c: hash[2] = 1 > 0 → print "c -> 1"

Output:
a -> 2
b -> 1
c -> 1
```

### **COMPLEXITY ANALYSIS:**

- **Time:** O(n) - two passes through string
- **Space:** O(1) - constant 26 element array
- **Key Insight:** Character arithmetic `c - 'a'` converts char to index (0-25)

---

## **QUESTION 5: Vowel Frequency**

### **Why This Algorithm?**

- Combines array hashing with vowel filtering
- Efficient O(n) solution
- Preserves input order for vowels

```cpp
#include <bits/stdc++.h>
using namespace std;

// Time: O(n)
// Space: O(1) - fixed array
void frequencyOfVowels(const string &s) {
    int hash[26] = {0};

    // Count all characters
    for (char c : s) {
        hash[c - 'a']++;
    }

    // Print only vowels in input order
    for (char c : s) {
        if ((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') &&
            hash[c - 'a'] > 0) {
            cout << c << " -> " << hash[c - 'a'] << endl;
            hash[c - 'a'] = 0; // Prevent duplicate printing
        }
    }
}

int main() {
    string s;
    cin >> s;
    frequencyOfVowels(s);
    return 0;
}
```

### **DRY RUN:**

```
Input: "education"

First pass - count all:
e: hash[4]++ → 1
d: hash[3]++ → 1
u: hash[20]++ → 1
c: hash[2]++ → 1
a: hash[0]++ → 1
t: hash[19]++ → 1
i: hash[8]++ → 1
o: hash[14]++ → 1
n: hash[13]++ → 1

Second pass - print vowels:
e: vowel & hash[4]=1 → print "e -> 1", hash[4]=0
d: not vowel → skip
u: vowel & hash[20]=1 → print "u -> 1", hash[20]=0
c: not vowel → skip
a: vowel & hash[0]=1 → print "a -> 1", hash[0]=0
t: not vowel → skip
i: vowel & hash[8]=1 → print "i -> 1", hash[8]=0
o: vowel & hash[14]=1 → print "o -> 1", hash[14]=0
n: not vowel → skip

Output:
e -> 1
u -> 1
a -> 1
i -> 1
o -> 1
```

### **COMPLEXITY ANALYSIS:**

- **Time:** O(n) - two linear passes
- **Space:** O(1) - fixed 26 element array
- **Alternative:** Could use unordered_map for only vowels to save minimal space

---

## **QUESTION 6: First Repeating Element**

### **Why This Algorithm?**

- Need frequency information first
- Then scan original to maintain order
- Two-pass approach preserves "first" semantics

```cpp
#include <bits/stdc++.h>
using namespace std;

// Time: O(n)
// Space: O(n) for frequency map
int firstRepeatingElement(vector<int> &arr) {
    unordered_map<int, int> freq;

    // Count frequencies
    for (int i = 0; i < arr.size(); i++) {
        freq[arr[i]]++;
    }

    // Find first element with frequency > 1
    for (int i = 0; i < arr.size(); i++) {
        if (freq[arr[i]] > 1) {
            return arr[i];
        }
    }

    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << firstRepeatingElement(arr);
    return 0;
}
```

### **DRY RUN:**

```
Input: [1, 2, 3, 2, 1]

First pass - build frequency:
1: freq[1]++ → 1
2: freq[2]++ → 1
3: freq[3]++ → 1
2: freq[2]++ → 2
1: freq[1]++ → 2

Frequency map:
1 → 2
2 → 2
3 → 1

Second pass - find first repeating:
arr[0] = 1, freq[1] = 2 > 1 → return 1

Output: 1

NOTE: This returns first element (by index) that has duplicates.
Some interpretations might want element whose second occurrence is earliest.
```

### **COMPLEXITY ANALYSIS:**

- **Time:** O(n) - two passes
- **Space:** O(n) - frequency map
- **Alternative Interpretation:** Store first occurrence index in map for different definition

---

## **QUESTION 7: First Non-Repeating Character**

### **Why This Algorithm?**

- Similar to Q6 but with frequency == 1
- Must scan original to maintain "first" order
- Two-pass approach essential

```cpp
#include <bits/stdc++.h>
using namespace std;

// Time: O(n)
// Space: O(n) for frequency map
char firstNonRepeatingCharacter(const string &s) {
    unordered_map<char, int> freq;

    // Count frequencies
    for (char c : s) {
        freq[c]++;
    }

    // Find first character with frequency 1
    for (char c : s) {
        if (freq[c] == 1) {
            return c;
        }
    }

    return '-'; // Sentinel for none found
}

int main() {
    string s;
    cin >> s;
    cout << firstNonRepeatingCharacter(s);
    return 0;
}
```

### **DRY RUN:**

```
Input: "aabbcdde"

First pass - count:
a: freq[a]++ → 1, then again → 2
b: freq[b]++ → 1, then again → 2
c: freq[c]++ → 1
d: freq[d]++ → 1, then again → 2
e: freq[e]++ → 1

Frequency map:
a → 2, b → 2, c → 1, d → 2, e → 1

Second pass - find first with freq=1:
a: freq=2 → skip
a: skip
b: freq=2 → skip
b: skip
c: freq=1 → return 'c'

Output: c
```

### **COMPLEXITY ANALYSIS:**

- **Time:** O(n) - two linear passes
- **Space:** O(k) where k = number of distinct characters
- **Edge Cases:** Empty string, all repeating characters

---

## **QUESTION 8: Check Arrays Equality (Frequency Based)**

### **Why This Algorithm?**

- Order doesn't matter → compare frequencies
- Single map with increment/decrement saves space
- Early size check optimizes

```cpp
#include <bits/stdc++.h>
using namespace std;

// Time: O(n)
// Space: O(n) for frequency map
bool checkFrequency(const vector<int> &arr1, const vector<int> &arr2) {
    // Quick size check
    if (arr1.size() != arr2.size())
        return false;

    unordered_map<int, int> freq;

    // Increment for arr1
    for (int x : arr1) {
        freq[x]++;
    }

    // Decrement for arr2
    for (int x : arr2) {
        freq[x]--;
    }

    // Check all frequencies are zero
    for (auto &pair : freq) {
        if (pair.second != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    vector<int> arr1(n1), arr2(n2);

    for (int i = 0; i < n1; i++) cin >> arr1[i];
    for (int i = 0; i < n2; i++) cin >> arr2[i];

    if (checkFrequency(arr1, arr2))
        cout << "Equal";
    else
        cout << "Not Equal";

    return 0;
}
```

### **DRY RUN:**

```
Input:
arr1 = [1, 2, 3, 2]
arr2 = [2, 1, 2, 3]

Size check: 4 == 4 → continue

Process arr1:
1: freq[1]++ → 1
2: freq[2]++ → 1
3: freq[3]++ → 1
2: freq[2]++ → 2

Process arr2:
2: freq[2]-- → 1
1: freq[1]-- → 0
2: freq[2]-- → 0
3: freq[3]-- → 0

Check all frequencies:
1 → 0, 2 → 0, 3 → 0 → All zero

Output: "Equal"
```

### **COMPLEXITY ANALYSIS:**

- **Time:** O(n) - three passes through elements
- **Space:** O(n) - frequency map
- **Alternative:** Sort both arrays and compare (O(n log n) time, O(1) space)

---

## **QUESTION 9: Digit Frequency**

### **Why This Algorithm?**

- Fixed range (0-9) → array hashing perfect
- Digit extraction via modulo and division
- O(1) space solution

```cpp
#include <bits/stdc++.h>
using namespace std;

// Time: O(d) where d = number of digits
// Space: O(1) - fixed 10 element array
void countDigitFrequency(long long n) {
    int hash[10] = {0};

    // Handle zero separately
    if (n == 0) {
        cout << "0 -> 1" << endl;
        return;
    }

    // Count digit frequencies
    while (n > 0) {
        int digit = n % 10;
        hash[digit]++;
        n /= 10;
    }

    // Print non-zero frequencies
    for (int i = 0; i < 10; i++) {
        if (hash[i] > 0) {
            cout << i << " -> " << hash[i] << endl;
        }
    }
}

int main() {
    long long n;
    cin >> n;
    countDigitFrequency(n);
    return 0;
}
```

### **DRY RUN:**

```
Input: 120312

Extraction process:
n = 120312
digit = 2, hash[2]++ → 1, n = 12031
digit = 1, hash[1]++ → 1, n = 1203
digit = 3, hash[3]++ → 1, n = 120
digit = 0, hash[0]++ → 1, n = 12
digit = 2, hash[2]++ → 2, n = 1
digit = 1, hash[1]++ → 2, n = 0

Final hash:
0 → 1, 1 → 2, 2 → 2, 3 → 1

Output:
0 -> 1
1 -> 2
2 -> 2
3 -> 1
```

### **COMPLEXITY ANALYSIS:**

- **Time:** O(d) where d = number of digits
- **Space:** O(1) - constant 10 element array
- **Edge Cases:** 0, negative numbers (handle with abs())

---

## **QUESTION 10: Remove Duplicates (Preserve Order)**

### **Why This Algorithm?**

- Set for O(1) duplicate check
- Original scan preserves order
- Output-only approach saves space

```cpp
#include <bits/stdc++.h>
using namespace std;

// Time: O(n) average
// Space: O(n) for the set
void removeDuplicatesPreserveOrder(const vector<int> &arr) {
    unordered_set<int> seen;

    for (int x : arr) {
        if (seen.find(x) == seen.end()) {
            cout << x << " ";
            seen.insert(x);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    removeDuplicatesPreserveOrder(arr);
    return 0;
}
```

### **DRY RUN:**

```
Input: [1, 2, 3, 2, 1, 4]

Process:
x = 1: not in seen → print "1 ", seen={1}
x = 2: not in seen → print "2 ", seen={1,2}
x = 3: not in seen → print "3 ", seen={1,2,3}
x = 2: in seen → skip
x = 1: in seen → skip
x = 4: not in seen → print "4 ", seen={1,2,3,4}

Output: 1 2 3 4
```

### **COMPLEXITY ANALYSIS:**

- **Time:** O(n) average
- **Space:** O(n) for the set
- **Alternative:** Could return new vector instead of printing

---

## **SUMMARY OF KEY INSIGHTS:**

### **When to use what:**

1. **Array Hashing:** Fixed small range (26 for letters, 10 for digits)
2. **unordered_map:** Large/unknown range, need frequency info
3. **unordered_set:** Only need presence/absence, no frequency
4. **Two-pass approach:** When order matters (Q4, Q6, Q7)

### **Time-Space Tradeoffs:**

- Hashing always trades space for time
- Array hashing: O(1) space, but limited to fixed ranges
- Map/Set: O(n) space, works for any range

### **Common Patterns:**

1. **Frequency problems:** Count → Process
2. **Order problems:** Store frequencies → Scan original
3. **Presence problems:** Set insertion → Set lookup

### **Performance Notes:**

- unordered_map average O(1), worst O(n) due to collisions
- In practice, STL implementations are efficient
- For guaranteed O(log n), use map (but usually unnecessary)

### **Interview Tips:**

1. Always clarify: "First" by index or by value?
2. Handle edge cases: empty input, all same elements
3. Mention alternatives and why you chose your approach

### KEY PATTERNS TO REMEMBER:

- Fixed Range → Use array hashing (Q4, Q5, Q9)
- Unknown Range → Use unordered_map/unordered_set
- Order Matters → Two-pass approach (count then scan original)
- Frequency Problems → Always count first, process later
- Presence/Absence Only → unordered_set is sufficient

This systematic approach ensures you can solve hashing problems efficiently and explain your reasoning clearly!
