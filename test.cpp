#include <bits/stdc++.h>
using namespace std;

// ⭐ Approach 1:
// ⭐ Approach 2:
// ⭐ Approach 3:

int main()
{
    vector<int> arr = {28, 38, 48, 18, 8, 22, 32, 42, 52, 62};
    int tableSize = 10;

    vector<vector<int>> hashTable(tableSize);

    for (int x : arr)
    {
        int index = x % tableSize;
        hashTable[index].push_back(x);
    }

    for(int i = 0; i < tableSize; i++)
    {
        cout << "Index " << i << ": ";
        for(int val : hashTable[i])
            cout << val << " ";
        cout << endl;
    }

    int key = 18;
    int index = key % tableSize;

    for(int val : hashTable[index])
    {
        if(val == key)
        {
            cout << key << " found at index " << index << endl;
            break;
        }
    }
}