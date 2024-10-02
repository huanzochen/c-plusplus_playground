#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // Overflow or underflow will both cause unexpected behavior.

  unsigned int unsingedA = 0;
  cout << "init unsingedA: " << unsingedA << endl;

  unsingedA--;
  cout << "underflowed int: " << unsingedA << endl;
  unsingedA--;
  cout << "underflowed int: " << unsingedA << endl;

  unsingedA++;
  cout << "underflowed int: " << unsingedA << endl;
  unsingedA++;
  cout << "underflowed int: " << unsingedA << endl;

  int signedA = -2147483648;
  cout << "init signedA: " << signedA << endl;

  signedA--;
  cout << "signedA int: " << signedA << endl;
  signedA--;
  cout << "signedA int: " << signedA << endl;

  signedA++;
  cout << "signedA int: " << signedA << endl;
  signedA++;
  cout << "signedA int: " << signedA << endl;

  return 0;
}