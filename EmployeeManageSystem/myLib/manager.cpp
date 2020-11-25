#include "manager.h"

Manager::Manager(int ID, string name, int DepID) {
  this->m_ID = ID;
  this->m_name = name;
  this->m_DepID = DepID;
}

void Manager::ShowInfo() {
  cout << "Employee ID: " << this->m_ID << "\tEmployee Name: " << this->m_name
       << "\tEmployee station: " << this->GetDepName()
       << "\tDuty: Complish the mission of boss and assign the missions of "
          "workers"
       << endl;
}

string Manager::GetDepName() { return string("Manager"); }