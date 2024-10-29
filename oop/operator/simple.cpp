#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Comparator {
  public:

  bool operator()(int a, int b){
    return a < b;
  }
};

int main() {
  int one = 1;
  int two = 2;

  Comparator comp;

  cout << comp(one, two) << endl;
}