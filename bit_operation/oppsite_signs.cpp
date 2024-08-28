#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool seeIfOpposite(int x, int y)
{
  // do XOR and see if the result is smaller than zero
  if ((x ^ y) < 0)
    return true;

  // else > 0
  return false;
}

int main()
{
  int x = -1, y = 2;

  cout << seeIfOpposite(x, y) << endl;

  cout << seeIfOpposite(10, 15) << endl;
  cout << seeIfOpposite(10, -15) << endl;
}