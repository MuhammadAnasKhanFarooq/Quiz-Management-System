#include "User.h"
#include <iostream>

User::User() : username(""), password("") {}

User::User(string uname, string pword) {
    if (uname.empty() || pword.empty())
        throw "Username/password cannot be empty";
    if (pword.length() < 6)
        throw "Password must be at least 6 characters";
    username = uname;
    password = pword;
}

void User::setCredentials(string uname, string pword) {
    if (uname.empty() || pword.empty())
        throw "Username/password cannot be empty";
    username = uname;
    password = pword;
}

bool User::authenticate(string uname, string pword) const {
    return (username == uname && password == pword);
}