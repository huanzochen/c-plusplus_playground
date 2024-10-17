#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Info
{
public:
  string address;
  int graduateTime;

  // constructor
  // Info(string &addr, int graduateTime) : address(addr), graduateTime(graduateTime)
  // {
  // }

  Info()
  {
    this->address = "";
    this->graduateTime = 0;
  }

  // constructor
  Info(string addr, int graduateTime)
  {
    this->address = addr;
    this->graduateTime = graduateTime;
  }
};

class Qualification
{
public:
  string id;
  string name;
  int passTime;

  // constrcutor
  // Qualification(string id, string name, int passTime) : id(id), name(name), passTime(passTime)
  // {
  // }

  // Defualt constructor
  // Qualification()
  // {
  //   this->id = "";
  //   this->name = "";
  //   this->passTime = 0;
  // }

  // consturctor
  Qualification(string id, string name, int passTime)
  {
    this->id = id;
    this->name = name;
    this->passTime = passTime;
  }
};

class Person
{
public:
  Info personalInfo;
  vector<Qualification> qualifications;
  bool isReferral;
  bool isExecutiveReferral;

  // constructor
  // Person(Info &info, vector<Qualification> &quals, bool isRefferral, bool isExecutiveReferral) : personalInfo(info), qualifications(quals), isReferral(isReferral), isExecutiveReferral(isExecutiveReferral)
  // {
  // }

  Person(Info &info, vector<Qualification> &quals, bool isReferral, bool isExecutiveReferral)
  {
    this->personalInfo = info;
    this->qualifications = quals;
    this->isReferral = isReferral;
    this->isExecutiveReferral = isExecutiveReferral;
  }
};

class Validator
{
public:
  virtual bool validate(const Person &candidate) = 0; // Pure virtual function
};

class NewGradValidator : public Validator
{
  virtual bool validate(const Person &candidate) override
  {
    bool isValid = true;

    // Check if address is set
    if (candidate.personalInfo.address.empty())
    {
      cout << "Address is missing";
      isValid = false;
    }

    // Check graduate time for new grads
    int currentDate = 202301;
    int graduateTime = candidate.personalInfo.graduateTime;
    if (!(graduateTime >= currentDate - 6 && graduateTime <= currentDate + 12))
    {
      cout << "Graduate is outside of 6 to 12 months range.";
      isValid = false;
    }

    return isValid;
  }
};

class ExecutiveReferralValidator : public Validator
{
public:
  virtual bool validate(const Person &candidate) override
  {
    if (candidate.isExecutiveReferral && !candidate.isReferral)
    {
      cout << "Executuve referral should also be reffereal.";
      return false;
    }
    return true;
  }
};

void validateCandidate(const Person &candidate, vector<Validator *> &validators)
{
  bool allValid = true;
  for (auto &validator : validators)
  {
    if (!validator->validate(candidate))
    {
      allValid = false;
    }
  }

  if (allValid)
  {
    cout << "Cadidate passed all validations";
  }
  else
  {
    cout << "Cadidate failed one or more validations";
  }
}

int main()
{
  Info testInfo("123 Test St, Test City", 202305); // e.g // graduate time in year

  Qualification qual1("Q001", "Computer Science Degree", 2022);
  Qualification qual2("Q002", "AWS Certification", 2023);
  vector<Qualification> qualifications = {qual1, qual2};

  Person candidate(testInfo, qualifications, true, false);

  vector<Validator *> validators;
  validators.push_back(new NewGradValidator());
  validators.push_back(new ExecutiveReferralValidator());

  validateCandidate(candidate, validators);
}