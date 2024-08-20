#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  cout << rand() << endl;

  int randTo = 10;
  for (int i = 0; i < randTo; i++)
  {
    cout << "randTo: " << rand() % randTo << endl;
  }
  cout << endl;

  int randTo2 = 10;
  int seed = 999;
  srand(seed);
  for (int i = 0; i < randTo2; i++)
  {
    cout << "randTo: " << rand() % randTo << endl;
  }

  int randTo3 = 1000;
  srand(time(NULL));
  for (int i = 0; i < randTo3; i++)
  {
    cout << "randTo: " << rand() % randTo3 << endl;
  }
}