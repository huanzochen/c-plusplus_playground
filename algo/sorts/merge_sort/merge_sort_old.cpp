#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void merge(vector<int> &nums, int start, int mid, int end)
  {

    // p1: start ~ mid
    // p2: mid + 1 ~ end

    // 利用雙指針技巧來合併數組
    int p1 = start;
    int p2 = mid + 1;

    vector<int> temp;

    // 在這兩個還沒到底的情況下
    while (p1 <= mid && p2 <= end)
    {
      if (nums[p1] < nums[p2])
      {
        temp.push_back(nums[p1]);
        p1++;
      }
      else if (nums[p2] <= nums[p1])
      {
        temp.push_back(nums[p2]);
        p2++;
      }
    }
    // if (p1 <= mid)
    if (p2 == end + 1)
    {
      temp.insert(temp.end(), nums.begin() + p1, nums.begin() + mid + 1);
    }
    // else if (p2 <= end)
    else if (p1 <= mid + 1)
    {
      temp.insert(temp.end(), nums.begin() + p2, nums.begin() + end + 1);
    }

    // cout << "start: " << start << " mid:" << mid << " end: " << end << endl;
    // cout << "temp content" << endl;
    // for (int i = 0; i < temp.size(); i++)
    // {
    //   cout << temp[i];
    //   if (i != temp.size() - 1)
    //     cout << ", ";
    // }
    // cout << endl;

    // temp 裡面就有我要的答案們了, 而且已經排序好
    // temp 的 index 是從 0 開始 0 ~ (end-start);
    // 把他對應到 nums 上面
    for (int i = start; i <= end; i++)
    {
      nums[i] = temp[i - start];
    }

    // cout << "nums content" << endl;
    // for (int i = 0; i < nums.size(); i++)
    // {
    //   cout << nums[i];
    //   if (i != nums.size() - 1)
    //     cout << ", ";
    // }
    // cout << endl;
  }

  void mergesort(vector<int> &nums, int start, int end)
  {
    // base case
    if (start >= end)
      return;

    // general case
    int mid = floor(start + (end - start) / 2);

    mergesort(nums, start, mid);
    mergesort(nums, mid + 1, end);

    // start, mid, end: 0,0,1

    merge(nums, start, mid, end);
  }

  vector<int> sortArray(vector<int> &nums)
  {
    mergesort(nums, 0, nums.size() - 1);
    return nums;
  }
};

int main()
{
  Solution sol;

  vector<int> test{5, 1, 1, 2, 0, 0};
  sol.sortArray(test);

  for (int i = 0; i < test.size(); i++)
  {
    cout << test[i];
    if (i != test.size() - 1)
      cout << ", ";
  }
}