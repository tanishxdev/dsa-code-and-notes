#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem : 
// Example : 
// Constraint : 

// 🔴 Approach 1 Brute Force : Sorting Based
// Intuition :
// Algo :
// TC :
// SC :
bool isAnagramSort(string s1, string s2) {
    if(s1.length() != s2.length()) return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

// 🔵 Approach 2 Better : Frequency Count
// Intuition :
// Algo :
// TC :
// SC :
bool isAnagramFreq(string s1, string s2) {
    if(s1.length() != s2.length()) return false;

    vector<int> freq(26, 0);

    // Increment for s1 
    for(char c : s1) freq[c - 'a']++;

    // Decrement for s2
    for(char c : s2) freq[c - 'a']--;

    // Check all zero
    for(int i : freq) {
        if( i != 0) return false;
    }
}
// 🟢 Approach 3 Optimal: Using Hash Map (for all characters)

// Intuition :

// If string may contain uppercase, digits, symbols,
// then we need a map instead of fixed array.

// 👉 Why use HashMap instead of Fixed Array (for characters)
// 1. Case 1: Only lowercase letters (a–z)

    // If the string contains only 'a' to 'z',
    // we can use a fixed-size array of 26 elements.

    // int freq[26] = {0};

    // for(char ch : s){
    //     freq[ch - 'a']++;
    // }

    // Why works?
    // Because there are only 26 possible characters → small, fixed range.

// 2. Case 2: Uppercase, digits, symbols => Problem when more character types appear

    // Example : "Aa1@#zZ"
    // It has uppercase (A–Z)
    // lowercase (a–z)
    // digits (0–9)
    // symbols (@, #, $, etc.)

    // If we still try to use an array, we’d have to decide:
    // “How many total possible characters should I handle?”

    // If ASCII → 256 characters
    // If Unicode → thousands of characters (impractical for array)

    // So — array indexing becomes inefficient or even invalid for symbols.

// 3. Solution: Use a Hash Map
    // HashMap allows you to dynamically store only the characters that appear,
    // no matter what they are (letters, digits, or symbols).

    // unordered_map<char, int> freq;

    // for(char ch : s) {
    //     freq[ch]++;   // automatically creates key if not present
    // }

// 4. Summary — When to Use What
    // | Case                                | Data Type                  | Why                                |
    // | ----------------------------------- | -------------------------- | ---------------------------------- |
    // | Only lowercase (a–z)                | `int freq[26]`             | Simple, faster, small fixed range  |
    // | Lower + Uppercase (A–Z, a–z)        | `int freq[52]`             | Still okay, but needs offset logic |
    // | ASCII characters                    | `int freq[256]`            | Works but wasteful if string small |
    // | Any char (digits, symbols, Unicode) | `unordered_map<char, int>` | Safe, flexible, memory-efficient   |

// 5. Example Comparison
    // ✅ Using Fixed Array (lowercase only)

    // string s = "abbca";
    // int freq[26] = {0};

    // for (char c : s)
    //     freq[c - 'a']++;

    // cout << "Count of b: " << freq['b' - 'a']; // Output: 2

    // ✅ Using HashMap (any characters)

    // string s = "A@a#1bB";
    // unordered_map<char, int> freq;

    // for (char c : s)
    //     freq[c]++;

    // cout << freq['@'];  // Output: 1
    // cout << freq['B'];  // Output: 1

// Algo :
// TC :
// SC :
bool isAnagramMap(string s1, string s2) {
    if(s1.length() != s2.length()) return false;

    unordered_map<char, int> mp;

    // Count frequency from s1
    for(char c : s1) mp[c]++;

    // Decrement frequency from s2
    for(char c : s2) {
        mp[c]--;
        if(mp[c] < 0) return false; // early exit
    }

    return true;


}

int main()
{
    string s1 = "listen", s2 = "silent";
    
    // Approach 1
    cout << (isAnagramSort(s1, s2) ? "It's Anagram" : "Not Anagram");
    
    // Approach 2
    cout << (isAnagramFreq(s1, s2) ? "Anagram" : "Not Anagram");
    
    // Approach 3
      string s1 = "Listen", s2 = "Silent";
    // Case-insensitive
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    cout << (isAnagramMap(s1, s2) ? "Anagram" : "Not Anagram");
     return 0;
}