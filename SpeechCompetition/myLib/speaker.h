#pragma once
#include <iostream>

using namespace std;

class Speaker {
 public:
  string GetName() { return this->m_Name; }
  double* GetSocre() { return this->m_Score; }

 private:
  string m_Name;
  double m_Score[2];
};