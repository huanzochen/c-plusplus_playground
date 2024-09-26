#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
  int tmp = a;
  a = b;
  b = tmp;
}

int pivot_helper(vector<int> &vec, int start, int end)
{
  int pivotIdx = start;
  int pivot = vec[pivotIdx];

  int l = start + 1;
  int r = end;

  // r 會恰巧停在小於 pivot 的位置

  while (l <= r)
  {
    while (l < end && vec[l] < pivot)
    {
      l++;
    }

    while (r > start + 1 && vec[r] > pivot)
    {
      r--;
    }

    // 因為 l 和 r 不一定只走一步，如果他們已經相等，或相互超過了，那就應該被立即結束, 否則會交換到奇怪的內容。
    if (l >= r)
    {
      break;
    }

    // 當他們兩個都不動了，就會停在需要互換的位置
    swap(vec[l], vec[r]);
  }

  // 等到都交換完之後，在把 pivot 移到對應的中間位置.
  swap(vec[pivotIdx], vec[r]);
  pivotIdx = r;

  return pivotIdx;
}

void quick_sort(vector<int> &vec, int left, int right)
{
  // base case
  if (left > right)
  {
    return;
  }

  int pivotIndex = pivot_helper(vec, left, right);

  // This could probably be 0, -1, cause the right has -1.
  quick_sort(vec, left, pivotIndex - 1);
  // %his could probably be 2,1 , cause the left has +1.
  quick_sort(vec, pivotIndex + 1, right);
}

int main()
{
  vector<int> testData{5, 8, 2, 1, 4, 3, 7, 6, 0};

  cout << "unsorted result: ";
  for (const auto &i : testData)
  {
    cout << i << " ";
  }
  cout << endl;

  quick_sort(testData, 0, testData.size() - 1);

  cout << "sorted result: ";
  for (auto it = testData.begin(); it != testData.end(); it++)
  {
    cout << *it << " ";
  }
  cout << endl;
}