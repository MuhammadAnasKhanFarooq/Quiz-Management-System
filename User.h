#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
protected:
    string username;
    string password; // Still plaintext but with validation

public:
    User();
    User(string uname, string pword);

    void setCredentials(string uname, string pword);
    bool authenticate(string uname, string pword) const;

    string getUsername() const { return username; }
    // Removed getPassword() for security
};

#endif