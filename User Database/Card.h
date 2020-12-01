//
// Created by yassi on 29-Nov-20.
//


#ifndef PROJECT_CARD_H
#define PROJECT_CARD_H

#include <iostream>

class Card {
private:
    std::string card_holder;
    std::string card_number;
    std::string cvv;
    std::pair<int,int> expiry_date;
public:
    Card(std::string p_card_holder, std::string p_card_number, std::string p_cvv, int p_M, int p_Y);
    ~Card();
};


#endif //PROJECT_CARD_H
