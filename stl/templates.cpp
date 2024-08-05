// complex template functions maybe intimidating.

#include <iostream>
#include <string>
using namespace std;

// The following to are equivalent, the only difference maybe style convention.

// template <typename G>
template <class G>

G getMax(G a, G b)
{
  // If you use your own class, you might sure your own class has overided the greater than operator, or it will cause error.
  return a > b ? a : b;
}

struct Person
{
public:
  string name;
  int age;

  bool operator>(const Person &rhs) const
  {
    return this->age < rhs.age;
  }
};

int main()
{
  int a = 10;
  int b = 15;
  // The c++ can deduce the type by itself.
  cout << "getMax(a, b): " << getMax(a, b) << endl;
  // Or you can explicitly declare the type
  cout << "getMax(a, b): " << getMax<double>(a, b) << endl;

  cout << "getMax(22.5, 33.5): " << getMax(22.5, 33.5) << endl;

  cout << "getMax('a', 'c'): " << getMax('a', 'c') << endl;
  cout << "getMax('A', 'c'): " << getMax('A', 'c') << endl;
  cout << "getMax('a', 'C'): " << getMax('a', 'C') << endl;

  cout << "getMax('a', 'C'): " << getMax("tommy", "kevin") << endl;

  Person p1{"Tommy", 22};
  Person p2{"Alan", 23};

  Person p3 = getMax(p1, p2);
  cout << p3.name << " is younger." << endl;
}