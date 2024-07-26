#include <iostream>
#include <vector>

using namespace std;

class Move
{
private:
  int *data;

public:
  void set_data_value(int d) { *data = d; }
  int get_data_value() { return *data; }

  // Constuctor
  Move(int d);
  // Copy Constructor
  // Move(const Move &source);
  // Move constructor
  Move(Move &&source) noexcept;
  // Destructor
  ~Move();
};

Move::Move(int d)
{
  data = new int;
  *data = d;
}

// Copy constructor with delegating
// Move::Move(const Move &source) : Move{*source.data}
// {
//   cout << "Copy constructor - deep copy:" << *data << endl;
// }

// Move constructor
Move::Move(Move &&source) noexcept : data(source.data)
{
  // u will see lots of moving cout cause vector will expand behind the scene.
  source.data = nullptr;
  cout << "Move constructor - moving resource: " << *data << endl;
};

Move::~Move()
{
  delete data;
  cout << "Destructor freeing data." << endl;
}

void display_shallow(Move s)
{
  cout << s.get_data_value() << endl;
}

int main()
{
  vector<Move> vec;

  vec.push_back(Move{10});

  vec.push_back(Move{20});
  vec.push_back(Move{30});
  vec.push_back(Move{40});

  vec.push_back(Move{50});
}