#include <bits/stdc++.h>
using namespace std;

// Trie Node definition
class TrieNode
{
public:
    // Each index represents a lowercase character
    // children[0] -> 'a'
    // children[25] -> 'z'
    TrieNode *children[26];

    // Marks end of a valid word
    bool isEndOfWord;

    // Constructor
    TrieNode()
    {

        // Initially, this node does not end any word
        isEndOfWord = false;

        // No children exist at creation
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};
