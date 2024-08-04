#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int partition(vector<int> &nums, int startIdx, int endIdx)
  {
    int pivotIdx = startIdx;
    int pivot = nums[pivotIdx];

    int forwardIdx = startIdx + 1;
    int backwardIdx = endIdx;

    while (forwardIdx <= backwardIdx)
    {

      while (forwardIdx < endIdx && nums[forwardIdx] < nums[pivotIdx])
      {
        forwardIdx++;
      }

      while (backwardIdx > startIdx &&
             nums[backwardIdx] >= nums[pivotIdx])
      {
        backwardIdx--;
      }

      // 太大就 break, 相等的話也不需要 swap
      if (forwardIdx >= backwardIdx)
      {
        break;
      }

      int temp = nums[backwardIdx];
      nums[backwardIdx] = nums[forwardIdx];
      nums[forwardIdx] = temp;
    }

    // swap
    int tmp = nums[backwardIdx];
    nums[backwardIdx] = nums[pivotIdx];
    nums[pivotIdx] = tmp;

    pivotIdx = backwardIdx;

    return pivotIdx;
  }

  void quicksort(vector<int> &nums, int startIdx, int endIdx)
  {
    // base case
    if (startIdx >= endIdx)
    {
      return;
    }

    // general case
    int p = partition(nums, startIdx, endIdx);

    quicksort(nums, startIdx, p - 1);
    quicksort(nums, p + 1, endIdx);
  }

  vector<int> sortArray(vector<int> &nums)
  {
    quicksort(nums, 0, nums.size() - 1);

    return nums;
  }
};