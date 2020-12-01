//
// Created by yassi on 29-Nov-20.
//

#include "User_DB.h"
using namespace std;

User_DB::User_DB()
{
}
void User_DB::addUser(User* p_user)
{
    users_list.push_back(p_user);
    number_of_users++;
    cout<<"User added successfully.\n";
}
void User_DB::deleteUser(string p_name, string p_email)
{
    for(auto it=users_list.begin();it!=users_list.end();) {
        if ((*it)->getUsername() == p_name && (*it)->getEmail() == p_email)
        {
            it = users_list.erase(it);
            number_of_users--;
        }
        else
            it++;
    }
    cout<<"User deleted successfully.\n";
}
bool User_DB::authenticate_user(string p_name, string p_password)
{
    for(auto it=users_list.begin();it!=users_list.end();it++)
    {
        if((*it)->getUsername()==p_name) {
            if((*it)->checkPassword(p_password))
            {
                cout<<"Username and Password validated\n";
                return true;
            }
            else
            {
                cout<<"Password invalid\n";
                return false;
            }
        }
    }
    cout<<"Invalid Username\n";
    return false;
}
User_DB::~User_DB()
{
}