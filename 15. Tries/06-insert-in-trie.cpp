#include <bits/stdc++.h>
using namespace std;

/*
    Each TrieNode represents:
    - One character in the Trie
    - 26 possible children (a–z)
    - A flag to mark end of a complete word
*/
class TrieNode
{
public:
    TrieNode *children[26]; // pointers to next characters
    bool isEndOfWord;       // true if a word ends here

    // Constructor: initialize node
    TrieNode()
    {
        isEndOfWord = false;

        // Initially, no children exist
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

/*
    Trie class manages:
    - Root node
    - Insert operation
*/
class Trie
{
private:
    TrieNode *root; // root does NOT store any character

public:
    // Constructor: create empty root node
    Trie()
    {
        root = new TrieNode();
    }

    /*
        Insert a word into the Trie

        Example: "cat"
        root → c → a → t (end)
    */
    void insert(string word)
    {
        // Start traversal from root
        TrieNode *node = root;

        // Traverse each character of the word
        for (char ch : word)
        {
            // Convert character to index (0–25)
            int index = ch - 'a';

            // If path does not exist, create a new node
            if (node->children[index] == nullptr)
            {
                node->children[index] = new TrieNode();
            }

            // Move to the next node
            node = node->children[index];
        }

        // After last character, mark end of word
        node->isEndOfWord = true;
    }
};

int main()
{
    Trie trie;

    // Insert words into the Trie
    trie.insert("cat");
    trie.insert("car");
    trie.insert("dog");

    cout << "Words inserted into Trie successfully.\n";

    
    return 0;
}
