#include <iostream>
#include <string>

using namespace std;

template <typename V>
class TrieMap
{
private:
  // ASCII character count
  static const int R = 256;
  // Number of key value pairs in the map
  int size = 0;

  // 這是一個被動的資料結構，所以用 struct.
  struct TrieNode
  {
    V val;
    array<TrieNode *, 256> children;

    // Constructor
    TrieNode() : val(V())
    {
      children.fill(nullptr);
    }

    ~TrieNode()
    {
      for (TrieNode *child : children)
      {
        delete child;
      }
    }
  };

  // Root node of the Trie
  TrieNode *root = nullptr;

public:
  // 在 Map 中添加 key
  void put(string key, V val);

  // 刪除 key 以及對應的值
  void remove(string key);

  // 搜索 key 對應的值，不存在則返回 null
  // get("the") -> 4
  // get("tha") -> null
  V get(string key);

  // 判斷 key 是否存在於 Map 中
  bool containsKey(string key);

  // 在 Map 所有鍵中搜索 query 的最短前綴
  // shortestPrefixOf(string query)
  string shortestPrefixOf(string query);

  // 在 Map 所有鍵中搜索 query 的最長前綴
  // longwstPrefixOf(string query)
  string longestPrefixOf(string query);

  // 搜索所有前綴為 prefix 的鍵
  // keysWithPrefix("th") -> ["that", "the", "them"]
  vector<string> keysWithPrefix(string prefix);

  // 判斷是和否存在前綴為 prefix 的鍵
  // hasKeyWithPrefix("tha") -> true
  // hasKeyWithPrefix("apple") -> true
  bool hasKeyWithPrefix(string prefix)
  {
    // 只要找到一個 node，就是存在 prefix.
    return getNode(root, prefix);
  }

  // 通配符 . 匹配任意字符，搜索所有匹配的鍵
  // keysWithPattern(".ip") -> ["rip", "sip", "gip"]
  // keysWithPattern(".i") -> []
  vector<string> keysWithPattern(string prefix);

  // 通配符 . 匹配任意字符，判斷是否存在匹配的鍵
  // hasKeyWithPattern(".ip") -> true
  // hasKeyWithPattern(".i") -> false
  bool hasKeyWithPattern(string pattern);

  // 返回 Map 鍵值對數量
  int getSize() const
  {
    return size;
  }

  V get(string key)
  {
    // 從 root 開始搜索 key
    TrieNode<V> x = getNode(root, key);
    if (x == null || x.val == null)
    {
      // x 為空或 x 的 val 字段都為空說明 key 沒有對應值
      return null;
    }
    return x.val;
  }

  // Get Trie 對應的 Node, 搜索到了返回 Node.
  // 對以下這句話有疑惑，先繼續看下去
  // 這里需要注意，就算 getNode(key) 的返回值 x 非空，也只能说字符串 key 是一个「前缀」；除非 x.val 同时非空，才能判断键 key 存在。
  TrieNode<V> *getNode(TrieNode<V> *node, const string &key)
  {
    TrieNode<V> *p = node;

    // 從節點 node 開始搜索 key
    for (size_t i = 0; i < key.length; i++)
    {
      if (p == nullptr)
      {
        // reach the end of the node
        return nullptr;
      }

      // There is still nodes to traverse
      char c = key[i];
      // p = p->children[c]
      // do i need unsigned char?
      p = p->children[static_cast<unsigned char>(c)];
    }

    return p;
  }
};