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
  Info(string &addr, int graduateTime)
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
  virtual ~Validator() = default;
  virtual bool validate(const Person &candidate) const = 0; // Pure virtual function
};