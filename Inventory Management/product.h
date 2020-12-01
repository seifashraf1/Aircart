#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <includes.h>

class Product {

private:
        long unique_id;
        string name;
        float price;
        float weight;
        int quantity;
public:
        Product (long p_id, string p_name, float p_price, float p_weight, int p_quantity);
        void setUniqueId (long p_id);
        long getUniqueId ();
        void setName (string p_name);
        string getName ();
        void setPrice (float p_price);
        float getPrice ();
        void setWeight (float p_weight);
        float getWeight ();
        void setQuantity (int p_quantity);
        int getQuantity ();
        int incQuantity (int amount=1);
        int decQuantity (int amount=1);
        ~Product ();
};

#endif