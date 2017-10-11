//*****************
//Project Name:
//Project Description:
//Project Author:
//Is this an extra credit Project:
//Date completed:
//Operating system used:
//IDE Used:
//*****************
#include <iostream>
#include <iomanip>
#include <map>
#include "utilities.hpp"
#include "Investment.hpp"
using namespace std;

int main() {
  srand(time(NULL));
  // map<key, value>
  map<string, Investment*> investmentMap;
  pair<map<string, Investment*>::iterator, bool> returnValue;

  // This pair is for retrieving data from the map
  map<string, Investment*>::iterator investmentIterator;

  #pragma region
  while (true) {
    string name = inputString("Investment Firm (-999 to quit): ", 2, 30);

    if (name == "-999") break; 

    cout << endl;

    double currentVal = inputDouble("Current Value: ", 1.00, 1000000000000.00, -999);

    Investment *temp = new Investment(getRandomString(6, 7), name, currentVal);

    if (investmentMap.insert(pair<string, Investment*>(temp->accountNumber, temp)).second) {
      cout << temp->name << " added successfully!" << endl << endl;
    } else {
      cout << temp->name << " already exists, not inserted!" << endl;
    }
  }
  #pragma endregion

  cout << endl;

  #pragma region
  cout << setw(20) << left << "Account Number";
  cout << setw(24) << "Investment Firm";
  cout << setw(20) << right << fixed << "Current Value" << endl;
  cout << setw(20) << left << "--------------";
  cout << setw(24) << "----------------";
  cout << setw(20) << right << fixed << "--------------" << endl;

  for (pair<string, Investment*> investmentPair : investmentMap) {
    cout << setw(20) << left << investmentPair.first;
    cout << setw(24) << investmentPair.second->name;
    cout << setw(20) << right << fixed << setprecision(2) << investmentPair.second->currentValue << endl;
  }
  #pragma endregion

  cout << endl;

  #pragma region  
  while (true) {
    string accountNum = inputString("Seach by Account Number (-999 to quit): ", 1, 6);
    if (accountNum == "-999") break;

    investmentIterator = investmentMap.find(accountNum);
    if (investmentIterator != investmentMap.end()) {
      cout << endl;
      cout << setw(20) << left << "Account Number";
      cout << setw(24) << "Investment Firm";
      cout << setw(20) << right << fixed << "Current Value" << endl;
      cout << setw(20) << left << "--------------";
      cout << setw(24) << "----------------";
      cout << setw(20) << right << fixed << "--------------" << endl;
      cout << setw(20) << left << investmentMap[accountNum]->accountNumber;
      cout << setw(24) << investmentMap[accountNum]->name;
      cout << setw(20) << right << fixed << setprecision(2) << investmentMap[accountNum]->currentValue << endl;

      cout << endl;
    } else {
      cout << endl;
      cout << "Investment with account number \"" << accountNum << "\" does not exist." << endl << endl; 
    }
  }
  #pragma endregion
  
  cout << endl;

  for (pair<string, Investment*> investmentPair : investmentMap) {
    delete investmentPair.second;
  }
  cout << "Program ending, have a nice day!" << endl;
  return 0;
}
