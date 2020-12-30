#pragma once
#include <stdlib.h>

#include <algorithm>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

#include "speaker.h"

using namespace std;

class SpeechManager {
 public:
  SpeechManager();
  ~SpeechManager();
  void show_Meun();
  void exit_System();
  // create 12 speakers
  void create_Speaker();

  // Initializ the container and the property
  void init_Speech();
  // start the speech
  void startSpeech();
  // shuffle the order of giving speech
  void speechDraw();
  // start the compete
  void speechContest();
  // show the score
  void showScore();
  // save the record
  void saveRecord();
  // load out the record
  void loadRecord();
  // show the record
  void showRecord();
  // clear the record
  void clearRecord();
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
  // the file empty flag
  bool fileIsEmpty;
  // an container for the recorded result
  map<int, vector<string> /* */> m_Record;
};