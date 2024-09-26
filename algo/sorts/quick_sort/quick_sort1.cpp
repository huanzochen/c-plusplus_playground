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
  int &pivot = vec[start];
  int pivotIndex = start;

  for (size_t i = start + 1; i <= end; i++)
  {
    int &current = vec[i];
    if (current < pivot)
    {
      pivotIndex++;

      if (i != pivotIndex)
        swap(current, vec[pivotIndex]);
    }
  }
  swap(vec[start], vec[pivotIndex]);

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