#ifndef INVESTMENT_HPP_
#define INVESTMENT_HPP_

#include <string>

class Investment {
public:
  Investment();
  Investment(std::string, std::string, double);
  virtual ~Investment();
  std::string accountNumber;
  std::string name;
  double currentValue;
private:

};

#endif