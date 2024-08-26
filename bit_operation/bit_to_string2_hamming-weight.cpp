#include <bitset>
#include <string>
#include <iostream>

using namespace std;

int hammingWeight(int n)
{
  // we know, if subtract n as 1, it will flip the bit after the least significant 1.
  // with this approach, we can just do the subtraction, and compare to origin with AND.
  // Then we can count the 1 ++, till the result of it has been to 0.

  int count = 0;

  while (n != 0)
  {
    count++;
    n = n & (n - 1);
  }

  return count;
}

int countNumOnes(int n)
{
  int count = 0;

  bitset<32> binaryN(n);

  string stringN = binaryN.to_string();
  // for(int i = 0; i < stringN.size(); i++){
  //   if(stringN[i] =='1'){
  //     count++;
  //   }
  // }
  for (char cur : stringN)
  {
    if (cur == '1')
    {
      count++;
    }
  }

  return count;
}

int loopAndFlip(int n)
{
  int count = 0;
  int mask = 1;

  // while (mask <= INT_MAX/2)
  // while(mask <= n)
  // {
  //   if ((n & mask) > 0)
  //     count++;
  //   mask = mask << 1;
  // }

  for (int i = 0; i < 32; i++)
  {
    if ((n & mask) != 0)
    {
      count++;
    }
    mask <<= 1;
  }

  return count;
}

int main()
{

  int num = 10;

  // count how many "1" are in the binary 10.
  cout << hammingWeight(num) << endl;
  cout << countNumOnes(num) << endl;
  cout << loopAndFlip(num) << endl;

  cout << (hammingWeight(num) == countNumOnes(num)) << endl;
  cout << boolalpha;
  cout << (hammingWeight(num) == countNumOnes(num)) << endl;
  cout << (hammingWeight(num) == loopAndFlip(num)) << endl;
  cout << (countNumOnes(num) == loopAndFlip(num)) << endl;
}