// #define,  # is pound symbol.
// Macros, #define
// The pre-processor don't know how C++ works, it only do find, and replace.

#include <iostream>
using namespace std;

#define MAX(a, b) ((a > b) ? a : b)

int main()
{
  cout << MAX(10, 20) << endl;
  cout << MAX(2.5, 3.5) << endl;
  cout << MAX('a', 'c') << endl;
}