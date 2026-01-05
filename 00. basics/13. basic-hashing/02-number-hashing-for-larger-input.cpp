#include <bits/stdc++.h>
using namespace std;

/*
👉 Problem Statement — Frequency of Elements in an Array

You are given an integer n, followed by n integers representing an array.

Your task is to count the frequency of each distinct element in the array
and print each element along with the number of times it appears.

Input:
- First line contains an integer n (size of array)
- Second line contains n space-separated integers

Output:
- For each distinct element, print:
  element -> frequency

Note:
- Output order is not guaranteed (unordered_map is used)
*/

// Function to print frequency of elements in an array
void printFrequency(const vector<int> &arr)
{
    // Step 4: Create an unordered_map to store frequency
    // Key   -> number from array
    // Value -> how many times that number appears
    // unordered_map gives average O(1) insertion & lookup
    unordered_map<int, int> freq;

    // Step 5: Count frequency of each element
    // Range-based for loop iterates over each element in arr
    for (int x : arr)
    {
        // If x is already present, increment its count
        // If not present, it is created with initial value 0,
        // then incremented to 1
        freq[x]++;
    }

    // Step 6: Print the frequency map
    // 'it.first'  -> key (array element)
    // 'it.second' -> value (frequency)
    for (auto it : freq)
    {
        cout << it.first << " -> " << it.second << "\n";
    }
}

int main()
{
    // Step 1: Read size of the array
    // 'n' represents how many elements the user will input
    int n;
    cin >> n;

    // Step 2: Create a vector of size n
    // Vector is a dynamic array that can grow/shrink automatically
    vector<int> arr(n);

    // Step 3: Read n elements into the vector
    // arr[i] stores the ith input value
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Step 7: Call the function to print frequencies
    printFrequency(arr);

    return 0;
}

// Complexity Analysis

// Time Complexity: O(n) average
// Space Complexity: O(n) (for hashmap)

// Since the values are not in a fixed range, unordered_map is preferred over an array for frequency counting.