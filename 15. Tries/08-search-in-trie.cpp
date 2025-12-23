#include <bits/stdc++.h>
using namespace std;

/*
    TrieNode represents:
    - One character position in the Trie
    - 26 possible children (a–z)
    - isEndOfWord marks if a complete word ends here
*/
class TrieNode
{
public:
    TrieNode *children[26]; // pointers to next characters
    bool isEndOfWord;       // true if a word ends at this node

    // Constructor: initialize node
    TrieNode()
    {
        isEndOfWord = false;

        // Initially, no child links exist
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

/*
    Trie class:
    - Maintains root node
    - Supports search operation
*/
class Trie
{
private:
    TrieNode *root; // root node (empty character)

public:
    // Constructor: create empty Trie
    Trie()
    {
        root = new TrieNode();
    }

    /*
        Search for a word in the Trie

        Returns:
        - true  → if word exists and ends correctly
        - false → if path breaks or word is incomplete
    */
    bool search(string word)
    {

        // Start traversal from root
        TrieNode *node = root;

        // Traverse each character in the word
        for (char ch : word)
        {

            // Convert character to index (0–25)
            int index = ch - 'a';

            // If required path does not exist,
            // the word was never inserted
            if (node->children[index] == nullptr)
            {
                return false;
            }

            // Move to next node in Trie
            node = node->children[index];
        }

        // After last character:
        // Check if this node marks end of a word
        return node->isEndOfWord;
    }
};

int main()
{
    Trie trie;

    // Manually insert words (for testing search)
    // NOTE: insert() assumed already implemented
    trie.search("cat"); // safe call even if not inserted

    // Example usage scenario:
    cout << "Search completed.\n";

    return 0;
}
