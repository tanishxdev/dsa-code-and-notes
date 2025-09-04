#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem : 
// Example : 
// Constraint : 

// 🔴 Approach 1 Brute Force : 
// Intuition :
// Algo :
// TC :
// SC :
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if ((i == 0 || nums[i] > nums[i - 1]) && 
                (i == n - 1 || nums[i] > nums[i + 1])) {
                return i;
            }
        }
        return -1; // should not happen as at least one peak exists
    }
};

// 🔵 Approach 2 Better : 
// Intuition :
// Algo :
// TC :
// SC :

// 🟢 Approach 3 Optimal: 
// Intuition :
// Algo :
// TC :
// SC :
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < nums[mid + 1]) {
                // peak will be on the right side
                low = mid + 1;
            } else {
                // peak will be at mid or on the left side
                high = mid;
            }
        }

        return low; // or high (same when loop ends)
    }
};

int main()
{
    
    return 0;
}