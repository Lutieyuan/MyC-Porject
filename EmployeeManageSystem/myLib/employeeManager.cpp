#include "employeeManager.h"

EmployeeManager::EmployeeManager() {
  // 1. file does not exist
  ifstream ifs;
  ifs.open(FILENAME, ios::in);

  if (ifs.fail()) {
    // cout << "file does not exit" << endl;
    this->m_EmpNum = 0;
    this->m_EmpArray = NULL;
    this->m_FileIsEmpty = true;
    ifs.close();
    return;
  }
  // 2. file exits, but empty
  char ch;
  ifs >> ch;  // read a char
  if (ifs.eof()) {
    cout << "The file is empty" << endl;
    this->m_EmpNum = 0;
    this->m_EmpArray = NULL;
    this->m_FileIsEmpty = true;
    ifs.close();
    return;
  }
  // 3. file exits, data exits
  size_t num = this->get_EmpNum();
  cout << "The number of employeese: " << num << endl;
  this->m_EmpNum = num;
  // establish the memory (equals to declare an array)
  this->m_EmpArray = new Employee*[num];
  // store the information of the file into the array
  this->init_Emp();
  // for (size_t i = 0; i < num; i++) {
  //   cout << this->m_EmpArray[i]->m_ID << " " << this->m_EmpArray[i]->m_name
  //        << " " << this->m_EmpArray[i]->m_DepID << endl;
  // }
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

EmployeeManager::~EmployeeManager() {
  if (this->m_EmpArray != NULL) {
    delete[] this->m_EmpArray;
    this->m_EmpArray = NULL;
  }
}

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
          break;
        }
        case 2: {
          employee = new Manager(ID, name, 2);
          break;
        }
        case 3: {
          employee = new Boss(ID, name, 3);
          break;
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
    this->m_FileIsEmpty = false;  // update the file state
    cout << "Add " << addNum << " employeese success" << endl;
    // save the information into txt
    this->save();

  } else {
    cout << "Wrong number" << endl;
  }
  cout << "Press any key and enter to return the main menu" << endl;
  string a;
  cin >> a;
  system("clear");
}

void EmployeeManager::save() {
  ofstream ofs;
  ofs.open(FILENAME, ios::out);
  if (ofs.fail()) {
    cout << "Open file " << FILENAME << "failed" << endl;
    return;
  }
  // write each employee into the file
  for (size_t i = 0; i < this->m_EmpNum; i++) {
    ofs << this->m_EmpArray[i]->m_ID << " " << this->m_EmpArray[i]->m_name
        << " " << this->m_EmpArray[i]->m_DepID << endl;
  }
  ofs.close();
}

size_t EmployeeManager::get_EmpNum() {
  ifstream ifs;
  ifs.open(FILENAME, ios::in);

  int ID;
  std::string name;
  int DepID;
  size_t num = 0;
  while (ifs >> ID && ifs >> name && ifs >> DepID) {
    num++;
  }
  return num;
};

void EmployeeManager::init_Emp() {
  ifstream ifs;
  ifs.open(FILENAME, ios::in);

  std::string name;
  int ID, DepID;
  int index = 0;
  while (ifs >> ID && ifs >> name && ifs >> DepID) {
    Employee* employee = NULL;
    switch (DepID) {
      case 1:
        employee = new Worker(ID, name, DepID);
        break;
      case 2:
        employee = new Manager(ID, name, DepID);
        break;
      case 3:
        employee = new Boss(ID, name, DepID);
        break;
      default:
        break;
    }
    this->m_EmpArray[index] = employee;
    index++;
  }
  ifs.close();
}