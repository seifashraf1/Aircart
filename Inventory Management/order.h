#ifndef ORDER_H_
#define ORDER_H_

#include <product.h>

class Order {

private:
        vector <Product*> cart;
        float total_price;
        float total_weight;

public:
        Order();
        void addToCart (Product * p_product);
        float computeTotalPrice ();
        float getTotalPrice ();
        float computeTotalWeight ();
        float getTotalWeight ();
        void printOrder ();
        ~Order();

};

#endif