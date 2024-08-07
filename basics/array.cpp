#include <iostream>
#include <string>
#include <array>

using namespace std;

template <typename V>
struct TrieNode
{
  V val;
  array<TrieNode *, 256> children;

  // Constructor
  TrieNode() : val(V())
  {
    children.fill(nullptr);
  }

  // Destructor
  ~TrieNode()
  {
    // for(int i = 0; i < children.size(); i++){
    //   delete children[i];
    // }
    for (TrieNode *child : children)
    {
      delete child;
    }
  }
};

template<typename J>
class TestInitializer{
public:
  J value;

  // Constructor
  TestInitializer(J val): value(val) {
  }
};

template<typename J>
class TestInitializerNoDefault{
public:
  J value;

  // Constructor
  TestInitializerNoDefault(): value(J()) {
  }
};

int main()
{
  // STL array
  array<int, 10> test{};
  test.fill(-1);

  cout << endl
       << "array test: " << test[1] << endl;

  // C-style array, more primitive
  // no method function provided.
  int testPrimitive[10]{};
  for (int i = 0; i < 10; i++)
  {
    cout << testPrimitive[i];
    if(i != 9) cout << ", ";
  }
  cout << endl;

  TrieNode<int> *root = new TrieNode<int>();
  root->val = 1;
  root->children['a'] = new TrieNode<int>();
  root->children['a']->val = 1;

  cout <<"root->children['a'].val: " << (root->children['a']->val) << endl;

  delete root;

  int content = 10;
  TestInitializer<int> init(content);
  cout << "init.value: " << init.value << endl;

  TestInitializerNoDefault<int> initND;
  cout << "initND.value: " << initND.value << endl;

  cout << int() << endl;
  cout << string() << endl;

  return 0;
}