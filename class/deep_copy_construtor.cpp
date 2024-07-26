#include <iostream>

using namespace std;

class Deep
{
private:
  int *data;

public:
  void set_data_value(int d) { *data = d; }
  int get_data_value() { return *data; }

  // Constuctor
  Deep(int d);
  // Copy Constructor
  Deep(const Deep &source);
  // Destructor
  ~Deep();
};

Deep::Deep(int d)
{
  data = new int;
  *data = d;
}

// Deep::Deep(const Deep &source)
// {
//   data = new int;

//   // copy by value
//   *data = *source.data;

//   cout << "Copy constructor - deep copy" << endl;
// }

// Deep::Deep(const Deep &source)
// {
//   data = new int;

//   // copy by value
//   *data = *source.data;

//   cout << "Copy constructor - deep copy" << endl;
// }

// delegating
Deep::Deep(const Deep &source) : Deep{*source.data}
{
  cout << "Copy constructor - deep copy" << endl;
}

Deep::~Deep()
{
  delete data;
  cout << "Destructor freeing data." << endl;
}

void display_shallow(Deep s)
{
  cout << s.get_data_value() << endl;
}

int main()
{
  Deep obj1{100};
  display_shallow(obj1);
}