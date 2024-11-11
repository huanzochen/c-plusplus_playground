#include <iostream>
#include <vector>

using namespace std;

/**
 You and your friend went to a party and get a goldchain,
  the goldchain has it's weight as a integer in each link,
  you guys wanted to seperate it to two part with the same weight and bring it home.
  please write a function determine if it can be seperated.
 */

// Signature
bool canSeparate(vector<int> weights){
  int n = weights.size();

  // first we calculate the sum of all the weight.
  // and measure target, it would be half of the weight.
  // we iterate over the goldchain, when it meets the target(half of sum),
  // means the rest of it can also be separate as the same weight, return true.

  int sum = 0;
  for(int i = 0; i < n; i++){
    sum += weights[i];
  }

  // edge case, if sum is odd, it can not be split by integer
  if(sum % 2 > 0) return false;
  int target = sum / 2;

  int acc = 0;
  for(int i = 0; i < n; i++){
    acc += weights[i];
    if(acc == target) return true;
  }

  return false;
}

int main() {
  vector<pair<vector<int>, bool>> goldChains{
    {{6, 6, 6, 12}, false},
    {{6, 6, 12}, true},
    {{5, 5, 5, 5}, true},
    {{1, 1, 1, 1, 2}, true},
    {{2, 4, 6, 8, 20}, true},
    {{15, 5, 5, 5}, true},
    {{3, 3, 3, 3, 6}, true},
    {{99, 2, 3, 3, 2}, false},
    {{9999, 20, 5, 10, 5}, false},
    {{5, 5, 10, 20, 9999}, false}
  };

  int n = goldChains.size();
  for(int i = 0; i < n; i++){
    pair<vector<int>, bool> cur = goldChains[i];
    vector<int> &goldChain = cur.first;
    bool result = cur.second;

    cout << (canSeparate(goldChain) == result ? "pass" : "not pass") << endl;
  }
}