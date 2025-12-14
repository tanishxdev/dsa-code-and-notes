#include <bits/stdc++.h>
using namespace std;

// ⭐ Approach 1: Brute Force (Just for Understanding)

pair<int, int> floorAndCeil(int arr[], int n, int x)
{
    int floorVal = -1;
    int ceilVal = -1;

    // Find floor (largest <= x)
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] <= x)
        {
            floorVal = arr[i];
            break;
        }
    }

    // Find ceil (smallest >= x)
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= x)
        {
            ceilVal = arr[i];
            break;
        }
    }

    return {floorVal, ceilVal};
}
// ⭐ Approach 2:
// ⭐ Approach 3:

int main()
{
    // test

    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;

    auto ans = floorAndCeil(arr, n, x);

    cout << "Floor: " << ans.first<< " " << "Ceil: " << ans.second << endl;

    return 0;
}