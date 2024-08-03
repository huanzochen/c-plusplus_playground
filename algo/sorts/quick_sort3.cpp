#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int> vecData)
{
  for (int i = 0; i < vecData.size(); i++)
  {
    int cur = vecData[i];
    cout << cur;
    if (i != vecData.size() - 1)
    {
      cout << ", ";
    }
  }
}

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

int partition(vector<int> &vecData, int start, int end)
{
  // Take the first element
  int pivotIndex = start;
  int pivot = vecData[pivotIndex];

  int i = start + 1;
  int j = end;

  // i, j 有可能兩者相等
  // 在只剩一個元素的情況下, 例如 start 1, end 1, 那 i = 2, j = 1, 就不會進來了
  while (i <= j)
  {

    // 停下來時剛好 vecData[i] 大於 pivot
    while (i < end && vecData[i] <= pivot)
    {
      i++;
    }

    // 停下來的時候剛好 vecData[j] 小於（或等於） pivot
    while (j > start && vecData[j] > pivot)
    {
      j--;
    }

    if (i >= j)
    {
      break;
    }

    // 這兩個值，應該要被互換，這樣才可以把路打通, 讓這個排序是 小的 > pivot > 大的.
    swap(vecData[i], vecData[j]);
  }
  // 換完後，j 的值一定會小於等於 pivot, 那就跟他換吧.
  swap(vecData[j], vecData[pivotIndex]);
  pivotIndex = j;

  return pivotIndex;
}

void quicksort(vector<int> &vecData, int start, int end)
{
  // base case
  if (start >= end)
    return;

  // general case
  int p = partition(vecData, start, end);

  cout << "p:" << p << endl;
  cout << "start: " << start << " end: " << end << endl;

  quicksort(vecData, start, p - 1);
  quicksort(vecData, p + 1, end);
}

int main()
{
  // vector<int> vecData{5, 3, 4, 1};
  vector<int> vecData{5, 8, 2, 1, 4, 3, 7, 6, 0};

  quicksort(vecData, 0, vecData.size() - 1);

  printVec(vecData);
}
