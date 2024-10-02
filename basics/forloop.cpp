#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<string> names = {"Tommy", "Keven", "Alex", "Steven"};

  for (int i = 0; i < names.size(); i++)
  {
    const string current = names[i];
    cout << "Index: " << i << " ";
    cout << current << endl;
  }
  cout << endl;
  for (int i = 0; i < names.size(); ++i)
  {
    const string current = names[i];
    cout << "Index: " << i << " ";
    cout << current << endl;
  }

  int a = 0;
  cout << "a++: " << a++ << endl;
  cout << "With ++a, it will display after increment" << endl
       << "++a: " << ++a << endl;

  for (auto name : names)
  {
    cout << "name: " << name << endl;
  }
  cout << endl;
  for (auto &current : names)
  {
    cout << "name: " << current << endl;
  }

  // run a code that will not run

  vector<int> nums(0);

  for (int i = 0; i < nums.size(); i++)
  {
    cout << "It will not run?" << endl;
  }

  vector<int> nums2{1, 2};

  for (int i = 2; i < nums2.size(); i++)
  {
    cout << "It will not run?" << endl;
  }
}