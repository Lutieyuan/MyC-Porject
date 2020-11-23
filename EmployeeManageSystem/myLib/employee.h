#pragma once
#include <iostream>

using namespace std;

class Employee {
 public:
  virtual void ShowInfo() = 0;
  virtual string GetDepName() = 0;

  int m_ID;
  string m_name;
  int m_DepID;
};
