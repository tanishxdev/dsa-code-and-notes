# PROBLEM (Original Statement)

Given an integer array `nums`, return the **sum of divisors** of the integers in that array that have **exactly four divisors**.
If there are no such integers, return `0`.

---

## BREAKDOWN PROBLEM

### What is being asked?

- From the given array, **select only those numbers** which have **exactly 4 divisors**.
- For each such number:

  - Find **all its divisors**
  - Add their **sum** to the final answer

### What is input?

- An integer array `nums`

### What is output?

- An integer → sum of divisors of all numbers that have exactly 4 divisors

### Example

```
nums = [21, 4, 7]

21 → divisors = 1, 3, 7, 21 (4 divisors) → sum = 32
4  → divisors = 1, 2, 4 (3 divisors) → ignore
7  → divisors = 1, 7 (2 divisors) → ignore

Answer = 32
```

---

## CONSTRAINT UNDERSTANDING

- `1 ≤ nums.length ≤ 10^4`
- `1 ≤ nums[i] ≤ 10^5`

### Constraint impact

- We **cannot** use an `O(n²)` approach
- For each number, divisor checking must be **efficient**
- Best possible approach: **O(n × √num)**

---

# BRUTE FORCE APPROACH

## First Thought Intuition

- For each number:

  - Check **all numbers from 1 to num**
  - Count divisors
  - If count == 4 → sum them

This is the most **straightforward** idea.

---

## Thought Process (Step-wise)

1. Take a number `x`
2. Loop from `1` to `x`
3. If `x % i == 0`, then `i` is a divisor
4. Count divisors
5. If count == 4, add all divisors to answer

---

## Pseudocode

```
result = 0
for each num in nums:
    count = 0
    sum = 0
    for i from 1 to num:
        if num % i == 0:
            count++
            sum += i
    if count == 4:
        result += sum
return result
```

---

## Algorithm

- Iterate over array
- For each number:

  - Check every possible divisor
  - Count and sum divisors

- Return final sum

---

## CODE (C++ and JavaScript)

### ❌ Not coding brute force

Because:

### Time Complexity

```
O(n × num) → worst case = 10^4 × 10^5 = 10^9 (TLE)
```

---

## Does This Approach Fail?

### YES

- Too slow
- Violates constraints

➡️ **Move to next approach**

---

# BETTER APPROACH (√n Divisor Method)

## First Thought Intuition

Key observations:

- Divisors **always come in pairs**
- If `i` divides `n`, then `n / i` also divides `n`
- We only need to check **up to √n**

---

## Thought Process (Step-wise)

1. For a number `n`
2. Loop `i` from `1` to `√n`
3. If `n % i == 0`

   - One divisor = `i`
   - Other divisor = `n / i`

4. Handle **perfect square** case separately
5. Count divisors carefully
6. If divisor count > 4 → stop early

---

## Pseudocode

```
function sumIfFourDivisors(n):
    count = 0
    sum = 0

    for i from 1 while i*i <= n:
        if n % i == 0:
            other = n / i

            if i == other:
                count += 1
                sum += i
            else:
                count += 2
                sum += i + other

            if count > 4:
                return 0

    if count == 4:
        return sum
    return 0
```

---

## Algorithm

- Loop through array
- For each number:

  - Find divisors using √n logic
  - Count divisors and sum them
  - If exactly 4 → add to result

---

## CODE (C++ and JavaScript)

---

### C++

#### V1 (Only Required Function)

```cpp
int sumFourDivisors(vector<int>& nums) {
    int result = 0;

    for (int num : nums) {
        int count = 0;
        int sum = 0;

        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                int other = num / i;

                if (i == other) {
                    count += 1;
                    sum += i;
                } else {
                    count += 2;
                    sum += i + other;
                }

                if (count > 4) break;
            }
        }

        if (count == 4) {
            result += sum;
        }
    }

    return result;
}
```

---

#### V2 (Complete Program)

```cpp
#include <bits/stdc++.h>
using namespace std;

int sumIfFourDivisors(int num) {
    int count = 0;
    int sum = 0;

    // Loop till sqrt(num) using i*i <= num
    for (int i = 1; i * i <= num; i++) {
        // Check if i divides num
        if (num % i == 0) {
            int other = num / i;

            // Perfect square case
            if (i == other) {
                count += 1;
                sum += i;
            }
            // Pair of divisors
            else {
                count += 2;
                sum += i + other;
            }

            // Early exit if more than 4 divisors
            if (count > 4) return 0;
        }
    }

    // Valid only if exactly 4 divisors
    return (count == 4) ? sum : 0;
}

int main() {
    vector<int> nums = {21, 4, 7};

    int result = 0;
    for (int num : nums) {
        result += sumIfFourDivisors(num);
    }

    cout << "Result = " << result << endl;
    return 0;
}
```

---

### JavaScript

#### V1 (Only Required Function)

```js
var sumFourDivisors = function (nums) {
  let result = 0;

  for (let num of nums) {
    let count = 0;
    let sum = 0;

    for (let i = 1; i * i <= num; i++) {
      if (num % i === 0) {
        let other = num / i;

        if (i === other) {
          count += 1;
          sum += i;
        } else {
          count += 2;
          sum += i + other;
        }

        if (count > 4) break;
      }
    }

    if (count === 4) result += sum;
  }

  return result;
};
```

---

#### V2 (Complete Program)

```js
function sumIfFourDivisors(num) {
  let count = 0;
  let sum = 0;

  for (let i = 1; i * i <= num; i++) {
    if (num % i === 0) {
      let other = num / i;

      if (i === other) {
        count += 1;
        sum += i;
      } else {
        count += 2;
        sum += i + other;
      }

      if (count > 4) return 0;
    }
  }

  return count === 4 ? sum : 0;
}

const nums = [21, 4, 7];
let result = 0;

for (let num of nums) {
  result += sumIfFourDivisors(num);
}

console.log("Result =", result);
```

---

## Time and Space Complexity

### Time Complexity

```
O(n × √max(nums[i]))
```

### Space Complexity

```
O(1)
```

---

## Dry Run (All Cases)

### Normal Case

```
num = 21
divisors found: 1, 21, 3, 7
count = 4 → sum = 32
```

### Best Case

```
num = prime
divisors = 2 → ignored
```

### Worst Case

```
num = highly composite
count exceeds 4 early → break
```

---

## Edge Cases

- `num = 1` → only 1 divisor
- Perfect square numbers (like 36)
- Large prime numbers
- Array with no valid numbers

All handled safely.

---

## How This Approach Handles the Problem

- Uses **math fundamentals**
- Avoids unnecessary checks
- Early exits for invalid numbers
- Respects constraints

---

## Does This Approach Fail?

### NO

---

# WHY THIS IS OPTIMAL

- Cannot do better than √n for divisor checking
- Space optimal
- Interview-accepted solution

---

mik

```
/*     Scroll below to see JAVA code    */
/*
    MY YOUTUBE VIDEO ON THIS Qn                : https://www.youtube.com/watch?v=MOYYok4_e0I
    Company Tags                               : Capital One, Amazon, Microsoft, Google, Meta
    Leetcode Link                              : https://leetcode.com/problems/four-divisors/description/

*/

/****************************************************** C++ **************************************************************/
//Approach - Simple maths - Iterate and find factors
//T.C : O(n * sqrt(maxNumber))
//S.C : O(1)
class Solution {
public:
    int sumIfFourDivisors(int num) {
        int divisors = 0;
        int sum = 0;

        for (int div = 1; div * div <= num; div++) {
            if (num % div == 0) {
                int other = num / div;

                if (div == other) {
                    divisors++;
                    sum += div;
                } else {
                    divisors += 2;
                    sum += (div + other);
                }
            }

            if (divisors > 4) {
                return 0;
            }
        }

        return divisors == 4 ? sum : 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int result = 0;

        for (int &num : nums) {
            result += sumIfFourDivisors(num);
        }

        return result;
    }
};


/****************************************************** JAVA **************************************************************/
//Approach - Simple maths - Iterate and find factors
//T.C : O(n * sqrt(maxNumber))
//S.C : O(1)
class Solution {

    private int sumIfFourDivisors(int num) {
        int divisors = 0;
        int sum = 0;

        for (int div = 1; div * div <= num; div++) {
            if (num % div == 0) {
                int other = num / div;

                if (div == other) {
                    divisors++;
                    sum += div;
                } else {
                    divisors += 2;
                    sum += div + other;
                }
            }

            if (divisors > 4) {
                return 0;
            }
        }

        return divisors == 4 ? sum : 0;
    }

    public int sumFourDivisors(int[] nums) {
        int result = 0;

        for (int num : nums) {
            result += sumIfFourDivisors(num);
        }

        return result;
    }
}
```
