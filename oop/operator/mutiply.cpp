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

class Doubler {
  public:
  auto operator()(int a){
    return a * 2;
  }
};

int main() {
  vector<int> origin{1, 2, 3, 4, 5};
  vector<int> res(origin.size(), 1000);

  // A. use lambda
  // transform(origin.begin(), origin.end(), res.begin(), [](int a){return a * 2;});

  // B. use it as a instance
  Doubler doubler;
  transform(origin.begin(), origin.end(), res.begin(), doubler);

  // C. use it directly call by class
  transform(origin.begin(), origin.end(), res.begin(), Doubler());

  printAll(res);


  // 其實我也可以單用 operator
  // 這會透過 Double() 創建一個臨時對象，在透過 x()調用 "Double()()", 調用完後會立即銷毀
  cout << "Doubler()(20): " << Doubler()(20) << endl;

  // 也可以提早創建一個新對象, 例如像這樣
  // 然後在調用他
  Doubler a_doubler;
  cout << "doubler(20): " << a_doubler(20) << endl;
  // 好處是，doubler 可被重複調用

}