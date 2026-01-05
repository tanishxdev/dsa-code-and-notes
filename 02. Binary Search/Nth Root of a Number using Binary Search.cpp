#include <bits/stdc++.h>
using namespace std;

// ⭐ Approach 1: Brute Force (Using power calculation)
// Time: O(m * n)
// Space: O(1)
// Idea: Try all numbers from 1 to m and check if i^n == m
// NOTE: pow() is unsafe due to floating-point precision

int nthRoot_Brute(int n, int m)
{
    for (int i = 1; i <= m; i++)
    {
        long long power = 1;

        // Compute i^n manually to avoid pow()
        for (int j = 0; j < n; j++)
        {
            power *= i;
            if (power > m)
                break;
        }

        if (power == m)
            return i;

        if (power > m)
            break;
    }
    return -1;
}

// ⭐ Approach 2: Binary Search (Optimal)
// Time: O(log m * n)
// Space: O(1)
// Idea:
// - Answer lies between 1 and m
// - Use binary search on base
// - Compute mid^n carefully and stop early if > m

int nthRoot_Binary(int n, int m)
{
    int low = 1, high = m;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        long long val = 1;

        // Compute mid^n safely
        for (int i = 0; i < n; i++)
        {
            val *= mid;

            // Early stopping to avoid overflow
            if (val > m)
                break;
        }

        if (val == m)
            return mid;
        else if (val < m)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// ⭐ Approach 3: Using pow() (NOT recommended)
// Time: O(log n)
// Space: O(1)
// Floating point precision can fail for large values

int nthRoot_Pow(int n, int m)
{
    int x = round(pow(m, 1.0 / n));
    if (pow(x, n) == m)
        return x;
    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;

    cout << "Brute Force Answer: " << nthRoot_Brute(n, m) << endl;
    cout << "Binary Search Answer: " << nthRoot_Binary(n, m) << endl;
    cout << "Pow Function Answer: " << nthRoot_Pow(n, m) << endl;

    return 0;
}
