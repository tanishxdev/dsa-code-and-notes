

# TRIE — INSERT OPERATION (ONLY INSERT)

---

## What We Covered Here

1. What **insert** really means in a Trie
2. Why insert is different from array / map insert
3. Exact responsibility of `insert(word)`
4. Step-by-step thinking (what / why / how)
5. Core observation behind Trie insertion
6. Insert algorithm (human thinking → machine steps)
7. Pseudocode (before any code)
8. Dry run with multiple examples
9. C++ implementation

   * V1: only required function
   * V2: full class with deep comments
10. JavaScript implementation
11. Edge cases
12. Time & Space complexity (deep explanation)
13. Common beginner mistakes
14. Interview-level takeaway

---

## 1. What Does “Insert” Mean in a Trie?

When we say:

```text
insert("apple")
```

We are **NOT**:

* storing `"apple"` as a whole string
* pushing it into a list
* mapping `"apple" → true`

Instead, we are:

> Creating / reusing **character nodes**
> along the path `a → p → p → l → e`
> and marking the **last node** as a valid word ending.

---

## 2. Why Trie Insert Is Special (Compared to Other DS)

### Array / Vector Insert

* Store full word
* No structure sharing

### HashSet Insert

* Fast exact lookup
* No prefix structure

### Trie Insert (Key Difference)

* Characters are stored **one by one**
* Prefixes are **shared**
* Memory is reused intelligently

This is why insert is the **foundation** of Trie.

---

## 3. Responsibility of `insert(word)` (VERY CLEAR)

After calling `insert(word)`:

1. Every character of `word` must exist as a path from root
2. The path must be connected correctly
3. The **last character node** must be marked as `endOfWord = true`
4. Existing paths must NOT be broken

That’s it. Nothing more.

---

## 4. High-Level Insert Thinking (Human Brain)

Imagine you are inserting `"app"`.

You stand at the **root**.

For each character:

* Ask:

  > “Is there already a node for this character?”
* If yes → move to it
* If no → create it, then move

After last character:

* Say:

  > “A word ends here.”

This exact thinking becomes code.

---

## 5. Core Observation (MOST IMPORTANT)

> **Trie insert is a path-building process, not a storage process.**

You are not “saving a word”.
You are **building a path of characters**.

---

## 6. Insert Algorithm (Step-by-Step)

Let `word = "apple"`

1. Start at `root`
2. For each character `ch` in `word`:

   * If `currentNode` does NOT have child `ch`

     * Create a new Trie node
   * Move to child `ch`
3. After last character:

   * Mark current node as `endOfWord = true`

---

## 7. Pseudocode (BEFORE CODE — VERY IMPORTANT)

```
INSERT(word):
    node = root

    for each character ch in word:
        if node has no child for ch:
            create new TrieNode
            link it with ch

        move node to child ch

    mark node as end of word
```

If this pseudocode is clear, code is mechanical.

---

## 8. Dry Run — Single Word (Very Slow)

### Insert `"app"`

```
root
```

#### Step 1: 'a'

* root has no 'a'
* create node 'a'
* move to 'a'

#### Step 2: 'p'

* 'a' has no 'p'
* create node 'p'
* move to 'p'

#### Step 3: 'p'

* no child 'p'
* create node
* move

#### End

* mark last 'p' as end of word

Result:

```
a → p → p*
```

---

## 9. Dry Run — Multiple Words (IMPORTANT)

Insert:

```
"app"
"apple"
```

### Insert `"app"`

Creates:

```
a → p → p*
```

### Insert `"apple"`

* 'a' exists → move
* 'p' exists → move
* 'p' exists → move
* 'l' does not → create
* 'e' does not → create
* mark 'e' as end

Final:

```
a → p → p* → l → e*
```

Notice:

* `"app"` is still valid
* Paths are reused
* No duplication

---

## 10. C++ Implementation — INSERT ONLY

We assume `TrieNode` is already designed (as you studied).

---

### C++ V1 — Only Required Function (Platform Style)

```cpp
void insert(string word) {
    TrieNode* node = root;

    for (char ch : word) {
        int idx = ch - 'a';

        if (node->children[idx] == nullptr) {
            node->children[idx] = new TrieNode();
        }

        node = node->children[idx];
    }

    node->isEndOfWord = true;
}
```

---

### Why This Works (Line by Line)

```cpp
TrieNode* node = root;
```

We always start insertion from root.

---

```cpp
int idx = ch - 'a';
```

Convert character to index `0–25`.

---

```cpp
if (node->children[idx] == nullptr)
```

Means:

> No path exists for this character yet.

So we create it.

---

```cpp
node = node->children[idx];
```

Move forward in the Trie.

---

```cpp
node->isEndOfWord = true;
```

Marks completion of word — **CRITICAL LINE**.

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
        root = new TrieNode(); // empty root
    }

    // Insert a word into the Trie
    void insert(string word) {

        // Start from root
        TrieNode* node = root;

        // Process each character
        for (char ch : word) {

            int index = ch - 'a';

            // If path does not exist, create it
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }

            // Move to next node
            node = node->children[index];
        }

        // Mark end of word
        node->isEndOfWord = true;
    }
};
```

---

## 11. JavaScript Implementation — INSERT ONLY

---

### JavaScript Version

```javascript
class TrieNode {
    constructor() {
        this.children = new Array(26).fill(null);
        this.isEndOfWord = false;
    }
}

class Trie {
    constructor() {
        this.root = new TrieNode();
    }

    insert(word) {
        let node = this.root;

        for (let ch of word) {
            let index = ch.charCodeAt(0) - 'a'.charCodeAt(0);

            if (node.children[index] === null) {
                node.children[index] = new TrieNode();
            }

            node = node.children[index];
        }

        node.isEndOfWord = true;
    }
}
```

Logic is **identical** to C++.

---

## 12. Edge Cases (INTERVIEW IMPORTANT)

1. **Insert empty string**

   * Usually ignored or root marked as end (depends on problem)
2. **Insert same word again**

   * No duplicate nodes created
   * End flag already true
3. **Insert prefix word**

   * `"app"` then `"apple"` → both valid
4. **Insert after longer word**

   * `"apple"` then `"app"` → mark earlier node as end

---

## 13. Time & Space Complexity (DEEP EXPLANATION)

### Time Complexity — O(L)

Where:

* `L` = length of word

Why?

* We process **each character once**
* Constant work per character

Independent of number of words already stored.

---

### Space Complexity — O(L) (Worst Case)

Worst case:

* All characters are new
* We create one node per character

Best case:

* Entire path already exists
* No new nodes created

---

## 14. Common Beginner Mistakes

1. Forgetting `isEndOfWord = true`
2. Creating new node even when child exists
3. Not starting from root
4. Treating insert like array push
5. Confusing prefix with full word

---

## 15. Interview-Level Takeaway (LOCK THIS)

> **Trie insert builds character paths and marks word endings.
> Prefix reuse is the core optimization.**

