#pragma once
#include <stdlib.h>

#include <iostream>
#include <map>
#include <vector>

#include "speaker.h"

using namespace std;

class SpeechManager {
 public:
  SpeechManager();
  ~SpeechManager();
  void show_Meun();
  void exit_System();

  // Initializ the container and the property
  void init_Speech();
  // member property
  // speakers of the 1st Epoch
  vector<int> v1;
  // speakers of the 2nd Epoch
  vector<int> v2;
  // speakers of the finnal winners
  vector<int> vVictory;
  // save the maping of the ID and the spearkers
  map<int, Speaker> m_Speaker;
  // save the current epoch
  int m_Index;
};