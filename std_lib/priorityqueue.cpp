#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class CustomCompare{
  public:
  bool operator()(int a, int b){
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
}