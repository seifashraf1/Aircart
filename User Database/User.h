//
// Created by yassi on 29-Nov-20.
//



#ifndef PROJECT_USER_H
#define PROJECT_USER_H

#include "Card.h"
#include <list>
#include <functional>

class User{
private:
    std::string username;
    uint32_t  password;
    std::string email;
    std::pair<float,float> home_location;
    std::list<Card> payment_card;
public:
    User(std::string p_username, std::string p_password, std::string p_email, float p_x, float p_y);
    void setUsername(std::string p_username);
    std::string getUsername();
    void setPassword(std::string p_Password);
    bool checkPassword(std::string p_password);
    std::string getEmail();
    void setEmail(std::string p_email);
    void setLocation(float p_x,float p_y);
    std::pair<float,float> getLocation();
    uint32_t Encrypt(std::string p_password);
    void addCard(Card p_card);
    ~User();
};

#endif //PROJECT_USER_H
