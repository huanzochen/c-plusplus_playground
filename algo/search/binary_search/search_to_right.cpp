#include <iostream>
#include <vector>
#include <string>

using namespace std;

// If I want to search the left bound at the target, and right bound

int binary_search_left_close_right_open(vector<int> &nums, int target)
{
  // using binary search variant to find the result
  // 左閉右開的寫法:

  int l = 0;
  int r = nums.size();

  while (l < r)
  {
    int mid = l + ((r - l) / 2);

    if (nums[mid] == target)
    {
      l = mid + 1;
    }
    else if (nums[mid] < target)
    {
      l = mid + 1;
    }
    else if (nums[mid] > target)
    {
      r = mid;
    }
  }

  return r - 1;
}

int binary_search_left_close_right_close(vector<int> &nums, int target)
{
  // 左閉右閉的寫法

  int l = 0;
  int r = nums.size() - 1;

  while (l <= r)
  {
    int mid = l + ((r - l) / 2);

    if (nums[mid] == target)
    {
      // 不知道找到哪一個 target, 有複數個，但我們要盡可能往右邊靠, 並且把目前找到的這個排除
      // 如果找到太大的值，下面的判斷式會減回來
      l = mid + 1;
    }
    else if (nums[mid] < target)
    {
      l = mid + 1;
    }
    else if (nums[mid] > target)
    {
      r = mid - 1;
    }
  }
  return r;
}

int main()
{
  vector<int> nums{0, 0, 0, 0, 1, 2, 2, 2, 3, 4, 8, 8, 9, 10};
  cout << "nums.size(): " << nums.size() << endl;
  int target = 2;

  // will return a index, convert it to nums
  cout << "nums: " << nums[binary_search_left_close_right_open(nums, target)] << " index: " << binary_search_left_close_right_open(nums, target) << endl;

  cout << "nums: " << nums[binary_search_left_close_right_close(nums, target)] << " index: " << binary_search_left_close_right_close(nums, target) << endl;

  int target2 = 6;
  cout << "target2: " << target2 << endl;
  // will return a index, convert it to nums
  cout << "nums: " << nums[binary_search_left_close_right_open(nums, target2)] << " index: " << binary_search_left_close_right_open(nums, target2) << endl;

  cout << "nums: " << nums[binary_search_left_close_right_close(nums, target2)] << " index: " << binary_search_left_close_right_close(nums, target2) << endl;

  double target3 = 11;
  cout << "target3: " << target3 << endl;
  // will return a index, convert it to nums
  cout << "nums: " << nums[binary_search_left_close_right_open(nums, target3)] << " index: " << binary_search_left_close_right_open(nums, target3) << endl;

  cout << "nums: " << nums[binary_search_left_close_right_close(nums, target3)] << " index: " << binary_search_left_close_right_close(nums, target3) << endl;
}