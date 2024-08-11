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

  int size() { return size; }
};