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

    vector<int> temp;

    for (int i = start; i <= end; i++)
    {
      temp.push_back(nums[i]);
    }

    // cout << "start: " << start << " mid:" << mid <<" end: " << end << endl;
    // cout << "temp content" << endl;
    // for (int i = 0; i < temp.size(); i++) {
    //     cout << temp[i];
    //     if (i != temp.size() - 1)
    //         cout << ", ";
    // }
    // cout << endl;

    // 利用雙指針技巧來合併數組
    int p1 = start;
    int p2 = mid + 1;

    for (int p = start; p <= end; p++)
    {
      // 如果 p1 到底了
      if (p1 == mid + 1)
      // if (p2 <= end), 不行這樣做，因為這個 for 回圈 會依序處理四個情況，所以要明確的點出 p1 的終止條件，然後處理 p2.
      {
        nums[p] = temp[p2 - start];
        p2++;
      }
      // 如果 p2 到底了
      else if (p2 == end + 1)
      // if(p1 <= mid), 不行這樣做，因為這個 for 回圈 會依序處理四個情況，所以要明確的點出 p2 的終止條件，然後處理 p1.
      {
        nums[p] = temp[p1 - start];
        p1++;
      }
      // 如果 p1 指針比 p2 大
      else if (temp[p1 - start] > temp[p2 - start])
      {
        nums[p] = temp[p2 - start];
        p2++;
      }
      // 如果 p2 指針比 p1 大
      else if (temp[p2 - start] >= temp[p1 - start])
      {
        nums[p] = temp[p1 - start];
        p1++;
      }
      else
      {
        cout << "should not be here" << endl;
        // cout << "p1: " << p1 << " p2: " << p2 << endl;

        // cout << "p2 - start:" << (int)(p2 - start) << " p1 - start:" << (int)(p1 - start) << endl;
        // cout << "temp[p2 - start]:" << temp[p2 - start] << " temp[p1 - start]:" << temp[p1 - start]<< endl;
      }
    }

    // cout << "nums content" << endl;
    // for (int i = 0; i < nums.size(); i++) {
    //     cout << nums[i];
    //     if (i != nums.size() - 1)
    //         cout << ", ";
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