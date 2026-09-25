#include "ViewScores.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void ViewScores::viewAllScores() const {
    ifstream inFile("scores.txt");
    if (!inFile) {
        cerr << "No scores recorded yet." << endl;
        return;
    }

    cout << "\n======= Student Scores =======" << endl;
    string line;

    while (getline(inFile, line)) {
        // Format: username: quiz title - score%
        size_t colonPos = line.find(':');
        size_t dashPos = line.find('-');

        if (colonPos != string::npos && dashPos != string::npos) {
            string username = line.substr(0, colonPos);
            string quizTitle = line.substr(colonPos + 1, dashPos - colonPos - 1);
            string score = line.substr(dashPos + 1);

            // Trim whitespaces
            username.erase(0, username.find_first_not_of(" "));
            username.erase(username.find_last_not_of(" ") + 1);

            quizTitle.erase(0, quizTitle.find_first_not_of(" "));
            quizTitle.erase(quizTitle.find_last_not_of(" ") + 1);

            score.erase(0, score.find_first_not_of(" "));
            score.erase(score.find_last_not_of(" ") + 1);

            cout << username << " attempted quiz \"" << quizTitle << "\" and got " << score << "%" << endl;
        }
        else {
            // In case of invalid format, print the raw line
            cout << line << endl;
        }
    }

    inFile.close();
}
