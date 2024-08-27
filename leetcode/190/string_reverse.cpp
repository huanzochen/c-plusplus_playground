/**
 * 190. Reverse Bits
Easy
Topics
Companies
Reverse bits of a given 32 bits unsigned integer.

Note:

Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825.


Example 1:

Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.
Example 2:

Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.


Constraints:

The input must be a binary string of length 32


Follow up: If this function is called many times, how would you optimize it?
 */

#include <iostream>
#include <string>

using namespace std;

uint32_t reverseNum(uint32_t n){

  // I can reverse it by converting to binary string
  // Reverse it, and than turn it to binary string,
  // Turn it to uint_32_t using static_case<uint32_t>binary.to_ulong().

  std::bitset<32> binary(n);
  string nStr = binary.to_string();

  // reverse the str
  int l = 0;
  int r = nStr.size()-1;
  while(l < r){
    auto tmp = nStr[l];
    nStr[l] = nStr[r];
    nStr[r] = tmp;
    l++;
    r--;
  }

  // convert it back to uint32_t.
  bitset<32> res(nStr);

  return static_cast<uint32_t>(res.to_ulong());
}

int main(){

  uint32_t n = 43261596;

  uint32_t res = reverseNum(n);

  cout << "(res == 964176192): " << (res == 964176192) << endl;

}