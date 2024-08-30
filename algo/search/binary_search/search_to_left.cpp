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

    // find the exact value
    if (nums[mid] == target)
    {
      r = mid;
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

  // 如果索引越界，說明目標中無該元素，返回 -1
  // 其實，在這裡， l 不可能小於 0, 但保持索引不越界是個好習慣
  if (l < 0 || l >= nums.size())
  {
    return -1;
  }

  return nums[l] == target ? l : -1;
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
      r = mid - 1;
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

  if (l < 0 || l >= nums.size())
  {
    return -1;
  }
  return nums[l] == target ? l : -1;
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