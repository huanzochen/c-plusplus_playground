#include <iostream>
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

vector<int> solution(vector<int> temp)
{

  // for loop int 0 ~ end
  // check i+1 ~ temp.size()-1 for i
  // heigher than temp[i] , count++

  // for start = i ~ end

  vector<int> res;

  for (int i = 0; i < static_cast<int>(temp.size()); i++)
  {
    int curTemp = temp[i];

    int waitDays = 0;

    for (int j = i + 1; j < static_cast<int>(temp.size()); j++)
    {
      int compTemp = temp[j];

      if (compTemp > curTemp)
      {
        waitDays = j - i;
        break;
      }
    }

    res.push_back(waitDays);
  }

  return res;
}

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
  // vector<int> temperatures{30, 60, 90};

  vector<vector<int>> temperatures_set{{73, 74, 75, 71, 69, 72, 76, 73}, {30, 40, 50, 60}, {30, 60, 90}};
  vector<string> ans{
      "1,1,4,2,1,1,0,0",
      "1,1,1,0",
      "1,1,0"};

  for (int i = 0; i < temperatures_set.size(); i++)
  {
    vector<int>
        sol;

    vector<int> temperatures = temperatures_set[i];
    sol = solution(temperatures);

    // print sol out
    for (int i = 0; i < static_cast<int>(sol.size()); i++)
    {
      cout << sol[i];
      if (i != static_cast<int>(sol.size() - 1))
        cout << ", ";
    }
    cout << endl;

    // convert sol to solString
    string solString = "";
    for (int i = 0; i < sol.size(); i++)
    {
      solString += to_string(sol[i]);
      if (i != sol.size() - 1)
        solString += ",";
    }

    cout << "solString: " << solString << " Correct? " << (solString == ans[i]) << endl;
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