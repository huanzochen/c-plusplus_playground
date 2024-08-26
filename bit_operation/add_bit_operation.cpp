#include<iostream>
#include<bitset>

using namespace std;

int add(int a, int b){
  return a + b;
}

int addBinary(int a, int b){
  // base case
  // if carry == 0, means we can return the sum.
  if(b == 0){
    return a;
  }

  // general case
  // Do XOR with a, b , list the bits that add together without carrying.
  int sum = a^b; // XOR
  // carry means AND operation of the two and left shift one bit.
  int carry = (a & b) << 1;

  // keep adding the two together.
  return addBinary(sum, carry);
}

int main() {

  cout << add(5, 6) << endl;

  cout << addBinary(5, 6) << endl;
}

