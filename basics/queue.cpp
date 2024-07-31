#include <queue>
#include <iostream>
using namespace std;

int main()
{
  queue<int> q;

  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  q.push(6);

  while (!q.empty())
  {
    cout << " Is Q is empty? !q.empty(): " << !q.empty() << endl;

    int nextNode = q.front();

    cout << "The next Node that will pop from q is, nextNode: " << nextNode << endl;

    q.pop();

    // If I insert elements here, the queue will never end.
    q.push(99);
  }
}