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
#include <map>
#include "utilities.hpp"
using namespace std;

int main() {

  multimap<string, double> investmentAccounts;

  multimap<string, double>::iterator mmIterator;

  pair<multimap<string, double>::iterator, multimap<string, double>::iterator> pairIterator;

  investmentAccounts.insert(pair<string, double>("456", 100000.00));
  investmentAccounts.insert(pair<string, double>("456", 200000.00));
  investmentAccounts.insert(pair<string, double>("456", 300000.00));
  investmentAccounts.insert(pair<string, double>("123", 400000.00));
  investmentAccounts.insert(pair<string, double>("789", 500000.00));

  pairIterator = investmentAccounts.equal_range("456");

  if (pairIterator.first == pairIterator.second) {
    cout << "Not found in the multimap" << endl;
  } else {
    for (
      mmIterator = pairIterator.first; // Starts at first as defined by the equal_range method above
      mmIterator != pairIterator.second; // Defined as the first node outside the range (789 for the example)
      mmIterator++
    )
      cout << mmIterator->first << ", " << mmIterator->second << endl;

    cout << "Program ending, have a nice day!" << endl;
    return 0;
  }
}
