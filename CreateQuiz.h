#ifndef CREATEQUIZ_H
#define CREATEQUIZ_H

#include <string>
using namespace std;

class CreateQuiz {
private:
    string quizTitle;
    string questions[5] = {};       // Initialize arrays
    string options[5][4] = {};      // Initialize 2D array
    char correctAnswers[5] = { '\0' }; // Initialize char array
    int questionCount = 0;          // Initialize counter

public:
    CreateQuiz() = default;         // Default constructor
    void create();
    void display() const;           // Made const
};

#endif