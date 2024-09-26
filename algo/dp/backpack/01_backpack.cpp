#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 兩個狀態， 背包的容量 && 可選擇的物品

// 裝進背包、不裝進背包

// dp[i][j] 的定義如下：對於當前 i 個物品，當可以裝進去的容量為 j, 裡面存著最大價值 dp[i][j].

// 比如說，選擇三個物品 i = 3, 背包可裝的容量 j 為 5, 那裡頭的最大價值是 6

// dp[0][...] = 0, 當背包沒有任何物品時，裡面裝的價值肯定是 0.
// dp[...][0] = 0, 當背包無法容下任何重量時，裡面裝的價值肯定是 0.

vector<vector<int>> dp;

void printAll(vector<vector<int>> &vecData)
{
  for (int i = 0; i < vecData.size(); i++)
  {
    for (int j = 0; j < vecData[0].size(); j++)
    {
      cout << vecData[i][j] << ", ";
    }
    cout << "   " << endl;
  }
  cout << "==================" << endl;
}

int knapsack(int N, int W, vector<int> &itemValues, vector<int> &itemWeights)
{

  dp = vector<vector<int>>(N + 1, vector<int>(W + 1));
  // for (int i = 0; i <= dp[0].size(); i++)
  // {
  //   dp[0][i] = 0;
  // }

  // intialize
  printAll(dp);

  // for 狀態 1
  // for 狀態 2
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= W; j++)
    {
      if (j - itemWeights[i - 1] < 0)
      {
        // base case
        // 當背包滿的時候
        // 裝不下“當前”物品的重量的時候 (代表背包太重了！！)
        // 1. 這個物品可能太重
        // 2. 背包可能沒重量
        // (但反正就是裝不進去了)

        // sol: 只能選擇不裝物品
        dp[i][j] = dp[i - 1][j];
      }
      else
      {
        // general case
        // 裝得下物品
        // 1. 選擇裝, 價值++
        // 2. 選擇不裝, 跳過

        // 當前物品 == i-1, 因為 i 有一個索引偏移
        dp[i][j] = max(dp[i - 1][j - itemWeights[i - 1]] + itemValues[i - 1], dp[i - 1][j]);
      }
    }
  }

  printAll(dp);

  // return, 裝 N 個物品和 W 的重量所能裝的價值
  return dp[N][W];
}

int main()
{
  // items 的數量
  int items = 3;
  // 可以裝下的總重量
  int maxWeight = 4;
  vector<int> itemValues{4, 2, 3};
  vector<int> itemWeights{2, 1, 3};

  cout << knapsack(items, maxWeight, itemValues, itemWeights) << endl;
}
