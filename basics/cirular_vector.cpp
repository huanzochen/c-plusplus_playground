#include <iostream>
#include <vector>

using namespace std;

int main()
{

  vector<int> arr{1, 2, 3, 4};
  int index = 0;

  // while (index < 100)
  // {
  //   // circular
  //   cout << arr[index % arr.size()] << endl;
  //   index++;
  // }
  // 输出：1,2,3,4,1,2,3,4,1,2,3,4...

  // the length should be power of 2.
  // how to extend the length to power of 2, see: https://graphics.stanford.edu/~seander/bithacks.html#RoundUpPowerOf2
  vector<int> arr2{1, 2, 3, 4, 5, 6, 7, 8};
  int index2 = 0;
  while (index2 < 100)
  {
    // circular
    cout << arr2[index2 & arr2.size() - 1] << endl;
    index2++;
  }
  // 输出：1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4...
}