#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class CustomCompare
{
public:
  bool operator()(int a, int b)
  {
    return a < b;
  }
};

int main()
{
  int arr[6]{23, 4, 22, 3, 16, 90};

  // std::priority_queue<int, vector<int>, greater<int>>
  //     heap;

  // auto customCompare = [](int a, int b)
  // { return a > b; };
  // using CompareType = decltype(customCompare);
  // std::priority_queue<int, vector<int>, CompareType>
  //     heap(customCompare);

  std::priority_queue<int, vector<int>, CustomCompare>
      heap;

  for (int i = 0; i < 6; i++)
  {
    heap.push(arr[i]);
  }

  while (!heap.empty())
  {
    std::cout << heap.top();
    heap.pop();
    if (heap.size() > 0)
      std::cout << ", ";
  }
  std::cout << std::endl;

  vector<int> arr2{23, 4, 22, 3, 16, 90};
  sort(arr2.begin(), arr2.end(), [](int a, int b)
       { return a < b; });

  for (int i = 0; i < arr2.size(); i++)
  {
    cout << arr2[i];
    if (i != arr2.size() - 1)
      cout << ", ";
  }
  cout << endl;

  vector<int> material{2, 33, 5, 156, 30, 44, 55};
  // get a min heap
  priority_queue<int, vector<int>, greater<int>> pq;

  for (auto cur : material)
  {
    pq.push(cur);
  }

  while (!pq.empty())
  {
    cout << pq.top();
    pq.pop();
    if (pq.size() > 0)
      cout << ", ";
  }
  cout << endl;

  class Comparatorpq2
  {
  public:
    auto operator()(int a, int b)
    {
      return a > b;
    }
  };

  // make it min heap
  priority_queue<int, vector<int>, Comparatorpq2> pq2;
  for (auto cur : material)
  {
    pq2.push(cur);
  }

  while (!pq2.empty())
  {
    cout << pq2.top();
    pq2.pop();
    if (pq2.size() > 0)
      cout << ", ";
  }
}