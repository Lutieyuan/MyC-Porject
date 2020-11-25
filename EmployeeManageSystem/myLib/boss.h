#pragma once
#include <iostream>

#include "employee.h"

using namespace std;

class Boss : public Employee {
 public:
  Boss(int ID, string name, int DepID);
  virtual void ShowInfo();
  virtual string GetDepName();
};