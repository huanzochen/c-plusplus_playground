#include <iostream>
#include <vector>

using namespace std;

template<typename M>
void printVec(vector<M> vecData)
{
  for (int i = 0; i < vecData.size(); i++)
  {
    int cur = vecData[i];
    cout << cur;
    if (i != vecData.size() - 1)
    {
      cout << ", ";
    }
  }
  cout << endl;
}

void printLAndR(int l, int r, vector<int> vec){
  for(int i = 0; i < vec.size(); i++){
    // 頭跟尾空兩格
    if(i == 0 || i == vec.size()-1){
      if(((i == l) && (l == r))){
        cout << "lr";
      } else if(i == l){
        cout << "l ";
      } else if(i == r){
        cout << "r ";
      } else if(i == 0){
        cout << ". ";
      } else if(i == vec.size()-1) {
        cout << " .";
      }
    } else {
      if(((i == l )&& (l == r))){
        cout << " lr";
      }
      else if(i == l){
        cout << " l ";
      } else if(i == r){
        cout << " r ";
      } else{
        // 中間三格
        cout << " . ";
      }
    }
  }
  cout << endl;
}

void swap(int &a, int &b)
{
  int tmp = a;
  a = b;
  b = tmp;
}

int pivot_helper(vector<int> &vec, int start, int end)
{
  int pivotIndex = end;
  int pivot = vec[end];

  int l = start;
  int r = end - 1;

  while(l <= r){
    // 先不斷的改位置，改到 l , r 兩邊都不動了，代表需要交換元素,
    // 才可以繼續動下去
    bool isNotMoving = true;

    // 因為一次只動一步，所以裡面不會需要提早結束的 code
    if(vec[l] < pivot){
      l++;
      isNotMoving = false;
    }

    if(vec[r] >= pivot) {
      r--;
      isNotMoving = false;
    }

    // 如果兩個 pointer 都沒在動，代表可以 swap 了.
    if(isNotMoving) {
      swap(vec[l], vec[r]);
      l++;
      r--;
    }
  }

  // 結束之後，看 pivot 在什麼位置, 在 end 的話，那要跟 l 互換，因為 l 會剛好停在，稍微大 pivot 一點的地方.
  swap(vec[pivotIndex], vec[l]);

  printLAndR(l, r ,vec);
  printVec(vec);

  pivotIndex = l;

  return pivotIndex;

}

void quick_sort(vector<int> &vec, int left, int right)
{
  // base case
  if (left >= right)
  {
    return;
  }

  int pivotIndex = pivot_helper(vec, left, right);

  // This could probably be 0, -1, cause the right has -1.
  quick_sort(vec, left, pivotIndex - 1);
  // %his could probably be 2,1 , cause the left has +1.
  quick_sort(vec, pivotIndex + 1, right);
}

int main()
{
  vector<int> testData{5, 8, 2, 2, 1, 4, 4, 3, 7, 7, 6, 0};
  // vector<int> testData{1,2,3,4,5};

  cout << "unsorted result: ";
  for (const auto &i : testData)
  {
    cout << i << " ";
  }
  cout << endl;

  quick_sort(testData, 0, testData.size() - 1);

  cout << "sorted result: ";
  for (auto it = testData.begin(); it != testData.end(); it++)
  {
    cout << *it << " ";
  }
  cout << endl;
}


/**
 *
 *
===== Before Swap
0, 3, 2, 1, 4, 5, 7, 6, 8
.  .  .  lr .  .  .  .  .
0, 3, 2, 1, 4, 5, 7, 6, 8
===== After Swap
0, 3, 2, 4, 1, 5, 7, 6, 8









*/