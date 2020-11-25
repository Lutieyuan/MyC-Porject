#include "worker.h"

Worker::Worker(int ID, string name, int DepID) {
  this->m_ID = ID;
  this->m_name = name;
  this->m_DepID = DepID;
};

void Worker::ShowInfo() {
  cout << "Employee ID: " << this->m_ID << "\tEmployee Name: " << this->m_name
       << "\tEmployee station: " << this->GetDepName()
       << "\tDuty: Complish the misson of manager" << endl;
};

string Worker::GetDepName() { return string("worker"); };