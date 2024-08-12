#include <iostream>

using namespace std;
class Node
{
public:
  int key;
  int val;

  Node *next;
  Node *prev;

  Node(int key, int value) : key{key}, val{value}
  {
    next = nullptr;
    prev = nullptr;
  }

  ~Node()
  {
  }
};

class DoubleLinkedList
{
  Node *head;
  Node *tail;

public:
  DoubleLinkedList()
  {
    head = new Node(0, 0);
    tail = new Node(0, 0);

    // make connection
    head->next = tail;
    tail->prev = head;
  }

  ~DoubleLinkedList()
  {
    // Delete all nodes between head and tail
    Node *current = head;
    while (current != nullptr)
    {
      Node *nextNode = current->next;
      delete current;
      current = nextNode;
    }
  }

  void addLast(int key, int val)
  {
    Node *newNode = new Node(key, val);

    newNode->prev = tail->prev;
    newNode->next = tail;
    tail->prev->next = newNode;
    // 最後再洗掉，要對 tail->prev 做一些事
    tail->prev = newNode;
  }

  // 刪除鏈表中的 x 節點 (x 一定存在)
  // 由於是雙鏈表而且給的是特定 Node 節點, 時間 O(1)
  void remove(Node *x)
  {
    // 把 x 抽掉
    x->next->prev = x->prev;
    x->prev->next = x->next;
  }

  // 刪除鏈表中的第一個節點，並返回該節點，時間 O(1)
  Node *removeFirst()
  {
    if (head->next == tail)
    {
      return nullptr;
    }
    Node *first = head->next;
    remove(first);
    return first;
  }

  void printAllNode()
  {
    Node *p1 = this->head;
    cout << "=======printAllNode" << endl;
    while (p1 != nullptr)
    {
      cout << "p1->key: " << p1->key << " ,val: " << p1->val << " ";
      p1 = p1->next;
    }
    cout << "================" << endl;
  }
};

int main()
{
  DoubleLinkedList du;

  du.addLast(2, 12);
  du.addLast(3, 34);
  du.printAllNode();
}