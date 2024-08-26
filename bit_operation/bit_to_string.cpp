#include <iostream>
#include <string>
using namespace std;

string toBinary(int n){
  std::bitset<32>binary(n);
  return binary.to_string();
}

int main() {
  // The negative value in c++ is:
  // 1. first, invert all the bits, turns all the 0 to 1, 1 to 0.
  // 2. and then +1
  // Above process is called "two's complement".
  int minusTwo = -2;
  string binaryMinusTwo = toBinary(minusTwo);

  int two = 2;
  string binaryTwo = toBinary(two);

  cout << "Binary representation of a: " << minusTwo << " is: " << binaryMinusTwo << endl;
  cout << "Binary representation of two: " << two << " is: " << binaryTwo << endl;
}