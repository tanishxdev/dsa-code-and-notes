## 2️⃣ Correct Mental Model (Very Important)

This problem is **NOT math** and **NOT big integers**.

It is simply:

> **Simulate addition with carry from right to left**

Key observations:

- Start from **last digit**
- If digit < 9 → add 1 and stop
- If digit == 9 → make it 0 and carry continues
- If carry goes past first digit → insert `1` at front

This is a **classic carry propagation pattern**.

---

## 3️⃣ Pattern Name (Use This in Sheet)

Use **one** of these (recommended order):

```
Carry Propagation
```

Alternative acceptable:

```
Array Simulation
```

Do NOT tag as:

- Math
- Big Integer
- String

Those are misleading.

---

## 4️⃣ Clean C++ Code (Interview-Expected)

### ✅ V1 — Required Function Only (LeetCode)

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        // If all digits were 9
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
```

---

## 5️⃣ Common Mistakes (Remember This)

- Converting digits to number → ❌ overflow
- Forgetting case `[9,9,9]` → ❌
- Using extra arrays unnecessarily → ❌

Interviewers **expect this exact solution**.

---

## 6️⃣ Final Google Sheet Row Example

| Problem     | Topic | Pattern           | Status |
| ----------- | ----- | ----------------- | ------ |
| 66 Plus One | Array | Carry Propagation | SOLVED |

---

## 7️⃣ One-Line Recall Rule (For Revision)

> “Right to left, handle 9s, maybe add 1 at front.”

If this sentence instantly clicks → you’ve mastered it.

---
