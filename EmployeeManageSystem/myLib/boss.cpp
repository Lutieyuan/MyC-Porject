#include "boss.h"

Boss::Boss(int ID, string name, int DepID) {
  this->m_ID = ID;
  this->m_name = name;
  this->m_DepID = DepID;
}

void Boss::ShowInfo() {
  cout << "Employee ID: " << this->m_ID << "\tEmployee Name: " << this->m_name
       << "\tEmployee station: " << this->GetDepName()
       << "\tDuty: Manage all the issue of the campany" << endl;
}

string Boss::GetDepName() { return string("Boss"); }