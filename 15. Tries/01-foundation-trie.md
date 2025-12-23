
# TRIE (PREFIX TREE) — FOUNDATIONS

---

## What We Covered Here

1. What problem Trie is actually designed to solve
2. Why normal data structures fail for this problem
3. Real-life intuition (before any code)
4. What a Trie really is (not textbook definition)
5. Core observation behind Trie
6. Trie node structure (mental model)
7. How words are stored step-by-step
8. Example Trie construction (deep dry run)
9. Why Trie is called a **Prefix Tree**
10. Time & Space complexity intuition (early understanding)
11. Common beginner confusions
12. Interview-level mindset takeaway

---

## 1. Problem First (WHY Trie Exists)

Before Trie, understand the **problem it solves**.

### Very Common Problem Type

You are given many strings, for example:

```
["apple", "app", "ape", "bat", "ball"]
```

You need to answer questions like:

* Does a word exist?
* How many words start with `"ap"`?
* Is `"app"` a complete word or just a prefix?
* Suggest words based on prefix (autocomplete)
* Insert words dynamically
* Search fast — **very fast**

---

## 2. Why Arrays / Strings / Hashing Are Not Enough

### Using Array of Strings

To check `"app"` exists:

* You may scan all strings
* Compare character by character

⛔ **O(N × L)** per query
(N = number of words, L = length of word)

Too slow.

---

### Using HashSet / Map

Search `"app"` → **O(1)**
Good.

But now ask:

> “How many words start with `ap`?”

You must again scan all words.

⛔ Prefix queries are **slow**

---

### Core Problem Summary

| Operation            | Hashing | Array | Trie |
| -------------------- | ------- | ----- | ---- |
| Exact search         | Fast    | Slow  | Fast |
| Prefix search        | Slow    | Slow  | Fast |
| Autocomplete         | Hard    | Hard  | Easy |
| Word structure reuse | ❌       | ❌     | ✅    |

👉 **Trie exists because of prefix queries.**

---

## 3. Real-Life Intuition (VERY IMPORTANT)

Think of **dictionary search**.

If you open a dictionary and want words starting with:

```
"pre"
```

You don’t scan the whole book.

You go:

```
p → r → e
```

And now you are already in the **right section**.

Everything below that point shares the same prefix.

👉 That is exactly what a Trie does.

---

## 4. What Is a Trie? (Mental Model, Not Definition)

A **Trie** is:

> A tree-like structure where
> each node represents **one character**,
> and paths represent **words**.

Important points:

* Root is **empty**
* Each edge = character
* Shared prefixes are stored **once**
* Words branch only when characters differ

---

## 5. Why Trie Is Called a “Prefix Tree”

Because:

* Every node represents a **prefix**
* All children under a node share that prefix

Example:

```
Words:
app
apple
ape
```

All start with:

```
a → p
```

That prefix is stored **only once**.

This is the **core optimization**.

---

## 6. Trie Node Structure (VERY CLEAR)

Each Trie node contains:

1. Children (next characters)
2. A flag: does a word end here?

### Mental Model

```
Node:
  children[26]
  isEndOfWord
```

Why `26`?

Because:

* lowercase English letters `'a'` to `'z'`

(We will generalize later.)

---

## 7. Visual Intuition (IMPORTANT)


Example words:

```
["app", "apple", "ape"]
```

Trie looks like:

```
(root)
  |
  a
  |
  p
  |
  p* ----> l ----> e*
   \
    e*
```

`*` = end of word

---

## 8. How a Word Is Inserted (Step-by-Step Thinking)

Let’s insert:

```
"apple"
```

### Step 1

Start at root (empty)

### Step 2

Read `'a'`

* No `'a'` child → create node

### Step 3

Read `'p'`

* No `'p'` child → create

### Step 4

Read next `'p'`

* Create again (separate node)

### Step 5

Read `'l'`, then `'e'`

### Step 6

Mark last node as **end of word**

Important rule:

> Only the **last character** gets `isEnd = true`

---

## 9. Insert Multiple Words (Dry Run)

Words:

```
["app", "apple", "ape"]
```

### Insert `"app"`

```
a → p → p*
```

### Insert `"apple"`

* `a` exists
* `p` exists
* `p` exists
* add `l → e*`

### Insert `"ape"`

* `a` exists
* `p` exists
* `e` does not → create
* mark end

Result:

```
a
|
p
| \
p* e*
|
l
|
e*
```

---

## 10. Why Trie Is Efficient (Key Observation)

* Shared prefixes are stored **once**
* Search follows character path
* No scanning of unrelated words

Search time depends on:

```
length of word
```

Not number of words.

This is the **killer feature**.

---

## 11. Early Complexity Intuition (No Math Panic)

Let:

* `L` = length of word

### Insert

```
O(L)
```

### Search

```
O(L)
```

### Prefix check

```
O(L)
```

Independent of number of words.

---

## 12. Common Beginner Confusions

1. Thinking Trie stores full words at nodes
2. Confusing Trie with Binary Tree
3. Forgetting `isEndOfWord` flag
4. Thinking Trie replaces HashMap (it doesn’t)
5. Not understanding **prefix reuse**

---

## 13. Interview-Level Mindset (LOCK THIS)

> Trie is not about storing words.
> Trie is about **organizing prefixes**.

If you explain this clearly, interviewers know you understand Trie.

---

## Key Takeaway (FOUNDATION LOCK)

> **Trie stores characters, not words.
> Paths form words.
> Prefixes are shared.**

---