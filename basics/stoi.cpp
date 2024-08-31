#include <iostream>
#include <string>
#include <vector>

#include <typeinfo>
#include <sstream>

using namespace std;

int main()
{
  string test = "235739";

  decltype(stoi(test)) number;

  cout << " the type of stoi(test) is: " << typeid(number).name() << endl;

  decltype(test) aString;

  cout << typeid(decltype(test)).name() << endl;
  cout << typeid(aString).name() << endl;

  stringstream ss;

  int aNumber = 2222;
  string aStringOfNumber;
  ss << aNumber;
  ss >> aStringOfNumber;
  cout << "aStringOfNumber: " << aStringOfNumber << endl;

  stringstream ss2;
  string bString = "333";
  int bNum = 0;
  ss2 << bString;
  ss2 >> bNum;
  cout << "bNum: " << bNum << endl;
  cout << typeid(decltype(bNum)).name() << endl;
}