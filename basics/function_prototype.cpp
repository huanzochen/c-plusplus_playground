#include <iostream>

using namespace std;

// Function prototype, it can be put in .h files. Header files.
double area_of_circle(double);
double calc_area_circle(double radius);
void sayHello();

const double pi = 3.14159;

int main()
{
  cout << area_of_circle(5) << endl;
  sayHello();
}

void sayHello()
{
  cout << "Hello world" << endl;
}

double area_of_circle(double radius)
{
  return calc_area_circle(radius);
}

double calc_area_circle(double radius)
{
  return pi * radius * radius;
}