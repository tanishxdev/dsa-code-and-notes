# IMPLEMENT TRIE – 1 (INSERT, SEARCH, STARTSWITH)

---

## What We Covered Here

1. What problem is actually being asked
2. Why Trie is needed (problem motivation)
3. What a Trie node contains (core design)
4. Trie class structure
5. Insert operation (deep)
6. Search operation (deep)
7. StartsWith (prefix check) operation (deep)
8. Step-by-step dry runs for given examples
9. C++ implementation

   * V1: Platform-only functions
   * V2: Full program, deeply commented
10. JavaScript implementation
11. Edge cases discussion
12. Time & Space complexity (deep explanation)
13. Common beginner mistakes
14. Interview-level Q&A synthesis
15. Final mental model (lock this)

---

## 1. Problem Understanding (VERY CLEAR)

You need to design a class **Trie** that supports three operations:

### Operations Required

1. `insert(word)`

   * Store a word into the Trie

2. `search(word)`

   * Return `true` **only if**

     * word exists
     * and word was fully inserted before

3. `startsWith(prefix)`

   * Return `true` if **any word** in Trie starts with this prefix

---

### Important Clarification

| Operation  | Checks path? | Checks end-of-word? |
| ---------- | ------------ | ------------------- |
| insert     | yes          | yes                 |
| search     | yes          | yes                 |
| startsWith | yes          | ❌ no                |

---

## 2. Why Trie Is Needed (WHY NOT ARRAY / MAP)

Given many words, we want:

* Fast search
* Fast prefix queries
* No scanning all words

Trie gives:

* **O(length of word)** time
* Independent of number of stored words

That’s the key reason Trie exists.

---

## 3. Trie Node Design (FOUNDATION)

Each Trie node represents **one character**.

### Trie Node Contains

1. `children[26]`

   * One pointer/reference for each letter `a–z`

2. `isEndOfWord`

   * Marks whether a word **ends here**

### Mental Model

```
Node:
  children → next characters
  isEndOfWord → complete word ends here?
```

---

## 4. Trie Class Structure

Trie has:

* One **root node**
* Root does **not** represent any character
* All operations start from root

---

## 5. INSERT OPERATION (DEEP)

### What Insert Does

For `insert("apple")`:

* Build path: `a → p → p → l → e`
* Create nodes only if missing
* Mark last node as `isEndOfWord = true`

---

### Insert Algorithm

1. Start at root
2. For each character:

   * If child doesn’t exist → create
   * Move to child
3. Mark last node as end

---

### Insert Pseudocode

```
insert(word):
    node = root
    for each ch in word:
        if node has no ch:
            create node for ch
        node = node[ch]
    node.isEndOfWord = true
```

---

## 6. SEARCH OPERATION (DEEP)

### What Search Means

`search("app")` asks:

> Was **this exact word** inserted?

Prefix is **not enough**.

---

### Search Algorithm

1. Start at root
2. For each character:

   * If path breaks → false
3. After last character:

   * Check `isEndOfWord`

---

### Search Pseudocode

```
search(word):
    node = root
    for each ch in word:
        if node has no ch:
            return false
        node = node[ch]
    return node.isEndOfWord
```

---

## 7. STARTSWITH OPERATION (PREFIX CHECK)

### What startsWith Means

`startsWith("app")` asks:

> Does **any word** start with `"app"`?

No need to check end-of-word.

---

### startsWith Algorithm

1. Start at root
2. For each character:

   * If path breaks → false
3. If all characters found → true

---

### startsWith Pseudocode

```
startsWith(prefix):
    node = root
    for each ch in prefix:
        if node has no ch:
            return false
        node = node[ch]
    return true
```

---

## 8. Dry Run — Example 1 (IMPORTANT)

### Operations

```
insert("apple")
search("apple") → true
search("app") → false
startsWith("app") → true
insert("app")
search("app") → true
```

### Why `search("app")` was false initially?

Because:

* Path existed
* But `isEndOfWord` was false

After inserting `"app"` → it becomes true.

---

## 9. C++ IMPLEMENTATION

---

### C++ V1 — Platform Style (Only Required Code)

```cpp
class Trie {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };

    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr)
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr)
                return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr)
                return false;
            node = node->children[idx];
        }
        return true;
    }
};
```

---

### C++ V2 — Full Program (Deep Commented)

```cpp
#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
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

    void insert(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }

            node = node->children[idx];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (node->children[idx] == nullptr)
                return false;

            node = node->children[idx];
        }

        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;

        for (char ch : prefix) {
            int idx = ch - 'a';

            if (node->children[idx] == nullptr)
                return false;

            node = node->children[idx];
        }

        return true;
    }
};
```

---

## 10. JavaScript IMPLEMENTATION

```javascript
class TrieNode {
    constructor() {
        this.children = new Array(26).fill(null);
        this.isEnd = false;
    }
}

class Trie {
    constructor() {
        this.root = new TrieNode();
    }

    insert(word) {
        let node = this.root;

        for (let ch of word) {
            let idx = ch.charCodeAt(0) - 'a'.charCodeAt(0);

            if (node.children[idx] === null) {
                node.children[idx] = new TrieNode();
            }

            node = node.children[idx];
        }

        node.isEnd = true;
    }

    search(word) {
        let node = this.root;

        for (let ch of word) {
            let idx = ch.charCodeAt(0) - 'a'.charCodeAt(0);

            if (node.children[idx] === null)
                return false;

            node = node.children[idx];
        }

        return node.isEnd;
    }

    startsWith(prefix) {
        let node = this.root;

        for (let ch of prefix) {
            let idx = ch.charCodeAt(0) - 'a'.charCodeAt(0);

            if (node.children[idx] === null)
                return false;

            node = node.children[idx];
        }

        return true;
    }
}
```

---

## 11. Edge Cases

1. Searching prefix as word → false unless inserted
2. Duplicate insert → no issue
3. Prefix shorter than word → handled
4. Empty string → depends on problem constraints

---

## 12. Time & Space Complexity (DEEP)

### Time Complexity

For word length `L`:

* Insert → **O(L)**
* Search → **O(L)**
* StartsWith → **O(L)**

Independent of number of words.

---

### Space Complexity

* Worst case: one node per character
* Total space = total characters across all unique words

```
O(total characters)
```

---

## 13. Common Beginner Mistakes

1. Treating prefix as word in search
2. Forgetting `isEnd` flag
3. Using map instead of array without reason
4. Not starting from root
5. Confusing search and startsWith

---

## 14. Interview-Level Q&A

**Q: Why Trie search is O(L)?**
Because we follow exactly one path of length `L`.

**Q: Why search("app") can be false when prefix exists?**
Because `isEndOfWord` is false.

**Q: When to use Trie over HashMap?**
When prefix queries are required.

---

## 15. FINAL MENTAL MODEL (LOCK THIS)

> Trie is a **character path tree**
> Insert builds paths
> Search checks path + end
> startsWith checks path only

