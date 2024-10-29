#include <string>
#include <iostream>
#include <vector>

using namespace std;

namespace vars {
  string namespaceScope = "namespaceScope";
}

using namespace vars;

string globalScope = "globalScope";

class ExampleScope{
  public:
  string classScope = "classScope";

  auto operator()(){
    cout << "classScope: " << classScope;
    cout << endl;
  }
};

int main() {
  string localMainScope = "localMainScope";

  ExampleScope example;

  cout << "localMainScope: " << localMainScope << endl;
  cout << "namespaceScope: " << namespaceScope << endl;
  cout << "globalScope: " << globalScope << endl;

  ExampleScope()();
  example();

}