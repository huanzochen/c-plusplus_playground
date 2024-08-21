#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class split
{
public:
  static vector<string> splitBySS(string str, char gap)
  {
    stringstream ss(str);
    string item;
    vector<string> splitedString;

    while (std::getline(ss, item, gap))
    {
      splitedString.push_back(item);
    }

    return splitedString;
  }

  static vector<string> splitMySelf(string str, char gap)
  {
    // I will recieve a string, and the corresponding gap that has to be cut.
    // And I will iterate through the string, if there is string, aggregate it into a string, if it is a gap, cut and push it into the vector.

    string aStr;
    vector<string> res;
    for (int i = 0; i < str.size(); i++)
    {
      char cur = str[i];
      if (cur == gap)
      {
        res.push_back(aStr);
        aStr = "";
      }
      else
      {
        aStr.push_back(cur);
      }
    }

    // push the last one, cause there is no gap anymore.
    res.push_back(aStr);

    return res;
  }
};

int main()
{

  string time = "23:59";
  vector<string> split = split::splitBySS(time, ':');

  // debug
  for (int i = 0; i < split.size(); i++)
  {
    cout << split[i];
    if (i != split.size() - 1)
      cout << ", ";
  }
  cout << endl;

  vector<string> split2 = split::splitMySelf(time, ':');
  // debug
  for (int i = 0; i < split2.size(); i++)
  {
    cout << split2[i];
    if (i != split2.size() - 1)
      cout << ", ";
  }
}