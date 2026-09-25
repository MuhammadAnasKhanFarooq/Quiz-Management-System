#include <iostream>
#include <fstream>
#include "RegisterStudent.h"
using namespace std;

RegisterStudent::RegisterStudent() {
    name = "";
    username = "";
    password = "";
    id = 0;
}

// Function to input student details
void RegisterStudent::inputStudentDetails() {
    cout << "Enter student full name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter username: ";
    getline(cin, username);

    cout << "Enter password: ";
    getline(cin, password);

    cout << "Enter student ID: ";
    cin >> id;
}

// Function to save student details to a file
void RegisterStudent::saveToFile() {
    ofstream file("students.txt", ios::app);
    if (file.is_open()) {
        file << name << "," << username << "," << password << "," << id << endl;
        file.close();
        cout << "Student registered successfully!" << endl;
    }
    else {
        cout << "Error: Could not open students.txt for writing!" << endl;
    }
}

// Setter for student name
void RegisterStudent::setName(string studentName) {
    name = studentName;
}

// Getter for student name
string RegisterStudent::getName() const {
    return name;
}

// Setter for student ID
void RegisterStudent::setId(int studentId) {
    id = studentId;
}

// Getter for student ID
int RegisterStudent::getId() const {
    return id;
}
