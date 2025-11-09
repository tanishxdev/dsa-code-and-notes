#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem : 
// Example : 
// Constraint : 

// 🔴 Approach 1 Brute Force : Iterative 
// Intuition :
// Algo :
// TC :
// SC :
string reverseIterative(string s) {
    string rev = "";
    for (int i = s.length() - 1; i >= 0; i--)
    {
        rev += s[i];
    }
    return rev;
    
}
// Dry Run
// Input: s = "hello"
// Steps:
// 1. Initialize an empty string rev.
// 2. Iterate over the string s in reverse order.
// 3. Append each character to rev.
// Output: olleh

// 🔵 Approach 2 Better : Recursive
// Intuition :
// Algo :
// TC :
// SC :
string reverseRecursive(string s) {
    if(s.length() <= 1) return s;
    return reverseRecursive(s.substr(1)) + s[0];
}
// 🟢 Approach 3 Optimal: In-place / Two Pointer
// Intuition :
// Algo :
// TC :
// SC :

void reverseInPlace(string &s){
    int left = 0, right = s.length() - 1;

    while (left < right)
    {
        swap(s[left], s[right]);
        left++;
        right--;
    }
    
}

int main()
{
    string s = "hello";

    // Approach 1
    cout << "Approach 1\n";
    cout << reverseIterative(s); // Output: olleh
    
    // Approach 2
    cout << "\nApproach 2\n";
    cout << reverseRecursive(s); // Output: olleh

    // Approach 3
    cout << "\nApproach 3\n";
    reverseInPlace(s);
    cout << s; // Output: olleh
    return 0;
}