#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

template<typename M>
void printAll(vector<M> res){
  int n = res.size();
  for(int i = 0; i < n; i++){
    cout << res[i];
    if(i != n-1) cout << ", ";
  }
  cout << endl;
}

class Comparator {
  public:
  auto operator()(string a, string b){
    if(a.size() == b.size())return a < b;
    return a.size() < b.size();
  }

  bool comparator(string a, string b){
    if(a.size() == b.size())return a < b;
    return a.size() < b.size();
  }
};

int main() {
  vector<string> names {"ula", "raymond", "steven", "bruce", "zoe", "tommy", "max"};

  // sort(names.begin(), names.end(), [](string a, string b){
  //   if(a.size() == b.size()) return a < b;
  //   return a.size() < b.size();
  // });

  // sort(names.begin(), names.end(), Comparator());

  // Comparator comp;
  // sort(names.begin(), names.end(), comp);

  Comparator comp;
  sort(names.begin(), names.end(), [&comp](string a, string b){
    return comp.comparator(a, b);
  });

  printAll(names);
}