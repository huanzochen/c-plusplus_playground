#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<int> vec{2, 3, 5, 62, 1, 3, 56, 8, 82, 3};

  quicksort(vec);

  for (int i = 0; i < vec.size(); i++)
  {
    int cur = vec[i];
    cout << cur;
    if (i != vec.size() - 1)
    {
      cout << ", ";
    }
  }
}

int partition(vector<int> &vec, int lo, int hi)
{
  return 0;
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
  sort(vec, 0, vec.size() - 1);
}
