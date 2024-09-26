#include <iostream>
#include <string>
#include <vector>

using namespace std;

class solution
{
public:
  string question(const string &givenTime, const string &referenceTime)
  {

    // a string with size 5
    // int h1 = givenTime[0]; // 0~2
    // int h2 = givenTime[1]; // 0~9 , exception, when fHour is 2, it should be only 3 at max.
    // int m1 = givenTime[3]; // 0~5
    // int m2 = givenTime[4]; // 0~9

    int closestMin = INT_MAX;
    string closestTime;

    for (int h1 = givenTime[0] == '?' ? 0 : givenTime[0] - '0'; h1 <= ((givenTime[0] == '?') ? ((givenTime[1] != '?' && (givenTime[1] - '0') > 4) ? 1 : 2) : givenTime[0] - '0'); h1++)
    {
      for (int h2 = givenTime[1] == '?' ? 0 : givenTime[1] - '0'; h2 <= ((givenTime[1] == '?') ? ((h1 == 2) ? 3 : 9) : givenTime[1] - '0'); h2++)
      {
        // first minute digit
        for (int m1 = givenTime[3] == '?' ? 0 : givenTime[3] - '0'; m1 <= ((givenTime[3] == '?') ? 5 : givenTime[3] - '0'); m1++)
        {
          for (int m2 = givenTime[4] == '?' ? 0 : givenTime[4] - '0'; m2 <= ((givenTime[4] == '?') ? 9 : givenTime[4] - '0'); m2++)
          {

            string givenT = to_string(h1) + to_string(h2) + ':' + to_string(m1) + to_string(m2);

            int givenMin = toMinutes(givenT);
            int referenceMin = toMinutes(referenceTime);

            // compare this two times

            if (abs(givenMin - referenceMin) < closestMin)
            {
              closestMin = abs(givenMin - referenceMin);
              closestTime = givenT;
            }

            // 4 for loop

            // cout << "h1h2:m1m2: " << h1 << "" << h2 << ":" << m1 << "" << m2 << endl;
          }
        }
      }
    }

    return closestTime;
  }

  int toMinutes(string timeStr)
  {
    string hour = timeStr.substr(0, 2);
    string minutes = timeStr.substr(3, 2);

    return stoi(hour) * 60 + stoi(minutes);
  }
};

int main()
{
  solution sol;

  cout << (sol.question("2?:?8", "23:57") == "23:58") << endl;
  cout << (sol.question("?8:4?", "09:00") == "08:49") << endl;
  cout << (sol.question("2?:23", "23:23") == "23:23") << endl;
  cout << (sol.question("??:59", "13:00") == "12:59") << endl;
  cout << (sol.question("??:0?", "13:03") == "13:03") << endl;
  cout << (sol.question("?8:2?", "18:23") == "18:23") << endl;
}
