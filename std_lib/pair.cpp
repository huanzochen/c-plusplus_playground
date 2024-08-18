
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  pair<int, int> test(20, 30);

  cout << "pair test:" << test.first << ", " << test.second << endl;

  vector<pair<int, int>> count(5);

  for (int i = 0; i < 5; i++)
  {
    count[i] = make_pair(i, i * 10);
    // count[i] = pair<int, int>(i, i * 10);
  }

  for (auto cur : count)
  {
    cout << "pair: " << cur.first << ", " << cur.second << " ";
  }
}