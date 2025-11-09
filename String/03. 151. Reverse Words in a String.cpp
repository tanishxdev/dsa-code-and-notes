#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem : Reverse Words in a String (with and without extra space)
// Example : 
// Constraint : 

// 🔴 Approach 1 Brute Force : 
// Intuition :
// Algo :
// TC :
// SC :
string reverseWords(string s) {
    stringstream ss(s); // stringstream auto skips extra spaces
    string word; // to store each word
    vector<string> words; // to store all words

    // 1.Step 1: Extract words from string
    while (ss >> word) // skips extra spaces automatically
    {
        words.push_back(word); // store the word
    }

    // Step 2: Reverse order of words
    reverse(words.begin(), words.end()); // reverse the vector
    
    // Step 3: Join words with space
    string result = "";

    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i < words.size() - 1) result += " "; // add space between words
    }
    return result;
    
}

// 🔵 Approach 2 Better : 
// Intuition :
// Algo :
// TC :
// SC :

// 🟢 Approach 3 Optimal:  In-place
// Intuition : To reduce space, we can do reversal inside the same string.

// Algo :
// Reverse the entire string.
// Then reverse each word individually to restore word order.

// TC :
// SC :

int main()
{
    string s = "  I   love   DSA  ";
    
    // Approach 1
    cout << reverseWords(s); // Output: "DSA love I"
    return 0;
}