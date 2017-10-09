#ifndef EMPLOYEE_HPP_
#define EMPLOYEE_HPP_

#include <iostream>
using namespace std;

class Employee {
public:
  Employee();
  virtual ~Employee();
  string firstName;
  string lastName;
  int ageInYears;
private:
};

#endif