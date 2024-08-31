#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
  int tmp = a;
  a = b;
  b = tmp;
}

int main()
{

  vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // I want to shuffle the nums in equal opportunity

  // if I want to get a random number between 0~9
  // cout << std::rand() % 10 << endl;

  int n = nums.size();

  for (int i = 0; i < n; i++)
  {
    // 假設 i 為 3, 我就得到一個 3~10 的整數
    int r = i + rand() % (n - i);

    swap(nums[r], nums[i]);
  }

  // 對於 n 個資料, permutation, it will have n! of possibilities
  // because with n[0], it has n possiblities
  // with n[1] , it has n-1
  // n[2] it has n-2
  // ......
  // n * n-1 * n-2... 1 == n!

  // and this shuffle algorithm. can proof that.

  for (int i = 0; i < n; i++)
  {
    cout << nums[i];
    if (i != n - 1)
      cout << " ";
  }
}