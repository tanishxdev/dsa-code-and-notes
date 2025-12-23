
# TRIE — SEARCH OPERATION (ONLY SEARCH)

---

## What We Covered Here

1. What **search** really means in a Trie
2. Difference between **searching a word** vs **checking a prefix**
3. Exact responsibility of `search(word)`
4. Step-by-step thinking (what / why / how)
5. Core observation behind Trie search
6. Search algorithm (human logic → machine steps)
7. Pseudocode (before code)
8. Dry runs (multiple cases)
9. C++ implementation

   * V1: only required function
   * V2: full class with deep comments
10. JavaScript implementation
11. Edge cases
12. Time & Space complexity (deep explanation)
13. Common beginner mistakes
14. Interview-level takeaway

---

## 1. What Does “Search” Mean in a Trie?

When we call:

```text
search("app")
```

We are asking:

> “Was **this exact word** inserted before?”

Important:

* `"app"` must exist
* AND it must be marked as a **complete word**
* Just being a prefix is **NOT enough**

---

## 2. Search vs Prefix Check (VERY IMPORTANT)

Assume we inserted:

```
["apple"]
```

Now:

| Query             | Answer | Why                     |
| ----------------- | ------ | ----------------------- |
| search("apple")   | true   | exact word exists       |
| search("app")     | false  | prefix only, not a word |
| startsWith("app") | true   | prefix exists           |

👉 **Search cares about `isEndOfWord`.**

---

## 3. Responsibility of `search(word)`

After calling `search(word)`:

Return `true` **only if**:

1. Every character path exists from root
2. The **last node** has `isEndOfWord == true`

If **either fails**, return `false`.

---

## 4. High-Level Search Thinking (Human Brain)

Searching `"apple"` means:

* Start at root
* For each character:

  * If path exists → move forward
  * If path breaks → word does not exist
* After last character:

  * Check: did a word end here?

This is it.
No branching. No guessing.

---

## 5. Core Observation (MOST IMPORTANT)

> **Trie search follows a single path.
> No backtracking. No alternatives.**

Unlike DP or recursion, search is **deterministic**.

---

## 6. Search Algorithm (Step-by-Step)

Given `word`:

1. Start at `root`
2. For each character `ch` in `word`:

   * If current node has no child `ch` → return `false`
   * Move to child `ch`
3. After loop:

   * If `isEndOfWord == true` → return `true`
   * Else → return `false`

---

## 7. Pseudocode (BEFORE CODE)

```
SEARCH(word):
    node = root

    for each character ch in word:
        if node has no child ch:
            return false
        node = child ch

    if node.isEndOfWord == true:
        return true
    else:
        return false
```

If this is clear, code is mechanical.

---

## 8. Dry Run — Exact Match Case

Inserted words:

```
["app", "apple"]
```

### search("app")

Steps:

* root → 'a' ✔
* 'a' → 'p' ✔
* 'p' → 'p' ✔
* End reached
* `isEndOfWord == true`

✅ return `true`

---

## 9. Dry Run — Prefix but Not Word

Inserted words:

```
["apple"]
```

### search("app")

Steps:

* root → 'a' ✔
* 'a' → 'p' ✔
* 'p' → 'p' ✔
* End reached
* `isEndOfWord == false`

❌ return `false`

This is the **most common interview trap**.

---

## 10. Dry Run — Character Missing

Inserted words:

```
["apple"]
```

### search("apz")

Steps:

* root → 'a' ✔
* 'a' → 'p' ✔
* 'p' → 'z' ❌ (missing)

❌ return `false` immediately

---

## 11. C++ Implementation — SEARCH ONLY

Assume `TrieNode` and `root` already exist.

---

### C++ V1 — Only Required Function

```cpp
bool search(string word) {
    TrieNode* node = root;

    for (char ch : word) {
        int idx = ch - 'a';

        if (node->children[idx] == nullptr)
            return false;

        node = node->children[idx];
    }

    return node->isEndOfWord;
}
```

---

### Why Each Step Exists

```cpp
if (node->children[idx] == nullptr)
    return false;
```

Means:

> Path does not exist → word was never inserted.

---

```cpp
return node->isEndOfWord;
```

Means:

> Prefix exists, but check if it is a **complete word**.

---

### C++ V2 — Full Class, Deep Commented

```cpp
#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Search for a word in the Trie
    bool search(string word) {

        // Start from root
        TrieNode* node = root;

        // Traverse each character
        for (char ch : word) {

            int index = ch - 'a';

            // If path breaks, word not found
            if (node->children[index] == nullptr) {
                return false;
            }

            // Move to next node
            node = node->children[index];
        }

        // Check if word actually ends here
        return node->isEndOfWord;
    }
};
```

---

## 12. JavaScript Implementation — SEARCH ONLY

```javascript
search(word) {
    let node = this.root;

    for (let ch of word) {
        let index = ch.charCodeAt(0) - 'a'.charCodeAt(0);

        if (node.children[index] === null) {
            return false;
        }

        node = node.children[index];
    }

    return node.isEndOfWord;
}
```

---

## 13. Edge Cases (INTERVIEW IMPORTANT)

1. **Search empty string**

   * Returns true only if empty word was inserted
2. **Search prefix**

   * Must return false if not marked as end
3. **Search word not inserted**

   * Path breaks → false
4. **Search after duplicate inserts**

   * Still true (no duplicates stored)

---

## 14. Time & Space Complexity (DEEP)

### Time Complexity — O(L)

* `L` = length of word
* One step per character
* No dependence on number of stored words

---

### Space Complexity — O(1)

* No extra memory used during search
* Only pointer movement

(Trie storage not counted here.)

---

## 15. Common Beginner Mistakes

1. Returning true just because path exists
2. Forgetting `isEndOfWord` check
3. Confusing search with `startsWith`
4. Thinking search is O(N)
5. Modifying nodes during search

---

## 16. Interview-Level Takeaway (LOCK THIS)

> **Trie search verifies both path existence and word termination.
> Prefix existence alone is not enough.**
