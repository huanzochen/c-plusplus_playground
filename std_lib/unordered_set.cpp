#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

void printAll(unordered_set<string> *test)
{
  cout << "print set: ";
  for (const string &cur : *test)
  {
    cout << cur << " ";
  }
  cout << endl;
}

int main()
{
  unordered_set<string> seen;

  // Capacity function
  cout << "seen.empty(): " << seen.empty() << endl;
  cout << "seen.size(): " << seen.size() << endl;
  cout << "seen.max_size(): " << seen.max_size() << endl;

  seen.insert("a");
  seen.insert("b");
  seen.insert("c");
  cout << "seen.size(): " << seen.size() << endl;
  printAll(&seen);

  seen.clear();
  cout << "seen.size(): " << seen.size() << endl;

  seen.insert("d");
  seen.insert("e");
  seen.insert("f");
  seen.insert("g");
  seen.insert("h");
  seen.insert("i");
  seen.insert("Rakuten");

  // erase by key
  seen.erase("Rakuten");
  printAll(&seen);

  // erase by range
  seen.erase(seen.find("h"), seen.end());
  printAll(&seen);

  // erase by iterator
  seen.erase(seen.begin());
  printAll(&seen);

  unordered_set<string> company{"Google", "Spotify", "Amazon", "Microsoft"};
  cout << "company.size(): " << company.size() << endl;

  seen.swap(company);
  cout << "After swap, the seen and company has swapped the value." << endl;
  printAll(&seen);
  printAll(&company);

}