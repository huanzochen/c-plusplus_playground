#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

struct Edge
{
  int to;
  int weight;

  Edge(int to, int weight)
  {
    this->to = to;
    this->weight = weight;
  }
};

// Approach 1: vector<vector<Edge>> graph;
class WeightedDigraph1
{
private:
  vector<vector<Edge>> graph;

public:
  WeightedDigraph1(int n) : graph(n) {}

  void addEdge(int from, int to, int weight)
  {
    graph[from].push_back(Edge(to, weight));
  }
};

// Approach 2: vector<vector<Edge*>> graph;
class WeightedDigraph2
{
private:
  vector<vector<Edge *>> graph;

public:
  WeightedDigraph2(int n) : graph(n) {}

  void addEdge(int from, int to, int weight)
  {
    graph[from].push_back(new Edge{to, weight});
  }

  ~WeightedDigraph2()
  {
    for (auto &edges : graph)
    {
      for (Edge *edge : edges)
      {
        delete edge;
      }
    }
  }
};

int main()
{
  WeightedDigraph1 graph1(5);
  graph1.addEdge(0, 1, 20);
  graph1.addEdge(0, 2, 22);
  graph1.addEdge(1, 2, 33);
}