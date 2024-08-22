#include <iostream>
#include <set>

using namespace std;

int main()
{

  set<int> digit{1, 3, 10, 4};

  auto it = digit.find(3);

  cout << "*it: " << *it << endl;
  cout << "*(--it): " << *(--it) << endl;
  cout << "*(++it): " << *(++it) << endl;
  cout << "*(++it): " << *(++it) << endl;
  cout << "*(++it): " << *(++it) << endl;
}