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

  string bmw = "BMW";
  cout << "bmw[1]: " << bmw[1] << endl;

  return 0;
}