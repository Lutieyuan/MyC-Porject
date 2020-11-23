#pragma
#include <iostream>
#include "employee.h"

using namespace std;

class Boss : public employee {
 public:
  Boss(int ID, string name, int DepID);
  virtual void ShowInfo();
  virtual string GetDepName();
};