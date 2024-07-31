
#include <iostream>
#include "Account.h"
#include <string>
void Account::set_name(const std::string &n) { name = n; }

std::string Account::get_name() { return name; }

bool Account::deposit(int b)
{
  balance += b;
  status = "ok!! save money success!";
  return true;
}
bool Account::withdraw(int b)
{
  if (b <= balance)
  {
    status = "ok!! withdraw your money!";
    balance -= b;
    return true;
  }
  else
  {
    status = "error! your money is not enough!";
    return false;
  }
}

int Account::get_balance() { return balance; }

std::string Account::get_status() { return status; }