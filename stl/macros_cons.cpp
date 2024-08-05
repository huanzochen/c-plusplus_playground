#include <iostream>
using namespace std;
#define SQUARE(a) a *a

#define SQUARE2(a) ((a) * (a))

int main()
{
  // it should be 25
  cout << SQUARE(5) << endl;

  // it expected to be 100 / (5*5) = 4
  // but it actually is 100 / 5 * 5 = 100 !!
  cout << 100 / SQUARE(5) << endl;

  // it should be 25
  cout << SQUARE2(5) << endl;

  // it has be corrected to 4.
  cout << 100 / SQUARE2(5) << endl;
}
