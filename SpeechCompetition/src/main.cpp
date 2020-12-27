

#include <iostream>

#include "speechManager.h"

using namespace std;

int main() {
  // Create an object of speech manager
  SpeechManager sm;

  int choice = 0;  // save the input
  while (true) {
    sm.show_Meun();
    cout << "Please input your choice:";
    cin >> choice;
    switch (choice) {
      case 1:  // Start the speech competition
        break;
      case 2:  // Look out the competition record
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