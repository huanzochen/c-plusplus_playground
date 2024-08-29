/**
 *
 * 70. Climbing Stairs
Solved
Easy
Topics
Companies
Hint
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?



Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step


Constraints:

1 <= n <= 45
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int climbing_mountain(int n)
{

  // we are now going to count stairs.

  // if n = 2,
  // 1+1
  // 2

  // n =3
  // 1+1+1
  // 1+2
  // 2+1
  // = 3

  // if there is sub problem here?
  // if there is optimal substructure here?

  // consider climbing ith stairs, the possibility to reach that level is:
  // 1. climbing 1 stairs from i-1th stairs
  // 2. climbing 2 stairs from i-2th stairs

  // That means, we can get i's answer by sum(i-1, i-2).

  // with this approach, i can see this problem as a dp problem, and do it with that.

  // first, initialize an vector with all elements is 0.
  // assign the initial value of the dp
  vector<int> dp(n + 1, 0);

  dp[1] = 1;
  dp[2] = 2;
  // we knew that dp[3] = dp[i-1] + dp[i-2]

  // it start from 3, cause and we already know 1 and 2.
  for (int i = 3; i < dp.size(); i++)
  {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  // the question only want me to return the n step possibilities.
  return dp[n];
}

int main()
{
  int n = 5;

  cout << (climbing_mountain(n) == 8) << endl;
}