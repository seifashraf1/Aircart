//
// Created by yassi on 29-Nov-20.
//

#ifndef PROJECT_USER_DB_H
#define PROJECT_USER_DB_H

#include "User.h"

class User_DB {
private:
    std::list<User*> users_list;
    int number_of_users;
public:
    User_DB();
    void addUser(User* p_user);
    void deleteUser(std::string p_name, std::string p_email);
    bool authenticate_user(std::string p_name, std::string p_password);
    ~User_DB();
};


#endif //PROJECT_USER_DB_H
