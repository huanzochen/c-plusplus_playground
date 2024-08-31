#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class Node
{
public:
  int val;
  Node *next;

  // Constructor
  Node(int v)
  {
    val = v;
    next = nullptr;
  }
};

int main()
{

  Node *head = new Node(0);

  head->next = new Node(1);
  head->next->next = new Node(2);
  head->next->next->next = new Node(3);
  head->next->next->next->next = new Node(4);
  head->next->next->next->next->next = new Node(5);

  /*
    我們現在要對一個 linkedlist, 再一次遍歷的時候，隨機返回一個節點的值
    每個節點被隨機抽樣的機率必須是相等的.
  */

  Node *p = head;

  int i = 0;

  // this is the number we will return
  int res = 0;

  srand(time(nullptr));
  while (p != nullptr)
  {
    i++;
    // 生成一個 0 ~ i 的隨機數
    // 0 == 隨機數的機率是 1/i
    // 第一個是 1 ,  n%1 永遠是 0
    // n%2, 有可能是 0,1,  0 的機率是 1/2
    if (0 == rand() % i)
    {
      res = p->val;
    }
    p = p->next;
  }

  cout << "res: " << res;
}