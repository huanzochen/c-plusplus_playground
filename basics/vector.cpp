#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};
  vector<char> vowel17{'a', 'e', 'i', 'o', 'u'};

  vector<double> hi_temperatures = {365, 80.0};

  vector<int> test_scores = {100, 95, 99};

  for (int i = 0; i < vowel.size(); i++)
  {
    cout << vowel[i];
    cout << endl;
  }

  for (int i = 0; i < vowel17.size(); i++)
  {
    cout << vowel17[i] << " ";
  }
}