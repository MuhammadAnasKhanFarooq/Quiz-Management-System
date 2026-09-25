#include <iostream>
#include <vector>
#include "Admin.h"
#include "Student.h"
#include "Menu.h"
#include "RegisterStudent.h"
#include "ViewStudents.h"
#include "DeleteStudent.h"
#include "CreateQuiz.h"
#include "ViewQuizzes.h"
#include "DeleteQuiz.h"
#include "ViewScores.h"
#include "AttemptQuiz.h"
#include "ViewResult.h"

using namespace std;

// --- Forward Declarations ---
static bool adminLogin();
static bool studentLogin(string& username);
static void handleAdminMenu(Menu& menu);
static void handleStudentMenu(Menu& menu, const string& username);

// --- Main Program ---
int main() {
    Menu menu;
    int mainChoice;

    do {
        menu.showMainMenu();
        mainChoice = menu.getChoice();

        switch (mainChoice) {
        case 1: { // Admin
            if (adminLogin()) {
                cout << "Login successful!\n";
                handleAdminMenu(menu);
            }
            else {
                cout << "Invalid credentials!\n";
            }
            break;
        }
        case 2: { // Student
            string username;
            if (studentLogin(username)) {
                cout << "Login successful!\n";
                handleStudentMenu(menu, username);
            }
            else {
                cout << "Invalid credentials!\n";
            }
            break;
        }
        case 3: // Exit
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (mainChoice != 3);

    return 0;
}

// --- Helper Functions ---
static bool adminLogin() {
    string username, password;
    cout << "Enter Admin Username: ";
    cin >> username;
    cout << "Enter Admin Password: ";
    cin >> password;

    Admin admin("admin", "admin123"); // Default credentials
    return admin.authenticate(username, password);
}

static bool studentLogin(string& username) {
    string password;
    cout << "Enter Student Username: ";
    cin >> username;
    cout << "Enter Student Password: ";
    cin >> password;

    return Student::authenticate(username, password);
}

// --- Admin Operations ---
static void handleAdminMenu(Menu& menu) {
    CreateQuiz quizMaker;
    ViewQuizzes quizViewer;
    DeleteQuiz quizDeleter;
    ViewScores scoreViewer;
    RegisterStudent studentRegistrar;
    ViewStudents studentViewer;
    DeleteStudent studentDeleter;

    int adminChoice;
    do {
        menu.showAdminMenu();
        adminChoice = menu.getChoice();

        switch (adminChoice) {
        case 1: // Register Student
            studentRegistrar.inputStudentDetails();
            studentRegistrar.saveToFile();
            break;
        case 2: // View Students
            studentViewer.displayFromFile(); // Updated to use file-based view
            break;
        case 3: { // Delete Student
            string username;
            cout << "Enter username to delete: ";
            cin >> username;
            studentDeleter.deleteByUsername(username);
            break;
        }
        case 4: // Create Quiz
            quizMaker.create();
            break;
        case 5: // View Quizzes
            quizViewer.displayAllQuizzes();
            break;
        case 6: // Delete Quiz
            quizDeleter.deleteQuiz();
            break;
        case 7: // View Scores
            scoreViewer.viewAllScores();
            break;
        case 8: // Logout
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (adminChoice != 8);
}

// --- Student Operations ---
static void handleStudentMenu(Menu& menu, const string& username) {
    AttemptQuiz quizAttempt(username);
    ViewResult resultViewer(username);

    int studentChoice;
    do {
        menu.showStudentMenu();
        studentChoice = menu.getChoice();

        switch (studentChoice) {
        case 1: // Attempt Quiz
            quizAttempt.start();
            break;
        case 2: // View Result
            resultViewer.showResults();
            break;
        case 3: // Logout
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (studentChoice != 3);
}