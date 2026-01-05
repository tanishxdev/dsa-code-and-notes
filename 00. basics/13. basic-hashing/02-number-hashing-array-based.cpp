#include <bits/stdc++.h>
using namespace std;

/*
👉 Problem Statement — Frequency of Elements Using Basic Hashing

You are given an integer n, followed by n integers.
Each integer lies in the range 0 to 100 (assumption for basic hashing).

Your task is to count the frequency of each element using
a simple hash array (no map / unordered_map).
*/

int main()
{
    // Step 1: Read size of array
    int n;
    cin >> n;

    // Step 2: Read array elements
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Step 3: Create hash array
    // Index represents the number
    // Value at index represents frequency
    // Range assumed: 0 to 100
    int hash[101] = {0};

    // Step 4: Store frequencies
    for (int x : arr)
    {
        hash[x]++;
    }

    // Step 5: Print frequency of elements that appeared
    for (int i = 0; i <= 100; i++)
    {
        if (hash[i] > 0)
        {
            cout << i << " -> " << hash[i] << endl;
        }
    }

    return 0;
}

// 👉 Core Concept (Very Important)

// This is called Direct Address Table / Basic Hashing.

// index  → element
// value  → frequency

// 👉 Example

// arr = [2, 3, 2, 5]

// hash[2] = 2
// hash[3] = 1
// hash[5] = 1

// 👉 Time & Space Complexity

// Time: O(n)
// Space: O(maxValue) → here O(101) → constant

// 👉 When to use this approach

// Use basic hashing when:
// Value range is small & known
// You want fastest possible access
// Interviewer asks for array-based hashing

// 👉 When NOT to use

// Do NOT use when:
// Values are large (10^9)
// Values are negative
// Range is unknown
// In those cases → use unordered_map.

// Dry Run

/*
Input:
n = 6
arr = [1, 2, 2, 3, 1, 2]

Step 1: Initialize hash array
hash[0] = 0
hash[1] = 0
hash[2] = 0
hash[3] = 0
...
hash[100] = 0

Step 2: Traverse array and update hash

i = 0, arr[i] = 1
hash[1]++  → hash[1] = 1

i = 1, arr[i] = 2
hash[2]++  → hash[2] = 1

i = 2, arr[i] = 2
hash[2]++  → hash[2] = 2

i = 3, arr[i] = 3
hash[3]++  → hash[3] = 1

i = 4, arr[i] = 1
hash[1]++  → hash[1] = 2

i = 5, arr[i] = 2
hash[2]++  → hash[2] = 3

Step 3: Final state of hash array (non-zero only)

hash[1] = 2
hash[2] = 3
hash[3] = 1

Step 4: Output

1 -> 2
2 -> 3
3 -> 1
*/
