#ifndef INV_H_
#define INV_H_

#include <includes.h>
#include <product.h>

#define MIN_STOCK 5

class Inventory {

private:
        map <long, Product*> inventory;

public:
        Inventory ();
        bool addProduct (Product * p_product);
        bool removeProduct (long unique_id);
        Product * getProduct (long unique_id);
        long checkQuantities ();
        void printInventory ();
        ~Inventory ();
};

#endif