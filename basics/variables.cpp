#include <iostream>

int main()
{
  int x, y, z;
  x = y = z = 50;
  std::cout << x + y + z << "\n";

  // const is to declare an immutable word
  const double pi = 3.14;
  std::cout << "the const is not able to modify " << pi << std::endl;
}