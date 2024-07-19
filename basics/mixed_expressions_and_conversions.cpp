#include <iostream>

using namespace std;

int main()
{
  int amount{100};
  int number{8};

  double average{};

  average = amount / number;
  cout << "The average of it, it will be convert to int, cause the two is both int.\naverage: " << average << endl;

  average = static_cast<double>(amount) / number;
  cout << "The average of it, it will be convert to int, cause the two is both int.\naverage: " << average << endl;
}