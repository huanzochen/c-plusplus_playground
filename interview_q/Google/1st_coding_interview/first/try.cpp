/**
 *
a vector array that is a gold chain with it’s weight

[6, 6, 10, 12]

must to remove an element, and let the seperate 2 part in the same weight.
the sequence can't be rearranged
 */

#include <iostream>
#include <vector>

using namespace std;

bool canSeperate(const vector<int> &weight)
{
  int n = weight.size();

  int p1 = 0;
  int p1W = 0;

  int totalW = 0;
  for (int i = 0; i < n; i++)
  {
    totalW += weight[i];
  }

  if (totalW % 2 > 0)
    return false;

  int half = totalW / 2;

  for (int i = 0; i < n; i++)
  {
    if (p1W < half)
    {
      p1 = i;
      p1W += weight[i];
    }
  }

  for (int i = 0; i < n; i++)
  {
    int updatedTotalW = (totalW - weight[i]);
    if (updatedTotalW % 2 > 0)
      return false;
    int updatedHalf = updatedTotalW / 2;
    int updatedP1W;

    // cout << "p1W:" << p1W << endl;

    if (i <= p1)
    {
      // in p1, substract the weight
      updatedP1W = p1W - weight[i];
    }
    else if (i == n - 1)
    {
      updatedP1W = p1W - weight[i - 1];
    }
    else
    {
      // not in p1
      updatedP1W = p1W;
    }

    // cout << "updatedP1W: " << updatedP1W << endl;
    // cout << "updatedTotalW:" << updatedTotalW << endl;
    // cout << "updatedHalf: " << updatedHalf << endl;
    // cout << "==============" << endl;

    if (updatedP1W == updatedHalf)
    {
      // cout << "updatedP1W == updatedHalf" << endl;
      // cout << "updatedP1W: " << updatedP1W << endl;
      // cout << "updatedTotalW:" << updatedTotalW << endl;
      // cout << "updatedHalf: " << updatedHalf << endl;
      return true;
    }
  }

  return false;
}

int main()
{
  vector<vector<int>> goldChains{
      {6, 6, 10, 12},   // Expected: 1
      {10, 6, 6, 12},   // Expected: 1
      {6, 6, 12},       // Expected: 1
      {5, 5, 5, 5},     // Expected: 0
      {1, 1, 1, 1, 2},  // Expected: 1
      {2, 4, 6, 8, 10}, // Expected: 0
      {15, 5, 5, 5},    // Expected: 0
      {3, 3, 3, 3, 6},  // Expected: 1
  };
  int n = goldChains.size();
  for (int i = 0; i < n; i++)
  {
    vector<int> goldChain = goldChains[i];
    cout << canSeperate(goldChain) << endl;
  }

  // cout << canSeperate(goldChains[2]) << endl;
}