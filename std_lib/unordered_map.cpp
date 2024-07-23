#include <iostream>
#include <unordered_map>

using namespace std;

void printAll(unordered_map<string, int> *test) {
  for(const auto &current: *test) {
    cout << "test key: " << current.first << " test value: " << current.second << endl;
  }
}

int main() {

  unordered_map <string, int> scorePerName {{"aaa", 10}, {"bbb", 11}};

  printAll(&scorePerName);

}
