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

// 🔵 Approach 2 Better : 
// Intuition :
// Algo :
// TC :
// SC :

// 🟢 Approach 3 Optimal: Two Pointer with Filtering
// Intuition :
// Algo :
// TC :
// SC :
bool isPalindrome(string s) {
    int l = 0, r = s.size() - 1;

    while (l < r) {
        // Skip non-alphanumeric characters
        if (!isalnum(s[l])) { l++; continue; }
        if (!isalnum(s[r])) { r--; continue; }

        // Compare lowercased characters
        if (tolower(s[l]) != tolower(s[r])) return false;

        l++;
        r--;
    }
    return true;
}
int main()
{
    string s = "A man, a plan, a canal: Panama";
    cout << (isPalindrome(s) ? "Palindrome" : "Not Palindrome");
    return 0;
}