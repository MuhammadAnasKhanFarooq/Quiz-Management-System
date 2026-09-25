#include "CreateQuiz.h"
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

void CreateQuiz::create() {
    cout << "Enter Quiz Title: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, quizTitle);

    // Write to file with clear structure
    ofstream quizFile("quizzes.txt", ios::app);
    if (!quizFile) {
        cerr << "Error: Could not open quizzes.txt\n";
        return;
    }

    // Write quiz header with ==== delimiter
    quizFile << "==== " << quizTitle << " ====\n";

    cout << "How many questions (max 5): ";
    int questionCount;
    cin >> questionCount;
    cin.ignore();

    for (int i = 0; i < questionCount; ++i) {
        cout << "Enter question " << i + 1 << ": ";
        getline(cin, questions[i]);
        quizFile << "Q: " << questions[i] << "\n";

        for (int j = 0; j < 4; ++j) {
            cout << "Option " << char('A' + j) << ": ";
            getline(cin, options[i][j]);
            quizFile << char('A' + j) << ") " << options[i][j] << "\n";
        }

        cout << "Enter correct option (A/B/C/D): ";
        cin >> correctAnswers[i];
        quizFile << "Correct: " << (char)toupper(correctAnswers[i]) << "\n\n";
        cin.ignore();
    }
    quizFile << "==== END ====\n\n"; // Clear end marker
    quizFile.close();
    cout << "Quiz saved successfully!\n";
}