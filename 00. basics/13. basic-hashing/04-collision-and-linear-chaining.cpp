#include <bits/stdc++.h>
using namespace std;

/*
👉 Problem Statement — Hash Table with Chaining (Division Method)

You are given a fixed array of integers.
Your task is to:
1) Insert elements into a hash table using the division method.
2) Resolve collisions using chaining.
3) Print the hash table.
4) Search for a given element (18).
*/

int main()
{
    vector<int> arr = {28, 38, 48, 18, 8, 22, 32, 42, 52, 62};
    int tableSize = 10;

    vector<vector<int>> hashTable(tableSize);

    // Insert elements using division method
    for (int x : arr)
    {
        int index = x % tableSize;
        hashTable[index].push_back(x);
    }

    // Print hash table
    for (int i = 0; i < tableSize; i++)
    {
        cout << "Index " << i << ": ";
        for (int val : hashTable[i])
        {
            cout << val << " ";
        }
        cout << endl;
    }

    // Search for element 18
    int key = 18;
    int index = key % tableSize;

    for (int val : hashTable[index])
    {
        if (val == key)
        {
            cout << "Found: " << val << endl;
            break;
        }
    }

    return 0;
}

/*
==================== Key Concepts (Interview Focus) ====================


👉 Hash Function

index = value % tableSize

👉 Collision Resolution

Chaining (store multiple values at same index)

👉 Search Optimization

Do NOT search entire table
Search only at:

value % tableSize


👉 Time & Space Complexity

Insertion
Average: O(1)
Worst (all collide): O(n)

Search
Average: O(1)
Worst: O(n)

Space
O(n + tableSize)


👉 Interview One-Liner

Chaining handles collisions by storing multiple keys at the same index using a linked structure.

*/

/*
==================== DRY RUN ====================

Given:
arr = {28, 38, 48, 18, 8, 22, 32, 42, 52, 62}
tableSize = 10

Hash function:
index = value % 10

Insertion:

28 % 10 = 8  → hashTable[8]  = {28}
38 % 10 = 8  → hashTable[8]  = {28, 38}
48 % 10 = 8  → hashTable[8]  = {28, 38, 48}
18 % 10 = 8  → hashTable[8]  = {28, 38, 48, 18}
 8 % 10 = 8  → hashTable[8]  = {28, 38, 48, 18, 8}

22 % 10 = 2  → hashTable[2]  = {22}
32 % 10 = 2  → hashTable[2]  = {22, 32}
42 % 10 = 2  → hashTable[2]  = {22, 32, 42}
52 % 10 = 2  → hashTable[2]  = {22, 32, 42, 52}
62 % 10 = 2  → hashTable[2]  = {22, 32, 42, 52, 62}

Final Hash Table:

Index 0:
Index 1:
Index 2: 22 32 42 52 62
Index 3:
Index 4:
Index 5:
Index 6:
Index 7:
Index 8: 28 38 48 18 8
Index 9:

Search:

key = 18
18 % 10 = 8

Search only in hashTable[8]:
{28, 38, 48, 18, 8}

18 found → print "Found: 18"

===============================================
*/
