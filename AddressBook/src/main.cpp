#include <iostream>
#include <unistd.h>
#include <string>
#include <stdlib.h>
#include <cstdio>
#define MAX 1000
 // define the max value of the person in the AddressBook

using namespace std;


// create struct person 
struct person
{
    string m_Name;
    int m_Gender; // 1--male; 2--female
    int m_Age;
    string m_Phone;
    string m_Address;
};

// create struct AddressBook
struct AddressBook
{
    // save the persons in an array
    struct person personArray[MAX];
    // the current value of the persons
    int m_Size; 

};

//1. add person
void addPerson(AddressBook * abk)
{
    if (abk->m_Size >= MAX)
    {
        cout << "The contact book is full, and can not add more!" << endl;
        return;
    }
    else
    {
        // Add Name
        string name;
        cout << "Please type in the name: " ;
        cin >> name;
        abk->personArray[abk->m_Size].m_Name = name;

        // Add Gender;
        int gender = 0;
        while (true)
        {   
            cout << "Please type in the Gender\n" << 
            "1 --- male\n" <<
            "0 --- female" << endl;
            cin >> gender;
            if (gender == 0 || gender ==1 )
            {
                abk->personArray[abk->m_Size].m_Gender = gender;
                break;
            }
            else
            {
                cout << "Wrong typing, please type 1 for male, 0 for female!" << endl;
            }
        }

        // Add age
        cout << "Please type in the age: " << endl;
        int age = 0;
        while (true) 
        {
            cin >> age;
            if (age < 150 & age > 0)
            {
                abk->personArray[abk->m_Size].m_Age = age;
                break;
            }
            else
            {
                cout << "Please consider the typing age (1~149 required)" << endl;
            }
        }

        // Add phone number
        cout << "Please type in the phone number: ";
        cin >> abk->personArray[abk->m_Size].m_Phone;

        // Add address
        cout << "Please type in the address: ";
        cin >> abk->personArray[abk->m_Size].m_Address;

        // update the size
        abk->m_Size ++;

        //     
        cout << "Add the person: " << name << " success! \n" 
             << "Press 1. any key and enter to continue... \n "
             << "or    2. Ctrl+C to exit" <<endl;
        string a;
        cin >> a;
        system("read");
        system("clear");
    }   
};


//2. show person
void showPerson(AddressBook * abk)
{
    //first make sure the AddressBook is not empty
    if (abk->m_Size == 0)
    {
        cout << "The contact is empty! " << endl;
    }
    else
    {
        for (int i = 0; i < abk->m_Size; i++)
        {
            cout << "Name: " << abk->personArray[i].m_Name << "\t"
                 << "Gender: " << (abk->personArray[i].m_Gender == 1 ? "male":"female") << "\t"  
                 << "Age: " << abk->personArray[i].m_Age << "\t"
                 << "PhoneNumber: " << abk->personArray[i].m_Phone << "\t"
                 << "Address: " << abk->personArray[i].m_Address << endl;
        }
    };
    //pause();
    cout << "Press 1. any key and enter to continue... \n "
        << "or    2. Ctrl+C to exit" <<endl;
    string a;
    cin >> a;
    system("clear");
}

//3a. check if the person is exist
int isExist(AddressBook *abk, string name)
{   //return -1: empty; -2: not find; >0: index
    //(1) check the the AddressBook is not empty
    if (abk->m_Size == 0)
    {
        cout << "The contect is empty and can not find any person!" << endl;
        return -1;
    }
    else
    {
        for (int i = 0; i < abk->m_Size; i++)
        {
            if (abk->personArray[i].m_Name == name)
                return i;
        }
        return -2;
    }    
}

//3. delete person
void deletePerson(AddressBook * abk)
{
    cout << "Please type in the person you want to delete: ";
    string name;
    cin >> name;
    // first check if the person exist
    int ret = isExist(abk, name);
    if (ret < 0 )
        cout << "We didn't find the person: " << name << endl;
    else
    {
        for (int i = ret; i < abk->m_Size; i++)
        {
            abk->personArray[i] = abk->personArray[i+1];
        }
        abk->m_Size --;
        cout << "delete person: " << name << " success! " <<endl;
    }
    cout << "Press any key and Enter to continue or press ctrl+C to Exit: " << endl; 
    string a;
    cin >> a;
    system("clear");  
};

//4. find person
void findPerson(AddressBook * abk)
{
    //check the address book
    if (abk->m_Size == 0)
        cout << "The contact is empty! No person to be finded" << endl;  
    else 
        {
            // find the person
            cout << "Please type in the person you want to find: ";
            string name;
            cin >> name;
            int ret = isExist(abk, name);
            if (ret >= 0)
            {
                cout << "We find the person you type in: " << endl;
                cout << "Name: " << abk->personArray[ret].m_Name << "\t"
                     << "Gender: " << (abk->personArray[ret].m_Gender ==1 ? "male":"female") << "\t"
                     << "Age: " << abk->personArray[ret].m_Age << "\t"
                     << "PhoneNum: " << abk->personArray[ret].m_Phone << "\t"
                     << "Address: " << abk->personArray[ret].m_Address << endl;
            } 
        };
    cout << "Find person finished! Please press ang key and Enter to continue or ctrl+C to Exit" << endl; 
    string a;
    cin >> a;
    system("clear");
}

//5. modfiy person
void modifyPerson(AddressBook * abk)
{
    //check the abk
    if (abk->m_Size ==0 )
    {
        cout << "The contact is empty, no person to be modified" <<endl;
    }
    else
    {
        //find the person
        cout << "Please type in the person you want to modify: ";
        string name;
        cin >> name;
        int ret = isExist(abk, name);
        if (ret == -1)
        {
            cout << "Can not find the person in the contact, Please chose 1 in the main menu to add the person directly!" << endl;

        } 
        else
        {
            // name
            cout << "Find the person: "<< name << ". Please type in the new name you want: ";
            string new_name;
            cin >> new_name;
            abk->personArray[ret].m_Name = new_name;
            // age
            cout << "Please type in the age: ";
            int new_age;
            cin >> new_age;
            abk->personArray[ret].m_Name = new_age;
            // gender
            cout << "Please type in the Gender: \n" 
                 << "1---male \n" 
                 << "0---female" << endl;
            int new_gender;
            cin >> new_gender;
            abk->personArray[ret].m_Gender = new_gender;
            // Phone number
            cout <<"Please type in the new phone number you want: ";
            string new_phoneNum;
            cin >> new_phoneNum;
            abk->personArray[ret].m_Phone = new_phoneNum;
            // Address
            cout <<"Please type in the new address you want: ";
            string new_address;
            cin >> new_address;
            abk->personArray[ret].m_Address = new_address;
            cout << "Modiy the person " << name << " finished!" << endl;    
        }   
    }
    cout << "Please press ang key and Enter to continue or ctrl+C to Exit" << endl; 
    string a;
    cin >> a;
    system("clear");
};

//6. empty the contact
void cleanPerson(AddressBook * abk)
{
    cout << "Do you really want to empty the contacts? (yes/no):" ;
    string flag;
    cin >> flag;
    if (flag.compare("Yes"))
    {
        abk->m_Size = 0;
        cout << "The contact has been emptied! ";
    }
    cout << "Please press ang key and Enter to continue or ctrl+C to Exit" << endl; 
    string a;
    cin >> a;
    system("clear");
};

void showMenu()
{
    cout << "*************************************" << endl;
    cout << "****** 1. Add    the  contacts ******" << endl;
    cout << "****** 2. Show   the  contacts ******" << endl;
    cout << "****** 3. Delete the  contacts ******" << endl;
    cout << "****** 4. Find   the  contacts ******" << endl;
    cout << "****** 5. Modify the  contacts ******" << endl;
    cout << "****** 6. Empty  the  contacts ******" << endl;
    cout << "****** 0. Exit   the  contacts ******" << endl;
    cout << "*************************************" << endl;
}

int main(int argc, char ** argv)
{
   
    AddressBook abk;
    abk.m_Size = 0;
    int select = 0;
    //
    while (true)
    {
        showMenu();  
        //
        cout << "Please type your choice: ";
        cin >> select;      
        //
        switch (select)
        {
        case 1: /*1. Add the contacts: */
            addPerson(&abk);
            break;
        case 2: /*2. Show   the  contacts */
            /* code */
            showPerson(&abk);
            break;
        case 3: /*3. Delete the  contacts */
            /* code
            {
                cout << "please type in the name you want find: " << endl;
                string name;
                cin >> name;
                int index_ =isExist(&abk, name);
                if (index_ == -2)
                    cout << "Doesn't find: " << name << endl;
                else if (index_ == -1)
                    cout << "No result, The contects is empty! " << endl;
                else
                    cout << "find: " << name << " in: " << index_ << endl;
            } */
            deletePerson(&abk);
            break;
        case 4: /*4. Find   the  contacts */
            /* code */
            findPerson(&abk);
            break;  
        case 5: /*5. Modify the  contacts */
            /* code */
            modifyPerson(&abk);
            break;  
        case 6: /*6. Empty  the  contacts */
            /* code */
            cleanPerson(&abk);
            break; 
        case 0: /*0. Exit   the  contacts */
            {
                cout << "Welcome for your next using! \n" 
                     << "Press any key and enter to Exit" << endl;
                string a;
                cin >> a;
                //system("read");    // equal to "press any key to continue~"
                system("clear");  // clean the screen 
                return 0;
            }
            break;                     
        default:
            cout << "Please type in the right choice : 0~6" << endl;
            break;
        }
    }
     
    
    return 0;
}