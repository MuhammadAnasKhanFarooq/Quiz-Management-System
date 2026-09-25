#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

class Admin : public User {
public:
    Admin(); // Default constructor
    Admin(string uname, string pword); // Constructor with credentials
};

#endif
