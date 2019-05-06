//*********************************************************************************
// File: Pex1 (main.cpp student.h student.cpp PQueue.h Tree234.h) 
// Author: Ning JIA
// Date: Nov 8, 2018
// Updated: Nov 8, 2018
//
// Purpose: Develop a hypothetical small university would like to have a program
//          to record and maintain their student records.
//
// Notes: binary search tree and (2,4) tree (search, traversal and insertion only)
//
// References: http://csci.viu.ca/~liuh/260/assignments/pex2.html
//*********************************************************************************
#include "student.h"
#include "BST.h"
#include "BTree.h"
using namespace std;
const char addNew = 'I';
const char listOne = 'N';
const char listbyNum = 'L';
const char listbyName = 'P';
const char help = 'H';
const char quit = 'Q';
typedef enum {
    Greeting, Menu, InvalidCommand
} MSGType;
void showMessage(MSGType type)
{
    switch (type)
    {
       case Greeting:
           cout << endl
                << "*** Welcome to Student Records System ***"
                << endl << endl;
           break;
       case Menu:
           cout << "-----------------------------------------" << endl
                << "Please enter" << endl
                << "  I to Add a new student" << endl
                << "  N to display ALL information about a student with student number" << endl
                << "  L to list the student number and the name" << endl
                << "  P to list the name and the student number" << endl
                << "  H to help to see this menu" << endl
                << "  Q to exit to terminate this program" << endl;
           break;
       case InvalidCommand:
           cout << endl
                << "Invalid command." << endl
                << endl;
           break;
    }
}
char getCommandFromInput()  // get the command from input
{
    char cmd;
    string garbage; 
    cout << "-----------------------------------------" << endl;
    cout << "Enter your command choice: ";
    cin >> cmd;
    getline(cin, garbage);     
    return toupper(cmd);
}
int main()
{
    showMessage(Greeting);
    showMessage(Menu);	// print the initial message and command options
    BTree Numberlist;
    BST Namelist;
    char cmd;    // cmd is used to store command letter
    // repeatedly get and process the next maintainence action
    while (cmd != quit) {
        cmd = getCommandFromInput();
		if (cmd == addNew){
            student* sptr = new student;
            int k = sptr->getStudentNumber();
            if (Numberlist.lookup(k) != 0){
                cout << "+++This student number aready used, Try again!+++" << endl;
            }else{
                Numberlist.insert(sptr->getStudentNumber(), *sptr);
                Namelist.insert(sptr->getStudentName(), *sptr);
                sptr->display();
                cout << "---This student added.---" << endl;
            }                     
		}else if (cmd == listOne){
		    if (Numberlist.isEmpty())
		        cout << "+++The student List is Empty!+++"<< endl;
            else{ 
		        int num;
    		    string garbage;
		        cout << "Please enter a student number: " << endl;
		        cin >> num;
		        getline(cin, garbage);
		        student* sptr = Numberlist.lookup(num);
		        if (sptr == NULL)
                    cout << "+++Can not find this student, Try again!+++" << endl;
                else sptr->display();
            }
		}else if (cmd == listbyNum){
		    if (Numberlist.isEmpty())
		        cout << "+++The student List is Empty!+++"<< endl;
            else Numberlist.traversal();
		}else if (cmd == listbyName){
		    if (Namelist.isEmpty())
		        cout << "+++The student List is Empty!+++"<< endl;
            else Namelist.traversal();
		}else if (cmd == help){
            showMessage(Menu);
    	}else if (cmd != quit){
    		showMessage(InvalidCommand);
        }
    }
    return 0;
}

