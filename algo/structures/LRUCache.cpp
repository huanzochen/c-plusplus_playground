#include <iostream>
#include <unordered_map>

using namespace std;

class Node
{
public:
  int key;
  int val;

  Node *next; // pointer to the next node.
  Node *prev; // pointer to the previous node.

  // Constructor
  Node(int k, int v) : key{k}, val{v}, next{nullptr}, prev{nullptr}
  {
  }
};

class DoubleLinkedList
{
public:
  Node *head;
  Node *tail;
  int size;

  // Constructor
  DoubleLinkedList() : size{0}
  {
    head = new Node(0, 0);
    tail = new Node(0, 0);

    (*head).next = tail;
    (*tail).prev = head;
  }

  ~DoubleLinkedList()
  {
    delete head;
    delete tail;
  }

  // 在尾部添加新節點 x, 時間 O(1)
  void addLast(Node *x)
  {
    x->prev = tail->prev;
    x->next = tail;
    tail->prev->next = x;

    // 最後再把 tail->prev 洗成 x
    tail->prev = x;
    size++;
  }

  // 刪除鏈表中的 x 節點 (x 一定存在)
  // 由於是雙鏈表而且給的是特定 Node 節點, 時間 O(1)
  void remove(Node *x)
  {
    x->prev->next = x->next;
    x->next->prev = x->prev;
    size--;
  }

  // 刪除鏈表中的第一個節點，並返回該節點，時間 O(1)
  Node *removeFirst()
  {
    if (head->next == tail)
      return nullptr;
    Node *first = head->next;
    remove(first);
    return first;
  }
};

class LRUCache
{
public:
  int get(int key)
  {
    if (map.count(key) == 0)
    {
      return -1;
    }
    // 將該數據提升為最常使用的
    makeRecently(key);
    return map[key]->val;
  }

  void put(int key, int val)
  {
    // 如果 key 存在的話，將其提升為最近使用的數據
    // 如果 key 不存在的話，插入這個新 key,
    // 如果容量已滿，淘汰舊的 key
    // 插入新的 key，將其提升為最近使用的數據
    if (map.count(key) > 0)
    {
      // makeRecently(key); 這樣做不會更新 value
      deleteKey(key);
      addRecently(key, val);
      return;
    }
    if (cache->size == cap)
    {
      removeLeastRecently();
    }
    addRecently(key, val);
  }

private:
  // key -> Node(key, val)
  unordered_map<int, Node *> map;
  // Node(k1, v1) <-> Node(k2, v2)
  DoubleLinkedList *cache;
  // 最大容量
  int cap;

  // 如果這個 node 已經在 cache 裡面，重新被在用一次
  void makeRecently(int key)
  {
    Node *x = map[key];
    // 先從鏈表中刪除這個節點
    cache->remove(x);
    cache->addLast(x);
  }

  // 添加最近使用的元素,  因為添加了一定是 recently(最近使用的)，所以有這個就夠.
  void addRecently(int key, int val)
  {
    Node *newNode = new Node(key, val);
    // 在 cache 中新增這個 node 到最末端
    cache->addLast(newNode);
    // 在 map 中新增這個 new Node 的映射
    map[key] = newNode;
  }

  // 刪除某一個 key (直接刪除某一個 key)
  void deleteKey(int key)
  {
    Node *x = map[key];
    cache->remove(x);
    map.erase(key);
  }

  void removeLeastRecently()
  {
    // 鏈表的第一個值就是最久沒被使用的
    Node *deletedNode = cache->removeFirst();
    // 同時別忘了從 map 中刪除他的 key
    map.erase(deletedNode->key);
  }

public:
  // Constructor
  LRUCache(int capacity) : cap{capacity}, map(), cache{new DoubleLinkedList()}
  {
  }
};

int main()
{
  LRUCache lru(3);

  lru.put(1, 10);
  lru.put(2, 11);
  lru.put(3, 17);

  cout << "lru.get(1): " << lru.get(1) << endl;
  lru.put(4, 11);

  // 因為 1 被提升了，因此存在，但是 2 應該會被篩掉
  cout << "lru.get(1): " << lru.get(1) << endl;
  cout << "lru.get(2): " << lru.get(2) << endl;
  // 3 仍然存在
  cout << "lru.get(3): " << lru.get(3) << endl;
  // 4 也存在
  cout << "lru.get(4): " << lru.get(4) << endl;

  lru.put(1, 22);
  // 1 會被更新成新值，並且 makeRecently
  cout << "lru.get(1): " << lru.get(1) << endl;

  lru.put(5, 77);
  // 加入 5 後，最後面的會被刷掉，在這裏，最後面的應該是 3 了
  // 果然被刷掉了
  cout << "lru.get(3): " << lru.get(3) << endl;
}