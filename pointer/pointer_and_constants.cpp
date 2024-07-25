#include <iostream>

using namespace std;

int main()
{
  // A. Pointer to constants
  int big = 10;
  int small = 5;

  const int *tall{&big};

  cout << "tall: " << *tall << endl;

  // This will cause error
  // *tall = 11;
  // This is ok due to the pointer can be change to point elsewhere.
  tall = &small;

  cout << "tall: " << *tall << endl;

  // B. Constant pointers
  int high{180};
  int low{165};

  int *const score_ptr{&high};

  cout << "score_ptr: " << *score_ptr << endl;

  // This is ok
  *score_ptr = 181;
  // This will cause error
  // score_ptr = &low;

  // This is ok because we can change what the value referes to high int.
  cout << "score_ptr: " << *score_ptr << endl;

  // C. Constant pointer to constants.

  string first = "Tommy";
  string second = "Kevin";

  const string *const babe{&first};

  cout << "*babe: " << *babe << endl;

  // The two of it below is no-go, becuase the pointer, and the variable is both constants.
  // *babe = second;
  // babe = &second;
}