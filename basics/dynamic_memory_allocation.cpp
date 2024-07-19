#include <iostream>

using namespace std;

int main()
{
  int *intPtr{nullptr};
  intPtr = new int;

  // Print the memory address of intPtr
  cout << intPtr << endl;

  // Print the the value in the pointer, this should contain garbage data
  cout << *intPtr << endl;

  *intPtr = 100;
  cout << intPtr << endl;
  cout << *intPtr << endl;

  delete intPtr; // frees the allocated storage
  cout << intPtr << endl;
  cout << *intPtr << endl;

  cout << "==========Second Test ===========" << endl;

  size_t size{0};
  double *temp_ptr{nullptr};

  cout << "How many temps?" << endl;
  cin >> size;

  // This will cause memory leak
  // while (true)
  // {
  //   temp_ptr = new double[size];
  // }

  temp_ptr = new double[size];

  cout << temp_ptr << endl;
  cout << *temp_ptr << endl;
}