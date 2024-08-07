#include <iostream>
#include <string>

using namespace std;

struct TrieNode
{
private:
  static const int ALPHABETS_SIZE{26};

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

      // Move to the next node to save another char.
      currentNode = currentNode->childNode[c - 'a'];
    }
  }

  bool getWordEnd()
  {
    return this->wordEnd;
  }

  void print_current_child(TrieNode *node)
  {
    cout << "node->children[26]: ";
    for (int i = 0; i < ALPHABETS_SIZE; i++)
    {
      cout << endl << "i: " << i << " ";
      if (node->childNode[i] != nullptr)
      {
        // 如果這個值是 false, 代表該字串不在尾端
        // true 是在尾端
        cout << node->childNode[i] << " : " << node->childNode[i]->getWordEnd();
      }
      else
      {
        cout << node->childNode[i];
      }
      if (i != ALPHABETS_SIZE - 1)
        cout << ", ";
    }
  }
};

int main()
{
  TrieNode *node = new TrieNode;

  string one = "that";

  node->insert_key(node, one);

  cout << "node->getWordEnd(): " << node->getWordEnd() << endl;

  node->print_current_child(node);

  return 0;
}