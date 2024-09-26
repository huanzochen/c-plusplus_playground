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
  int pivotIdx = end;
  int pivot = vec[pivotIdx];

  int l = start;
  int r = end - 1;

  cout << "===== Before Swap " << endl;
  printVec(vec);

  while (l <= r)
  {
    while (l <= end - 1 && vec[l] < pivot)
    {
      l++;
    }

    while (r >= start && vec[r] > pivot)
    {
      r--;
    }

    // 因為 l 和 r 不一定只走一步，如果他們已經相等，或相互超過了，那就應該被立即結束, 否則會交換到奇怪的內容。
    if (l >= r)
    {
      break;
    }

    // 當他們兩個都不動了，就會停在需要互換的位置
    swap(vec[l], vec[r]);
  }

  printLAndR(l, r, vec);
  printVec(vec);

  // 等到都交換完之後，l 會是恰恰比 pivot 大一點的值，跟 l 交換可以讓 pivot 位於所有數字的中間位置.
  swap(vec[pivotIdx], vec[l]);

  cout << "===== After Swap " << endl;
  printVec(vec);

  cout << "===== End =====" << endl;

  pivotIdx = l;
  return pivotIdx;
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
  vector<int> testData{5, 8, 2, 1, 4, 3, 7, 6, 0};

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