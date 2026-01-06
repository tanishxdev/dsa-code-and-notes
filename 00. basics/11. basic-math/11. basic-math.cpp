#include <bits/stdc++.h>
using namespace std;

// ============================================================================
// PROBLEM 1: COUNT DIGITS IN A NUMBER
// ============================================================================

/*
Problem Statement: Given an integer N, count the number of digits in it.
Example: N = 12345 → Output: 5
*/

// ----------------------------------------------------------------------------
// APPROACH 1: BRUTE FORCE (Naive Iterative)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Keep dividing the number by 10 repeatedly until it becomes 0
- Each division removes the last digit
- Count how many divisions were needed

TIME COMPLEXITY: O(log₁₀ N)
SPACE COMPLEXITY: O(1)

DRY RUN:
N = 12345
Iteration 1: 12345 → 1234 (count=1)
Iteration 2: 1234 → 123 (count=2)
Iteration 3: 123 → 12 (count=3)
Iteration 4: 12 → 1 (count=4)
Iteration 5: 1 → 0 (count=5)

EDGE CASES:
1. N = 0 → Should return 1 (0 has 1 digit)
2. N < 0 → Handle negative numbers
3. Large numbers → Works fine

WHY NOT OPTIMAL?:
- For N=0, needs special handling
- For extremely large numbers, still takes O(log N) time
- Could be done in O(1) with mathematical approach

PROBLEM WITH THIS APPROACH:
- Special case for 0 required
- Slightly slower than mathematical approach
*/

int countDigitsBrute(int n)
{
    // Edge case: if number is 0, it has 1 digit
    if (n == 0)
        return 1;

    // Handle negative numbers by taking absolute value
    n = abs(n);

    int count = 0;

    // Keep dividing by 10 until number becomes 0
    while (n > 0)
    {
        n = n / 10; // Remove last digit
        count++;    // Increment digit count
    }

    return count;
}

// ----------------------------------------------------------------------------
// APPROACH 2: BETTER (Using String Conversion)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Convert integer to string
- Count length of string

TIME COMPLEXITY: O(log₁₀ N) (for conversion to string)
SPACE COMPLEXITY: O(log₁₀ N) (for storing string)

DRY RUN:
N = 12345
String = "12345"
Length = 5

EDGE CASES:
1. N = 0 → String "0", length = 1
2. N < 0 → String includes '-' sign

WHY NOT OPTIMAL?:
- Extra memory for string
- Conversion overhead
- Not truly O(1) time

PROBLEM WITH THIS APPROACH:
- Creates string object which takes memory
- Not suitable for performance-critical applications
*/

int countDigitsString(int n)
{
    // Convert to string (handles negative automatically)
    string str = to_string(n);

    // For negative numbers, exclude the minus sign
    if (n < 0)
    {
        return str.length() - 1;
    }

    return str.length();
}

// ----------------------------------------------------------------------------
// APPROACH 3: OPTIMAL (Mathematical - Logarithm)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Number of digits in N = floor(log₁₀(N)) + 1
- Because: if N has d digits, then 10^(d-1) ≤ N < 10^d
- Taking log₁₀: d-1 ≤ log₁₀(N) < d

TIME COMPLEXITY: O(1)
SPACE COMPLEXITY: O(1)

DRY RUN:
N = 12345
log₁₀(12345) ≈ 4.0915
floor(4.0915) = 4
4 + 1 = 5

EDGE CASES:
1. N = 0 → log₁₀(0) is undefined, needs special handling
2. N < 0 → Use absolute value

WHY IT'S OPTIMAL:
- Constant time operation
- No loops or recursion
- Minimal memory usage

MATHEMATICAL PROOF:
- Let N have d digits
- Then: 10^(d-1) ≤ N < 10^d
- Taking log: d-1 ≤ log₁₀(N) < d
- Therefore: d = floor(log₁₀(N)) + 1
*/

int countDigitsOptimal(int n)
{
    // Edge case: 0 has 1 digit
    if (n == 0)
        return 1;

    // Use absolute value for negative numbers
    n = abs(n);

    // Mathematical formula: floor(log10(n)) + 1
    return floor(log10(n)) + 1;
}

// ============================================================================
// PROBLEM 2: REVERSE DIGITS OF A NUMBER
// ============================================================================

/*
Problem Statement: Given an integer N, reverse its digits.
Example: N = 12345 → Output: 54321
Constraint: Handle overflow cases
*/

// ----------------------------------------------------------------------------
// APPROACH 1: BRUTE FORCE (Using String)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Convert to string
- Reverse the string
- Convert back to integer

TIME COMPLEXITY: O(log₁₀ N)
SPACE COMPLEXITY: O(log₁₀ N)

DRY RUN:
N = 12345
String = "12345"
Reversed string = "54321"
Convert to int = 54321

EDGE CASES:
1. Negative numbers → Handle sign separately
2. Trailing zeros → 1200 → 21 (not 0021)
3. Overflow → 2^31-1 = 2147483647 reversed is 7463847412 > INT_MAX

WHY NOT OPTIMAL?:
- String manipulation overhead
- Doesn't handle overflow well
- Extra memory for string
*/

int reverseNumberBrute(int n)
{
    // Convert to string
    string str = to_string(abs(n));

    // Reverse the string
    reverse(str.begin(), str.end());

    // Convert back to integer
    long long result = stoll(str);

    // Apply sign if original was negative
    if (n < 0)
    {
        result = -result;
    }

    // Check for overflow
    if (result > INT_MAX || result < INT_MIN)
    {
        return 0; // Or throw exception based on requirements
    }

    return (int)result;
}

// ----------------------------------------------------------------------------
// APPROACH 2: BETTER (Using Long Long to prevent overflow)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Extract last digit using % 10
- Build reversed number by: reversed = reversed * 10 + digit
- Use long long to handle potential overflow during calculation

TIME COMPLEXITY: O(log₁₀ N)
SPACE COMPLEXITY: O(1)

DRY RUN:
N = 12345
reversed = 0
Iteration 1: digit=5, reversed=5, n=1234
Iteration 2: digit=4, reversed=54, n=123
Iteration 3: digit=3, reversed=543, n=12
Iteration 4: digit=2, reversed=5432, n=1
Iteration 5: digit=1, reversed=54321, n=0

EDGE CASES:
1. Negative numbers → Work with absolute value
2. Numbers ending with 0 → 1200 → 21
3. Overflow → Return 0 if overflow occurs

WHY NOT OPTIMAL?:
- Uses larger data type (long long)
- Still needs overflow check

PROBLEM WITH THIS APPROACH:
- Not purely using int operations
- Long long may not be available in all environments
*/

int reverseNumberBetter(int n)
{
    long long reversed = 0;
    int temp = abs(n);

    while (temp > 0)
    {
        int digit = temp % 10;            // Get last digit
        reversed = reversed * 10 + digit; // Append to reversed number
        temp = temp / 10;                 // Remove last digit

        // Check for overflow during calculation
        if (reversed > INT_MAX)
        {
            return 0;
        }
    }

    // Apply original sign
    if (n < 0)
    {
        reversed = -reversed;
    }

    return (int)reversed;
}

// ----------------------------------------------------------------------------
// APPROACH 3: OPTIMAL (Pure integer operations with overflow prevention)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Extract digits one by one
- Before adding new digit, check if reversed * 10 + digit will overflow
- Use INT_MAX/10 and INT_MIN/10 as bounds

TIME COMPLEXITY: O(log₁₀ N)
SPACE COMPLEXITY: O(1)

DRY RUN:
N = 12345
reversed = 0
Check at each step:
1. reversed=0, digit=5 → 0*10+5=5 (safe)
2. reversed=5, digit=4 → 5*10+4=54 (safe)
... and so on

EDGE CASES:
1. INT_MAX = 2147483647 → reversed 7463847412 would overflow
2. INT_MIN = -2147483648
3. Negative numbers
4. Numbers ending with 0

WHY IT'S OPTIMAL:
- Pure integer operations
- No extra memory
- Handles overflow properly
- Works within int range

OVERFLOW PREVENTION LOGIC:
- For positive: if reversed > INT_MAX/10, overflow will occur
- For negative: if reversed < INT_MIN/10, overflow will occur
- If reversed == INT_MAX/10, check if digit > 7 (for 32-bit int)
- If reversed == INT_MIN/10, check if digit < -8
*/

int reverseNumberOptimal(int n)
{
    int reversed = 0;

    while (n != 0)
    {
        int digit = n % 10; // Extract last digit

        // Check for overflow before updating reversed
        // Positive overflow check
        if (reversed > INT_MAX / 10 ||
            (reversed == INT_MAX / 10 && digit > 7))
        {
            return 0;
        }

        // Negative overflow check
        if (reversed < INT_MIN / 10 ||
            (reversed == INT_MIN / 10 && digit < -8))
        {
            return 0;
        }

        // Update reversed number
        reversed = reversed * 10 + digit;
        n = n / 10; // Remove last digit
    }

    return reversed;
}

// ============================================================================
// PROBLEM 3: CHECK PALINDROME NUMBER
// ============================================================================

/*
Problem Statement: Check if a number reads the same forward and backward.
Example: 121 → true, 123 → false, -121 → false
*/

// ----------------------------------------------------------------------------
// APPROACH 1: BRUTE FORCE (String comparison)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Convert to string
- Compare with its reverse

TIME COMPLEXITY: O(log₁₀ N)
SPACE COMPLEXITY: O(log₁₀ N)

DRY RUN:
N = 121
String = "121"
Reversed = "121"
Compare → equal → true

EDGE CASES:
1. Negative numbers → Not palindrome (e.g., -121)
2. Single digit → Always palindrome
3. Numbers with trailing zeros → 100 → reversed is 001 → false

WHY NOT OPTIMAL?:
- Extra memory for string
- Conversion overhead

PROBLEM WITH THIS APPROACH:
- Creates unnecessary string objects
- Not efficient for multiple checks
*/

bool isPalindromeBrute(int n)
{
    // Negative numbers are not palindromes
    if (n < 0)
        return false;

    string original = to_string(n);
    string reversed = original;
    reverse(reversed.begin(), reversed.end());

    return original == reversed;
}

// ----------------------------------------------------------------------------
// APPROACH 2: BETTER (Reverse half and compare)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Reverse only the second half of the number
- Compare first half with reversed second half
- This avoids string conversion

TIME COMPLEXITY: O(log₁₀ N)
SPACE COMPLEXITY: O(1)

DRY RUN:
N = 1221
Step 1: reversed = 0
Step 2: Extract last digit (1), reversed = 1, n = 122
Step 3: Extract last digit (2), reversed = 12, n = 12
Step 4: n (12) == reversed (12) → true

EDGE CASES:
1. Negative numbers → false
2. Single digit → true
3. Numbers ending with 0 → only 0 works (10 is not palindrome)

WHY NOT OPTIMAL?:
- Still reverses half the number
- Edge cases for odd-digit numbers

PROBLEM WITH THIS APPROACH:
- Need to handle odd and even digit counts differently
*/

bool isPalindromeBetter(int n)
{
    // Negative numbers and numbers ending with 0 (except 0) are not palindromes
    if (n < 0 || (n % 10 == 0 && n != 0))
    {
        return false;
    }

    int reversedHalf = 0;

    // Reverse only the second half
    while (n > reversedHalf)
    {
        reversedHalf = reversedHalf * 10 + (n % 10);
        n /= 10;
    }

    // For even digits: n == reversedHalf
    // For odd digits: n == reversedHalf / 10 (middle digit doesn't matter)
    return n == reversedHalf || n == reversedHalf / 10;
}

// ----------------------------------------------------------------------------
// APPROACH 3: OPTIMAL (Mathematical comparison)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Compare first and last digits repeatedly
- Remove first and last digits after comparison
- No need to reverse the entire number

TIME COMPLEXITY: O(log₁₀ N)
SPACE COMPLEXITY: O(1)

DRY RUN:
N = 12321
div = 10000 (10^(digits-1))
first = 12321/10000 = 1
last = 12321%10 = 1
Equal → remove first and last → n = 232
Update div = 100

WHY IT'S OPTIMAL:
- Minimal operations
- No string conversion
- Handles all edge cases
- Early exit when mismatch found

MATHEMATICAL APPROACH:
- Find divisor = 10^(digits-1)
- first = n / divisor
- last = n % 10
- Compare first and last
- Remove first and last: n = (n % divisor) / 10
- divisor /= 100
*/

bool isPalindromeOptimal(int n)
{
    // Edge cases
    if (n < 0)
        return false; // Negative numbers
    if (n < 10)
        return true; // Single digit

    // Find the divisor (10^(digits-1))
    int divisor = 1;
    while (n / divisor >= 10)
    {
        divisor *= 10;
    }

    int temp = n;

    while (temp > 0)
    {
        int first = temp / divisor; // First digit
        int last = temp % 10;       // Last digit

        if (first != last)
        {
            return false; // Not a palindrome
        }

        // Remove first and last digits
        temp = (temp % divisor) / 10;

        // Update divisor (removed 2 digits)
        divisor /= 100;
    }

    return true;
}

// ============================================================================
// PROBLEM 4: FIND GCD/HCF OF TWO NUMBERS
// ============================================================================

/*
Problem Statement: Find Greatest Common Divisor of two numbers.
Example: GCD(12, 18) = 6
*/

// ----------------------------------------------------------------------------
// APPROACH 1: BRUTE FORCE (Linear Search)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Check all numbers from 1 to min(a,b)
- Find the largest number that divides both

TIME COMPLEXITY: O(min(a,b))
SPACE COMPLEXITY: O(1)

DRY RUN:
a=12, b=18
Check from 1 to 12:
1 divides both
2 divides both
3 divides both
... up to 6
Largest = 6

EDGE CASES:
1. a=0 → GCD = b
2. b=0 → GCD = a
3. Negative numbers → GCD is same for absolute values
4. a=b → GCD = a

WHY NOT OPTIMAL?:
- Very slow for large numbers
- Unnecessary checks

PROBLEM WITH THIS APPROACH:
- Inefficient for numbers like (1000000, 1)
- Too many iterations
*/

int gcdBrute(int a, int b)
{
    // Handle negative numbers
    a = abs(a);
    b = abs(b);

    // Edge cases
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    int gcd = 1;
    int limit = min(a, b);

    // Check all numbers from 1 to min(a,b)
    for (int i = 1; i <= limit; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i; // Update gcd if i divides both
        }
    }

    return gcd;
}

// ----------------------------------------------------------------------------
// APPROACH 2: BETTER (Reverse Linear Search)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Start from min(a,b) and go downwards
- Stop at first common divisor (which will be largest)

TIME COMPLEXITY: O(min(a,b)) worst case
SPACE COMPLEXITY: O(1)

DRY RUN:
a=12, b=18
Start from 12, check if divides both → No
11 → No
10 → No
...
6 → Yes → Return 6

EDGE CASES:
- Same as brute force
- Better average case when numbers are co-prime

WHY NOT OPTIMAL?:
- Still O(n) in worst case
- Not efficient for large prime numbers

PROBLEM WITH THIS APPROACH:
- Worst case when numbers are prime (e.g., 1000003, 1000033)
- Still linear time
*/

int gcdBetter(int a, int b)
{
    a = abs(a);
    b = abs(b);

    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // Start from min and go downwards
    for (int i = min(a, b); i >= 1; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            return i; // First found is largest
        }
    }

    return 1; // Co-prime numbers
}

// ----------------------------------------------------------------------------
// APPROACH 3: OPTIMAL (Euclidean Algorithm - Iterative)
// ----------------------------------------------------------------------------

/*
INTUITION (EUCLIDEAN ALGORITHM):
- GCD doesn't change if we replace larger number with difference
- Based on: GCD(a,b) = GCD(b, a mod b)
- Keep reducing until one number becomes 0

MATHEMATICAL PROOF:
Let d = GCD(a,b)
Then a = d*x, b = d*y where GCD(x,y)=1
a mod b = a - floor(a/b)*b
        = d*x - floor(d*x/d*y)*d*y
        = d*(x - floor(x/y)*y)
So GCD(b, a mod b) = d*GCD(y, x mod y) = d

TIME COMPLEXITY: O(log(min(a,b)))
SPACE COMPLEXITY: O(1)

DRY RUN:
a=48, b=18
48 % 18 = 12 → GCD(18,12)
18 % 12 = 6 → GCD(12,6)
12 % 6 = 0 → GCD(6,0) = 6

WHY IT'S OPTIMAL:
- Logarithmic time complexity
- Very efficient even for large numbers
- Simple implementation

EDGE CASES:
- Handles 0 properly
- Works for negative numbers
- Handles large numbers efficiently
*/

int gcdOptimalIterative(int a, int b)
{
    // Handle negative numbers
    a = abs(a);
    b = abs(b);

    // Euclidean Algorithm
    while (b != 0)
    {
        int remainder = a % b;
        a = b;
        b = remainder;
    }

    return a; // When b becomes 0, a is GCD
}

// ----------------------------------------------------------------------------
// APPROACH 4: OPTIMAL (Euclidean Algorithm - Recursive)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Same as iterative but using recursion
- Base case: if b == 0, return a
- Recursive case: GCD(b, a mod b)

TIME COMPLEXITY: O(log(min(a,b)))
SPACE COMPLEXITY: O(log(min(a,b))) for recursion stack

DRY RUN:
GCD(48,18) calls GCD(18,12)
GCD(18,12) calls GCD(12,6)
GCD(12,6) calls GCD(6,0)
Returns 6

WHY USE RECURSION:
- Cleaner code
- Mathematically elegant
- Same time complexity

WHEN NOT TO USE:
- Very deep recursion might cause stack overflow
- Iterative is usually preferred in production
*/

int gcdOptimalRecursive(int a, int b)
{
    // Base case
    if (b == 0)
    {
        return abs(a);
    }

    // Recursive case
    return gcdOptimalRecursive(b, a % b);
}

// ============================================================================
// PROBLEM 5: CHECK ARMSTRONG NUMBER
// ============================================================================

/*
Problem Statement: Check if sum of digits raised to power of number of digits equals the number.
Example: 153 = 1³ + 5³ + 3³ = 153 → true
*/

// ----------------------------------------------------------------------------
// APPROACH 1: BRUTE FORCE (String based)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Convert to string to get digits
- For each digit, raise to power of length
- Sum and compare

TIME COMPLEXITY: O(log₁₀ N * log₁₀ N) for pow operation
SPACE COMPLEXITY: O(log₁₀ N)

DRY RUN:
N = 153
String = "153", length = 3
Sum = 1³ + 5³ + 3³ = 1 + 125 + 27 = 153
Sum == N → true

EDGE CASES:
1. Single digit: all are Armstrong (1-9)
2. 0 is Armstrong
3. Negative numbers: not Armstrong
4. Large numbers: check for overflow

WHY NOT OPTIMAL?:
- String conversion overhead
- pow() function may be expensive
- Extra memory

PROBLEM WITH THIS APPROACH:
- Uses floating point pow() which can have precision issues
- Creates string unnecessarily
*/

bool isArmstrongBrute(int n)
{
    if (n < 0)
        return false;

    string str = to_string(n);
    int len = str.length();
    long long sum = 0;

    for (char ch : str)
    {
        int digit = ch - '0';
        sum += pow(digit, len);

        // Early exit if sum already exceeds n
        if (sum > n)
        {
            return false;
        }
    }

    return sum == n;
}

// ----------------------------------------------------------------------------
// APPROACH 2: BETTER (Mathematical without pow)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Extract digits using modulus
- Implement power function without pow()
- Avoid string conversion

TIME COMPLEXITY: O(log₁₀ N * k) where k is exponent
SPACE COMPLEXITY: O(1)

DRY RUN:
N = 153
Digits: 3, 5, 1
3³ = 27, 5³ = 125, 1³ = 1
Sum = 153

EDGE CASES:
- Same as before
- Handles overflow better

WHY NOT OPTIMAL?:
- Custom power function needed
- Still O(n²) in worst case for power calculation

PROBLEM WITH THIS APPROACH:
- Power calculation for each digit is expensive
- Could be optimized with precomputation
*/

// Helper function for integer power
long long intPower(int base, int exp)
{
    long long result = 1;
    for (int i = 0; i < exp; i++)
    {
        result *= base;
    }
    return result;
}

bool isArmstrongBetter(int n)
{
    if (n < 0)
        return false;

    int original = n;
    int digits = 0;
    int temp = n;

    // Count digits
    while (temp > 0)
    {
        digits++;
        temp /= 10;
    }

    long long sum = 0;
    temp = n;

    // Calculate sum of powers
    while (temp > 0)
    {
        int digit = temp % 10;
        sum += intPower(digit, digits);
        temp /= 10;

        // Early exit
        if (sum > original)
        {
            return false;
        }
    }

    return sum == original;
}

// ----------------------------------------------------------------------------
// APPROACH 3: OPTIMAL (Precomputed powers)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Precompute all digit powers (0-9) raised to number of digits
- Store in array for O(1) lookup
- This eliminates repeated power calculations

TIME COMPLEXITY: O(log₁₀ N)
SPACE COMPLEXITY: O(10) = O(1)

DRY RUN:
N = 153, digits = 3
Precompute: pow[0]=0, pow[1]=1, pow[2]=8, ..., pow[9]=729
Sum = pow[3] + pow[5] + pow[1] = 27 + 125 + 1 = 153

WHY IT'S OPTIMAL:
- No repeated power calculations
- Minimal operations
- Handles all cases efficiently

EDGE CASES:
- Works for 0 (digits=1, sum=0)
- Handles single digit numbers
- Efficient for large numbers

OPTIMIZATION:
- Precompute only once per digit count
- Reuse for multiple checks if needed
*/

bool isArmstrongOptimal(int n)
{
    if (n < 0)
        return false;

    int original = n;
    int digits = 0;
    int temp = n;

    // Count digits
    while (temp > 0)
    {
        digits++;
        temp /= 10;
    }

    // Precompute powers of digits 0-9
    long long power[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        long long p = 1;
        for (int j = 0; j < digits; j++)
        {
            p *= i;
        }
        power[i] = p;
    }

    // Calculate sum using precomputed powers
    long long sum = 0;
    temp = original;

    while (temp > 0)
    {
        int digit = temp % 10;
        sum += power[digit];
        temp /= 10;

        // Early exit
        if (sum > original)
        {
            return false;
        }
    }

    return sum == original;
}

// ============================================================================
// PROBLEM 6: PRINT ALL DIVISORS OF A NUMBER
// ============================================================================

/*
Problem Statement: Find all divisors of a number N.
Example: N=12 → 1, 2, 3, 4, 6, 12
*/

// ----------------------------------------------------------------------------
// APPROACH 1: BRUTE FORCE (Linear)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Check every number from 1 to N
- If N % i == 0, it's a divisor

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(d) where d = number of divisors

DRY RUN:
N=12
Check 1-12:
1, 2, 3, 4, 6, 12 are divisors

EDGE CASES:
1. N=0 → Infinite divisors (conceptually)
2. N=1 → Only 1
3. N negative → Same divisors as absolute value

WHY NOT OPTIMAL?:
- Too slow for large N
- Checks unnecessary numbers

PROBLEM WITH THIS APPROACH:
- Inefficient for prime numbers (checks all N)
- Not scalable
*/

vector<int> divisorsBrute(int n)
{
    vector<int> result;

    // Handle edge cases
    if (n == 0)
    {
        // 0 is divisible by all numbers except 0
        // Usually return empty or special case
        return result;
    }

    n = abs(n); // Work with positive

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            result.push_back(i);
        }
    }

    return result;
}

// ----------------------------------------------------------------------------
// APPROACH 2: BETTER (Optimized to N/2)
// ----------------------------------------------------------------------------

/*
INTUITION:
- No number greater than N/2 (except N itself) divides N
- Check only up to N/2, then add N itself

TIME COMPLEXITY: O(N/2) = O(N)
SPACE COMPLEXITY: O(d)

DRY RUN:
N=12
Check 1-6: 1, 2, 3, 4, 6
Add 12

EDGE CASES:
1. N=1 → Special handling
2. Even numbers vs odd numbers

WHY NOT OPTIMAL?:
- Still O(N) time
- Not much improvement for large N

PROBLEM WITH THIS APPROACH:
- Still linear time
- For N=10^9, needs 5×10^8 iterations
*/

vector<int> divisorsBetter(int n)
{
    vector<int> result;

    if (n == 0)
        return result;
    n = abs(n);

    if (n == 1)
    {
        result.push_back(1);
        return result;
    }

    // Check up to n/2
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            result.push_back(i);
        }
    }

    // Add n itself
    result.push_back(n);

    return result;
}

// ----------------------------------------------------------------------------
// APPROACH 3: OPTIMAL (Pair method - O(√N))
// ----------------------------------------------------------------------------

/*
INTUITION:
- Divisors always come in pairs (i, n/i)
- Only need to check up to √n
- For each i that divides n, add both i and n/i

MATHEMATICAL INSIGHT:
If i divides n, then n/i also divides n
We only need to find one of each pair

TIME COMPLEXITY: O(√N)
SPACE COMPLEXITY: O(d)

DRY RUN:
N=12, √12≈3.46
Check i=1: 1 divides 12, add 1 and 12
Check i=2: 2 divides 12, add 2 and 6
Check i=3: 3 divides 12, add 3 and 4
i=4 > √12, stop

Result: 1, 12, 2, 6, 3, 4 (need sorting)

WHY IT'S OPTIMAL:
- Drastically reduces checks
- From O(N) to O(√N)
- Example: N=10^9: √N=31623 vs N=10^9

EDGE CASES:
1. Perfect squares: add only once (i == n/i)
2. N=0, N=1 special cases
3. Negative numbers
*/

vector<int> divisorsOptimal(int n)
{
    vector<int> result;

    if (n == 0)
        return result;
    n = abs(n);

    // Special case for 1
    if (n == 1)
    {
        result.push_back(1);
        return result;
    }

    // Find divisors up to √n
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            result.push_back(i); // First divisor

            // Add the pair divisor (avoid duplicate for perfect squares)
            if (i != n / i)
            {
                result.push_back(n / i);
            }
        }
    }

    // Sort for better readability
    sort(result.begin(), result.end());

    return result;
}

// ----------------------------------------------------------------------------
// APPROACH 4: OPTIMAL WITH TWO LISTS (Sorted output)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Use two lists: one for smaller divisors, one for larger
- Avoids sorting at the end (already in order)

TIME COMPLEXITY: O(√N)
SPACE COMPLEXITY: O(d)

DRY RUN:
N=12
i=1: small=[1], large=[12]
i=2: small=[1,2], large=[12,6]
i=3: small=[1,2,3], large=[12,6,4]
Combine: [1,2,3,4,6,12]

WHY IT'S BETTER:
- No need for sorting
- Maintains order naturally
- More efficient

EDGE CASES:
- Perfect squares handled properly
*/

vector<int> divisorsOptimalSorted(int n)
{
    vector<int> small, large;

    if (n == 0)
        return small;
    n = abs(n);

    if (n == 1)
    {
        return {1};
    }

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            small.push_back(i); // Smaller divisor

            if (i != n / i)
            {
                large.push_back(n / i); // Larger divisor
            }
        }
    }

    // Combine: small in order + large in reverse order
    vector<int> result = small;
    reverse(large.begin(), large.end());
    result.insert(result.end(), large.begin(), large.end());

    return result;
}

// ============================================================================
// PROBLEM 7: CHECK PRIME NUMBER
// ============================================================================

/*
Problem Statement: Check if a number is prime (only divisible by 1 and itself).
Example: 7 → true, 9 → false
*/

// ----------------------------------------------------------------------------
// APPROACH 1: BRUTE FORCE (Check all numbers)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Check divisibility by all numbers from 2 to N-1
- If any divides N, not prime

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)

DRY RUN:
N=7
Check 2-6: none divide 7 → prime
N=9
Check 2-8: 3 divides 9 → not prime

EDGE CASES:
1. N <= 1 → Not prime
2. N = 2 → Prime (only even prime)
3. Large N → Very slow

WHY NOT OPTIMAL?:
- Very inefficient
- Unnecessary checks

PROBLEM WITH THIS APPROACH:
- For N=10^9, needs 10^9 checks
- Completely impractical
*/

bool isPrimeBrute(int n)
{
    // Edge cases
    if (n <= 1)
        return false;
    if (n == 2)
        return true;

    // Check all numbers from 2 to n-1
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false; // Found a divisor
        }
    }

    return true;
}

// ----------------------------------------------------------------------------
// APPROACH 2: BETTER (Check up to N/2)
// ----------------------------------------------------------------------------

/*
INTUITION:
- If N has a divisor > N/2, it must have a divisor < 2
- Only need to check up to N/2

TIME COMPLEXITY: O(N/2) = O(N)
SPACE COMPLEXITY: O(1)

DRY RUN:
N=17
Check 2-8: none divide → prime
N=15
Check 2-7: 3 divides → not prime

WHY NOT OPTIMAL?:
- Still O(N) time
- Only halves the checks

PROBLEM WITH THIS APPROACH:
- Still too slow for large numbers
*/

bool isPrimeBetter(int n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;

    // Check up to n/2
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

// ----------------------------------------------------------------------------
// APPROACH 3: OPTIMAL (Check up to √N)
// ----------------------------------------------------------------------------

/*
INTUITION (CRITICAL INSIGHT):
- If N is composite (not prime), it has at least one divisor ≤ √N
- Proof: Let N = a × b. If both a > √N and b > √N, then a×b > N (contradiction)
- So at least one factor ≤ √N

TIME COMPLEXITY: O(√N)
SPACE COMPLEXITY: O(1)

DRY RUN:
N=17, √17≈4.12
Check 2-4: none divide → prime
N=15, √15≈3.87
Check 2-3: 3 divides → not prime

WHY IT'S OPTIMAL FOR SINGLE CHECK:
- Drastic reduction from O(N) to O(√N)
- For N=10^9: √N=31623 vs N=10^9
- Practical for most cases

EDGE CASES:
1. N <= 1: not prime
2. N = 2, 3: prime
3. Even numbers > 2: not prime (quick check)
*/

bool isPrimeOptimal(int n)
{
    // Edge cases
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;

    // Quick check for even numbers (except 2)
    if (n % 2 == 0)
        return false;

    // Check only odd divisors up to √n
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

// ----------------------------------------------------------------------------
// APPROACH 4: MOST OPTIMAL (6k ± 1 optimization)
// ----------------------------------------------------------------------------

/*
INTUITION (MATHEMATICAL OPTIMIZATION):
- All primes > 3 are of form 6k ± 1
- Proof: Any integer can be represented as 6k, 6k±1, 6k±2, 6k±3, 6k±4
  - 6k, 6k±2, 6k±4 are divisible by 2
  - 6k±3 is divisible by 3
  - Only 6k±1 could be prime
- Reduces checks to 1/3 of numbers

TIME COMPLEXITY: O(√N) but with smaller constant
SPACE COMPLEXITY: O(1)

DRY RUN:
N=17
Check divisibility by 2, 3
Check i=5 (6×1-1): 17%5≠0
Check i=7 (6×1+1): 17%7≠0
i=11 > √17, stop → prime

WHY IT'S MOST OPTIMAL:
- Fewer iterations than √N method
- Based on mathematical property of primes
- Constant factor improvement

EDGE CASES:
- Works for all N > 3
*/

bool isPrimeMostOptimal(int n)
{
    // Edge cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // Quick checks for divisibility by 2 or 3
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    // Check numbers of form 6k ± 1
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }

    return true;
}

// ============================================================================
// MAIN FUNCTION - TEST ALL APPROACHES
// ============================================================================

int main()
{
    cout << "=== MATHS PROBLEM WALKTHROUGH ===\n\n";
    // Test Count Digits
    cout << "1. COUNT DIGITS:\n";
    cout << "Brute (12345): " << countDigitsBrute(12345) << endl;
    cout << "String (12345): " << countDigitsString(12345) << endl;
    cout << "Optimal (12345): " << countDigitsOptimal(12345) << endl;
    cout << "Edge case (0): " << countDigitsOptimal(0) << endl;
    cout << "Edge case (-123): " << countDigitsOptimal(-123) << endl;

    // Test Reverse Number
    cout << "\n2. REVERSE NUMBER:\n";
    cout << "Brute (12345): " << reverseNumberBrute(12345) << endl;
    cout << "Better (12345): " << reverseNumberBetter(12345) << endl;
    cout << "Optimal (12345): " << reverseNumberOptimal(12345) << endl;
    cout << "Edge case (1200): " << reverseNumberOptimal(1200) << endl;
    cout << "Edge case (-123): " << reverseNumberOptimal(-123) << endl;

    // Test Palindrome
    cout << "\n3. PALINDROME CHECK:\n";
    cout << "Brute (121): " << (isPalindromeBrute(121) ? "true" : "false") << endl;
    cout << "Better (121): " << (isPalindromeBetter(121) ? "true" : "false") << endl;
    cout << "Optimal (121): " << (isPalindromeOptimal(121) ? "true" : "false") << endl;
    cout << "Not palindrome (123): " << (isPalindromeOptimal(123) ? "true" : "false") << endl;
    cout << "Negative (-121): " << (isPalindromeOptimal(-121) ? "true" : "false") << endl;

    // Test GCD
    cout << "\n4. GCD/HCF:\n";
    cout << "Brute (12,18): " << gcdBrute(12, 18) << endl;
    cout << "Better (12,18): " << gcdBetter(12, 18) << endl;
    cout << "Optimal Iterative (12,18): " << gcdOptimalIterative(12, 18) << endl;
    cout << "Optimal Recursive (12,18): " << gcdOptimalRecursive(12, 18) << endl;
    cout << "Edge case (0,5): " << gcdOptimalIterative(0, 5) << endl;

    // Test Armstrong
    cout << "\n5. ARMSTRONG NUMBER:\n";
    cout << "Brute (153): " << (isArmstrongBrute(153) ? "true" : "false") << endl;
    cout << "Better (153): " << (isArmstrongBetter(153) ? "true" : "false") << endl;
    cout << "Optimal (153): " << (isArmstrongOptimal(153) ? "true" : "false") << endl;
    cout << "Not Armstrong (123): " << (isArmstrongOptimal(123) ? "true" : "false") << endl;

    // Test Divisors
    cout << "\n6. DIVISORS:\n";
    vector<int> divs = divisorsOptimalSorted(12);
    cout << "Divisors of 12: ";
    for (int d : divs)
        cout << d << " ";
    cout << endl;

    // Test Prime
    cout << "\n7. PRIME CHECK:\n";
    cout << "Brute (17): " << (isPrimeBrute(17) ? "true" : "false") << endl;
    cout << "Better (17): " << (isPrimeBetter(17) ? "true" : "false") << endl;
    cout << "Optimal (17): " << (isPrimeOptimal(17) ? "true" : "false") << endl;
    cout << "Most Optimal (17): " << (isPrimeMostOptimal(17) ? "true" : "false") << endl;
    cout << "Not prime (15): " << (isPrimeMostOptimal(15) ? "true" : "false") << endl;

    return 0;
}
// 🎯 KEY TAKEAWAYS FOR INTERVIEWS
// Always start with brute force - Shows you understand the problem
// Identify inefficiencies - What makes brute force slow?
// Look for patterns/math - Most optimizations come from mathematical insights
// Consider edge cases - 0, negative numbers, overflow, large inputs
// Space vs Time tradeoff - Can you use extra memory to reduce time?
// Early exits - Return as soon as answer is known
// Avoid unnecessary operations - Precompute, cache, reuse

// 🔍 PATTERN RECOGNITION
// Digit manipulation problems → Use % 10 and / 10
// Divisibility problems → Check only up to √n
// Number property problems → Look for mathematical properties
// Optimization problems → Consider precomputation
// Overflow problems → Check bounds before operations