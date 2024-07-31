#include <iostream>

using namespace std;

int main()
{
  int score = 10;
  int *scorePointer = &score;

  cout << "score: " << score << endl;
  cout << "pointer of score, this indicates the score variable address:\n"
       << scorePointer << endl;
  cout << "print the score value from pointer: " << *scorePointer << endl;

  // Memory address of score, &score
  cout << "================ Score Memory Address Test =================" << endl;
  cout << "Memory address of score, \n&score: " << &score << endl;

  // Reference test
  cout << "================ Reference Test =================" << endl;
  int &scoreRef = score;
  cout << "Reference of scoreRef, it should display the score value \nscoreRef: " << scoreRef << endl;
  cout << "The address of scoreRef, \n&scoreRef: " << &scoreRef << endl;

  int *scoreRefPointer = &scoreRef;
  cout << "It will also display the score value, because scoreRefPointer is another pointer point to scoreRef" << endl
       << "*scoreRefPointer: " << *scoreRefPointer << endl
       << "The score address saved by scoreRefPointer, \nscoreRefPointer: " << scoreRefPointer << endl
       << "The own memory address of scoreRefPointer, \n&scoreRefPointer: " << &scoreRefPointer << endl;
}