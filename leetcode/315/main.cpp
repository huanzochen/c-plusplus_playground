#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  // to save the element for sorting.
  vector<pair<int, int>> temp;

  // 紀錄每個元素比自己小的元素個數
  vector<int> res;

public:
  vector<int> countSmaller(vector<int> &nums)
  {
    temp.resize(nums.size());
    res.resize(nums.size());

    vector<pair<int, int>> arr(nums.size());
    // put the value, and its origin index inside the pair array, to update
    // the count array value, because we want to return the order when the
    // nums comes in.

    for (int i = 0; i < nums.size(); i++)
    {
      arr[i] = make_pair(nums[i], i);
    }

    // after that, we can do what merge sort does, and then modify the
    // things we want.
    sort(arr, 0, arr.size() - 1);

    // test if the array has been sorted.
    // cout << "========= print sorted arr.";
    // for (int i = 0; i < arr.size(); i++) {
    //     // arr's value is save in the first value of the pair.
    //     cout << arr[i].first;
    //     if (i != arr.size() - 1)
    //         cout << ", ";
    // }
    // cout << endl;

    return res;
  }

  // do the merge sort thing.
  void sort(vector<pair<int, int>> &arr, int lo, int hi)
  {
    // base case
    // 代表已經被切到最細了，只有一個 element
    if (lo == hi)
      return;

    // general case
    int mid = (lo + hi) / 2;

    sort(arr, lo, mid);
    sort(arr, mid + 1, hi);

    merge(arr, lo, mid, hi);
  }

  // 將切到最細的 array 們，合併起來
  void merge(vector<pair<int, int>> &arr, int lo, int mid, int hi)
  {
    for (int i = lo; i <= hi; i++)
    {
      // 因為這是一個 pair, 所以這傳遞的其實是 pair.
      temp[i] = arr[i];
    }

    // 再來，開始做 two pointer 去把這些值去做合併的動作.

    int i = lo;
    int j = mid + 1;

    // we know 在合併的過程中, 比 current 小的值是 j - (mid+1)

    cout << "for,========= " << endl;
    cout << "lo: " << lo << " mid: " << mid << " hi: " << hi << endl;

    cout << "the array is now: ";
    for (int i = lo; i <= hi; i++)
    {
      cout << arr[i].first;
      if (i != hi)
        cout << ", ";
    }
    cout << endl;

    for (int k = lo; k <= hi; k++)
    {
      if (i == mid + 1)
      {
        // that means i 已經到底了
        arr[k] = temp[j];
        j++;
      }
      else if (j == hi + 1)
      {
        arr[k] = temp[i];
        i++;

        res[arr[k].second] += j - (mid + 1);

        cout << " 'j == hi + 1', ";
        cout << "the value arr[k]: " << arr[k].first << " has been saved added the smaller number, the smaller number is: " << (j - (mid + 1)) << endl;

        // debug
        // printVec(arr);
        // printStatus(i, j, mid, true);
      }
      else if (temp[i].first > temp[j].first)
      {
        arr[k] = temp[j];
        j++;
      }
      else if (temp[j].first >= temp[i].first)
      {
        arr[k] = temp[i];
        i++;

        res[arr[k].second] += j - mid - 1;

        cout << "the value arr[k]: " << arr[k].first << " has been saved added the smaller number, the smaller number is: " << (j - (mid + 1)) << endl;

        // debug
        // printVec(arr);
        // printStatus(i, j, mid, false);
      }
      else
      {
        cout << "it should not be here.";
      }
    }

    cout << endl;
  }

  template <typename T, typename M>
  void printVec(vector<pair<T, M>> &vecData)
  {
    // cout << "printvec: ";
    for (int i = 0; i < vecData.size(); i++)
    {
      cout << vecData[i].first;
      if (i != vecData.size() - 1)
        cout << ", ";
    }
    cout << endl;
  }

  void printStatus(int i, int j, int mid, bool isJEnd)
  {
    cout << "i: " << i << " "
         << "j: " << j << " "
         << "mid: " << mid << endl;
    if (isJEnd)
      cout << "j == hi + 1, ";
    cout << "j - (mid+1): " << j - (mid + 1) << endl;
  }
};

int main()
{
  Solution sol;

  vector<int> material{5, 2, 6, 3};

  sol.countSmaller(material);
}