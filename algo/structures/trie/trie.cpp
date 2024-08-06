#include <iostream>
#include <string>

#include "trieMap.h"

template <typename V>
int TrieMap<V>::getSize() {
  return this->size;
}

template class TrieMap<int>; // Example for int type
template class TrieMap<std::string>; // Example for std::string type