#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem: Rotate an array by 1 position to the right
// Example: arr = [1,2,3,4,5] → [5,1,2,3,4]
// Constraints: 1 <= n <= 10^6

// ---------------------------------------------------
// 🔴 Approach 1: Brute Force (using extra array)
// Intuition:
//   - Copy elements into a temporary array
//   - Last element goes to first position
//   - Rest are shifted by 1
// ---------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution1 {
public:
    void rotate(vector<int> &arr) {
        int n = arr.size();
        vector<int> temp(n);

        temp[0] = arr[n-1];           // last element becomes first
        for (int i = 0; i < n-1; i++) {
            temp[i+1] = arr[i];       // shift elements to right
        }

        arr = temp;                   // copy back to original array
    }
};

// ---------------------------------------------------
// 🔵 Approach 2: Better (in-place shifting)
// Intuition:
//   - Store the last element
//   - Shift elements one step to the right
//   - Put last element at first position
// ---------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution2 {
public:
    void rotate(vector<int> &arr) {
        int n = arr.size();

        int last = arr[n-1];           // save last element

        // shift elements right by one
        for (int i = n-1; i > 0; i--) {
            arr[i] = arr[i-1];
        }

        arr[0] = last;                 // put last at first
    }
};

// ---------------------------------------------------
// 🟢 Approach 3: Optimal (using reverse trick)
// Intuition:
//   - Reverse whole array → [5,4,3,2,1]
//   - Reverse subarray from 1 to n-1 → [5,1,2,3,4]
// ---------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution3 {
public:
    void rotate(vector<int> &arr) {
        reverse(arr.begin(), arr.end());      // reverse entire array
        reverse(arr.begin()+1, arr.end());    // reverse everything except first
    }
};

// ---------------------------------------------------
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    Solution3 s;   // try Solution1, Solution2, Solution3
    s.rotate(arr);

    for (int x : arr) cout << x << " ";  // Output: 5 1 2 3 4
    return 0;
}
