#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

//https://cplusplus.com/reference/map/map/
// map is implemented by binary search tree.

int main()
{
  map<string, int> ageOfPeople = {{"Tommy", 10},
                                  {"Sally", 15},
                                  {"Bob", 20}};
  for (const auto &person : ageOfPeople)
  {
    cout << person.first << ": " << person.second << " years old\n";
  }

  unordered_map<string, int> ageOfPeopleHash = {{"Tommy", 15}, {"Sally", 20}, {"Bob", 10}};
  ageOfPeopleHash["Alice"] = 25;

  for (const pair<const string, int> &person : ageOfPeopleHash)
  {
    cout << person.first << ": " << person.second << " years old\n";
  }

  if (ageOfPeopleHash.find("Alice") != ageOfPeopleHash.end())
  {
    cout << "Alice is in the map ageOfPeopleHash, it's age is, Alice: "
         << ageOfPeopleHash["Alice"] << endl;
  }

  if (ageOfPeopleHash.find("Eve") == ageOfPeopleHash.end())
    cout << "Eve is not in the unordered_map ageOfPeopleHash\n";
}