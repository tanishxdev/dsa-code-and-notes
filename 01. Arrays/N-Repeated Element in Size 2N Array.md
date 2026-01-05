## 2️⃣ Why This Is NOT a Trick Problem

Given facts:

* Array size = `2N`
* Total unique elements = `N + 1`
* Exactly **one element appears N times**
* Others appear **once**

So:

> The repeated element must appear **very close to itself**
> Probability-wise, duplicates show up fast.

This allows **early exit**, not full counting.

---

## 3️⃣ Correct Mental Models (Choose ONE in Sheet)

You can solve this in **multiple ways**, but tag **only one dominant pattern**.

### Best Pattern Tag

```
Frequency / Early Duplicate Detection
```

Alternative acceptable tags:

```
Hashing
Set-based Detection
```

Do NOT tag as:

* Sorting
* Math
* Two pointers
  Those are unnecessary here.

---

## 4️⃣ Expected Interview Solution (O(N), O(1) or O(N))

### 🧠 Idea

The moment you see an element **again**, that’s the answer.

---

## 5️⃣ C++ Code (Minimal, Clean, Interview-Ready)

### ✅ V1 — Required Function Only (LeetCode)

```cpp
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> seen;

        for (int x : nums) {
            if (seen.count(x)) {
                return x;   // first repeated element
            }
            seen.insert(x);
        }
        return -1; // never reached as per constraints
    }
};
```

---

## 6️⃣ Even Better (Constant Space Trick – Bonus)

Because duplicates appear close, check neighbors:

```cpp
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) return nums[i];
            if (i + 2 < n && nums[i] == nums[i + 2]) return nums[i];
            if (i + 3 < n && nums[i] == nums[i + 3]) return nums[i];
        }
        return -1;
    }
};
```

Interviewers love this **constraint-based thinking**.

---

## 7️⃣ Final Sheet Row Example

| Problem                | Topic | Pattern                               | Status |
| ---------------------- | ----- | ------------------------------------- | ------ |
| 961 N-Repeated Element | Array | Frequency / Early Duplicate Detection | SOLVED |

---
