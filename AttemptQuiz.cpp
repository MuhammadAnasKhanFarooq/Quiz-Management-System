#include "AttemptQuiz.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype> // For toupper()

using namespace std;

AttemptQuiz::AttemptQuiz(const string& username) {
    this->username = username;
}

void AttemptQuiz::start() {
    ifstream quizFile("quizzes.txt");
    if (!quizFile.is_open()) {
        cout << "No quizzes available to attempt." << endl;
        return;
    }

    // Step 1: Load quiz titles and positions
    const int MAX_QUIZZES = 50;
    string titles[MAX_QUIZZES];
    streampos positions[MAX_QUIZZES];
    int quizCount = 0;

    string line;
    while (getline(quizFile, line)) {
        if (line.find("====") == 0 && line.find("END") == string::npos) {
            if (quizCount >= MAX_QUIZZES) break;

            positions[quizCount] = quizFile.tellg(); // Store position after title line

            // Extract title
            size_t start = line.find_first_not_of("= ");
            size_t end = line.find_last_not_of("= ");
            titles[quizCount] = line.substr(start, end - start + 1);
            quizCount++;
        }
    }

    if (quizCount == 0) {
        cout << "No quizzes found.\n";
        return;
    }

    cout << "\n===== Available Quizzes =====\n";
    for (int i = 0; i < quizCount; ++i) {
        cout << (i + 1) << ". " << titles[i] << "\n";
    }

    int choice;
    cout << "Enter the number of the quiz you want to attempt: ";
    cin >> choice;

    while (choice < 1 || choice > quizCount) {
        cout << "Invalid choice. Enter again: ";
        cin >> choice;
    }

    // Step 2: Jump to quiz content
    quizFile.clear();
    quizFile.seekg(positions[choice - 1]);

    int totalQuestions = 0;
    int correctAnswers = 0;

    cout << "\n---------- Attempting Quiz: " << titles[choice - 1] << " ----------\n";

    while (getline(quizFile, line)) {
        if (line.find("====") == 0 || line.find("END") != string::npos) break;

        if (line.find("Q: ") == 0) {
            string question = line.substr(3);
            string optionA, optionB, optionC, optionD, correctLine;

            getline(quizFile, optionA);
            getline(quizFile, optionB);
            getline(quizFile, optionC);
            getline(quizFile, optionD);
            getline(quizFile, correctLine);

            // Display question and options
            cout << "\nQ: " << question << endl;
            cout << optionA << endl;
            cout << optionB << endl;
            cout << optionC << endl;
            cout << optionD << endl;

            cout << "Your answer (A/B/C/D): ";
            char userAnswer;
            cin >> userAnswer;
            userAnswer = toupper(userAnswer);

            while (userAnswer < 'A' || userAnswer > 'D') {
                cout << "Invalid input. Please enter A, B, C, or D: ";
                cin >> userAnswer;
                userAnswer = toupper(userAnswer);
            }

            // Parse correct answer from "Correct: A"
            char correctAns = ' ';
            size_t pos = correctLine.find("Correct:");
            if (pos != string::npos) {
                string ans = correctLine.substr(pos + 8);
                ans.erase(0, ans.find_first_not_of(" \t"));
                correctAns = toupper(ans[0]);
            }

            if (userAnswer == correctAns) {
                correctAnswers++;
            }

            totalQuestions++;
        }
    }

    quizFile.close();

    // Step 3: Show and save result
    int score = (totalQuestions == 0) ? 0 : (correctAnswers * 100) / totalQuestions;
    cout << "\nQuiz completed! Your Score: " << score << "% (" << correctAnswers << " out of " << totalQuestions << " correct)" << endl;

    ofstream scoreFile("scores.txt", ios::app);
    if (scoreFile.is_open()) {
        scoreFile << username << ": " << titles[choice - 1] << " - " << score << "%\n";
        scoreFile.close();
    }
    else {
        cout << "Error saving score to file." << endl;
    }
}
