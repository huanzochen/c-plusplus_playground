#include <iostream>

using namespace std;

void r_value_func(int &&num)
{
  cout << "a func that receives r_value num: " << num << endl;
}

void l_value_func(int &num)
{
  cout << "a func that receives l_value num: " << num << endl;
}

int main()
{
  int x = 1000;

  r_value_func(100);
  // This will cause error because it is not able to receive r-value func.
  // r_value_func(x);

  // This will cause error because it is not able to receive r-value.
  // l_value_func(200);
  l_value_func(x);
}