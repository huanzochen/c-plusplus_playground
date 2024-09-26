#include <vector>
#include <iostream>

using namespace std;

class Vertex
{
public:
  int id;
  vector<Vertex *> neighbors;
};

void traverse(Vertex *s, vector<bool> visited)
{
  // base case
  if (s == nullptr)
  {
    return;
  }
  if (visited[s->id])
  {
    // prevent looping
    return;
  }
  // prefix location
  visited[s->id] = true;
  cout << "visit " << s->id << endl;
  for (auto neighbor : s->neighbors)
  {
    traverse(neighbor, visited);
  }
}

int main()
{
  // create a test graph
  vector<Vertex *> vertices(5);
  for (int i = 0; i < 5; i++)
  {
    vertices[i] = new Vertex();
    vertices[i]->id = i;
  }

  // add edges
  vertices[0]->neighbors = {vertices[1], vertices[2]};
  vertices[1]->neighbors = {vertices[0], vertices[3]};
  vertices[2]->neighbors = {vertices[0], vertices[4]};
  vertices[3]->neighbors = {vertices[1]};
  vertices[4]->neighbors = {vertices[2]};

  // create visited vector
  vector<bool> visited(5, false);

  traverse(vertices[0], visited);

  return 0;
}