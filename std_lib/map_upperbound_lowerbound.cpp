#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{

  map<int, string> names{{1, "tommy"}, {2, "kevin"}, {3, "alan"}, {4, "kimberly"}, {15, "finn"}, {16, "miki"}, {17, "Joy"}, {20, "Sadness"}};

  // 選定的 value <= element，第一個大於等於他的數值.
  map<int, string>::iterator lowerBound = names.lower_bound(15);
  if (lowerBound != names.end())
  {
    cout << "lowerBound of 15 is: " << lowerBound->first;
  }
  cout << endl;

  // 選定的 value < element(陣列中的元素), 第一個大於他的數值.
  map<int, string>::iterator upperBound = names.upper_bound(15);
  if (upperBound != names.end())
  {
    cout << "upperBound of 16 is: " << upperBound->second;
  }
  cout << endl;

  map<int, int> calendar{{14, 17}, {15, 20}};

  pair<int, int> newDate = {10, 16};
  map<int, int>::iterator later = calendar.upper_bound(newDate.second);

  if (later != calendar.end())
  {
    cout << "the upperbound of newDate {10, 16} in the calendar is: " << later->first << ", " << later->second << endl;
  }

  pair<int, int> anotherDate = {9, 13};
  auto later2 = calendar.upper_bound(anotherDate.second);

  if (later2 == calendar.begin())
  {
    cout << "begin means this iterator is the first result" << endl;
    cout << "begin, the upperbound of newDate {9, 13} in the calendar is: " << later2->first << ", " << later2->second << endl;

    // what will happen minus the iterator
    cout << "(--later2)->first " << (--later2)->first << ", " << "(--later2)->second: " << (--later2)->second << endl;
  }
}