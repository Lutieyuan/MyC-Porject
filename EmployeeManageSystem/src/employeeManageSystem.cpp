#include <stdlib.h>

#include <iostream>

#include "boss.h"
#include "employee.h"
#include "employeeManager.h"
#include "manager.h"
#include "worker.h"

using namespace std;

int main() {
  // test code
  // employee *employee = NULL;
  // employee = new Worker(1, "Tom", 1);
  // employee->ShowInfo();
  // delete employee;

  // employee = new Manager(2, "Jack", 2);
  // employee->ShowInfo();
  // delete employee;

  // employee = new Boss(3, "Peter", 3);
  // employee->ShowInfo();
  // delete employee;

  EmployeeManager em;

  int choice = 0;
  while (true) {
    em.ShowMeun();
    cout << "Please enter your choice: ";
    cin >> choice;
    switch (choice) {
      case 0:  // exit
        em.ExitSystem();
        break;
      case 1:  // add employee
        em.Add_Emp();
        break;
      case 2:  // show employee
        em.Show_Emp();
        break;
      case 3:  // delete employee
        em.Del_Emp();
        break;
      case 4:  // modify employee
        em.Mod_Emp();
        break;
      case 5:  // search employee
        em.Find_Emp();
        break;
      case 6:  // sort employee
        em.Sort_Emp();
        break;
      case 7:  // empty files
        em.Clean_File();
        break;
      default:
        system("clear");
        break;
    }
  }

  cout << "Press Any key and Enter to exit!" << endl;
  std::string a;
  cin >> a;
  system("clear");
  return 0;
}