#pragma once
#include <iostream>

using namespace std;

class Speaker {
 public:
  string GetName() { return this->m_Name; }
  double *GetSocre() { return this->m_Score; }
  void SetName(const string &name) { this->m_Name = name; }
  template <class T, int N>
  void SetSocre(T (&score)[N]) {
    for (int i = 0; i < N; i++) {
      this->m_Score[i] = score[i];
    }
  }
  template <class T>
  void SetEpochSocre(T score, int epoch) {
    this->m_Score[epoch] = score;
  }

 private:
  string m_Name;
  double m_Score[2];
};