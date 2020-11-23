#include "employeeManager.h"

EmployeeManager::EmployeeManager() {
  this->m_EmpNum = 0;
  this->m_EmpArray = NULL;
}

void EmployeeManager::ShowMeun() {
  cout << "************************************************" << endl;
  cout << "**** Welcome to the Employee Manage System ****" << endl;
  cout << "*********** 0.Exit the System ******************" << endl;
  cout << "*********** 1.Add the Employee Info ************" << endl;
  cout << "*********** 2.Show the Employee Info ***********" << endl;
  cout << "*********** 3.Delete the Retired Employee*******" << endl;
  cout << "*********** 4.Modify the Employee Info *********" << endl;
  cout << "*********** 5.Search the Employee Info *********" << endl;
  cout << "*********** 6.Sort the Employee by ID **********" << endl;
  cout << "*********** 7.Empty the System Files ***********" << endl;
  cout << endl;
}

void EmployeeManager::ExitSystem() {
  cout << "Welcome for your next time!" << endl;
  cout << "Press any key and Enter to exit" << endl;
  string a;
  cin >> a;
  system("clear");
  exit(0);  // exit system
}

EmployeeManager::~EmployeeManager() {}

void EmployeeManager::Add_Emp() {
  cout << "Please enter the number of employee: ";
  size_t addNum = 0;
  cin >> addNum;

  if (addNum > 0) {
    size_t newSize = this->m_EmpNum + addNum;
    // create the space
    Employee** newSpace = new Employee*[newSize];

    if (this->m_EmpArray != NULL) {
      for (size_t i = 0; i < this->m_EmpNum; i++) {
        newSpace[i] = this->m_EmpArray[i];
      }
    }
    // add new data in batch
    for (size_t i = 0; i < addNum; i++) {
      int ID;
      string name;
      int DepSelect;

      cout << "Please input the ID of " << i + 1 << " th employee: ";
      cin >> ID;
      cout << "Please input the name of " << i + 1 << " th employee: ";
      cin >> name;
      cout << "Please Select the Department of " << i + 1 << " th employee "
           << endl;
      cout << "1. Normal worker" << endl;
      cout << "2. Manager" << endl;
      cout << "3. Boss" << endl;
      cin >> DepSelect;

      Employee* employee = NULL;
      switch (DepSelect) {
        case 1: {
          employee = new Worker(ID, name, 1);
        }
        case 2: {
          employee = new Manager(ID, name, 2);
        }
        case 3: {
          employee = new Boss(ID, name, 3);
        }
        default:
          break;
      }
      // add the new employee to the newSpace
      newSpace[this->m_EmpNum + i] = employee;
    }
    // delete the origin space
    delete[] this->m_EmpArray;
    // update the arry
    this->m_EmpArray = newSpace;
    this->m_EmpNum = newSize;
    cout << "Add " << addNum << " employeese success" << endl;

  } else {
    cout << "Wrong number" << endl;
  }
  cout << "Press any key and enter to return the main menu" << endl;
  string a;
  cin >> a;
  system("clear");
}
