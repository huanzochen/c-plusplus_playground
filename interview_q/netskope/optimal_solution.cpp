#include <iostream>
#include <ios>
using namespace std;

/*------------------------------------------------------------------------

Given an array of integers temperatures represents the daily temperatures,
return an array answer such that answer[i] is the number of days you have
to wait after the ith day to get a warmer temperature. If there is no
future day for which this is possible, keep answer[i] == 0 instead.

----------------------------------------------------------------------------

Example 1:
----------
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

// for loop int 0 ~ end
// check i+1 ~ temp.size()-1 for i
// heigher than temp[i] , count++

// for start = i ~ end


Example 2:
----------
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]


Example 3:
----------
Input: temperatures = [30,60,90]
Output: [1,1,0]


[30,.........., 31]


Constraints:
1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100

----------------------------------------------------------------------------*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  template <typename M>
  void printVec(vector<M> &vec)
  {
    for (int i = 0; i < static_cast<int>(vec.size()); i++)
    {
      cout << vec[i];
      if (i != static_cast<int>(vec.size() - 1))
        cout << ", ";
    }
    cout << endl;
  }

  template <typename N>
  string convertVecToString(vector<N> &vec)
  {
    string res;

    for (int i = 0; i < static_cast<int>(vec.size()); i++)
    {
      int cur = vec[i];
      res += to_string(cur);
      if (i != static_cast<int>(vec.size() - 1))
        res += ",";
    }

    return res;
  }

  vector<int> getDaysToWarm(vector<int> temp)
  {

    // consider You are wating in the line with the people with temp cm tall
    // you can only see someone is taller, and we want the first one taller in front of you.
    // with this method, we can use stack to solve this problem

    // Example:

    // 70 (You),  65cm , 77cm(the person you'll see) , 60cm(been hided), 88cm (you'll see but more further...)

    // with this approach, you can start saving people at the end,
    // using stack, filter the people lower than you, and the most people near you is the higest one next to you.

    // and because in this question we want to count the days, so we will count when popping the shorter person.

    vector<int> stack;
    vector<int> res(temp.size());

    int count = 0;
    int prev = -1;

    for (int i = static_cast<int>(temp.size() - 1); i >= 0; i--)
    {

      // if the next one is higher than current, than keep use the count.
      // if the next one is lower than current, than reset the count.
      if (temp[i] < prev)
      {
        count = 0;
      }

      while (stack.size() != 0 && temp[i] >= stack.back())
      {
        stack.pop_back();
        count++;
      }

      if (stack.size() == 0)
      {
        res[i] = 0;
      }
      else
      {
        res[i] = count + 1;
      }

      stack.push_back(temp[i]);
      prev = temp[i];
    }

    return res;
  }
};

// To execute C++, please define "int main()"
int main()
{
  auto words = {"Hello, ", "World!", "\n"};
  for (const char *const &word : words)
  {
    cout << word;
  }

  // vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};
  // vector<int> temperatures{30,40,50,60};
  // vector<int> temperatures{30,60,90};

  vector<vector<int>> tempSets{{73, 74, 75, 71, 69, 72, 76, 73}, {30, 40, 50, 60}, {30, 60, 90}};
  vector<string> ansSets{"1,1,4,2,1,1,0,0", "1,1,1,0", "1,1,0"};

  Solution sol;

  for (int i = 0; i < static_cast<int>(tempSets.size()); i++)
  {
    vector<int> res;
    res = sol.getDaysToWarm(tempSets[i]);
    sol.printVec(res);

    string solString = sol.convertVecToString(res);
    cout << boolalpha;
    cout << "solution:" << (solString == ansSets[i]) << endl;
  }

  return 0;
}

// Your previous Plain Text content is preserved below:

// This is just a simple shared plaintext pad, with no execution capabilities.

// When you know what language you'd like to use for your interview,
// simply choose it from the dots menu on the tab, or add a new language
// tab using the Languages button on the left.

// You can also change the default language your pads are created with
// in your account settings: https://app.coderpad.io/settings

// Enjoy your interview!