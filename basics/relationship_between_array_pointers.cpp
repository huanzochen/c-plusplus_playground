#include <iostream>

using namespace std;

int scores[]{100, 95, 89};

int main()
{

  cout << "scores: " << scores[0] << endl;
  cout << "scores: " << scores[1] << endl;
  cout << "scores: " << scores[2] << endl;
  cout << "scores: " << scores[3] << endl;

  int *scorePtr = {scores};

  cout << "*scorePtr: " << *scorePtr << endl;
  cout << "*scorePtr: " << *(scorePtr + 1) << endl;
  cout << "*scorePtr: " << *(scorePtr + 2) << endl;
  cout << "*scorePtr: " << *(scorePtr + 3) << endl;

  cout << "*scorePtr: " << *(scorePtr) + 1 << endl;
  cout << "*scorePtr: " << *(scorePtr) + 2 << endl;

  cout << *scores << endl;
  cout << *(scores + 1) << endl;
  cout << *(scores + 2) << endl;

  // double[] height
}