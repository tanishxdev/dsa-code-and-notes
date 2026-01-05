#include <bits/stdc++.h>
using namespace std;

// ⭐ Approach 1: Brute Force
// Time: O(n)
// Space: O(1)
// Idea: Try every number from 1 to n and keep updating answer
// until i*i exceeds n.

int floorSqrt_Brute(int n)
{
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        // Use long long to avoid integer overflow
        if ((long long)i * i <= n)
            ans = i;
        else
            break; // once square exceeds n, no need to continue
    }

    return ans;
}

// ⭐ Approach 2: Binary Search (Optimal)
// Time: O(log n)
// Space: O(1)
// Idea:
// - sqrt(n) always lies between 1 and n
// - Find the largest mid such that mid*mid <= n

int floorSqrt_Binary(int n)
{
    int low = 1, high = n;
    int ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if ((long long)mid * mid <= n)
        {
            ans = mid;     // mid is a valid answer
            low = mid + 1; // try to find a larger one
        }
        else
        {
            high = mid - 1; // mid^2 too large
        }
    }

    return ans;
}

// ⭐ Approach 3: Using STL (Not recommended for interviews)
// Time: O(1)
// Space: O(1)
// Uses built-in sqrt but may cause precision issues

int floorSqrt_STL(int n)
{
    return (int)sqrt(n);
}

int main()
{
    int n;
    cin >> n;

    cout << "Brute Force Answer: " << floorSqrt_Brute(n) << endl;
    cout << "Binary Search Answer: " << floorSqrt_Binary(n) << endl;
    cout << "STL Answer: " << floorSqrt_STL(n) << endl;

    return 0;
}
