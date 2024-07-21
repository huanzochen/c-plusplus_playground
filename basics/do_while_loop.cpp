#include <iostream>

using namespace std;

int main()
{

  int integer{};

  do
  {
    cout << "Enter an integer between 0 and 100:" << endl;
    cin >> integer;
  } while (integer < 0 || integer > 100);
  cout << "You entered: " << integer << "\nThanks!" << endl;
}