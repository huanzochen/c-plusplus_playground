#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{

  vector<int> track{5, 4, 3, 2, 1};

  string res;

  for (auto c : track)
  {
    cout << "c: " << c << endl;

    res.push_back(c + '0');
  }

  cout << "res: " << res << endl;
}