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

bool canSeperate(const vector<int> &weights)
{
  int n = weights.size();
  int totalSum = 0;
  for (int weight : weights)
  {
    totalSum += weight;
  }

  // Try removing each element and check if the rest can be split equally
  for (int i = 0; i < n; i++)
  {
    int newTotalSum = totalSum - weights[i];

    if (newTotalSum % 2 > 0)
      continue;

    int target = newTotalSum / 2;
    int currentSum = 0;

    // Check if we can reach target by summing elements up to some point in the chain
    for (int j = 0; j < n; j++)
    {
      // The one has to be removed.
      if (j == i)
        continue;

      currentSum += weights[j];
      if (currentSum == target)
      {
        // if it meets the half of totalNewSums, it also indicates the rest of it is also half.
        return true;
      }
      else if (currentSum > target)
      {
        break; // stop early if the currentSum meets the target.
      }
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
    cout << canSeperate(goldChain) << endl;
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

