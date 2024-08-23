#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printVec(vector<T> &vecData)
{
  for (int i = 0; i < vecData.size(); i++)
  {
    cout << vecData[i];
    if (i != vecData.size() - 1)
      cout << ", ";
  }
  cout << endl;
}

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

  // erase a value by iterator, erase can only called by iterator.
  modifierExample.erase(modifierExample.begin());
  printVector(modifierExample);

  cout << "====================" << endl;

  vector<int> oneToTen(10);

  for (int i = 0; i < oneToTen.size(); i++)
  {
    oneToTen[i] = i + 1;
  }
  printVec(oneToTen);

  vector<int> oneToTen2;
  for (int i = 0; i < 10; i++)
  {
    oneToTen2.push_back(i + 1);
  }
  printVec(oneToTen2);

  oneToTen.resize(5);
  printVec(oneToTen);
  oneToTen2.resize(5, 0);
  printVec(oneToTen2);
  // fill with 0 with the new field
  oneToTen2.resize(10, 0);
  printVec(oneToTen2);
}
