#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        // what is the length of the nums vector?
        // what is the constraint of nums[i]?

        // the output value should between 1 ~ nums.size()
        // it is at least 1, itself.

        // A. Brute force
        // we can try from the start

        // Assume nums has N element
        // for loop 0 ~ N-1
        // index -> index+1, i+2, i+3
        // for loop i ~ N-1
        // 0 -> 1, 2, 3...
        // 1-> 2,3,4...

        // time complexity will be O(N^2)

        // B. dynamic programming
        // does this have sub problem? v
        // does it have optimial sub structure?
        // is it searching for a max/min value? v

        // we treated each element as it's sub problem
        // with 10, the possibility for it is 10 itself, only 1.
        // with 9, the possibility will be [10, 9], [9], obviously, there is
        // only one solution, itself...

        // with 7, the possibility will be [10,9,2,5,3,7] , ..... ,  [7], it we
        // search for the answer of 3, we can combine the previous answer in
        // other value we have find already like we can take the 3 result is
        // "2", and add it one on it to be three max(max(10,9,2,5,3) + 1(7),
        // 1(7)) dp[i] = [dp[0...i-1]+1, dp[i]].

        // dp[i] = max(dp[j] + 1) for all j where nums[j] < nums[i] and j < i.
        // j number should smaller than i , and j should in front of i.

        vector<int> dp(nums.size(), 1);

        for (int i = 1; i < dp.size(); i++)
        {
            int cur = nums[i];
            // find the previous biggest value
            for (int j = 0; j < i; j++)
            {
                int prev = nums[j];
                if (prev < cur)
                {
                    // biggestPrev = max(biggestPrev, dp[j]);
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            // dp[i] = max(biggestPrev + 1, dp[i]);
        }

        // after this for loop, we saved all the value in dp array,
        // and lets find the biggest one.

        int res = INT_MIN;
        for (int i = 0; i < dp.size(); i++)
        {
            res = max(res, dp[i]);
        }

        return res;
    }
};

int main()
{

    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};

    Solution *sol;

    cout << (sol->lengthOfLIS(nums) == 4) << endl;
}