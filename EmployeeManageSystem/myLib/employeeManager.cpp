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
  // cout << "The number of employeese: " << num << endl;
  this->m_EmpNum = num;
  this->m_FileIsEmpty = false;
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
    for (size_t i = 0; i < this->m_EmpNum; i++) {
      if (this->m_EmpArray[i] != NULL) {
        delete this->m_EmpArray[i];
      }
    }
    delete[] this->m_EmpArray;
    this->m_EmpArray = NULL;
    this->m_EmpNum = 0;
    this->m_FileIsEmpty = true;
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
      while (this->IsExist(ID) != -1) {
        cout << "The ID has alread used in the existing system. Please choose "
                "another ID: ";
        cin >> ID;
      }
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
    Employee* employee = NULL;  // declare
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
    this->m_EmpArray[index] = employee;  // init
    index++;
  }
  ifs.close();
};

void EmployeeManager::Show_Emp() {
  // Check whether the file is empty
  if (this->m_FileIsEmpty) {
    cout << "The file does not exist or hold no record!" << endl;
  } else {
    for (size_t i = 0; i < this->m_EmpNum; i++) {
      this->m_EmpArray[i]->ShowInfo();
    }
  }
  cout << "Press any key and enter key to the main menu" << endl;
  std::string a;
  cin >> a;
  system("clear");
}

// delete the Emp by ID
void EmployeeManager::Del_Emp() {
  // 1. fisrt check the file exists
  if (this->m_FileIsEmpty) {
    cout << "The file does not exist or is empty" << endl;
  } else {  // 2.remove the selected ID if exists, else print the "not find"
    // message
    cout << "Please the ID the employee to be deleted: ";
    int id = 0;
    cin >> id;
    size_t index = this->IsExist(id);
    if (index == -1) {
      cout << "Delete failed. The employee does not exist!" << endl;
    } else {
      for (size_t i = index; i < (this->m_EmpNum - 1); i++) {
        this->m_EmpArray[i] = this->m_EmpArray[i + 1];
      }
      this->m_EmpNum--;
      // update the data into empfile.txt
      this->save();
      cout << "Delete the employee succeed" << endl;
    }
  }
  cout << "Press any key and enter to the main menu" << endl;
  string a;
  cin >> a;
  system("clear");
};
// check whether the employee exists, and return his ID
int EmployeeManager::IsExist(int ID) {
  int index = -1;
  for (size_t i = 0; i < this->m_EmpNum; i++) {
    if (ID == this->m_EmpArray[i]->m_ID) {
      index = i;
      break;
    }
  }
  return index;
};

void EmployeeManager::Mod_Emp() {
  // check the file exist
  if (this->m_FileIsEmpty) {
    cout << "The file does not exist or is empty" << endl;
  } else {
    cout << "Please type in the ID to be modified: ";
    int ID;
    cin >> ID;
    int index = this->IsExist(ID);
    if (index == -1) {
      cout << "Modify failed! The person does not exist" << endl;

    } else {
      delete this->m_EmpArray[index];
      // Here delete the pointer for the reason that the poniter arry hold
      // different kind of object(Worker, manager, and boss). So we'd better not
      // directly overwrite the child's  member with its parent's member
      cout << "Find the employe with ID: " << ID
           << ". Please type in the new ID: ";
      int newID;
      cin >> newID;
      cout << "Please type in the new name: ";
      std::string newName;
      cin >> newName;
      cout << "Please select the new department of the employee: " << endl
           << "1. Worker" << endl
           << "2. Manager" << endl
           << "3. Boss" << endl;
      int newDepID;
      cin >> newDepID;
      Employee* employee = NULL;
      switch (newDepID) {
        case 1:
          employee = new Worker(newID, newName, newDepID);
          break;
        case 2:
          employee = new Manager(newID, newName, newDepID);
          break;
        case 3:
          employee = new Boss(newID, newName, newDepID);
          break;
        default:
          break;
      }
      this->m_EmpArray[index] = employee;
      // this->Show_Emp();
      cout << "Modify the employee succeed" << endl;
    }
    this->save();
  }
  cout << "Press any key and enter to the main menu" << endl;
  string a;
  cin >> a;
  system("clear");
}

void EmployeeManager::Find_Emp() {
  if (this->m_FileIsEmpty) {
    cout << "The file does not exist or is empty" << endl;
  } else {
    cout << "Please select the key to find:" << endl
         << "1. By ID" << endl
         << "2. By name" << endl;
    int select = 0;
    cin >> select;
    if (select == 1) {
      cout << "Please type in the ID of employee to be found: ";
      int ID;
      cin >> ID;
      int index = this->IsExist(ID);
      if (index != -1) {
        cout << "Find the employ with ID: " << ID << " success!" << endl;
        cout << "The detail information of the employee are list below" << endl;
        this->m_EmpArray[index]->ShowInfo();
      } else {
        cout << "Find the employee with ID " << ID
             << " failed. Please check the ID!" << endl;
      }
    } else if (select == 2) {
      cout << "Please type in the name of the employee need to be found: ";
      std::string name;
      cin >> name;
      bool findFlag = false;
      for (size_t i = 0; i < this->m_EmpNum; i++) {
        if (this->m_EmpArray[i]->m_name == name) {
          cout << "Find the employee with name: " << name << endl
               << "The detail information of the employee is list below"
               << endl;
          this->m_EmpArray[i]->ShowInfo();
          findFlag = true;
          // break;
        }
      }
      if (!findFlag) {
        cout << "Find the employee with name failed. No such person with name "
             << name << endl;
      }
    }
  }
  cout << "Press any key and enter to the main menu" << endl;
  string a;
  cin >> a;
  system("clear");
}

void EmployeeManager::Sort_Emp() {
  if (this->m_FileIsEmpty) {
    cout << "The file does not exist or is empty" << endl;
    cout << "Press any key and enter to the main menu" << endl;
    string a;
    cin >> a;
    system("clear");
  } else {
    cout << "Please select the sort type:" << endl
         << "1. sort ID by increasing" << endl
         << "2. sort ID by decreasing" << endl;
    int select = 0;
    cin >> select;

    for (size_t i = 0; i < this->m_EmpNum; i++) {
      int minOrMax = i;
      for (size_t j = i + 1; j < this->m_EmpNum; j++) {
        if (select == 1) {
          if (this->m_EmpArray[minOrMax]->m_ID > this->m_EmpArray[j]->m_ID)
            minOrMax = j;
        } else if (select == 2) {
          if (this->m_EmpArray[minOrMax]->m_ID < this->m_EmpArray[j]->m_ID)
            minOrMax = j;
        }
      }
      //
      Employee* emp_temp = this->m_EmpArray[i];
      this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
      this->m_EmpArray[minOrMax] = emp_temp;
    }
    cout << "Sort the employee by ID finished!" << endl;
    this->save();
    this->Show_Emp();
  }
}

void EmployeeManager::Clean_File() {
  if (this->m_FileIsEmpty) {
    cout << "The file does not exist or is already empty" << endl;
  } else {
    cout << "Are you sure to clean the file[yes/no]: ";
    std::string flag;
    cin >> flag;
    if (flag == "yes") {
      ofstream ofs(FILENAME, ios::trunc);
      ofs.close();
      for (size_t i = 0; i < this->m_EmpNum; i++) {
        // delete each object in the stack
        if (this->m_EmpArray[i] != NULL) {
          delete this->m_EmpArray[i];
          this->m_EmpArray[i] = NULL;
        }
      }
      delete[] this->m_EmpArray;
      this->m_EmpArray = NULL;
      this->m_EmpNum = 0;
      this->m_FileIsEmpty = true;
      cout << "Clean the EmpFile succeed!" << endl;
    }
  }
  cout << "Press any key and enter to the main menu" << endl;
  string a;
  cin >> a;
  system("clear");
};
