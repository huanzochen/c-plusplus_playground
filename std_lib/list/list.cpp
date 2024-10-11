#include <iostream>
#include <list>

using namespace std;

class Solution {
  list<int> doubleLinkedList;
public:
  // create LinkedList
  Solution(){
    doubleLinkedList = list<int>(4, -1);

    doubleLinkedList.push_front(10);
    doubleLinkedList.push_back(20);
    doubleLinkedList.push_back(30);
    doubleLinkedList.push_front(5);
    printAll(doubleLinkedList);
  }

  void printAll(list<int> lists){
    cout << "lists: ";
    for(auto cur: lists){
      cout << cur << " ";
    }
    cout << endl;
  }

  void addValueAtTheEnd(){
    doubleLinkedList.push_back(10);
    printAll(doubleLinkedList);
  }

  void removeValueAtTheFront(){
    doubleLinkedList.pop_front();
    printAll(doubleLinkedList);
  }

  void eraseWithIterator(){
    doubleLinkedList.erase(doubleLinkedList.begin());
    printAll(doubleLinkedList);
  }

  void removeWithSpecificVal(int val) {
    doubleLinkedList.remove(val);
    printAll(doubleLinkedList);
  }


};

int main()
{
  Solution sol;
  sol.addValueAtTheEnd();
  sol.removeValueAtTheFront();
  sol.eraseWithIterator();
  sol.removeWithSpecificVal(20);

  // If there are multiple vals, it will be remove together.
  sol.removeWithSpecificVal(-1);

  return 0;
}

