#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
  const int temp{*a};
  *a = *b;
  *b = temp;
}

int main()
{

  int x = 100;
  int y = 200;

  cout << "x: " << x << ", " << "y: " << y << endl;

  swap(&x, &y);

  // Now the x & y has been swap
  cout << "x: " << x << ", " << "y: " << y << endl;
}