#include <bits/stdc++.h>
using namespace std;

// ============================================================================
// PROBLEM 1: PRINT "HELLO" N TIMES USING RECURSION
// ============================================================================

/*
Problem Statement: Print "Hello" N times using recursion.
Example: N = 3 → Output: Hello Hello Hello
*/

// ----------------------------------------------------------------------------
// APPROACH 1: BRUTE FORCE (Tail Recursion - Print then Call)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Print first, then make recursive call for remaining times
- Base case: when n == 0, stop recursion
- Each call handles one "Hello" print

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(N) (recursion stack depth)

DRY RUN:
N = 3
Call 1: print "Hello", n=3 → call printHello(2)
Call 2: print "Hello", n=2 → call printHello(1)
Call 3: print "Hello", n=1 → call printHello(0)
Call 4: n=0 → return (base case)

Stack unwinds: returns back

Output:
Hello
Hello
Hello

EDGE CASES:
1. N = 0 → No output
2. N < 0 → Should handle or assume N >= 0
3. Large N → Stack overflow risk

WHY NOT OPTIMAL?:
- Uses tail recursion (could be converted to iteration)
- Stack space O(N) for deep recursion

PROBLEM WITH THIS APPROACH:
- Stack overflow for very large N
- Not tail-call optimized in all compilers
*/

void printHelloBrute(int n)
{
    // Base case: when nothing left to print
    if (n <= 0)
        return;

    // Print first
    cout << "Hello" << endl;

    // Recursive call for remaining
    printHelloBrute(n - 1);
}

// ----------------------------------------------------------------------------
// APPROACH 2: BETTER (With parameter validation)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Same as brute force but with better parameter handling
- Check for invalid inputs
- Could add error messages

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(N)

DRY RUN: Same as brute force

EDGE CASES HANDLED:
- Negative N → Error or return immediately
- Very large N → Still risk of stack overflow

WHY NOT OPTIMAL?:
- Same recursion depth issue
- Just adds validation
*/

void printHelloBetter(int n)
{
    // Validate input
    if (n <= 0)
    {
        if (n < 0)
        {
            cout << "Error: N cannot be negative" << endl;
        }
        return;
    }

    // Print and recurse
    cout << "Hello" << endl;
    printHelloBetter(n - 1);
}

// ----------------------------------------------------------------------------
// APPROACH 3: OPTIMAL (Iterative version - when recursion not needed)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Sometimes recursion is overkill for simple iteration
- Convert recursive solution to iterative
- Avoids stack overflow risk

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)

DRY RUN:
N = 3
Loop i=0 → print "Hello"
Loop i=1 → print "Hello"
Loop i=2 → print "Hello"

WHY IT'S OPTIMAL FOR THIS PROBLEM:
- No recursion overhead
- Constant space
- No risk of stack overflow

WHEN TO USE RECURSION VS ITERATION:
- Use recursion when problem naturally recursive (trees, backtracking)
- Use iteration for simple loops
*/

void printHelloOptimal(int n)
{
    // Edge case
    if (n <= 0)
        return;

    // Simple loop instead of recursion
    for (int i = 0; i < n; i++)
    {
        cout << "Hello" << endl;
    }
}

// ============================================================================
// PROBLEM 2: PRINT NAME N TIMES USING RECURSION
// ============================================================================

/*
Problem Statement: Print given name N times using recursion.
Similar to Problem 1 but with custom string.
*/

// ----------------------------------------------------------------------------
// SINGLE OPTIMAL RECURSIVE APPROACH
// ----------------------------------------------------------------------------

/*
INTUITION:
- Print name, then recurse for remaining times
- Base case stops recursion

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(N)

DRY RUN: Similar to Problem 1

VARIATIONS:
1. Tail recursion (print then call)
2. Head recursion (call then print)
*/

void printName(int n, const string &name)
{
    // Base case
    if (n <= 0)
        return;

    // Print and recurse (tail recursion)
    cout << name << endl;
    printName(n - 1, name);
}

// ============================================================================
// PROBLEM 3: PRINT 1 TO N USING RECURSION
// ============================================================================

/*
Problem Statement: Print numbers from 1 to N in ascending order using recursion.
Example: N = 5 → Output: 1 2 3 4 5
*/

// ----------------------------------------------------------------------------
// APPROACH 1: BRUTE FORCE (Head Recursion - Call then Print)
// ----------------------------------------------------------------------------

/*
INTUITION:
- First reach the base case (N = 0)
- Then print while returning (unwinding the stack)
- This gives ascending order: deepest call prints 1 first

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(N)

DRY RUN (CRITICAL TO UNDERSTAND):
N = 3
Call 1: print1toN(3) → calls print1toN(2) [not printed yet]
Call 2: print1toN(2) → calls print1toN(1) [not printed yet]
Call 3: print1toN(1) → calls print1toN(0) [not printed yet]
Call 4: print1toN(0) → returns (base case)

Now stack unwinds:
Return to Call 3: prints 1
Return to Call 2: prints 2
Return to Call 1: prints 3

Output: 1 2 3

WHY THIS WORKS:
- Recursion goes deep first
- Printing happens on the way back
- This is HEAD RECURSION (recursive call comes before processing)

EDGE CASES:
1. N = 0 → No output
2. N = 1 → Output: 1
3. N < 0 → Handle properly
*/

void print1toNBrute(int n)
{
    // Base case
    if (n <= 0)
        return;

    // Recursive call first (head recursion)
    print1toNBrute(n - 1);

    // Print while returning (after recursive call)
    cout << n << " ";
}

// ----------------------------------------------------------------------------
// APPROACH 2: BETTER (With extra parameter for current number)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Pass current number as parameter
- Start from 1, increment until reaching N
- More intuitive for some people

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(N)

DRY RUN:
print1toNHelper(1, 3) → prints 1 → calls print1toNHelper(2, 3)
print1toNHelper(2, 3) → prints 2 → calls print1toNHelper(3, 3)
print1toNHelper(3, 3) → prints 3 → calls print1toNHelper(4, 3)
Base case reached (4 > 3) → return

Output: 1 2 3

WHY THIS IS CLEARER:
- Explicitly tracks current position
- Base case: current > N
*/

void print1toNHelper(int current, int n)
{
    // Base case: when current exceeds N
    if (current > n)
        return;

    // Print current
    cout << current << " ";

    // Recurse for next number
    print1toNHelper(current + 1, n);
}

void print1toNBetter(int n)
{
    if (n <= 0)
        return;
    print1toNHelper(1, n);
}

// ----------------------------------------------------------------------------
// APPROACH 3: OPTIMAL (Tail recursion optimization possible)
// ----------------------------------------------------------------------------

/*
INTUITION:
- If we want to use tail recursion for potential compiler optimization
- Pass accumulated result as parameter
- Some compilers can optimize tail recursion to iteration

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1) if tail-call optimized, otherwise O(N)

NOTE:
- Tail recursion means recursive call is the last operation
- Some compilers optimize this to avoid stack growth
*/

void print1toNTailRec(int n, int current = 1)
{
    // Base case
    if (current > n)
        return;

    // Print current
    cout << current << " ";

    // Tail recursive call (last operation)
    print1toNTailRec(n, current + 1);
}

// ============================================================================
// PROBLEM 4: PRINT N TO 1 USING RECURSION
// ============================================================================

/*
Problem Statement: Print numbers from N to 1 in descending order using recursion.
Example: N = 5 → Output: 5 4 3 2 1
*/

// ----------------------------------------------------------------------------
// APPROACH 1: BRUTE FORCE (Tail Recursion - Print then Call)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Print current N first
- Then make recursive call with N-1
- This gives descending order

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(N)

DRY RUN:
N = 3
Call 1: print 3 → call printNto1(2)
Call 2: print 2 → call printNto1(1)
Call 3: print 1 → call printNto1(0)
Call 4: n=0 → return

Output: 3 2 1

WHY THIS IS TAIL RECURSION:
- Recursive call is the last operation
- Printing happens before the call
*/

void printNto1Brute(int n)
{
    // Base case
    if (n <= 0)
        return;

    // Print current N first
    cout << n << " ";

    // Then recurse for N-1
    printNto1Brute(n - 1);
}

// ----------------------------------------------------------------------------
// APPROACH 2: HEAD RECURSION VERSION
// ----------------------------------------------------------------------------

/*
INTUITION:
- First make recursive call
- Then print while returning
- But this would give 1 2 3... not what we want!

INTERESTING OBSERVATION:
For descending order, we need TAIL recursion
For ascending order, we need HEAD recursion
*/

// ============================================================================
// PROBLEM 5: SUM OF FIRST N NATURAL NUMBERS USING RECURSION
// ============================================================================

/*
Problem Statement: Calculate sum of first N natural numbers using recursion.
Example: N = 5 → Output: 15 (1+2+3+4+5)
*/

// ----------------------------------------------------------------------------
// APPROACH 1: BRUTE FORCE (Standard Recursion)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Mathematical definition: sum(N) = N + sum(N-1)
- Base case: sum(0) = 0

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(N) for recursion stack

MATHEMATICAL FORMULA:
sum(N) = N * (N + 1) / 2 (O(1) time)
But we're doing recursion practice

DRY RUN:
sum(5) = 5 + sum(4)
sum(4) = 4 + sum(3)
sum(3) = 3 + sum(2)
sum(2) = 2 + sum(1)
sum(1) = 1 + sum(0)
sum(0) = 0 (base case)

Now unwind:
sum(1) = 1 + 0 = 1
sum(2) = 2 + 1 = 3
sum(3) = 3 + 3 = 6
sum(4) = 4 + 6 = 10
sum(5) = 5 + 10 = 15

EDGE CASES:
1. N = 0 → sum = 0
2. N = 1 → sum = 1
3. N < 0 → Handle error
*/

int sumNBrute(int n)
{
    // Base case
    if (n <= 0)
        return 0;

    // Recursive formula: n + sum(n-1)
    return n + sumNBrute(n - 1);
}

// ----------------------------------------------------------------------------
// APPROACH 2: BETTER (Parameterized Recursion - Tail Recursive)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Pass accumulated sum as parameter
- This is tail-recursive (could be optimized)
- Avoids returning through all stack frames

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1) if tail-call optimized

DRY RUN:
sumNTail(5, 0) → calls sumNTail(4, 5)
sumNTail(4, 5) → calls sumNTail(3, 9)
sumNTail(3, 9) → calls sumNTail(2, 12)
sumNTail(2, 12) → calls sumNTail(1, 14)
sumNTail(1, 14) → calls sumNTail(0, 15)
Base case: return 15

WHY THIS IS BETTER:
- Tail recursion can be optimized
- No need to wait for all returns
*/

int sumNTail(int n, int sum = 0)
{
    // Base case
    if (n <= 0)
        return sum;

    // Tail recursive call
    return sumNTail(n - 1, sum + n);
}

// ----------------------------------------------------------------------------
// APPROACH 3: OPTIMAL (Mathematical Formula - Not Recursive)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Use formula: sum = N * (N + 1) / 2
- Derived from pairing: (1+N) + (2+(N-1)) + ... = (N+1) * N/2

TIME COMPLEXITY: O(1)
SPACE COMPLEXITY: O(1)

WHEN TO USE:
- In practice, use formula for performance
- Use recursion only for practice/learning

FORMULA DERIVATION:
sum = 1 + 2 + 3 + ... + N
Also sum = N + (N-1) + ... + 1
Add both: 2*sum = (N+1) + (N+1) + ... (N times)
2*sum = N*(N+1)
sum = N*(N+1)/2
*/

int sumNOptimal(int n)
{
    if (n <= 0)
        return 0;
    return n * (n + 1) / 2;
}

// ============================================================================
// PROBLEM 6: FACTORIAL OF N USING RECURSION
// ============================================================================

/*
Problem Statement: Calculate factorial of N using recursion.
Definition: N! = N × (N-1) × (N-2) × ... × 1
Example: 5! = 120
Special: 0! = 1
*/

// ----------------------------------------------------------------------------
// APPROACH 1: BRUTE FORCE (Standard Recursion)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Mathematical definition: factorial(N) = N × factorial(N-1)
- Base case: factorial(0) = 1, factorial(1) = 1

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(N)

DRY RUN:
factorial(5) = 5 × factorial(4)
factorial(4) = 4 × factorial(3)
factorial(3) = 3 × factorial(2)
factorial(2) = 2 × factorial(1)
factorial(1) = 1 × factorial(0)
factorial(0) = 1 (base case)

Unwind:
factorial(1) = 1 × 1 = 1
factorial(2) = 2 × 1 = 2
factorial(3) = 3 × 2 = 6
factorial(4) = 4 × 6 = 24
factorial(5) = 5 × 24 = 120

EDGE CASES:
1. N = 0 → 1
2. N = 1 → 1
3. N < 0 → Error (factorial not defined for negative integers)
4. Large N → Overflow (use long long)
*/

long long factorialBrute(int n)
{
    // Handle invalid input
    if (n < 0)
    {
        cout << "Error: Factorial not defined for negative numbers" << endl;
        return -1; // Or throw exception
    }

    // Base cases
    if (n == 0 || n == 1)
        return 1;

    // Recursive case
    return n * factorialBrute(n - 1);
}

// ----------------------------------------------------------------------------
// APPROACH 2: BETTER (Tail Recursive)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Pass accumulated result as parameter
- Multiply as we go down
- Tail recursion can be optimized

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1) if tail-call optimized

DRY RUN:
factorialTail(5, 1) → calls factorialTail(4, 5)
factorialTail(4, 5) → calls factorialTail(3, 20)
factorialTail(3, 20) → calls factorialTail(2, 60)
factorialTail(2, 60) → calls factorialTail(1, 120)
factorialTail(1, 120) → return 120
*/

long long factorialTail(int n, long long result = 1)
{
    // Base case
    if (n <= 1)
        return result;

    // Tail recursive call
    return factorialTail(n - 1, result * n);
}

// ----------------------------------------------------------------------------
// APPROACH 3: OPTIMAL (Iterative for production)
// ----------------------------------------------------------------------------

/*
INTUITION:
- For production code, use iterative approach
- Avoids recursion overhead and stack overflow risk

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)

WHEN TO USE:
- Use iterative for production
- Use recursive for practice/teaching
*/

long long factorialOptimal(int n)
{
    if (n < 0)
        return -1; // Error

    long long result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

// ============================================================================
// PROBLEM 7: REVERSE AN ARRAY USING RECURSION
// ============================================================================

/*
Problem Statement: Reverse an array using recursion.
Example: [1, 2, 3, 4, 5] → [5, 4, 3, 2, 1]
*/

// ----------------------------------------------------------------------------
// APPROACH 1: BRUTE FORCE (Two-pointer recursion)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Use two pointers: start and end
- Swap elements at start and end
- Recursively process inner array (start+1, end-1)
- Base case: when start >= end

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(N) for recursion stack

DRY RUN:
Array: [1, 2, 3, 4, 5]
Call 1: swap(0,4) → [5,2,3,4,1] → recurse(1,3)
Call 2: swap(1,3) → [5,4,3,2,1] → recurse(2,2)
Call 3: start=2, end=2 → base case → return

EDGE CASES:
1. Empty array → Do nothing
2. Single element → Already reversed
3. Even length → Works fine
4. Odd length → Works fine
*/

void reverseArrayBrute(int arr[], int start, int end)
{
    // Base case: when pointers meet or cross
    if (start >= end)
        return;

    // Swap current elements
    swap(arr[start], arr[end]);

    // Recursively process inner array
    reverseArrayBrute(arr, start + 1, end - 1);
}

// ----------------------------------------------------------------------------
// APPROACH 2: BETTER (Single pointer recursion)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Use only one index parameter
- Swap element at index i with element at (n-i-1)
- Stop when i >= n/2

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(N)

DRY RUN:
Array: [1,2,3,4,5], n=5
Call 1: i=0, swap with index 4 → [5,2,3,4,1]
Call 2: i=1, swap with index 3 → [5,4,3,2,1]
Call 3: i=2, i >= 5/2 → stop
*/

void reverseArraySinglePtr(int arr[], int i, int n)
{
    // Base case: processed half the array
    if (i >= n / 2)
        return;

    // Swap symmetric positions
    swap(arr[i], arr[n - i - 1]);

    // Recurse for next position
    reverseArraySinglePtr(arr, i + 1, n);
}

// ----------------------------------------------------------------------------
// APPROACH 3: OPTIMAL (Iterative two-pointer)
// ----------------------------------------------------------------------------

/*
INTUITION:
- For production, iterative is better
- Two pointers moving towards center

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)

WHEN TO USE:
- Use iterative for production
- Use recursive for practice
*/

void reverseArrayOptimal(int arr[], int n)
{
    int start = 0, end = n - 1;
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// ============================================================================
// PROBLEM 8: CHECK IF STRING IS PALINDROME USING RECURSION
// ============================================================================

/*
Problem Statement: Check if a string reads same forward and backward using recursion.
Example: "madam" → true, "hello" → false
Note: Should be case-insensitive? Usually yes in interviews.
*/

// ----------------------------------------------------------------------------
// APPROACH 1: BRUTE FORCE (Two-pointer recursion)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Compare characters at start and end
- If equal, recursively check inner substring
- Base cases:
  1. start >= end → true (empty or single character)
  2. characters not equal → false

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(N) for recursion stack

DRY RUN:
s = "madam", n=5
Call 1: s[0]='m' vs s[4]='m' → equal → recurse(1,3)
Call 2: s[1]='a' vs s[3]='a' → equal → recurse(2,2)
Call 3: start=2, end=2 → base case → return true

EDGE CASES:
1. Empty string → true (usually)
2. Single character → true
3. Case sensitivity → handle if needed
4. Spaces/punctuation → usually ignore in palindrome checks
*/

bool isPalindromeBrute(const string &s, int start, int end)
{
    // Base case 1: empty string or single character
    if (start >= end)
        return true;

    // Base case 2: mismatch found
    if (s[start] != s[end])
        return false;

    // Recursive case: check inner substring
    return isPalindromeBrute(s, start + 1, end - 1);
}

// ----------------------------------------------------------------------------
// APPROACH 2: BETTER (With case normalization)
// ----------------------------------------------------------------------------

/*
INTUITION:
- First normalize string (lowercase, remove non-alphanumeric)
- Then apply palindrome check
- More realistic for interview problems

TIME COMPLEXITY: O(N) for normalization + O(N) for check = O(N)
SPACE COMPLEXITY: O(N) for normalized string

EXAMPLE:
"A man, a plan, a canal: Panama" → true
Normalize: "amanaplanacanalpanama"
*/

string normalizeString(const string &s)
{
    string result;
    for (char c : s)
    {
        if (isalnum(c))
        {
            result += tolower(c);
        }
    }
    return result;
}

bool isPalindromeBetter(const string &s)
{
    string normalized = normalizeString(s);
    return isPalindromeBrute(normalized, 0, normalized.length() - 1);
}

// ----------------------------------------------------------------------------
// APPROACH 3: OPTIMAL (Iterative two-pointer)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Use two pointers from both ends
- Compare while moving towards center
- Skip non-alphanumeric characters

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)

WHY IT'S OPTIMAL:
- No recursion overhead
- No extra string creation (can process in-place)
- Handles edge cases efficiently
*/

bool isPalindromeOptimal(const string &s)
{
    int left = 0, right = s.length() - 1;

    while (left < right)
    {
        // Skip non-alphanumeric characters from left
        while (left < right && !isalnum(s[left]))
            left++;

        // Skip non-alphanumeric characters from right
        while (left < right && !isalnum(s[right]))
            right--;

        // Compare characters (case-insensitive)
        if (tolower(s[left]) != tolower(s[right]))
        {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

// ============================================================================
// PROBLEM 9: FIBONACCI NUMBER USING RECURSION
// ============================================================================

/*
Problem Statement: Find Nth Fibonacci number using recursion.
Fibonacci: F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2)
Example: F(6) = 8
*/

// ----------------------------------------------------------------------------
// APPROACH 1: BRUTE FORCE (Naive Recursion)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Direct translation of mathematical definition
- F(n) = F(n-1) + F(n-2)
- Base cases: F(0)=0, F(1)=1

TIME COMPLEXITY: O(2^N) - EXPONENTIAL!
SPACE COMPLEXITY: O(N) for recursion stack

WHY EXPONENTIAL?:
- Each call makes two more calls
- Creates binary tree of calls
- Many repeated calculations

DRY RUN (showing repeated work):
F(5) = F(4) + F(3)
F(4) = F(3) + F(2)
F(3) = F(2) + F(1)
F(2) = F(1) + F(0)
Notice F(3) calculated twice, F(2) calculated three times!

EDGE CASES:
1. n = 0 → 0
2. n = 1 → 1
3. n < 0 → Error (Fibonacci not defined for negative)
*/

int fibonacciBrute(int n)
{
    // Handle invalid input
    if (n < 0)
        return -1; // Error

    // Base cases
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    // Recursive case
    return fibonacciBrute(n - 1) + fibonacciBrute(n - 2);
}

// ----------------------------------------------------------------------------
// APPROACH 2: BETTER (Memoization - Top-down DP)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Store computed results to avoid recalculation
- Before computing, check if already computed
- This is Dynamic Programming (memoization)

TIME COMPLEXITY: O(N) - LINEAR!
SPACE COMPLEXITY: O(N) for memo array + recursion stack

DRY RUN:
F(5) → compute F(4) → compute F(3) → compute F(2) → compute F(1) and F(0)
Store results as we compute
F(3) already computed when needed for F(4)

WHY IT'S BETTER:
- Eliminates repeated calculations
- Exponential → Linear improvement
*/

int fibonacciMemoHelper(int n, vector<int> &memo)
{
    // Check if already computed
    if (memo[n] != -1)
        return memo[n];

    // Base cases
    if (n == 0)
        return memo[n] = 0;
    if (n == 1)
        return memo[n] = 1;

    // Compute and store
    memo[n] = fibonacciMemoHelper(n - 1, memo) + fibonacciMemoHelper(n - 2, memo);
    return memo[n];
}

int fibonacciMemo(int n)
{
    if (n < 0)
        return -1;

    // Initialize memoization array with -1 (not computed)
    vector<int> memo(n + 1, -1);

    return fibonacciMemoHelper(n, memo);
}

// ----------------------------------------------------------------------------
// APPROACH 3: OPTIMAL (Iterative - Bottom-up DP)
// ----------------------------------------------------------------------------

/*
INTUITION:
- Compute from bottom up: F(0), F(1), F(2), ...
- Use only previous two values
- No recursion overhead

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1) - only need last two values!

DRY RUN:
n=5
prev2=0, prev1=1
i=2: curr=0+1=1, update prev2=1, prev1=1
i=3: curr=1+1=2, update prev2=1, prev1=2
i=4: curr=1+2=3, update prev2=2, prev1=3
i=5: curr=2+3=5, done

WHY IT'S OPTIMAL:
- Linear time
- Constant space
- No recursion risk
*/

int fibonacciOptimal(int n)
{
    if (n < 0)
        return -1;
    if (n <= 1)
        return n;

    int prev2 = 0; // F(n-2)
    int prev1 = 1; // F(n-1)

    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

// ----------------------------------------------------------------------------
// BONUS: MATRIX EXPONENTIATION APPROACH (O(log N) time)
// ----------------------------------------------------------------------------

/*
INTUITION (ADVANCED):
- Use matrix exponentiation to get O(log N) time
- Based on: [F(n+1) F(n); F(n) F(n-1)] = [1 1; 1 0]^n
- Use fast exponentiation (binary exponentiation)

TIME COMPLEXITY: O(log N)
SPACE COMPLEXITY: O(1)

WHEN TO USE:
- When N is very large (e.g., 10^9)
- Competitive programming
- Not typically asked in interviews unless specifically mentioned
*/

// ============================================================================
// PROBLEM 10: PRINT ALL SUBSEQUENCES OF A STRING (BONUS)
// ============================================================================

/*
Problem Statement: Print all subsequences of a string.
Subsequence: Can remove any characters but maintain order
Example: "abc" → "", "a", "b", "c", "ab", "ac", "bc", "abc"
Total: 2^n subsequences
*/

// ----------------------------------------------------------------------------
// APPROACH: RECURSIVE BACKTRACKING
// ----------------------------------------------------------------------------

/*
INTUITION:
- For each character, we have two choices: take it or skip it
- Recursively explore both choices
- Build current subsequence as we go

TIME COMPLEXITY: O(2^N * N) - 2^N subsequences, each up to length N
SPACE COMPLEXITY: O(N) for recursion stack and current string

DRY RUN:
s = "abc", index=0, curr=""
Take 'a': curr="a" → recurse index=1
Skip 'a': curr="" → recurse index=1
... and so on

WHY THIS IS IMPORTANT:
- Fundamental backtracking pattern
- Basis for many other problems (subsets, combinations, etc.)
*/

void printSubsequences(const string &s, int index, string current)
{
    // Base case: processed all characters
    if (index == s.length())
    {
        cout << "\"" << current << "\" ";
        return;
    }

    // Choice 1: Take current character
    printSubsequences(s, index + 1, current + s[index]);

    // Choice 2: Skip current character
    printSubsequences(s, index + 1, current);
}

// ============================================================================
// MAIN FUNCTION - TEST ALL RECURSION PROBLEMS
// ============================================================================

int main()
{
    cout << "=== RECURSION PROBLEM WALKTHROUGH ===\n\n";

    // Problem 1: Print Hello N times
    cout << "1. PRINT HELLO 3 TIMES:\n";
    cout << "Brute (recursive):\n";
    printHelloBrute(3);
    cout << "Optimal (iterative):\n";
    printHelloOptimal(3);

    // Problem 2: Print Name N times
    cout << "\n2. PRINT NAME 2 TIMES:\n";
    printName(2, "Alice");

    // Problem 3: Print 1 to N
    cout << "\n3. PRINT 1 TO 5:\n";
    cout << "Head recursion: ";
    print1toNBrute(5);
    cout << "\nTail recursion: ";
    print1toNTailRec(5);
    cout << endl;

    // Problem 4: Print N to 1
    cout << "\n4. PRINT 5 TO 1:\n";
    cout << "Tail recursion: ";
    printNto1Brute(5);
    cout << endl;

    // Problem 5: Sum of first N numbers
    cout << "\n5. SUM OF FIRST 5 NUMBERS:\n";
    cout << "Recursive: " << sumNBrute(5) << endl;
    cout << "Tail recursive: " << sumNTail(5) << endl;
    cout << "Mathematical (optimal): " << sumNOptimal(5) << endl;

    // Problem 6: Factorial
    cout << "\n6. FACTORIAL OF 5:\n";
    cout << "Recursive: " << factorialBrute(5) << endl;
    cout << "Tail recursive: " << factorialTail(5) << endl;
    cout << "Iterative (optimal): " << factorialOptimal(5) << endl;

    // Problem 7: Reverse array
    cout << "\n7. REVERSE ARRAY [1,2,3,4,5]:\n";
    int arr[] = {1, 2, 3, 4, 5};
    cout << "Original: ";
    for (int x : arr)
        cout << x << " ";

    // Make a copy for recursive version
    int arr1[] = {1, 2, 3, 4, 5};
    reverseArrayBrute(arr1, 0, 4);
    cout << "\nRecursive reverse: ";
    for (int x : arr1)
        cout << x << " ";

    // Make another copy for iterative
    int arr2[] = {1, 2, 3, 4, 5};
    reverseArrayOptimal(arr2, 5);
    cout << "\nIterative reverse: ";
    for (int x : arr2)
        cout << x << " ";
    cout << endl;

    // Problem 8: Palindrome check
    cout << "\n8. PALINDROME CHECK:\n";
    string test1 = "madam";
    string test2 = "hello";
    cout << test1 << " (recursive): " << (isPalindromeBrute(test1, 0, test1.length() - 1) ? "true" : "false") << endl;
    cout << test2 << " (recursive): " << (isPalindromeBrute(test2, 0, test2.length() - 1) ? "true" : "false") << endl;

    string test3 = "A man, a plan, a canal: Panama";
    cout << test3 << " (optimal with normalization): " << (isPalindromeOptimal(test3) ? "true" : "false") << endl;

    // Problem 9: Fibonacci
    cout << "\n9. FIBONACCI NUMBERS:\n";
    cout << "F(6) naive recursive: " << fibonacciBrute(6) << endl;
    cout << "F(6) with memoization: " << fibonacciMemo(6) << endl;
    cout << "F(6) iterative (optimal): " << fibonacciOptimal(6) << endl;

    // Bonus: Print all subsequences
    cout << "\n10. ALL SUBSEQUENCES OF \"abc\":\n";
    printSubsequences("abc", 0, "");
    cout << endl;

    return 0;
}

// 🎯 RECURSION THINKING FRAMEWORK
// Step 1: Identify Base Case(s)
// Smallest valid input (e.g., n=0, empty string, single element)
// Invalid input (e.g., n<0, null pointer)
// Simple case that can be solved directly

// Step 2: Define Recursive Case
// How to break problem into smaller version (n → n-1, n/2, etc.)
// What to do with result of recursive call
// Combine results if multiple recursive calls

// Step 3: Ensure Progress Towards Base Case
// Parameters must change in recursive call
// Must eventually reach base case
// No infinite recursion

// Step 4: Handle Return Values
// What to return at base case
// How to combine returns from recursive calls
// Tail vs non-tail recursion considerations

// 📝 RECURSION INTERVIEW CHECKLIST: For Each Recursion Problem
// ✅ Define function signature with parameters
// ✅ Identify base case (s)-when to stop
// ✅ Define recursive case -how to break down
// ✅ Ensure progress parameters must change
// ✅ Handle return values - what to combine
// ✅ Consider optimization - memoization, tail recursion
// ✅ Test with small cases - verify logic
// ✅ Check edge cases - empty, single, negative
// ✅ Analyze complexity - time and space
// ✅ Discuss alternatives - iterative solution

// 📊 RECURSION PATTERNS SUMMARY
// | **Problem Type** | **Pattern**                      | **Time Complexity** | **Space Complexity** | **Key Insight**                                |
// | ---------------- | -------------------------------- | ------------------- | -------------------- | ---------------------------------------------- |
// | Linear Recursion | Single recursive call            | O(N)                | O(N)                 | Problem reduces by 1 each time                 |
// | Binary Recursion | Two recursive calls              | O(2ⁿ)               | O(N)                 | Exponential growth (naive Fibonacci)           |
// | Tail Recursion   | Recursive call is last operation | O(N)                | O(1)* if optimized   | Can be converted to iteration                  |
// | Head Recursion   | Recursive call before processing | O(N)                | O(N)                 | Processing happens on return (e.g., print 1→N) |
// | Divide & Conquer | Break into subproblems           | O(N log N)          | O(log N)             | Split, solve, and merge (Merge/Quick sort)     |
// | Backtracking     | Try choices, undo if fails       | O(branch^depth)     | O(depth)             | Explore search space (subsets, permutations)   |