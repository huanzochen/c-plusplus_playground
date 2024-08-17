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
}
