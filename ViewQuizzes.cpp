#include "ViewQuizzes.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void ViewQuizzes::displayAllQuizzes() const {
    ifstream quizFile("quizzes.txt");
    if (!quizFile) {
        cerr << "No quizzes available.\n";
        return;
    }

    cout << "\n===== AVAILABLE QUIZZES =====\n";
    string line;
    int quizNumber = 1;

    while (getline(quizFile, line)) {
        // Check for quiz title line, e.g. ==== y ====
        if (line.find("====") == 0 && line.find("END") == string::npos) {
            // Extract quiz title between '=' signs, trimming spaces
            size_t start = line.find_first_not_of("= ");
            size_t end = line.find_last_not_of("= ");
            string title = line.substr(start, end - start + 1);

            cout << "\nQuiz " << quizNumber++ << ": " << title << "\n";

            // Read and print quiz content until we hit "==== END ===="
            while (getline(quizFile, line) && line != "==== END ====") {
                if (line.find("Q: ") == 0) {
                    cout << "  " << line << "\n";
                }
                else if (line.find(")") != string::npos) {
                    cout << "    " << line << "\n";
                }
                else if (line.find("Correct:") != string::npos) {
                    cout << "    " << line << "\n";
                }
                else if (!line.empty()) {
                    // Print any other non-empty lines just in case
                    cout << "  " << line << "\n";
                }
            }
        }
    }
    quizFile.close();
}
