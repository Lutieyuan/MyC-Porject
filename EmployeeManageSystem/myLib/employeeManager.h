#pragma once
#include <stdlib.h>

#include <iostream>

#include "boss.h"
#include "employee.h"
#include "manager.h"
#include "worker.h"

using namespace std;

class EmployeeManager {
 public:
  EmployeeManager();
  ~EmployeeManager();
  void ShowMeun();
  void ExitSystem();

  // record the number of employee
  size_t m_EmpNum;
  // store the pointer of employee in an array
  Employee** m_EmpArray;
  // add the employ in batch
  void Add_Emp();
};