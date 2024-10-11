#include <list>
#include <iostream>

using namespace std;

class Solution{
  public:
  list<int> dl;
  unordered_map<int,list<int>::iterator> nodeMap;

  Solution(){

    dl.push_back(10);
    nodeMap[10] = prev(dl.end());
    dl.push_back(20);
    nodeMap[20] = prev(dl.end());
    dl.push_back(25);
    nodeMap[30] = prev(dl.end());
    dl.push_back(30);
    nodeMap[30] = prev(dl.end());
    dl.push_back(35);
    nodeMap[35] = prev(dl.end());
    dl.push_back(40);
    nodeMap[40] = prev(dl.end());
    printList();
  }

  bool deleteKeyWith(int key){
    if(nodeMap.count(key) == 0) {
      cout <<  "no exist key" << endl;
      return false;
    }

    // erase from dl through iterator.
    dl.erase(nodeMap[key]);

    // erase from map through value.
    nodeMap.erase(key);

    cout << "erase done." << endl;;
    printList();
    return true;
  }

  bool deleteKeyWithSearchingIterator(int key){
    unordered_map<int, list<int>::iterator>::iterator it = nodeMap.find(key);
    if(nodeMap.find(key) == nodeMap.end()){
      cout << "not found." << endl;;
      return false;
    }

    dl.erase(it->second);
    nodeMap.erase(key);

    printf("erase %d done. ", key);
    printList();
    return true;
  }

  int getValueWithKey(int key){
    if(nodeMap.count(key) == 0) return -1;

    return *nodeMap[key];
  }

  void printList(){
    cout << "list: ";
    for(auto cur: dl){
      cout << cur << " ";
    }
    cout << endl;
  }
};

int main() {
  Solution sol;
  sol.deleteKeyWith(10);
  sol.deleteKeyWithSearchingIterator(10);
  sol.deleteKeyWithSearchingIterator(20);
  sol.deleteKeyWithSearchingIterator(35);

  cout << "getValueWithKey(30): " << sol.getValueWithKey(30) << endl;;

}