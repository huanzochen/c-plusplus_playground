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
  void put(string key, V val)
  {
    if (!containsKey(key))
    {
      // 新增建值對
      size++;
    }
    // 需要一個額外的輔助函數，並接收其返回值
    root = put(root, key, val, 0);
  }

  TrieNode *put(TrieNode *node, const string &key, V val, int i)
  {
    if (node == nullptr)
    {
      // 如果樹枝不存在，則新建
      node = new TrieNode();
    }
    if (i == key.size())
    {
      // key 的路徑已經插入完成，將值 val 存入節點
      node->val = val;
      return node;
    }
    char c = key[i];
    // 遞歸插入子節點，並接收他的返回值
    node->children[static_cast<unsigned char>(c)] = put(node->children[static_cast<unsigned char>(c)], key, val, i + 1);

    return node;
  }

  // 刪除 key 以及對應的值
  void remove(string key)
  {
    if (!containsKey(key))
    {
      return;
    }
    root = remove(root, key, 0);
    size--;
  }

  TrieNode *remove(TrieNode *node, const string &key, int i)
  {
    // base case
    if (node == nullptr)
    {
      return nullptr;
    }
    if (i == key.size())
    {
      node->val = V();           // Reset to default value
      node->val.isValid = false; // Mark as inValid
    }
    else
    {
      char c = key[i];
      // 遞歸去子樹進行刪除
      node->children[c] = remove(node->children[c], key, i + 1);
    }

    // 後序位置，遞歸路上的節點可能需要被清理
    if (node->val.isValid)
    {
      // 如果該 TrieNode 存儲著 val, 不需要被清理
      return node;
    }
    // 檢查該 node children 是否有東西，也就是是否有後綴
    for (int c = 0; c < R; c++)
    {
      if (node->children[c] != nullptr)
      {
        // 只要存在一個子節點 (後綴樹枝)，就不需要被清理
        return node;
      }
    }

    // 既沒有存儲 val, 也沒有後綴樹枝，則該節點需要被清理
    return nullptr;
  }

  // 判斷 key 是否存在於 Map 中
  bool containsKey(string key)
  {
    return get(key).isValid;
  }

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
      if (p->val.isValid)
      {
        cout << endl
             << "query: " << query << endl;
        cout << "query[i]: " << query[i] << " i: " << i << endl;
        // 找到一個鍵是 query 的前綴
        return query.substr(0, i);
      }
      // 向下搜索
      char c = query[i];
      p = p->children[static_cast<unsigned char>(c)];
    }

    // 到了最後一個節點
    if (p != nullptr && p->val.isValid)
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
    int max_len = 0;
    // 從解點 node 開始搜索 key
    for (int i = 0; i < query.size(); i++)
    {
      if (p == nullptr)
      {
        // 無法向下搜索
        break;
      }
      if (p->val.isValid)
      {
        // 找到一個是 query 的前綴的值
        max_len = i;
      }

      char c = query[i];
      // 因為 char 存在 index 裡（也就是樹枝上，所以這樣去訪問）
      p = p->children[static_cast<unsigned char>(c)];
    }

    // 最後，檢查 p 本身是不是一個鍵
    if (p != nullptr || p->val.isValid)
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
    cout << "path: " << path << endl;
    if (x == nullptr)
    {
      // 到達葉子底部節點
      return;
    }
    if (x->val.isValid)
    {
      // 找到一個 key, 添加到 res 中
      res.push_back(path);
    }
    for (char c = 0; c < R; c++)
    {
      // 做選擇
      path.push_back(c);
      traverse(x->children[static_cast<unsigned char>(c)], path, res);
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
      if (node->val.isValid)
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
        traverseWithPattern(node->children[static_cast<unsigned char>(j)], track, pattern, i, res);
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
  bool hasKeyWithPattern(string pattern)
  {
    return traverseHasKeyWithPattern(root, pattern, 0);
  }

  // 函數定義： 從 node 節點開始匹配 pattern[i...], 返回是否成功匹配
  bool traverseHasKeyWithPattern(TrieNode *root, string pattern, int i)
  {
    // base case
    if (root == nullptr)
    {
      // 樹枝不存在, 匹配失敗
      return false;
    }
    if (i == pattern.size())
    {
      // pattern 走到頭了，看看匹配到的是否是一個鍵
      // 有可能會出現 true 的地方.
      return root->val.isValid;
    }

    char c = pattern[i];
    // 沒有遇到通配符的情況
    if (c != '.')
    {
      // 從 root->children[i] 開始繼續找 pattern[i+1..]
      traverseHasKeyWithPattern(root->children[static_cast<unsigned char>(c)], pattern, i + 1);
    }
    // 大開殺戒了, 遍歷 256 個字元去尋找所有的可能性
    else if (c == '.')
    {
      for (int i = 0; i < R; i++)
      {
        if (traverseHasKeyWithPattern(root->children[i], pattern, i + 1))
        {
          // 只要其中一個有 true, 就 return true.
          return true;
        }
      }
    }
    else
    {
      cout << "traverseHasKeyWithPattern - It should not be here." << endl;
    }
    // 都沒有匹配.
    return false;
  }

  // 這是一個偷懶的實現
  // bool hasKeyWithPattern(string pattern){
  //   return !keyWithPattern(pattern);
  // }

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
    if (x == nullptr || x->val.isValid)
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

// Define a struct to act as a placeholder
struct Placeholder
{
  bool isValid;

  Placeholder() : isValid(true) {}

  bool operator==(const Placeholder &other) const
  {
    return this->isValid == other.isValid;
  }
};

class TrieSet
{
private:
  // 底層用一個 TrieMap, 鍵就是 TrieSet, 值僅作為 placeholder 的作用
  // 值得類型可以隨便設置，樓主參考 java 標準庫設成 object.
  TrieMap<Placeholder> map;

public:
  // **增**
  void add(string &key)
  {
    map.put(key, Placeholder());
  }

  // **刪**
  void remove(string key)
  {
    map.remove(key);
  }

  // **查**
  // 判斷元素 key 是否存在集合中
  bool contains(string &key)
  {
    return map.containsKey(key);
  }

  // 在集合中尋找 query 的最短前綴
  string shortestPrefixOf(string query)
  {
    return map.shortestPrefixOf(query);
  }

  // 在集合中尋找 query 的最長前綴
  string longestPrefixOf(string query)
  {
    return map.longestPrefixOf(query);
  }

  vector<string> keysWithPrefix(string prefix)
  {
    return map.keysWithPrefix(prefix);
  }

  // 判斷集合中是否存在前綴為 prefix 的元素
  bool hasKeyWithPrefix(string prefix)
  {
    return map.hasKeyWithPrefix(prefix);
  }

  vector<string> keysWithPattern(string pattern)
  {
    return map.keysWithPattern(pattern);
  }

  // 通配符 . 匹配任意字符，判斷集合中是否存在匹配 pattern 的元素
  bool hasKeyWithPattern(string pattern)
  {
    return map.hasKeyWithPattern(pattern);
  }

  // 返回集中元素的個數
  int getsize()
  {
    return map.getSize();
  }
};

int main()
{
  TrieSet trie;

  string word1 = "apple";
  string word2 = "app";
  string word3 = "application";
  string word4 = "bat";
  string word5 = "batch";
  string word6 = "batman";

  trie.add(word1);
  trie.add(word2);
  trie.add(word3);
  trie.add(word4);
  trie.add(word5);
  trie.add(word6);

  string prefix1 = "app";
  string prefix2 = "bat";
  string prefix3 = "cat";

  string pattern1 = "b.t";

  cout << "Contains prefix '" << prefix1 << "': " << trie.hasKeyWithPrefix(prefix1) << endl;
  cout << "Contains prefix '" << prefix2 << "': " << trie.hasKeyWithPrefix(prefix2) << endl;
  cout << "Contains prefix '" << prefix3 << "': " << trie.hasKeyWithPrefix(prefix3) << endl;

  cout << "hasKeyWithPrefix ====  " << endl;
  vector<string> b = trie.keysWithPrefix("b");
  for (int i = 0; i < b.size(); i++)
  {
    cout << b[i];
    if (i != b.size() - 1)
      cout << ", ";
  }

  cout
      << "======" << endl;

  cout
      << "Contains pattern '" << pattern1 << "': " << trie.hasKeyWithPattern(pattern1) << endl;

  cout << "shortestPrefixOf: " << trie.shortestPrefixOf(word6) << endl;
  cout << "longestPrefixOf: " << trie.longestPrefixOf(word6) << endl;

  return 0;
}