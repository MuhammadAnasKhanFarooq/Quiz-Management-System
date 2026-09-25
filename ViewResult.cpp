#include "ViewResult.h"
#include <iostream>
#include <fstream>

using namespace std;

ViewResult::ViewResult(const string& username) {
    this->username = username;
}

void ViewResult::showResults() {
    ifstream file("scores.txt");
    if (!file.is_open()) {
        cout << "No results found. File could not be opened." << endl;
        return;
    }

    string line;
    bool found = false;

    cout << "\n-------------------- Your Quiz Results --------------------\n";
    while (getline(file, line)) {
        if (line.find(username + ":") == 0) {
            // Format: username: quiz title - score%
            size_t colonPos = line.find(':');
            size_t dashPos = line.find('-');

            if (colonPos != string::npos && dashPos != string::npos) {
                string quizTitle = line.substr(colonPos + 1, dashPos - colonPos - 1);
                string score = line.substr(dashPos + 1);

                // Trim extra spaces
                quizTitle.erase(0, quizTitle.find_first_not_of(" "));
                quizTitle.erase(quizTitle.find_last_not_of(" ") + 1);
                score.erase(0, score.find_first_not_of(" "));
                score.erase(score.find_last_not_of(" ") + 1);

                cout << username << " attempted quiz \"" << quizTitle << "\" and got " << score << "%" << endl;
                found = true;
            }
        }
    }

    if (!found) {
        cout << "No results found for user: " << username << endl;
    }

    file.close();
}
