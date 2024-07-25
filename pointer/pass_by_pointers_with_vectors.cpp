#include <iostream>

using namespace std;

void display(int *array, int sentinel)
{
  while (*array != sentinel)
  {
    cout << *array++ << " ";
  }
  cout << endl;
}

// void display_by_reference(int &array, int sentinel)
// {
//   while (array != sentinel)
//   {
//     cout << array++ << " ";
//   }
//   cout << endl;
// }

int main()
{

  int scores[]{100, 98, 97, 79, -1};

  display(scores, -1);

  // It's not ok because it will treated as a interger
  // display_by_reference(scores, -1);

  cout << endl;
  return 0;
}