#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

template <typename V>
class TrieMap
{
private:
  // ASCII character count
  static const int R = 256;
  // Number of key value pairs in the map
  int size = 0;

public:
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

  // 在 Map 中添加 key
  void put(string key, V val);

  // 刪除 key 以及對應的值
  void remove(string key);

  // 判斷 key 是否存在於 Map 中
  bool containsKey(string key);

  // 在 Map 所有鍵中搜索 query 的最短前綴
  // shortestPrefixOf(string query)
  string shortestPrefixOf(string query)
  {
    TrieNode *p = root;
    // 從節點 node 開始搜索 key
    for (int i = 0; i < query.size(); i++)
    {
      if (p == nullptr)
      {
        // 無法向下搜索
        return "";
      }
      if (p->val != nullptr)
      {
        // 找到一個鍵是 query 的前綴
        return query.substr(0, i);
      }
      // 向下搜索
      char c = query[i];
      p = p->children[c];
    }

    // 到了最後一個節點
    if (p != nullptr && p->val != nullptr)
    {
      return query;
    }
    return "";
  }

  // 在 Map 所有鍵中搜索 query 的最長前綴
  // longwstPrefixOf(string query)
  string longestPrefixOf(string query)
  {
    TrieNode *p = root;
    int max_len;
    // 從解點 node 開始搜索 key
    for (int i = 0; i < query.size(); i++)
    {
      if (p == nullptr)
      {
        // 無法向下搜索
        return "";
      }
      if (p->val != nullptr)
      {
        // 找到一個是 query 的前綴的值
        max_len = i;
      }

      char c = query[i];
      // 因為 char 存在 index 裡（也就是樹枝上，所以這樣去訪問）
      p = p->children[c];
    }

    // 最後，檢查 p 本身是不是一個鍵
    if (p != nullptr || p->val != nullptr)
    {
      // 如果 query 本身就是一個鍵
      return query;
    }
    return query.substr(0, max_len);
  }

  // 搜索所有前綴為 prefix 的鍵
  // keysWithPrefix("th") -> ["that", "the", "them"]
  vector<string> keysWithPrefix(string prefix)
  {
    vector<string> res;
    // 找到匹配 prefix 在 Trie 樹的那個節點
    TrieNode *x = getNode(root, prefix);
    // 如果找不到這個節點，說明沒有這個 prefix 啊.
    if (x == nullptr)
    {
      return res;
    }

    traverse(x, prefix, res);
    return res;
  }

  // 遍歷以 node 為根的所有值，找到所有鍵
  void traverse(TrieNode *x, string path, vector<string> &res)
  {
    if (x == nullptr)
    {
      // 到達葉子底部節點
      return;
    }
    if (x->val != V())
    {
      // 找到一個 key, 添加到 res 中
      res.push_back(path);
    }
    for (char c = 0; c < R; c++)
    {
      // 做選擇
      path.push_back(c);
      traverse(x->children[c], path, res);
      path.pop_back();
    }
  }

  // 判斷是和否存在前綴為 prefix 的鍵
  // hasKeyWithPrefix("tha") -> true
  // hasKeyWithPrefix("apple") -> true
  bool hasKeyWithPrefix(string prefix)
  {
    // 只要找到一個 node，就是存在 prefix.
    return getNode(root, prefix) != nullptr;
  };

  // 通配符 . 匹配任意字符，搜索所有匹配的鍵
  // keysWithPattern(".ip") -> ["rip", "sip", "gip"]
  // keysWithPattern(".i") -> []
  vector<string> keysWithPattern(string pattern)
  {
    vector<string> res;
    // The start track absolutely is "".
    traverseWithPattern(root, "", pattern, 0, res);
    return res;
  }

  void traverseWithPattern(TrieNode *node, string track, string pattern, int i, vector<string> &res)
  {
    // base case
    if (node == nullptr)
    {
      // 樹枝不存在，即字符 pattern[i-1] 匹配失敗
      return;
    }
    // 到達對應的長度
    if (i == pattern.size())
    {
      // pattern 匹配完成
      if (node->val != V())
      {
        res.push_back(track);
      }
      return;
    }

    // general case

    char c = pattern[i];
    // 當前 pattern 為通配符, 可以變化成任意字符
    if (c == '.')
    {
      for (char j = 0; j < R; j++)
      {
        track.push_back(j);
        traverseWithPattern(node->children[j], track, pattern, i, res);
        track.pop_back();
      }
    }
    else
    {
      // pattern[i] 是普通字符 c
      track.push_back(c);
      // traverseWithPattern(node->children[c], track, pattern, i, res);
      traverseWithPattern(node->children[static_cast<unsigned char>(c)], track, pattern, i, res);
      track.pop_back();
    }
  }

  // 通配符 . 匹配任意字符，判斷是否存在匹配的鍵
  // hasKeyWithPattern(".ip") -> true
  // hasKeyWithPattern(".i") -> false
  bool hasKeyWithPattern(string pattern);

  // 返回 Map 鍵值對數量
  int getSize() const
  {
    return size;
  };

  // 搜索 key 對應的值，不存在則返回 null
  // get("the") -> 4
  // get("tha") -> null
  V get(string key)
  {
    // 從 root 開始搜索 key
    TrieNode *x = getNode(root, key);
    if (x == nullptr || x->val == V())
    {
      // x 為空或 x 的 val 字段都為空說明 key 沒有對應值
      return V();
    }
    return x->val;
  };

  // Get Trie 對應的 Node, 搜索到了返回 Node.
  // 對以下這句話有疑惑，先繼續看下去
  // 這里需要注意，就算 getNode(key) 的返回值 x 非空，也只能说字符串 key 是一个「前缀」；除非 x.val 同时非空，才能判断键 key 存在。
  TrieNode *getNode(TrieNode *node, const string &key)
  {
    TrieNode *p = node;

    // 從節點 node 開始搜索 key
    for (size_t i = 0; i < key.size(); i++)
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
  };
};

int main()
{
  cout << "hello world!" << endl;

  TrieMap<int> trie;

  return 0;
}