#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

int pivot_helper(vector<int> &vec, int start, int end)
{
  int l = start;
  int r = start + 1;

  int pivotIndex = start;
  int pivot = vec[start];

  while(r <= end){
    if(vec[r] < pivot){
      l++;
      swap(vec[r], vec[l]);
    }
    r++;
  }

  swap(vec[pivotIndex], vec[l]);

  pivotIndex = l;

  return pivotIndex;
}

void quick_sort(vector<int> &vec, int left, int right)
{
  if (left < right)
  {
    int pivotIndex = pivot_helper(vec, left, right);

    quick_sort(vec, left, pivotIndex - 1);
    quick_sort(vec, pivotIndex + 1, right);
  }
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