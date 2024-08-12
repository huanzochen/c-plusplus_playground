#include <iostream>
#include <list>

using namespace std;

int main()
{

  list<int> p1(4, 100);

  // out put the elements of the list
  for (auto value : p1)
  {
    cout << value << " ";
  }
  cout << endl;

  p1.push_back(10);
  p1.push_front(20);
  p1.push_back(30);

  for (auto cur : p1)
  {
    cout << cur << " ";
  }
  cout << endl;

  return 0;
}