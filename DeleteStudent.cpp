#include "DeleteStudent.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio> // for remove/rename
using namespace std;

void DeleteStudent::deleteByUsername(const string& usernameToDelete) {
    ifstream infile("students.txt");
    ofstream tempFile("temp.txt");
    string line;
    bool found = false;

    if (!infile || !tempFile) {
        cerr << "Error opening files.\n";
        return;
    }

    while (getline(infile, line)) {
        if (line.find(usernameToDelete) == string::npos) {
            tempFile << line << endl;
        }
        else {
            found = true;
        }
    }

    infile.close();
    tempFile.close();

    if (found) {
        remove("students.txt");
        rename("temp.txt", "students.txt");
        cout << "Student deleted successfully.\n";
    }
    else {
        remove("temp.txt");
        cout << "Student not found.\n";
    }
}