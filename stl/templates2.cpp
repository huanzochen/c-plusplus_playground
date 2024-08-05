#include <iostream>
#include <string>

using namespace std;

struct Person
{
public:
  string name;
  int age;

  void sayHi()
  {
    cout << "Hello! my name is " << name << "!" << endl;
  }

  bool operator>(const Person &rhs)
  {
    return this->age > rhs.age;
  }
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
  os << p.name;
  return os;
}

template <typename T>
T getMax(T a, T b)
{
  return a > b ? a : b;
}

template <typename T1, typename T2>
void printAll(T1 a, T2 b)
{
  cout << a << " " << b << endl;
}

int main()
{
  Person p1{"Tommy", 22};
  Person p2{"Alan", 23};

  cout << getMax(p1, p2) << endl;
}