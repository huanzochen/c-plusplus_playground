#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename M>
void printVec(vector<M> vec)
{
  for (int i = 0; i < vec.size(); i++)
  {
    cout << vec[i];
    if (i != vec.size() - 1)
      cout << ", ";
  }
  cout << endl;
}

vector<int> numberOfItems(const string &s, const vector<int> &startIndices, const vector<int> &endIndices)
{
  cout << s << endl;

  int n = s.size();
  vector<int> prefix(n + 1, 0); // prefix[i] stores the number of '*' up to index i
  vector<int> leftPipe(n, -1);  // leftPipe[i] stores the nearest '|' to the left of i (inclusive)
  vector<int> rightPipe(n, -1); // rightPipe[i] stores the nearest '|' to the right of i (inclusive)

  // Build the prefix sum for '*'
  for (int i = 0; i < n; i++)
  {
    prefix[i + 1] = prefix[i] + (s[i] == '*' ? 1 : 0);
  }

  printVec(prefix);

  // Fill leftPipe array
  int lastPipe = -1;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == '|')
      lastPipe = i;
    leftPipe[i] = lastPipe;
  }

  printVec(leftPipe);

  // Fill rightPipe array
  lastPipe = -1;
  for (int i = n - 1; i >= 0; i--)
  {
    if (s[i] == '|')
      lastPipe = i;
    rightPipe[i] = lastPipe;
  }

  printVec(rightPipe);

  vector<int> result;

  // Answer each query
  for (int i = 0; i < startIndices.size(); i++)
  {
    int start = startIndices[i] - 1; // Convert to 0-based index
    int end = endIndices[i] - 1;     // Convert to 0-based index

    // Find the valid range between two '|'s
    int leftBound = rightPipe[start];
    int rightBound = leftPipe[end];

    if (leftBound != -1 && rightBound != -1 && leftBound < rightBound)
    {
      result.push_back(prefix[rightBound + 1] - prefix[leftBound + 1]);
    }
    else
    {
      result.push_back(0);
    }
  }

  return result;
}

int main()
{
  // Example usage:
  string s = "|**|*|*";
  vector<int> startIndices = {1, 1};
  vector<int> endIndices = {5, 6};

  vector<int> result = numberOfItems(s, startIndices, endIndices);

  for (int count : result)
  {
    cout << count << endl; // Outputs: 2, 3
  }

  return 0;
}