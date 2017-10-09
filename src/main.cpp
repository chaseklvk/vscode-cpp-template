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
#include <list>
#include <iterator>
#include "utilities.hpp"
#include "Employee.hpp"
using namespace std;

int main() {
  list<string> myNameList;
  list<string>::iterator myNameListIterator;

  myNameList.push_back("Stan");
  myNameList.push_back("Carol");
  myNameList.push_back("Tammy");
  myNameList.push_back("Sue");
  myNameList.push_back("Jacob");

  // Iterate through list with iterator
  for (
    myNameListIterator = myNameList.begin(); 
    myNameListIterator != myNameList.end(); 
    myNameListIterator++
  ) {
    cout << "Name is " << *myNameListIterator << endl;
  }

  list<Employee*> myEmployeeList;
  list<Employee*>::iterator myEmployeeListIterator;

  for (int i = 0; i < 5; i++) {
    Employee *anEmployee = new Employee();
    anEmployee->ageInYears = i;
    myEmployeeList.push_back(anEmployee);
  }

  // Using abbreviated syntax
  for (Employee* tempEmployee : myEmployeeList) 
    cout << "Employee Age: " << tempEmployee->ageInYears << endl;

  for (
    myEmployeeListIterator = myEmployeeList.begin();
    myEmployeeListIterator != myEmployeeList.end();
    myEmployeeListIterator++
  )
    cout << "Employee Age: " << (*myEmployeeListIterator)->ageInYears << endl;

  for (
    myEmployeeListIterator = myEmployeeList.begin();
    myEmployeeListIterator != myEmployeeList.end();
    myEmployeeListIterator++
  ) 
    delete *myEmployeeListIterator;

  cout << "Program ending, have a nice day!" << endl;
  return 0;
}
