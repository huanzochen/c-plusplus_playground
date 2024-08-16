#include <iostream>

using namespace std;

class Node
{
public:
  int key;
  int val;
  Node *prev;
  Node *next;

  Node(int key, int value)
  {
    this->key = key;
    this->val = value;
    prev = nullptr;
    next = nullptr;
  }
};

class DoubleLinkedList
{
public:
  Node *head;
  Node *tail;

  DoubleLinkedList()
  {
    head = new Node(0, 0);
    tail = new Node(0, 0);
    head->next = tail;
    tail->prev = head;
  }

  // add to the last of the node
  void addLast(int key, int value)
  {
    // add node to the last element.
    Node *newNode = new Node(key, value);
    newNode->next = tail;
    newNode->prev = tail->prev;
    tail->prev->next = newNode;
    tail->prev = newNode;
  }

  // remove a node in the linkedlist
  void remove(Node *node)
  {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void removeFirst()
  {
    if (head->next == tail)
    {
      return;
    }
    Node *first = head->next;
    head->next = first->next;
    first->next->prev = head;
    remove(first);
  }

  void printAll()
  {
    Node *current = head->next;
    while (current != nullptr)
    {
      cout << "current->key: " << current->key << " "
           << "current->val: " << current->val << " ";
      current = current->next;
    }
  }
};

int main()
{
  DoubleLinkedList dl;

  dl.addLast(2, 33);
  dl.addLast(3, 44);

  dl.printAll();
}