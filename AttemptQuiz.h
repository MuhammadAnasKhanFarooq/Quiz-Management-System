#ifndef ATTEMPTQUIZ_H
#define ATTEMPTQUIZ_H

#include <string>

class AttemptQuiz {
private:
    std::string username;

public:
    AttemptQuiz(const std::string& username);
    void start();  // Starts the quiz attempt
};

#endif // ATTEMPTQUIZ_H