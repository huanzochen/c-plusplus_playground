#include <iostream>

using namespace std;

int main()
{
  int p = 10;
  int *pointer = nullptr;

  cout << "p: " << p << endl;
  cout << "sizeof: " << sizeof(p) << endl;
  cout << "memory address: " << &p << endl;

  cout << "pointer: " << pointer << endl;
  cout << "sizeof: " << sizeof(pointer) << endl;
  cout << "memory address: " << &pointer << endl;

  double score = 95.5;
  double *scorePointer = nullptr;

  cout << "score: " << score << endl;
  cout << "sizeof: " << sizeof(score) << endl;
  cout << "memory address: " << &score << endl;

  cout << "scorePointer: " << scorePointer << endl;
  cout << "sizeof: " << sizeof(scorePointer) << endl;
  cout << "memory address: " << &scorePointer << endl;

  long peopleInEarth{7'600'000'000};
  long *peoplePointer = nullptr;

  cout << "peopleInEarth: " << peopleInEarth << endl;
  cout << "sizeof: " << sizeof(peopleInEarth) << endl;
  cout << "memory address: " << &peopleInEarth << endl;

  cout << "peoplePointer: " << peoplePointer << endl;
  cout << "sizeof: " << sizeof(peoplePointer) << endl;
  cout << "memory address: " << &peoplePointer << endl;
}