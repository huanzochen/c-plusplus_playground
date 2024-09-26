#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

struct Edge
{
  int to;
  int weight;

  Edge(int to, int weight) : to(to), weight(weight) {}
};

class WeightedGraph
{
public:
  vector<vector<int>> matrix;

  // Constructor
  WeightedGraph(int n)
  {
    matrix = vector<vector<int>>(n, vector<int>(n, 0));
  }

  // this will be O(1)
  void addEdge(int from, int to, int weight)
  {
    matrix[from][to] = weight;

    // cout << "matrix[from][to]:" << matrix[from][to] << endl;
    printf("matrix[%d][%d]: %d \n", from, to, matrix[from][to]);
  }

  // This will also be O(1), the advantage of using two dimensional array
  void removeWdge(int from, int to)
  {
    matrix[from][to] = 0;
  }

  bool hasEdge(int from, int to)
  {
    return matrix[from][to] != 0;
  }

  int weight(int from, int to)
  {
    return matrix[from][to];
  }

  // 查, 返回某個節點的所有鄰居節點
  // 以一個 from 來說, 所有 to 都是他的鄰居？ 是.
  vector<Edge> neighbors(int v)
  {
    vector<Edge> res;
    cout << "matrix[v].size(): " << matrix[v].size() << endl;
    for (int i = 0; i < matrix[v].size(); i++)
    {
      if (matrix[v][i] > 0)
      {
        res.push_back(Edge(i, matrix[v][i]));
      }
    }
    return res;
  }
};

int main()
{
  WeightedGraph graph(4);
  graph.addEdge(0, 1, 3);
  graph.addEdge(1, 2, 2);
  graph.addEdge(2, 1, 40);
  graph.addEdge(2, 3, 10);
  graph.addEdge(2, 12, 10); // this could leads to unexpected behavior
  graph.addEdge(3, 7, 88);

  vector<Edge> neighbors = graph.neighbors(2);

  for (int i = 0; i < neighbors.size(); i++)
  {
    printf("neighbors[%d].weight: %d  \n", i, neighbors[i].weight);
  }

  // graph.addEdge(7, 19, 88);
}