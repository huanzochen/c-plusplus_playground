#include <iostream>
#include <string>

using namespace std;

int main () {
  int even = 2;
  int odd = 1;


  printf("even: %d, with even&1: %d \n", even, even&1);
  printf("odd: %d, with odd&1: %d \n", odd, odd&1);

  return 0;
}