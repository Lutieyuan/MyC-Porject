#include "speechManager.h"

SpeechManager::SpeechManager() {
  // init the speech competition
  this->init_Speech();
  // create the speakers
  this->create_Speaker();
}

SpeechManager::~SpeechManager() {}

void SpeechManager::show_Meun() {
  cout << "**************************************************" << endl;
  cout << "**** Welcome to the Speech Competition system ****" << endl;
  cout << "**** 1. Start the speech competition *************" << endl;
  cout << "**** 2. Look out the competition record***********" << endl;
  cout << "**** 3. Empty the competition record *************" << endl;
  cout << "**** 0. Exit the competition system **************" << endl;
  cout << "**************************************************" << endl;
  cout << endl;
}

void SpeechManager::exit_System() {
  cout << "Welcome for the next time" << endl;
  cout << "Press any key and \"Enter\" to exit" << endl;
  string a;
  cin >> a;
  system("clear");
  exit(0);
}

void SpeechManager::init_Speech() {
  // set the container empty
  this->v1.empty();
  this->v2.empty();
  this->vVictory.empty();
  this->m_Speaker.empty();

  // init the index of the speech epoch
  this->m_Index = 1;
}

void SpeechManager::create_Speaker() {
  string nameSeed = "ABCDEFGHIJKL";
  for (int i = 0; i < nameSeed.size(); i++) {
    string name = "Speaker_";
    name = name + nameSeed[i];
    // initialize each speaker
    Speaker sp;
    sp.SetName(name);
    double init_score[2] = {0, 0};
    sp.SetSocre(init_score);
    // initialize the speaker's ID
    this->v1.push_back(i + 1001);
    // put the speaker into map with its ID
    this->m_Speaker.insert(make_pair(i + 1001, sp));
  }
}