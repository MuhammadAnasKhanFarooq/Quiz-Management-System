#include "ViewStudents.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void ViewStudents::displayFromFile() const {
    ifstream file("students.txt");
    if (!file.is_open()) {
        cerr << "No students registered yet." << endl;
        return;
    }

    cout << "\n===== REGISTERED STUDENTS =====" << endl;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, username, password;
        int id;

        getline(ss, name, ',');
        getline(ss, username, ',');
        getline(ss, password, ',');
        ss >> id;

        cout << "Name: " << name << endl
            << "Username: " << username << endl
            << "ID: " << id << endl
            << "--------------------------" << endl;
    }
    file.close();
}