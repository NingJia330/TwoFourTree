#include "student.h"
int getValidNumber(string prompt, int low, int high)
{
    int num;
    string garbage;
    bool getVaildnum = false;
    cout << prompt << endl;
	do{
		cin >> num;
		if (cin.fail()||num < low || num > high){
            cout << "The number must be in the range of "
                 << low << " and " << high
                 << ". Enter again." << endl;
			cin.clear();
			getline(cin, garbage);
		}
		else{
			getVaildnum = true;
			getline(cin, garbage);
		}
	} while (getVaildnum == false);
    return num;
}
string getValidstring(string prompt, int Maxlength)
{
    string str;
    cout << prompt << endl;
    getline(cin, str);
    while (str == "" || str.length() > Maxlength){
        cout << "The string must NOT be an empty one and less than "
             << Maxlength << " characters long" << endl;
        getline(cin, str);
    }
    return str;
}
student::student() 
{
    studentNumber = getValidNumber("Enter a six digit Student Number: ", 100000, 999999);
    studentName = getValidstring("Enter Student Name: ", 80);
    streetAddress = getValidstring("Enter student's Street Address: ", 80);
    cityAddress = getValidstring("Enter student's City Address: ", 80);
    emailAddress = getValidstring("Enter student's Email Address: ", 80);
}
student::~student() 
{ }
void student::display()const 
{
    cout << "_________________________________________"<< endl
         << " Student Number: " << studentNumber << endl
         << "   Student Name: " << studentName << endl
         << " Street Address: " << streetAddress << endl		
         << "   City Address: " << cityAddress << endl
         << "  Email Address: " << emailAddress << endl;
}
int student::getStudentNumber()const
{
    return studentNumber;
}
string student::getStudentName()const
{
    return studentName;
}

