#include <bits/stdc++.h>
using namespace std;

/* ================================
   QUESTION 1: Frequency Query
   ================================ */

// Time Complexity: O(n) for building, O(1) per query
// Space Complexity: O(n) for frequency map
int frequencyQuery(const vector<int> &arr, int q)
{
    unordered_map<int, int> freq;
    for (int x : arr)
    {
        freq[x]++;
    }
    return freq[q];
}

/* ================================
   QUESTION 2: Count Distinct Elements
   ================================ */

// Time Complexity: O(n) average, O(n²) worst-case (collisions)
// Space Complexity: O(n) worst case (all unique)
int countDistinctElement(const vector<int> &arr)
{
    unordered_set<int> s;
    for (int x : arr)
    {
        s.insert(x);
    }
    return s.size();
}

/* ================================
   QUESTION 3: Check Element Presence
   ================================ */

// Time Complexity: O(n) to build set, O(1) to check
// Space Complexity: O(n) for the set
bool checkElementPresence(const vector<int> &arr, int target)
{
    unordered_set<int> s;
    for (int x : arr)
    {
        s.insert(x);
    }
    return s.find(target) != s.end();
}

/* ================================
   QUESTION 4: Character Frequency (Lowercase)
   ================================ */

// Time Complexity: O(n)
// Space Complexity: O(1) - fixed 26 size array
void frequencyOfLowercase(const string &s)
{
    int hash[26] = {0};

    for (char c : s)
    {
        hash[c - 'a']++;
    }

    for (char c : s)
    {
        if (hash[c - 'a'] > 0)
        {
            cout << c << " -> " << hash[c - 'a'] << endl;
            hash[c - 'a'] = 0;
        }
    }
}

/* ================================
   QUESTION 5: Vowel Frequency
   ================================ */

// Time Complexity: O(n)
// Space Complexity: O(1) - fixed array
void frequencyOfVowels(const string &s)
{
    int hash[26] = {0};

    for (char c : s)
    {
        hash[c - 'a']++;
    }

    for (char c : s)
    {
        if ((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') &&
            hash[c - 'a'] > 0)
        {
            cout << c << " -> " << hash[c - 'a'] << endl;
            hash[c - 'a'] = 0;
        }
    }
}

/* ================================
   QUESTION 6: First Repeating Element
   ================================ */

// Time Complexity: O(n)
// Space Complexity: O(n) for frequency map
int firstRepeatingElement(vector<int> &arr)
{
    unordered_map<int, int> freq;

    for (int i = 0; i < arr.size(); i++)
    {
        freq[arr[i]]++;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (freq[arr[i]] > 1)
        {
            return arr[i];
        }
    }

    return -1;
}

/* ================================
   QUESTION 7: First Non-Repeating Character
   ================================ */

// Time Complexity: O(n)
// Space Complexity: O(n) for frequency map
char firstNonRepeatingCharacter(const string &s)
{
    unordered_map<char, int> freq;

    for (char c : s)
    {
        freq[c]++;
    }

    for (char c : s)
    {
        if (freq[c] == 1)
        {
            return c;
        }
    }

    return '-';
}

/* ================================
   QUESTION 8: Check Arrays Equality (Frequency Based)
   ================================ */

// Time Complexity: O(n)
// Space Complexity: O(n) for frequency map
bool checkFrequency(const vector<int> &arr1, const vector<int> &arr2)
{
    if (arr1.size() != arr2.size())
        return false;

    unordered_map<int, int> freq;

    for (int x : arr1)
    {
        freq[x]++;
    }

    for (int x : arr2)
    {
        freq[x]--;
    }

    for (auto &pair : freq)
    {
        if (pair.second != 0)
        {
            return false;
        }
    }

    return true;
}

/* ================================
   QUESTION 9: Digit Frequency
   ================================ */

// Time Complexity: O(d) where d = number of digits
// Space Complexity: O(1) - fixed 10 element array
void countDigitFrequency(long long n)
{
    int hash[10] = {0};

    if (n == 0)
    {
        cout << "0 -> 1" << endl;
        return;
    }

    while (n > 0)
    {
        int digit = n % 10;
        hash[digit]++;
        n /= 10;
    }

    for (int i = 0; i < 10; i++)
    {
        if (hash[i] > 0)
        {
            cout << i << " -> " << hash[i] << endl;
        }
    }
}

/* ================================
   QUESTION 10: Remove Duplicates (Preserve Order)
   ================================ */

// Time Complexity: O(n) average
// Space Complexity: O(n) for the set
void removeDuplicatesPreserveOrder(const vector<int> &arr)
{
    unordered_set<int> seen;

    for (int x : arr)
    {
        if (seen.find(x) == seen.end())
        {
            cout << x << " ";
            seen.insert(x);
        }
    }
    cout << endl;
}

/* ================================
   MAIN FUNCTION - Test All Solutions
   ================================ */
int main()
{
    cout << "=== HASHING PRACTICE SOLUTIONS ===\n\n";

    // Test Q1: Frequency Query
    cout << "Q1: Frequency Query\n";
    vector<int> arr1 = {1, 2, 3, 2, 1, 2};
    int q = 2;
    cout << "Array: ";
    for (int x : arr1)
        cout << x << " ";
    cout << "\nQuery: " << q;
    cout << "\nFrequency: " << frequencyQuery(arr1, q) << "\n\n";

    // Test Q2: Count Distinct Elements
    cout << "Q2: Count Distinct Elements\n";
    vector<int> arr2 = {1, 2, 2, 3, 4, 4, 4};
    cout << "Array: ";
    for (int x : arr2)
        cout << x << " ";
    cout << "\nDistinct count: " << countDistinctElement(arr2) << "\n\n";

    // Test Q3: Check Element Presence
    cout << "Q3: Check Element Presence\n";
    vector<int> arr3 = {10, 20, 30, 40};
    int target = 30;
    cout << "Array: ";
    for (int x : arr3)
        cout << x << " ";
    cout << "\nTarget: " << target;
    cout << "\nResult: " << (checkElementPresence(arr3, target) ? "Exists" : "Does not exist") << "\n\n";

    // Test Q4: Character Frequency
    cout << "Q4: Character Frequency (Lowercase)\n";
    string s4 = "abac";
    cout << "String: " << s4 << endl;
    frequencyOfLowercase(s4);
    cout << endl;

    // Test Q5: Vowel Frequency
    cout << "Q5: Vowel Frequency\n";
    string s5 = "education";
    cout << "String: " << s5 << endl;
    frequencyOfVowels(s5);
    cout << endl;

    // Test Q6: First Repeating Element
    cout << "Q6: First Repeating Element\n";
    vector<int> arr6 = {1, 2, 3, 2, 1};
    cout << "Array: ";
    for (int x : arr6)
        cout << x << " ";
    cout << "\nFirst repeating: " << firstRepeatingElement(arr6) << "\n\n";

    // Test Q7: First Non-Repeating Character
    cout << "Q7: First Non-Repeating Character\n";
    string s7 = "aabbcdde";
    cout << "String: " << s7;
    cout << "\nFirst non-repeating: " << firstNonRepeatingCharacter(s7) << "\n\n";

    // Test Q8: Check Arrays Equality
    cout << "Q8: Check Arrays Equality\n";
    vector<int> arr8a = {1, 2, 3, 2};
    vector<int> arr8b = {2, 1, 2, 3};
    cout << "Array 1: ";
    for (int x : arr8a)
        cout << x << " ";
    cout << "\nArray 2: ";
    for (int x : arr8b)
        cout << x << " ";
    cout << "\nAre they equal? " << (checkFrequency(arr8a, arr8b) ? "Yes" : "No") << "\n\n";

    // Test Q9: Digit Frequency
    cout << "Q9: Digit Frequency\n";
    long long num = 120312;
    cout << "Number: " << num << endl;
    countDigitFrequency(num);
    cout << endl;

    // Test Q10: Remove Duplicates
    cout << "Q10: Remove Duplicates (Preserve Order)\n";
    vector<int> arr10 = {1, 2, 3, 2, 1, 4, 5, 3};
    cout << "Original: ";
    for (int x : arr10)
        cout << x << " ";
    cout << "\nWithout duplicates: ";
    removeDuplicatesPreserveOrder(arr10);

    return 0;
}