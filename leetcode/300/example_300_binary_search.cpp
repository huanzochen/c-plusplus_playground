#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
      vector<int> top(nums.size(), 0);

      int piles = 0;

      for(int i = 0; i < nums.size(); i++){
        // 要處理的撲克牌
        int poker  = nums[i];

        // 二分查找
        int left = 0, right = piles;
        while(left < right){
          int mid = (left + right) / 2;
          if(top[mid] > poker){
            right = mid;
          } else if(top[mid] < poker){
            left = mid + 1;
          } else {
            right = mid;
          }
        }

        // 沒找到合適的牌堆，新建一堆
        if(left == piles) piles++;

        // 把這張牌堆放到堆頂
        top[left] = poker;

        for(int i =0; i < top.size();i++){
          cout << top[i];
          if(i != top.size()-1) cout << ", ";
        }
        cout << endl;
      }

      return piles;
    }
};

int main()
{

    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};

    Solution *sol;

    cout << (sol->lengthOfLIS(nums) == 4) << endl;
}