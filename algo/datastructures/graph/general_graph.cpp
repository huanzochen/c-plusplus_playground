#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

// 存儲相鄰節點，及邊的權重
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

class Graph
{
public:
  // 添加一條邊 (帶權重)
  virtual void addEdge(int from, int to, int weight) = 0;

  // 删除一条边
  virtual void removeEdge(int from, int to) = 0;

  // 判断两个节点是否相邻
  virtual bool hasEdge(int from, int to) = 0;

  // 返回一条边的权重
  virtual int weight(int from, int to) = 0;

  // 返回某个节点的所有邻居节点和对应权重
  virtual vector<Edge> neighbors(int v) = 0;

  // 返回节点总数
  virtual int size() = 0;

  // 虚拟析构函数，确保子类正确释放资源
  virtual ~Graph() {}
};

class WeightedDigraph
{
public:
  vector<vector<Edge>> graph;

  WeightedDigraph(int n)
  {
    // 我们这里简单起见，建图时要传入节点总数，这其实可以优化
    // 比如把 graph 设置为 Map<Integer, List<Edge>>，就可以动态添加新节点了
    graph = vector<vector<Edge>>(n);
  }

  // 添加一條帶權重的有向邊，複雜度 O(1)
  void addEdge(int from, int to, int weight)
  {
    graph[from].push_back(Edge(to, weight));
  }

  // 刪, 刪除一條有向邊，複雜度 O(V)
  // 找到對應的有向邊，刪除
  void removeEdge(int from, int to)
  {
    vector<Edge> &node = graph[from];
    for (auto it = node.begin(); it != node.end(); it++)
    {
      cout << "it->to: " << it->to << endl;
      if (it->to == to)
      {
        graph[from].erase(it);
        break;
      }
    }
  }

  // 查 找出兩個節點是否相鄰，複雜度 O(V)
  // 從 from 的 array 裡存的節點中，有沒有 to. 有 to 的話代表他們相鄰.
  bool hasEdge(int from, int to)
  {
    auto node = graph[from];
    for (auto e : node)
    {
      if (e.to == to)
      {
        return true;
      }
    }
    // 找不到的話就是沒有
    return false;
  }

  // 查，返回一条边的权重，复杂度 O(V)
  int weight(int from, int to)
  {
    for (auto e : graph[from])
    {
      if (e.to == to)
      {
        return e.weight;
      }
    }

    // if not found the current to node
    throw invalid_argument("No such edge");
  }

  // 查, 返回節點的所有鄰居節點, 複雜度 O(1)
  // why neighbors need & neighbors here?
  vector<Edge> neighbors(int v)
  {
    return graph[v];
  }
};

int main()
{
  WeightedDigraph graph(3);
  graph.addEdge(0, 1, 1);
  graph.addEdge(1, 2, 2);
  graph.addEdge(2, 0, 3);
  graph.addEdge(2, 1, 4);

  cout << boolalpha;

  cout << graph.hasEdge(0, 1) << endl; // true
  cout << graph.hasEdge(1, 2) << endl; // true
  cout << graph.hasEdge(1, 0) << endl; // false
  cout << graph.hasEdge(0, 2) << endl; // false

  // 返回 2 的所有鄰居節點
  for (const auto &edge : graph.neighbors(2))
  {
    cout << "2 -> " << edge.to << ", weight: " << edge.weight << endl;
  }
  // 2 -> 0, weight: 3
  // 2 -> 1, weight: 4

  graph.removeEdge(0, 1);
  // cout << graph.hasEdge(0, 1) << endl; // false

  // return 0;
}