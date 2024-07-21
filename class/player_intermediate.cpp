#include <iostream>
#include <string>

using namespace std;

class Account
{
public:
  void set_name(string n) { name = n; };
  string get_name() { return name; };
  void deposit(int b) { balance = b; };
  int get_balance() { return balance; };

private:
  string name;
  int balance{0};
};

int main()
{
  Account frank_account;

  frank_account.set_name("frank");
  cout << "frank name is: " << frank_account.get_name() << endl;
  frank_account.deposit(1000);
  cout << "frank's balance is: " << frank_account.get_balance() << endl;
}