/**
 *
A vector array that is a gold chain with it’s weight.

example like [6, 6, 10, 12].

You must remove an element, and let the seperate 2 parts has the same weight.
the sequence of element can't be rearranged.

return is this is able to seperate.
 */

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
    int newSum = totalSum - weights[i];

    if (newSum % 2 > 0)
      continue;

    int target = newSum / 2;
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
  };
  int n = goldChains.size();
  cout << boolalpha << endl;
  for (int i = 0; i < n; i++)
  {
    vector<int> goldChain = goldChains[i];
    cout << canSeperate(goldChain) << endl;
  }
}