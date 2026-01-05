# LeetCode 756 — Pyramid Transition Matrix

## 1. Problem Overview (What is being asked?)

You are given:

* A **bottom row** of blocks as a string `bottom`
* A list of **allowed triangular patterns** `allowed`

Each block is a **single character**.

### Pyramid Rules

* Each upper row has **one block less** than the row below
* Every block in the upper row is formed using **two adjacent blocks** from the row below
* Only patterns from `allowed` can be used

Each allowed pattern:

```
"ABC"
```

Means:

* Bottom left = `A`
* Bottom right = `B`
* Top block = `C`

### Goal

Return **true** if you can build the pyramid **all the way to the top (length = 1)**
Return **false** otherwise.

---

## 2. Key Observations

1. You always combine **pairs of adjacent characters**
2. Each pair may have **multiple possible top characters**
3. Choosing the wrong top character can lead to a **dead end**
4. You must **try all valid possibilities**
5. This naturally leads to **backtracking**

---

## 3. Why Greedy Fails (Important Insight)

Example:

```
bottom = "BCD"
allowed = ["BCE", "BCD", "CDE", "DEF"]
```

For pair `"BC"`:

* Options: `E`, `D`

If you pick `E` greedily:

```
BCD
 EE
```

Next pair is `"EE"` → invalid → dead end

But if you pick `D`:

```
BCD
 DE
  F
```

Valid pyramid

👉 **Conclusion:**
You must **try, explore, undo, and retry** → Backtracking

---

## 4. Data Structure Optimization

### Why a Map?

Searching `allowed` linearly every time is slow.

Instead, build:

```
map<string, vector<char>>
```

Example:

```
"BC" → ['C', 'D']
"CD" → ['E']
"CE" → ['A']
```

This allows **O(1)** access to all valid top blocks for a pair.

---

## 5. Backtracking Strategy

### State Definition

To fully describe a recursive state, we need:

1. `current` → current row string
2. `idx` → index inside current row
3. `above` → row being built above

---

## 6. Base Cases

### Case 1: Reached the Top

```
if current.length == 1 → return true
```

### Case 2: Finished One Row

```
if idx == current.length - 1
→ move to next row
→ current = above
→ above = ""
→ idx = 0
```

---

## 7. Recursive Transition (Core Logic)

1. Take pair:

```
pair = current.substr(idx, 2)
```

2. If pair not in map → return false

3. For every possible top character:

```
for ch in mp[pair]:
    above.push_back(ch)     // DO
    if solve(current, idx+1, above):
        return true         // EXPLORE
    above.pop_back()        // UNDO
```

4. If no option works → return false

---

## 8. Complete Algorithm (Backtracking + Memoization)

### Why Memoization?

Same `(current, idx, above)` state can repeat.

So we store:

```
memo[key] = true/false
```

Key format:

```
current + "_" + idx + "_" + above
```

---

## 9. Pseudocode

```
buildMap(allowed)

solve(current, idx, above):
    if current.length == 1:
        return true

    key = current + "_" + idx + "_" + above
    if key in memo:
        return memo[key]

    if idx == current.length - 1:
        return memo[key] = solve(above, 0, "")

    pair = current[idx..idx+1]
    if pair not in map:
        return memo[key] = false

    for each ch in map[pair]:
        above.push(ch)
        if solve(current, idx+1, above):
            return memo[key] = true
        above.pop()

    return memo[key] = false
```

---

## 10. Time Complexity Analysis

Let:

* `n` = length of bottom
* `L` = average number of options per pair

Worst-case combinations:

```
L^(n-1) + L^(n-2) + ... + L^1
≈ O(L^n)
```

This is **exponential**, but:

### Why It Passes?

* `n ≤ 6`
* Characters limited to `{A..F}`
* Memoization prunes repeated states heavily

---

## 11. Space Complexity

* Recursion depth: `O(n)`
* Memoization states: bounded by small input size

Overall:

```
O(number of unique states)
```

---

## 12. Final Takeaways (Interview Gold)

* This is a **classic backtracking + memoization** problem
* Key pattern:

  ```
  Do → Explore → Undo
  ```
* Greedy approach fails
* Constraint size allows exponential solution
* State caching is crucial

---