#include <iostream>
#include <vector>
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

    currentNode->wordEnd = true;
  }

  bool searchKey(TrieNode *node, const string &key)
  {
    // Initialize the curr pointer with the root node
    TrieNode *curr = node;

    // Iterate across the length of the string
    // string iteration
    for (auto c : key)
    {
      // Directly check if the current node exists?
      if (curr->childNode[c - 'a'] == nullptr)
      {
        return false;
      }
      curr = curr->childNode[c - 'a'];
    }
    // Return true if the current key exists.
    // false means the complete word is not existing.
    return curr->wordEnd;
  }

  bool hasPrefix(TrieNode *root, const string &key)
  {
    // start to iterate through the tree to find the shortest prefix
    for (char c : key)
    {
      if (root->wordEnd)
        return true;
      if (root->childNode[c - 'a'] == nullptr)
        return false;
      // Go to the child node
      root = root->childNode[c - 'a'];
    }
    return false;
  }

  string shortestPrefixOf(TrieNode *root, const string &key)
  {
    // start to iterate through the tree to find the shortest prefix
    for (int i = 0; i < key.size(); i++)
    {
      if (root->wordEnd)
      {
        return key.substr(0, i);
      }

      if (root->childNode[key[i] - 'a'] == nullptr)
        return "";
      // Go to the child node
      root = root->childNode[key[i] - 'a'];
    }
    return "";
  }

  string longestPrefixOf(TrieNode *root, const string &key)
  {
    int max_len = -1;
    // start to iterate through all the keys, and try to find which is wordEnd == true;
    for (int i = 0; i < key.size(); i++)
    {
      // If find a word, update the index.
      if (root->wordEnd)
      {
        max_len = i;
      }
      // current char
      char c = key[i];
      // no exists word, no possibilities to find the rest.
      if (root->childNode[c - 'a'] == nullptr)
        return "";
      // means there are child to find
      root = root->childNode[c - 'a'];
    }
    return max_len == -1 ? "" : key.substr(0, max_len);
  }

  TrieNode *getNode(TrieNode *root, const string &key)
  {
    for (auto c : key)
    {
      // if root == nullptr, 無法向下搜索
      if (root == nullptr)
        return nullptr;
      root = root->childNode[c - 'a'];
    }
    return root;
  }

  vector<string> keysWithPrefix(TrieNode *root, const string &key)
  {
    vector<string> res;
    // current track for saving temp value iterated.
    string track = key;

    // first, go to the prefix node to start the iteration.
    root = getNode(root, key);
    if (root == nullptr)
      return res;

    // search for keys with Prefix, traverse down and try to find.
    traverse(root, res, key, track);

    return res;
  }

  void traverse(TrieNode *root, vector<string> &res, const string &key, string &track)
  {
    // base case
    if (root == nullptr)
      return;
    if (root->wordEnd)
    {
      // cout << "find a word, save the word into res." << endl
      //      << "The word is: " << track << endl;
      res.push_back(track);
    }

    // Go SPREAD!! and find the word has this prefix!
    for (int i = 0; i < ALPHABETS_SIZE; i++)
    {
      track.push_back('a' + i);
      traverse(root->childNode[i], res, key, track);
      track.pop_back();
    }
  }

  bool getWordEnd()
  {
    return this->wordEnd;
  }

  void print_current_child(TrieNode *node)
  {
    // base case
    if (node == nullptr)
    {
      cout << "This is not a node.";
      return;
    }

    // general case
    if (node != nullptr && node->wordEnd)
    {
      cout << endl
           << "This is the last node with a complete word." << endl;
    }
    for (int i = 0; i < ALPHABETS_SIZE; i++)
    {
      // cout << "i: " << i << " ,";
      if (node->childNode[i] != nullptr)
      {
        // 如果這個值是 false, 代表該字串不在尾端
        // true 是在尾端
        cout << endl
             << "======= find Child! =======" << endl;
        cout << "child i: " << i << " , it equals to char: " << char(i + 'a') << endl;
        cout << node->childNode[i] << " : " << node->childNode[i]->getWordEnd();

        print_current_child(node->childNode[i]);
      }
      else
      {
        // This is the pointer of the node, if nothing contains, it is 0x0.
        // cout << node->childNode[i];
      }
      // if (i != ALPHABETS_SIZE - 1)
      //   cout << ", ";
    }
    cout << endl
         << "for loop done on this layer." << endl;
  }
};

int main()
{
  TrieNode *node = new TrieNode;
  // cout << "node->getWordEnd(): " << node->getWordEnd() << endl;

  vector<string> materials{"that", "flat", "flatten", "app", "apple", "applicant", "application", "applic"};

  for (auto current : materials)
  {
    node->insert_key(node, current);
  }

  cout << "=========" << endl;
  for (auto current : materials)
  {
    cout << "searchKey: " << current << ", " << node->searchKey(node, current) << endl;
  }

  cout << "=========" << endl;
  for (auto current : materials)
  {
    cout << "hasPrefix: " << current << ", " << node->hasPrefix(node, current) << endl;
  }

  cout << "=========" << endl;
  for (auto current : materials)
  {
    cout << "shortestPrefixOf: " << current << ": " << node->shortestPrefixOf(node, current) << endl;
  }

  cout << "=========" << endl;
  for (auto current : materials)
  {
    cout << "longestPrefixOf: " << current << ": " << node->longestPrefixOf(node, current) << endl;
  }

  cout << "=========" << endl;
  cout << "keysWithPrefix app: " << endl;
  vector<string> appResult = node->keysWithPrefix(node, "app");
  for (int i = 0; i < appResult.size(); i++)
  {
    cout << appResult[i];
    if (i != appResult.size() - 1)
      cout << ", ";
  }
  cout << endl;

  delete node;
  return 0;
}