#include <iostream>
#include "Account.h"

using namespace std;

int main()
{
  Account tommy;

  tommy.set_name("tommy");
  tommy.deposit(1000);
  cout << tommy.get_status() << endl;

  tommy.withdraw(200);
  cout << tommy.get_status() << endl;
}