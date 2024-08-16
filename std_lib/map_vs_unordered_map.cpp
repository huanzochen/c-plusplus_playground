#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{

  std::unordered_map<int, std::string> unorderedNames{{1, "anky"}, {2, "ashlinmorffy"}, {3, "kornocarge"}, {4, "kimberly"}, {10, "wayne"}, {15, "finn"}};
  // print the unordered_map
  for (auto cur : unorderedNames)
  {
    std::cout << cur.first << ": " << cur.second << std::endl;
  }
  std::cout << std::endl;

  std::map<int, std::string> orderedNames{{1, "tommy"}, {2, "kevin"}, {3, "alan"}, {4, "kimberly"}, {15, "finn"}, {16, "miki"}, {17, "Joy"}, {20, "Sadness"}};

  // print the map
  for (auto cur : orderedNames)
  {
    std::cout << cur.first << ": " << cur.second << std::endl;
  }
  std::cout << std::endl;

  // lower_bound & upper_bound
  // https://theriseofdavid.github.io/2021/02/28/C++/C++_binarysearch/

  std::map<int, std::string>::iterator itlow = orderedNames.lower_bound(10);
  if (itlow != orderedNames.end())
  {
    std::cout << "lower than 10, " << itlow->first << ": " << itlow->second << std::endl;
  }

  std::map<int, std::string>::iterator itupper = orderedNames.upper_bound(10);
  if (itupper != orderedNames.end())
  {
    std::cout << "upper than 10, " << itupper->first << ": " << itupper->second << std::endl;
  }

  // 選定的 value <= element，第一個大於等於他的數值.
  map<int, string>::iterator lowerBound = orderedNames.lower_bound(15);
  if (lowerBound != orderedNames.end())
  {
    cout << "lowerBound of 15 is: " << lowerBound->first;
  }
  cout << endl;

  // 選定的 value < element(陣列中的元素), 第一個大於他的數值.
  map<int, string>::iterator upperBound = orderedNames.upper_bound(15);
  if (upperBound != orderedNames.end())
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
  if (later2 != calendar.end())
  {
    cout << "the upperbound of newDate {9, 13} in the calendar is: " << later2->first << ", " << later2->second << endl;
  }
}
