#include <iostream>

using namespace std;

int main()
{
  int x, y, z;
  x = y = z = 50;
  std::cout << x + y + z << "\n";

  // const is to declare an immutable word
  const double pi = 3.14;
  std::cout << "the const is not able to modify " << pi << std::endl;

  // The compiler above c++14 is able to add ' in the numbers for better readability
  long people_on_earth{7'600'000'000};
  cout << "There are about " << people_on_earth << " people on Earth." << endl;
}