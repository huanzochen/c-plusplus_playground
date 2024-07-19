#include <iostream>

using namespace std;

inline int sum(int a, int b)
{
  return a + b;
}

// int sum(int a, int b)
// {
//   return a + b;
// }

double sum(double a, double b)
{
  cout << "the typeid().name() of a is:\n" << typeid(a).name() << endl;
  return a + b;
}

int main()
{
  // overloading function
  int aInt = 4;
  int bInt = 10;

  cout << sum(aInt, bInt) << endl;

  // overloading function
  double aDouble = 5.2;
  double bDouble = 6.3;

  cout << sum(aDouble, bDouble) << endl;

  // It will be promote to double
  cout << sum(122.2F, 122.4F) << endl;
}