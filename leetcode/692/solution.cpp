#include <iostream>
#include <string>
#include <queue>

using namespace std;

template <typename M>
void printAll(vector<M> res){
  int n = res.size();
  for(int i = 0; i < n; i++){
    cout << res[i];
    if(i != n-1) cout << ", ";
  }
  cout << endl;
}

class Solution
{
public:
  class Comparator
  {
  public:
    auto operator()(pair<int, vector<string>> a, pair<int, vector<string>> b)
    {
      return a.first < b.first;
    }
  };

  vector<string> countPair(unordered_map<int, vector<string>> &freqMap)
  {
    priority_queue<pair<int, vector<string>>, vector<pair<int, vector<string>>>, Comparator> maxHeap;

    // put the freqMap data into maxHeap.
    for (pair<int, vector<string>> cur: freqMap)
    {
      maxHeap.push(cur);
    }

    // In the maxHeap, it will have 3 elements, with 10 words.
    // if we want to take 5, the words we want to take will always smaller then total words.
    int k = 5;

    // k = 5 words out, and the result which is in the same words, will be arrange in lexicographical order.
    vector<string> res;
    int count = 0;
    while (count < k)
    {
      auto pairOfFreq = maxHeap.top();
      maxHeap.pop();

      vector<string> listString = pairOfFreq.second;
      // sort the string with same freq in lexicographical order
      sort(listString.begin(), listString.end());
      int lenOfList = listString.size();

      printAll(listString);
      int lenToAdd = 0;
      if (count + lenOfList > k)
      {
        lenToAdd = k - count;
      }
      else
      {
        lenToAdd = lenOfList;
      }
      res.insert(res.end(), listString.begin(), listString.begin() + lenToAdd);
      count += lenToAdd;
    }

    return res;
  }
};

int main()
{
  Solution sol;
  unordered_map<int, vector<string>> freqMap{{0, {"person", "Leo", "Alice"}}, {1, {"word", "cat", "dog", "tommy"}}, {2, {"nn", "ashley", "apple"}}};

  vector<string> res = sol.countPair(freqMap);

  printAll(res);
}