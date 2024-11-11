/**
 You and your friend went to a party and get a goldchain,
  the goldchain has it's weight as a integer in each link,
  you guys wanted to seperate it to two part with the same weight and bring it home.
  But before that you must remove a link from the goldchain.
  please write a function determine if it can be seperated.
*/

// goldchain is not able to rearrange.
// how if the weight is negative? if it will effect the answer?

// example like [6, 6, 10, 12].

#include <iostream>
#include <vector>

using namespace std;

  // We try to pre-calculate the sum from left and from right.
  // With this approach, we get the accumulated result,
  // and try to remove one element at a time to determine if it can be separate.

  // valid
  // input: [6, 10, 100, 8, 8]
  // output: true

  // prefixSum = [6, 16, 116, 124, 132]
  // suffixSum = [132, 126, 116, 16, 8]
  // we get the totalSum from last element in prefixSum,

  // Edge case: if totalSum % 2 > 0, return false cause odd can't be separate.

  // than we run a for loop, iterate over 0...n-1 and try to delete one in each iteration.
    // for 0 ... n-1
    // if we remove i == 0  (edge case)
    // prefixSum[i+1] === suffixSum[i+2]

    // if we remove i == 1, 2...n-2
    // prefixSum[i-1] === suffixSum[i+1]

    // if we remove i == n-1 (edge case)
    // prefixSum[i-2] == suffixSum[i-1]


//debug
void printAll(vector<int> data){
  int n = data.size();
  for(int i = 0; i < n; i++){
    cout << data[i];
    if(i != n-1) cout << " ";
  }
  cout << endl;
}

bool separateCheck(int remove, vector<int> &prefixSum, vector<int> &suffixSum,const vector<int> &weights){
  int n = prefixSum.size();
  int removeVal = weights[remove];
  for(int i = 0; i < n; i++){
    if(remove == i) continue;

    int left = 0;
    int right = 0;

    if(i > remove){
      left = prefixSum[i] - removeVal;
    }else {
      left = prefixSum[i];
    }

    if(i+1 <= remove){
      right = suffixSum[i+1] - removeVal;
    }else{
      right = suffixSum[i+1];
    }

    if(left == right) return true;
  }
  return false;
}

bool canSeparate(const vector<int> &weights)
{
  int n = weights.size();

  //{9999, 20, 5, 10, 5}

  // build prefixSum &  suffixSum
  vector<int> prefixSum(n, 0); // {9999, 10019, 10024, 10034, 10039}
  vector<int> suffixSum(n, 0); // {10039 ,40, 20, 15, 5}

  for(int i = 0; i < n; i++){
    if(i == 0) prefixSum[i] = weights[i];
    else {prefixSum[i] = prefixSum[i-1] + weights[i];}
  }
  for(int i = n-1; i >= 0; i--){
    if(i == n-1) suffixSum[i] = weights[i];
    else {suffixSum[i] = suffixSum[i+1] + weights[i];}
  }

  // {10, 6, 6, 12}
  // {10, 16, 22, 34}
  // {34, 24, 18, 12}

  int totalSum = prefixSum.back(); // suffixSum[0]

  // if(totalSum % 2 > 0) return false; // no need this line, because we about to remove one element

  // debug
  // printAll(prefixSum);
  // printAll(suffixSum);

  // Try to remove elements, and see if it still can be separated.
    // todo, edge case , first and last element.
  for(int i = 0; i < n; i++){
    int removeEl = weights[i]; // 10
    if(separateCheck(i, prefixSum, suffixSum, weights)) return true;
  }

  // If we doesn't find a solution, return false;
  return false;
}

int main()
{
  vector<vector<int>> goldChains{
      {6, 6, 10, 12},     // Expected: true
      {10, 6, 6, 12},     // Expected: true
      {6, 10, 100, 8, 8}, // Expected: true
      {6, 6, 12},         // Expected: true
      {5, 5, 5, 5},       // Expected: false
      {1, 1, 1, 1, 2},    // Expected: true
      {2, 4, 6, 8, 10},   // Expected: false
      {15, 5, 5, 5},      // Expected: false
      {3, 3, 3, 3, 6},    // Expected: true
      {99, 2, 3, 3, 2},   // Expected: true => The one has to be removed at the first.
      {9999, 20, 5, 10, 5}, // Expected: true => Remove the first an the second can cover the rest.
      {5, 5, 10, 20, 9999}  // Expected: true => Remove the last an the second last can cover the rest.
  };
  int n = goldChains.size();
  cout << boolalpha << endl;
  for (int i = 0; i < n; i++)
  {
    vector<int> goldChain = goldChains[i];
    cout << canSeparate(goldChain) << endl;
  }
}


