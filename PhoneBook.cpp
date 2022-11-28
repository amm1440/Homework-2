#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib>
#include "PhoneBook.h"

using namespace std;

/* this function takes the file wanted to be read in and
checks to see it the file will not be read*/
bool PhoneBook::fileCheck(string name)
{
       ifstream file;
       file.open(name.c_str());

       if(!file)
           return true;
       else
           return false;

       file.close();
}

/* this fucntion takes file name what needs to be searched and
a level to see how many times it was iterated and retruns either
the results of the search or no entry*/
bool PhoneBook::searching(string name, string search, int level)
{
       ifstream file;
       file.open(name.c_str());

       int searchLength = search.length();
       int count;
       string str1, str2;

       if (search == ".")
           return 0;


       file >> count;

       for ( int i=0; i<count; i++)
       {
            file >> str1 >> str2;

            if(level >= 3 &&strcasecmp(str1.substr(0 ,searchLength).c_str(),search.c_str()) != 0)
                return cout << "***No Entry found.***\n";

            if (strcmp(str1.c_str(), "PHONEBOOK-FILE") == 0)
            {
                 if (searching(str2, search, level+1))
                     return true;
            }

            else if(strcasecmp(str1.substr(0 ,searchLength).c_str(),search.c_str()) == 0)
            {
               return cout << str1 << " " << str2 << endl;
            }
       }
}


/*this function takes the input of user to get the file name
and what the user wants to search it takes these inputs and
runs the fileCheck and searching functions*/
void PhoneBook::run()
{

    string fileName;
    cout << "Name of phonebook file to read in: ";
    cin >> fileName;

    string searchFor = " ";

    int notSatisfied = 1;

    if (fileCheck(fileName))
        notSatisfied = 0;
    else
        cout << "PhoneBook successfully read\n";

    while (notSatisfied)
    {
       cout << "Please enter person to search for: ";
       cin >> searchFor;

       if (searchFor == ".")
       {
           cout << "Thanks for using this program!";
           notSatisfied = 0;
       }


      searching(fileName, searchFor , 1);


    }

}

