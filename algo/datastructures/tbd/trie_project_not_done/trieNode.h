#ifndef TRIENODE_H
#define TRIENODE_H

// 這是一個被動的資料結構，所以用 struct.
template <typename V>
struct TrieNode
{
  V val = V();
  TrieNode<V> *children[256] = {nullptr};
};


#endif // TRIENODE_H