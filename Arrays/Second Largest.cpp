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
    int getSecondLargest(vector<int> &arr) {
    int n = arr.size();
    
    
    int largest = arr[0];
    for(int i = 0;  i<n; i++){
        if(arr[i] > largest)
            largest = arr[i];
    }
    int secLargest = -1;
    for(int i = 0; i<n; i++){
        if(arr[i] < largest && arr[i] > secLargest){
            secLargest = arr[i];
        }
    }
    
    return secLargest;
    }
};

// 🔵 Approach 2 Better : 
// Intuition :
// Algo :
// TC :
// SC :
class Solution {
public:
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        
        int largest = arr[0];
        int secLargest = -1;  // assume -1 if no second largest
        
        for(int i = 1; i < n; i++) {
            if(arr[i] > largest) {
                secLargest = largest;   // update 2nd largest
                largest = arr[i];       // update largest
            } 
            else if(arr[i] < largest && arr[i] > secLargest) {
                secLargest = arr[i];    // update if between
            }
        }
        
        return secLargest;
    }
};
int main()
{
    
    return 0;
}