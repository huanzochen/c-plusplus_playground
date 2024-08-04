#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int> vec)
{
  for (int i = 0; i < vec.size(); i++)
  {
    cout << vec[i];
    if (i != vec.size() - 1)
    {
      cout << ", ";
    }
  }
}

int partition(vector<int> vecData, int startIdx, int endIdx)
{
  int pivotIdx = endIdx;
  int pivot = vecData[pivotIdx];
  int forwardIdx = startIdx;
  int backwardIdx = endIdx - 1;

  while (forwardIdx <= backwardIdx)
  {
    int forward = vecData[forwardIdx];
    bool idxNotMoving = true;

    if (forward < pivot)
    {
      idxNotMoving = false;
      forwardIdx++;
    }

    int backward = vecData[backwardIdx];
    if (backward >= pivot)
    {
      idxNotMoving = false;
      backwardIdx--;
    }

    if (idxNotMoving)
    {
      int temp = vecData[forwardIdx];
      vecData[forwardIdx] = vecData[backwardIdx];
      vecData[backwardIdx] = temp;

      forwardIdx++;
      backwardIdx--;
    }
  }

  // After the while, because forwardIdx is approaching to the pivot, so it should be swapped with the pivot.
  int tmp = vecData[forwardIdx];
  vecData[forwardIdx] = vecData[pivotIdx];
  vecData[pivotIdx] = tmp;

  pivotIdx = forwardIdx;

  return pivotIdx;
}

void quickSort(vector<int> vecData, int startIdx, int endIdx)
{
  // base case
  if (startIdx >= endIdx)
    return;

  // general case

  int p = partition(vecData, startIdx, endIdx);

  quickSort(vecData, startIdx, p - 1);
  quickSort(vecData, p + 1, endIdx);
}

int main()
{
  vector<int> vecData{5, 3, 4, 1};

  quickSort(vecData, 0, vecData.size() - 1);

  printVec(vecData);
}