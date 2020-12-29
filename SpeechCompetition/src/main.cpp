

#include <iostream>

#include "speechManager.h"

using namespace std;

int main() {
  // Create an object of speech manager
  SpeechManager sm;
  //   for (map<int, Speaker>::iterator it = sm.m_Speaker.begin();
  //        it != sm.m_Speaker.end(); it++) {
  //     cout << "ID: " << it->first << " Name: " << it->second.GetName()
  //          << " Score: " << it->second.GetSocre()[0] << endl;
  //   }

  int choice = 0;  // save the input
  while (true) {
    sm.show_Meun();
    cout << "Please input your choice:";
    cin >> choice;
    switch (choice) {
      case 1:  // Start the speech competition
        sm.startSpeech();
        break;
      case 2:  // Check out the competition record
        sm.showRecord();
        break;
      case 3:  // Empty the competition record
        break;
      case 0:  // Exit the competition system
        sm.exit_System();
        break;
      default:
        system("clear");
    }
  }
}