#include <iostream>
#include <string>

using namespace std;

struct TrieNode
{
private:
  // pointer array for child nodes of each node
  TrieNode *childNode[26];

  // Used for indicating ending of string
  bool wordEnd;

public:
  // Constructor
  TrieNode()
  {
    // constructor
    // initialize all the wordEnd variable with false
    // initialize all the index of childNode array with NULL
    wordEnd = false;
    for (int i = 0; i < 26; i++)
    {
      childNode[i] = nullptr;
    }
  }

  void insert_key(TrieNode *root, string &key)
  {
    // Initialize he currentNode pointer
    // with the root node
    TrieNode *currentNode = root;

    // Iterate across the length of the string
    for (auto c : key)
    {

      // Check if the node exist for the current
      // character in the Trie
      if (currentNode->childNode[c - 'a'] == nullptr)
      {
        // If node for current character does not exist
        // then make a new node
        TrieNode *newNode = new TrieNode();

        // Keep the reference for the newly created node.
        currentNode->childNode[c - 'a'] = newNode;
      }
    }
  }
};

int main()
{

  return 0;
}