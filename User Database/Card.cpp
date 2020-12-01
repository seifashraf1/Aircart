//
// Created by yassi on 29-Nov-20.
//

#include "Card.h"
using namespace std;

Card::Card(string p_card_holder, string p_card_number, string p_cvv, int p_M, int p_Y)
{
    card_holder=p_card_holder;
    card_number=p_card_number;
    cvv=p_cvv;
    expiry_date.first=p_M;
    expiry_date.second=p_Y;
}
Card::~Card()
{
}