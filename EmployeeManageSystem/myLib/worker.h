#pragma once
#include <iostream>
#include "employee.h"

using namespace std;

class Worker:public employee
{
public:
    Worker(int ID, string name, int depID);
    virtual void ShowInfo();
    virtual string GetDepName();

};

