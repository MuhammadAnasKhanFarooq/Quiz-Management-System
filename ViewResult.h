#ifndef VIEWRESULT_H
#define VIEWRESULT_H

#include <string>
using namespace std;

class ViewResult {
private:
    string username;  // Student's username
public:
    ViewResult(const string& username);
    void showResults();  // Show quiz results for this user
};

#endif
