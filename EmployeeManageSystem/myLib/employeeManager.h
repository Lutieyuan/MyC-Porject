#pragma once
#include <stdlib.h>

#include <fstream>
#include <iostream>

#include "boss.h"
#include "employee.h"
#include "manager.h"
#include "worker.h"
#define FILENAME "empFile.txt"

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
  // save the employ information into txt
  void save();
  // record the state of the file.txt
  bool m_FileIsEmpty;
  // get the num of person in file.txt
  size_t get_EmpNum();
  // init the Emp
  void init_Emp();
};