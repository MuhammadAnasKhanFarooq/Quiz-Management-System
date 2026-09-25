#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include <string>
using namespace std;


class Student : public User {
public:
    Student();
    Student(string uname, string pword);
    static bool authenticate(const string& username, const string& password);
    void display() const; // Added display function
};

#endif