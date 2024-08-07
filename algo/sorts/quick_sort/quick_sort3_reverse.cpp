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
  int pivotIndex = end;
  int pivot = vecData[pivotIndex];

  int i = start;
  int j = end - 1;

  // i, j 有可能兩者相等
  // 在只剩一個元素的情況下, 例如 start 1, end 1, 那 i = 2, j = 1, 就不會進來了
  while (i <= j)
  {

    // 停下來時剛好 vecData[i] 大於 pivot, 或到 array 的 end.
    // i moves to the right, stopping when it finds an element greater than the pivot or reaches the end of the range.
    while (i < end && vecData[i] < pivot)
    {
      i++;
    }

    // 停下來的時候剛好 vecData[j] 小於 pivot, 或到 array 的 start.
    // j moves to the left, stopping when it finds an element less than or equal to the pivot or reaches the start of the range.
    while (j > start && vecData[j] >= pivot)
    {
      j--;
    }

    // 一樣就不用 swap 了.
    if (i >= j)
    {
      break;
    }

    // 這兩個值，應該要被互換，這樣才可以把路打通, 讓這個排序是 小的 > pivot > 大的.
    swap(vecData[i], vecData[j]);
  }
  // 換完後，i 的值一定會大於或等於 pivot, 那就跟他換吧, 要跟 i 換因為他是向右走，最後有機會跟 pivot 撞再一起
  swap(vecData[i], vecData[pivotIndex]);
  pivotIndex = i;

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