#ifndef REGISTER_STUDENT_H
#define REGISTER_STUDENT_H

#include <string>
using namespace std;

class RegisterStudent {
private:
    string name;
    string username;
    string password;
    int id;  // Assuming you want to store an ID for each student

public:
    RegisterStudent();  // Constructor
    void inputStudentDetails();  // Function to input student details
    void saveToFile();  // Function to save student data to file

    // Setter and getter methods for name and ID
    void setName(string studentName);
    string getName() const;
    void setId(int studentId);
    int getId() const;
};

#endif  // REGISTER_STUDENT_H
