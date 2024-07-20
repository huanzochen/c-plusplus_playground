#include <iostream>

using namespace std;

int main()
{

  int scores[]{100, 95, 89, 68, -1};

  int *scorePtr = scores;

  cout << scorePtr << endl;

  cout << *scorePtr << endl;
  cout << *scorePtr++ << endl;
  cout << *scorePtr++ << endl;
  cout << *scorePtr << endl;
  cout << *scorePtr << endl;

  cout << *(scorePtr + 1) << endl;
}