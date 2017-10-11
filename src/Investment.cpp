#include "Investment.hpp"
#include <iostream>

Investment::Investment() {
  this->accountNumber = "";
  this->name = "";
  this->currentValue = 0;
}

Investment::Investment(std::string accountNum, std::string name, double current) {
  this->accountNumber = accountNum;
  this->name = name;
  this->currentValue = current;
}

Investment::~Investment() {
  std::cout << "Deleting investment \"" << this->accountNumber << "\""<< std::endl;
}