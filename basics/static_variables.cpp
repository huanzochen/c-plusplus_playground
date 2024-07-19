#include <iostream>

using namespace std;

void staticVariable() {
  // It will only initialize once
  static int num = 2000;

  num += 1000;

  cout << "the static value \nnum: " << num << endl;

}

int main() {
  staticVariable();
  staticVariable();
  staticVariable();

  // This will cause error
  cout << "If I try to get the static variable in another scope, it will return error \nnum: " << num << endl;

}