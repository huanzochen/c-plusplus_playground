#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int> &vec)
{
  for (int i = 0; i < vec.size(); i++)
  {
    int current = vec[i];
    cout << current << " ";
  }
  cout << endl;
}

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
    cout << vowel17[i] << " " << endl;
  }

  // https://cplusplus.com/reference/vector/vector/
  // Modifiers
  cout << "==========Modifiers==========" << endl;

  vector<int> modifierExample = {1, 2, 3, 4, 5, 6};
  printVector(modifierExample);

  // push_back a value
  modifierExample.push_back(7);
  printVector(modifierExample);

  // pop_back a value
  modifierExample.pop_back();
  printVector(modifierExample);

  // insert a value
  modifierExample.insert(modifierExample.begin(), 0);
  printVector(modifierExample);
}