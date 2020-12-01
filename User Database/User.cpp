//
// Created by yassi on 29-Nov-20.
//
#include "User.h"
using namespace std;

User::User(string p_username, string p_password, string p_email, float p_x, float p_y)
{
    setUsername(p_username);
    setPassword(p_password);
    setEmail(p_email);
    setLocation(p_x, p_y);
}
void User::setUsername(string p_username)
{
    username=p_username;
    cout<<"Username set successfully.\n";
}
std::string User::getUsername()
{
    return username;
}
void User::setPassword(string p_Password)
{
    password=Encrypt(p_Password);
    cout<<"Password set successfully.\n";
}
bool User::checkPassword(string p_password)
{
    size_t i = 0;
    uint32_t hash = 0;
    while (i != p_password.length()) {
        hash += p_password[i++];
        hash += hash << 10;
        hash ^= hash >> 6;
    }
    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;
    return (password==hash);
}
void User::setEmail(string p_email)
{
    email=p_email;
    cout<<"Email set successfully.\n";
}
string User::getEmail()
{
    return email;
}
void User::setLocation(float p_x,float p_y)
{
    home_location.first=p_x;
    home_location.second=p_y;
    cout<<"Home Location set successfully.\n";
}
pair<float,float> User::getLocation()
{
    return home_location;
}

uint32_t  User::Encrypt(std::string p_password)
{
    size_t i = 0;
    uint32_t hash = 0;
    while (i != p_password.length()) {
        hash += p_password[i++];
        hash += hash << 10;
        hash ^= hash >> 6;
    }
    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;
    password=hash;
    return hash;
}

void User::addCard(Card p_card)
{
    payment_card.push_back(p_card);
    cout<<"Card added successfully.\n";
}
User::~User()
{
}