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
  cout << "With ++a, it will display after increment" << endl << "++a: " << ++a << endl;

  for(auto name: names){
    cout << "name: " << name << endl;
  }
  cout << endl;
  for(auto& current: names) {
    cout << "name: " << current << endl;
  }

}