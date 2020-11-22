#include "employeeManager.h"

EmployeeManager::EmployeeManager()
{

}

void EmployeeManager::ShowMeun()
{
    cout<< "************************************************"<< endl;
    cout<< "**** Welcome to the Employee Manage System ****" << endl;
    cout<< "*********** 0.Exit the System ******************"<< endl;
    cout<< "*********** 1.Add the Employee Info ************"<< endl;
    cout<< "*********** 2.Show the Employee Info ***********"<< endl;
    cout<< "*********** 3.Delete the Retired Employee*******"<< endl;
    cout<< "*********** 4.Modify the Employee Info *********"<< endl;
    cout<< "*********** 5.Search the Employee Info *********"<< endl;
    cout<< "*********** 6.Sort the Employee by ID **********"<< endl;
    cout<< "*********** 7.Empty the System Files ***********"<< endl;
    cout << endl;
}

void EmployeeManager::ExitSystem()
{
    cout << "Welcome for your next time!"<< endl;
    cout << "Press any key and Enter to exit"<<endl;
    string a;
    cin >> a;
    system("clear");
    exit(0); //exit system
}

EmployeeManager::~EmployeeManager()
{

}

