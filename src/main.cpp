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

  while (true) {
    string name = inputString("Investment Firm (-999 to quit): ", 2, 30);

    if (name == "-999") break; 

    double currentVal = inputDouble("Current Value (-999 to quit): ", 1.00, 1000000000000.00, -999);

    Investment *temp = new Investment(getRandomString(6, 7), name, currentVal);

    if (investmentMap.insert(pair<string, Investment*>(temp->accountNumber, temp)).second) {
      cout << temp->name << " added successfully!" << endl << endl;
    } else {
      cout << temp->name << " already exists, not inserted!" << endl;
    }
  }

  cout << endl;

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

  cout << endl;

  for (pair<string, Investment*> investmentPair : investmentMap) {
    delete investmentPair.second;
  }
  cout << "Program ending, have a nice day!" << endl;
  return 0;
}
