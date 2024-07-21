#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>

class Account
{
public:
  void set_name(const std::string &n);

  std::string get_name();

  bool deposit(int b);
  bool withdraw(int b);

  int get_balance();

  std::string get_status();

private:
  std::string name;
  int balance{0};
  std::string status;
};

#endif // _ACCOUNT_H_