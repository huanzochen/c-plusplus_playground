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

bool canSeparate(const vector<int> &weights)
{
  int n = weights.size();

  // O(n^2) sol

  // first, we'll get the sum, the target will be sum/2

  // remove from 0 ... n, one of them
  // for i 0 ... n
    // update as newSum, and newTarget,
    // for j 0 ... n
    // if(i == j) continue
    // and see the rest of it could be append to new target,
    // if it can, the rest of it are both valuable.

  int sum = 0;
  for(int i = 0; i < n; i++){
    sum += weights[i];
  }

  // We're starting to remove the elements one by one.
  for(int i = 0; i < n; i++){
    int remove = weights[i];

    int newSum = sum - remove;
    if(newSum % 2 > 0) continue;
    int target = newSum / 2;

    int acc = 0;
    for(int j = 0; j < n; j++){
      if(j == i) continue;
      acc += weights[j];

      // if we find a valid sol, means the rest of it is also the same weight.
      if(acc == target) return true;
      else if(acc > target) break; // stop early if acc already bigger than the target.
    }
  }

  return false;
}

int main()
{
  vector<vector<int>> goldChains{
      {6, 6, 10, 12},   // Expected: true
      {10, 6, 6, 12},   // Expected: true
      {6, 6, 12},       // Expected: true
      {5, 5, 5, 5},     // Expected: false
      {1, 1, 1, 1, 2},  // Expected: true
      {2, 4, 6, 8, 10}, // Expected: false
      {15, 5, 5, 5},    // Expected: false
      {3, 3, 3, 3, 6},  // Expected: true
      {99, 2, 3, 3, 2}, // Expected: true => The one has to be removed at the first.
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

// Follow up question:
/**
 You and your friend went to a party and get a goldchain,
  the goldchain has it's weight as a integer in each link,
  you guys wanted to seperate it to two part with the same weight and bring it home.
  But before that you must remove a link from the goldchain.
  please write a function determine if it can be seperated.
*/

