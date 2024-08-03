#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int> &vec)
{
  // cout << "printVec=================" << endl;
  for (int i = 0; i < vec.size(); i++)
  {
    int cur = vec[i];
    cout << cur;
    if (i != vec.size() - 1)
    {
      cout << ", ";
    }
  }
  cout << endl;
}

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

int partition(vector<int> &vec, int lo, int hi)
{
  int pivot = vec[lo];
  // i, j 定義為開區間, 同時定義
  // [lo, i) <= pivot; (j, hi] > pivot
  // 之後都要正確維護這個邊界區間的定義

  int i = lo + 1; // lo 已經被取成 pivot 吧, 所以是 lo + 1
  int j = hi;

  while (i <= j)
  {

    while (i < hi && vec[i] <= pivot)
    {
      i++;
      // 此 while 結束時剛好 vec[i] > pivot
    }
    while (j > lo && vec[j] > pivot)
    {
      j--;
      // 此 while 結束時恰好 vec[j] <= pivot
    }

    if (i >= j)
    {
      break;
    }

    // 此時 [lo, i) <= pivot && (j, hi] > pivot
    // 交換 vec[j] 和 vec[i]
    swap(vec[i], vec[j]);
    // 此時 [lo, i] <= pivot && [j, hi] > pivot
  }

  swap(vec[lo], vec[j]);

  return j;
}

// This is a recursive function, it will traverse through all the value.
void sort(vector<int> &vec, int lo, int hi)
{
  // base case
  if (lo >= hi)
  {
    return;
  }

  // general case

  // 對 nums[lo..hi] 進行切分
  // 使得 nums[lo..p-1] <= nums[p] < nums[p+1..hi]
  int p = partition(vec, lo, hi);

  sort(vec, lo, p - 1);
  sort(vec, p + 1, hi);
}

void quicksort(vector<int> &vec)
{
  // cout << "vec[4]: " << vec[4] << endl;
  sort(vec, 0, vec.size() - 1);
}

int main()
{
  vector<int> vec{2, 3, 5, 62, 1, 3, 56, 8, 82, 3};

  quicksort(vec);

  printVec(vec);
}
