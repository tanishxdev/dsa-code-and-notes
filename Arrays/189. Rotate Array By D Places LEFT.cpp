#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem: LEFT Rotate an Array by K Places
// Given an array of size `n`, rotate it to the left by `d` positions.

// Example:
// Input : arr = [1, 2, 3, 4, 5, 6, 7], d = 2
// Output: arr = [3, 4, 5, 6, 7, 1, 2]

// 🔴 Approach 1: Brute Force using Extra Array
// TC: O(n), SC: O(d)
void leftRotateBrute(vector<int>& arr, int d) {
    int n = arr.size();
    if (n <= 1 || d == 0) return;

    d %= n; // Handle d > n
    vector<int> temp(d);

    // Store first d elements
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    // Shift remaining elements to the left
    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }

    // Place stored elements at the end
    for (int i = 0; i < d; i++) {
        arr[n - d + i] = temp[i];
    }
}

// 🔵 Approach 2: Optimal using Reversal Algorithm
// TC: O(n), SC: O(1)
void leftRotateOptimal(vector<int>& arr, int d) {
    int n = arr.size();
    if (n == 0 || d == 0) return;

    d %= n;

    // Step 1: Reverse first d elements
    reverse(arr.begin(), arr.begin() + d);

    // Step 2: Reverse remaining n-d elements
    reverse(arr.begin() + d, arr.end());

    // Step 3: Reverse entire array
    reverse(arr.begin(), arr.end());
}

// 🔧 Utility Function to Print Array
void printArray(const vector<int>& arr) {
    for (int val : arr) cout << val << " ";
    cout << endl;
}

// 🧪 Driver Code
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int d = 3;

    cout << "Original Array: ";
    printArray(arr);

    // Use any one approach
    // leftRotateBrute(arr, d);
    leftRotateOptimal(arr, d);

    cout << "Array after Left Rotation by " << d << ": ";
    printArray(arr);

    return 0;
}
