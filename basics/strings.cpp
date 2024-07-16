#include <iostream>
#include <string>

using namespace std;

int main()
{
  std::string cars[4] = {"Volvo", "BMW", "Ford", "Fiat"};

  // to verify the array contents
  for (int i = 0; i < 4; ++i)
  {
    cout << "Number of cars: " << cars[i] << std::endl;
  }

  return 0;
}