#include "Student.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
Student::Student() : User() {}
Student::Student(string uname, string pword) : User(uname, pword) {}

bool Student::authenticate(const string& username, const string& password) {
    ifstream file("students.txt");
    if (!file.is_open()) return false;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string storedName, storedUser, storedPass;
        int id;

        getline(ss, storedName, ',');
        getline(ss, storedUser, ',');
        getline(ss, storedPass, ',');
        ss >> id;

        if (storedUser == username && storedPass == password) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void Student::display() const {
    cout << "Student: " << getUsername() << std::endl;
    // Add more display logic as needed
}