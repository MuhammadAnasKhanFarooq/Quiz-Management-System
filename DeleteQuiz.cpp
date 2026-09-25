#include "DeleteQuiz.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void DeleteQuiz::deleteQuiz() {
    const int MAX_QUIZZES = 100;
    const int MAX_LINES = 100;
    string quizzes[MAX_QUIZZES][MAX_LINES];
    int quizLineCounts[MAX_QUIZZES] = { 0 };
    string quizTitles[MAX_QUIZZES];

    ifstream inFile("quizzes.txt");
    if (!inFile) {
        cout << "No quizzes found.\n";
        return;
    }

    int quizIndex = -1;
    string line;
    bool inQuiz = false;

    while (getline(inFile, line)) {
        // Trim trailing and leading whitespaces if needed here (optional)
        if (line.find("====") != string::npos && !inQuiz) {
            quizIndex++;
            inQuiz = true;
            quizTitles[quizIndex] = line;
        }

        if (inQuiz && quizIndex >= 0) {
            quizzes[quizIndex][quizLineCounts[quizIndex]++] = line;
        }

        if (line == "==== END ====") {
            inQuiz = false;
        }
    }

    inFile.close();

    if (quizIndex < 0) {
        cout << "No quizzes to delete.\n";
        return;
    }

    // Display quiz titles
    cout << "\n===== AVAILABLE QUIZZES =====\n";
    for (int i = 0; i <= quizIndex; i++) {
        cout << i + 1 << ". " << quizTitles[i] << endl;
    }

    // Get user choice
    int choice;
    cout << "\nEnter quiz number to delete: ";
    cin >> choice;

    if (choice < 1 || choice > quizIndex + 1) {
        cout << "Invalid choice.\n";
        return;
    }

    // Write all other quizzes back to file
    ofstream outFile("quizzes.txt");
    for (int i = 0; i <= quizIndex; i++) {
        if (i == (choice - 1)) continue;

        for (int j = 0; j < quizLineCounts[i]; j++) {
            outFile << quizzes[i][j] << endl;
        }
    }
    outFile.close();

    cout << "Quiz deleted successfully.\n";
}
