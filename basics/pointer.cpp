#include <iostream>

using namespace std;

int main() {
  int score = 10;
  int *scorePointer = &score;

  cout << "score: " << score << endl;
  cout << "pointer of score, this indicates the score variable address:\n" << scorePointer << endl;
  cout << "print the score value from pointer: " << *scorePointer << endl;

}