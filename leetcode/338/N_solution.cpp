/**
 * 338. Counting Bits
Easy
Topics
Companies
Hint
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.



Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101


Constraints:

0 <= n <= 105


Follow up:

It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?
 */

#include <string>
#include <iostream>
using namespace std;

int countOneBit(int n) // assume the biggest number is n.
{
  int sum = 0;

  // flip the least significant 1 bit as n-1 and AND with the n.
  // it will once flip a 1 bit.
  while (n != 0)
  {
    // the while time depends on '1' bit in n,
    // so the it will run logN+1 times in the worst case.
    // logN
    sum++;
    n = n & (n - 1);
  }

  return sum;
}

string convertVecToString(vector<int> vecData)
{
  string resString = "[";
  for (int i = 0; i < vecData.size(); i++)
  {
    resString += to_string(vecData[i]);
    if (i != vecData.size() - 1)
      resString += ',';
  }
  resString += ']';

  return resString;
}

vector<int> getOneInN(int n)
{
  // now I have integer n, and i want to get the "1" is in each numbers.
  // the method to approach that has multiple ways,
  // here I will use
  // 1. take away the last set bit from current number,
  // 2. and look at the last bit of number is 1 or 0.

  // and I will take it from bottom to top, which can be dp + least significant bit

  vector<int> count(n + 1, 0);
  count[0] = 0; // 0 has 0 "1"
  count[1] = 1; // 1 has 1, "1"

  // we can start with 1, ignore the zero
  for (int i = 1; i < count.size(); i++)
  {
    // after we remove the least significant bit, the result with added 1 is always add one more "1" count, that is what we wanted.
    count[i] = count[i & (i - 1)] + 1;
  }

  return count;
}

int main()
{
  int n = 5;

  string testAnsN = "[0,1,1,2,1,2]";

  vector<int> res = getOneInN(n);

  string resString = convertVecToString(res);
  cout << "resString: " << resString << endl;
  cout << (testAnsN == resString) << endl;
}