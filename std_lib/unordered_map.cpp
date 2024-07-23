#include <iostream>
#include <unordered_map>

using namespace std;

void printAll(unordered_map<string, int> *test)
{
  for (const auto &current : *test)
  {
    cout << "key: " << current.first << " value: " << current.second << endl;
  }
}

int main()
{

  unordered_map<string, int> scorePerName{{"aaa", 10}, {"bbb", 11}};

  scorePerName.insert({"c", 1});

  cout << "scorePerName.count('c'): " << scorePerName.count("c") << endl;

  if (scorePerName.count("c") > 0)
  {
    cout << "should be here  \n";
    scorePerName.insert({static_cast<string>("c"), static_cast<int>(scorePerName.count("c")) + 1});
  }
  else
  {
    scorePerName.insert({"c", 1});
  }

  cout << "static_cast<int>(scorePerName.count('c')) + 1: " << static_cast<int>(scorePerName.count("c")) + 1 << endl;

  scorePerName.insert({"d", 1});
  // The second insert will be ignored
  if (scorePerName.count("d") > 0)
  {
    scorePerName["d"] = scorePerName["d"] + 1;
  }
  else
  {
    scorePerName.insert({"d", 1});
  }

  // It is able to add a key in c++ if the key still not exists.
  scorePerName["e"] = 1;

  printAll(&scorePerName);
}
