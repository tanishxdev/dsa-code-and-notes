#include <bits/stdc++.h>
using namespace std;

/*
    TrieNode represents one node in the Trie.

    Each node contains:
    - children[26] → pointers for characters 'a' to 'z'
    - isEnd        → true if a complete word ends at this node
*/
class TrieNode
{
public:
    TrieNode *children[26]; // child pointers
    bool isEnd;             // marks end of a word

    // Constructor: initialize a fresh node
    TrieNode()
    {
        isEnd = false;

        // Initially, no child nodes exist
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

/*
    Trie class supports:
    - insert(word)
    - search(word)
    - startsWith(prefix)
*/
class Trie
{
private:
    TrieNode *root; // root node (does not store any character)

public:
    // Constructor: create an empty Trie
    Trie()
    {
        root = new TrieNode(); // empty root
    }

    /*
        Insert a word into the Trie.

        Example:
        insert("cat")
        root → c → a → t (isEnd = true)
    */
    void insert(string word)
    {

        // Start traversal from root
        TrieNode *node = root;

        // Process each character in the word
        for (char ch : word)
        {

            // Convert character to index (0–25)
            int idx = ch - 'a';

            // If the path does not exist, create it
            if (node->children[idx] == nullptr)
            {
                node->children[idx] = new TrieNode();
            }

            // Move to the next node
            node = node->children[idx];
        }

        // After last character, mark end of word
        node->isEnd = true;
    }

    /*
        Search for a complete word in the Trie.

        Returns:
        - true  → word exists
        - false → word does not exist or only prefix exists
    */
    bool search(string word)
    {

        // Start from root
        TrieNode *node = root;

        // Traverse each character
        for (char ch : word)
        {

            int idx = ch - 'a';

            // If path breaks, word is not present
            if (node->children[idx] == nullptr)
                return false;

            // Move to next node
            node = node->children[idx];
        }

        // Word is valid only if it ends here
        return node->isEnd;
    }

    /*
        Check if any word in Trie starts with the given prefix.

        Returns:
        - true  → prefix exists
        - false → prefix does not exist
    */
    bool startsWith(string prefix)
    {

        // Start from root
        TrieNode *node = root;

        // Traverse prefix characters
        for (char ch : prefix)
        {

            int idx = ch - 'a';

            // If path breaks, prefix not found
            if (node->children[idx] == nullptr)
                return false;

            // Move to next node
            node = node->children[idx];
        }

        // All prefix characters found
        return true;
    }
};

int main()
{

    Trie trie;

    // Insert words
    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");

    // Search tests
    cout << "search(\"apple\"): " << trie.search("apple") << endl; // true
    cout << "search(\"app\"): " << trie.search("app") << endl;     // true
    cout << "search(\"ap\"): " << trie.search("ap") << endl;       // false

    // Prefix tests
    cout << "startsWith(\"ap\"): " << trie.startsWith("ap") << endl;   // true
    cout << "startsWith(\"ba\"): " << trie.startsWith("ba") << endl;   // true
    cout << "startsWith(\"cat\"): " << trie.startsWith("cat") << endl; // false

    return 0;
}
