#include "Menu.h"
#include <iostream>
using namespace std;

void Menu::showMainMenu() {
    cout << "\n===== MAIN MENU =====" << endl;
    cout << "1. Admin Login" << endl;
    cout << "2. Student Login" << endl;
    cout << "3. Exit" << endl;
}

void Menu::showAdminMenu() {
    cout << "\n===== ADMIN MENU =====" << endl;
    cout << "1. Register Student" << endl;
    cout << "2. View All Students" << endl;
    cout << "3. Delete Student" << endl;
    cout << "4. Create Quiz" << endl;
    cout << "5. View Quizzes" << endl;
    cout << "6. Delete Quiz" << endl;
    cout << "7. View Scores" << endl;
    cout << "8. Logout" << endl;
}

void Menu::showStudentMenu() {
    cout << "\n===== STUDENT MENU =====" << endl;
    cout << "1. Attempt Quiz" << endl;
    cout << "2. View Result" << endl;
    cout << "3. Logout" << endl;
}

int Menu::getChoice() {
    int choice;
    cout << "Enter your choice: ";
    while (!(cin >> choice)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a number: ";
    }
    return choice;
}