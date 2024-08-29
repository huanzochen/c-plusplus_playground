#include <iostream>
#include <vector>
#include <string>

using namespace std;

// will return index
int binary_search_left_close_right_open(vector<int> &nums, int &target)
{
  int l = 0;
  int r = nums.size();

  while (l < r)
  {
    int mid = l + ((r - l) / 2);

    if (nums[mid] == target)
    {
      return mid;
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

  return -1;
}

// will return index
int binary_search_left_close_right_close(vector<int> &nums, int &target)
{
  int l = 0;
  int r = nums.size() - 1;

  while (l <= r)
  {
    int mid = l + ((r - l) / 2);

    if (nums[mid] == target)
    {
      return mid;
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

  return -1;
}

int main()
{
  vector<int> nums{0, 0, 0, 0, 1, 2, 2, 2, 3, 4, 8, 8, 9, 10};
  cout << "nums.size(): " << nums.size() << endl;
  int target = 2;

  // will return a index, convert it to nums
  cout << "nums: " << nums[binary_search_left_close_right_open(nums, target)] << " index: " << binary_search_left_close_right_open(nums, target) << endl;

  cout << "nums: " << nums[binary_search_left_close_right_close(nums, target)] << " index: " << binary_search_left_close_right_close(nums, target) << endl;
}