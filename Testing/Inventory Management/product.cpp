#include <product.h>

Product::Product (long p_id, string p_name, float p_price, float p_weight, int p_quantity){
        
        unique_id = p_id;
        name = p_name;
        price = p_price;
        weight = p_weight;
        quantity = p_quantity;
}

void Product::setUniqueId (long p_id){
        unique_id = p_id;
}
long Product::getUniqueId (){
        return unique_id;
}

void Product::setName (string p_name){
        name = p_name;
}
string Product::getName (){
        return name;
}

void Product::setPrice (float p_price){
        price = p_price;
}
float Product::getPrice (){
        return price;
}

void Product::setWeight (float p_weight){
        weight = p_weight;
}
float Product::getWeight (){
        return weight;
}

int Product::getQuantity (){
        return quantity;
}
void Product::setQuantity (int p_quantity){
        quantity = p_quantity;
}
int Product::incQuantity (int amount){
        quantity += amount;
        return quantity;
}
int Product::decQuantity (int amount){
        quantity = quantity - amount;
        return quantity;
}

Product::~Product (){}