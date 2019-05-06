#ifndef STUDENT_H
#define STUDENT_H

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

class student{
    public:
        student(); //ceate a new student with student Number, Name, and each Address
        ~student();       //destructor 
        void display()const;    //display one student all info.
        int getStudentNumber()const;    //get the Student Number
        string getStudentName()const;   //get the Student Name
    private:
        int studentNumber;
        string studentName;
        string streetAddress;
        string cityAddress;
        string emailAddress;
};
int getValidNumber(string prompt, int low, int high); 
string getValidString(string prompt, int strlength);

#endif
