#include <bits/stdc++.h>
using namespace std;

/*
👉 Problem Statement — Character Frequency Using Hashing

You are given a string.
Your task is to count the frequency of characters using hashing.

We will handle THREE cases:
1) Only lowercase letters (a–z)
2) Only uppercase letters (A–Z)
3) Mixed characters (ASCII based hashing)
*/

/* -------------------------------------------------- */
/* 1️⃣ ONLY LOWERCASE LETTERS (a–z) */
/* -------------------------------------------------- */

void lowercaseHashing(string s)
{
    int hash[26] = {0};

    for (char c : s)
    {
        hash[c - 'a']++;
    }

    cout << "Lowercase character frequency:\n";
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] > 0)
        {
            cout << char(i + 'a') << " -> " << hash[i] << endl;
        }
    }
}

/* -------------------------------------------------- */
/* 2️⃣ ONLY UPPERCASE LETTERS (A–Z) */
/* -------------------------------------------------- */

void uppercaseHashing(string s)
{
    int hash[26] = {0};

    for (char c : s)
    {
        hash[c - 'A']++;
    }

    cout << "\nUppercase character frequency:\n";
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] > 0)
        {
            cout << char(i + 'A') << " -> " << hash[i] << endl;
        }
    }
}

/* -------------------------------------------------- */
/* 3️⃣ MIXED CHARACTERS (ASCII HASHING) */
/* -------------------------------------------------- */

void asciiHashing(string s)
{
    // ASCII range: 0 to 255
    int hash[256] = {0};

    for (char c : s)
    {
        hash[(int)c]++;
    }

    cout << "\nASCII character frequency:\n";
    for (int i = 0; i < 256; i++)
    {
        if (hash[i] > 0)
        {
            cout << char(i) << " -> " << hash[i] << endl;
        }
    }
}

/* -------------------------------------------------- */
/* MAIN FUNCTION */
/* -------------------------------------------------- */

int main()
{
    string s;
    cin >> s;

    // Call based on requirement
    // lowercaseHashing(s); // use only if string has a–z
    // uppercaseHashing(s); // use only if string has A–Z
    asciiHashing(s); // use for mixed characters

    return 0;
}

/*
Dry Understanding (Mental Model)

-------------------------
Lowercase / Uppercase
hash[index] = frequency
index = char - 'a'  OR  char - 'A'
-------------------------

-------------------------
ASCII Hashing
hash[ASCII value of character] = frequency
-------------------------
Example:

'A' → ASCII 65 → hash[65]
'a' → ASCII 97 → hash[97]
'1' → ASCII 49 → hash[49]

Complexity (All 3)

Time: O(n)
Space: O(1) → constant
Lower / Upper → O(26) → constant
ASCII → O(256) → constant

Interview One-Liners (Very Important)

Lowercase only? → Use int hash[26]
Uppercase only? → Use int hash[26]
Mixed characters? → Use int hash[256]
Unicode? → Use unordered_map<char,int>
 */