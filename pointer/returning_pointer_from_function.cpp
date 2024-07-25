#include <iostream>

using namespace std;

int *create_array(size_t size, int init_value = 0)
{
  int *new_storage{nullptr};
  new_storage = new int[size];
  for (size_t i{0}; i < size; i++)
  {
    // Pointer arithmetic
    *(new_storage + i) = init_value;
    // new_storage[i] = init_value;
  }
  return new_storage;
}

void display(const int *const array, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    cout << array[i] << endl;
  }
  cout << endl;
}

int main()
{
  int *my_array{nullptr};
  size_t size;
  int init_value{};

  cout << "How many interger would you like to allocate?" << endl;
  cin >> size;
  cout << "What value do you like them to initialize to? " << endl;
  cin >> init_value;

  my_array = create_array(size, init_value);

  cout << "\n-----------------------------" << endl;

  display(my_array, size);
  delete[] my_array;
  return 0;
}