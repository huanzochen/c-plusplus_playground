#include <iostream>
using namespace std;

int main()
{
  // default
  cout << (true == false) << endl;

  cout << std::boolalpha;
  cout << (true == false) << endl;

  cout << std::noboolalpha;
  cout << (true == false) << endl;
}