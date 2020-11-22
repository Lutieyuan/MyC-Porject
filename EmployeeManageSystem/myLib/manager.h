#pragma
#include <iostream>
#include "employee.h"

using namespace std;

class Manager:public employee
{
public:
    Manager(int ID, string name, int DepID);
    virtual void ShowInfo();
    virtual string GetDepName();
};