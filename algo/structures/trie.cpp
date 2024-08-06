#include <iostream>
#include <string>

// 這是一個被動的資料結構，所以用 struct.
template <typename V>
struct TrieNode
{
  v val = V();
  TrieNode<V> *children[256] = {nullptr};
};

template <typename V>
class TrieMap
{
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
  bool hasKeyWithPrefix(string prefix);

  // 通配符 . 匹配任意字符，搜索所有匹配的鍵
  // keysWithPattern(".ip") -> ["rip", "sip", "gip"]
  // keysWithPattern(".i") -> []
  vector<string> keysWithPattern(string prefix);

  // 通配符 . 匹配任意字符，判斷是否存在匹配的鍵
  // hasKeyWithPattern(".ip") -> true
  // hasKeyWithPattern(".i") -> false
  bool hasKeyWithPattern(string pattern);

  // 返回 Map 鍵值對數量
  int size()
};